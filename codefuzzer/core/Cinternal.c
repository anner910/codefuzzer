#include "Core.h"


#ifdef __cplusplus
extern "C"{
#endif

void in_mutatorInit(void)
{
	MdataBitFillInit();
	MdataBitMulRandomInit();
	MdataBitOneRandomInit();
	MdataBitZeroInit();

	MdataByteMulInsertInit();
	MdataByteMulRandomInit();
	MdataByteOneInsertInit();
	MdataByteOneRandomInit();

	MdataCorpusSwapInit();

	MdataLengthExtendMagicMemInit();
	MdataLengthExtendSpecificInit();
	MdataLengthRepeatSelfInsertInit();
	MdataLengthRepeatSelfTailInit();
	
	MdataMemoryDictBlobInit();
	MdataMemoryDictStringInit();
	MdataMemoryHookInit();
	MdataMemoryNumberStringInit();
	MdataMemoryOtherCorpusInit();
	MdataMemoryStaticStringInit();

	MdataNumberChangeInit();
	MdataNumberDictInit();
	MdataNumberHookInit();
	MdataNumberSelfInit();
	MdataNumberSizeInit();
	MdataNumberStringInit();
	
	MdataReduceInit();

	MdataSelfToOtherInit();
	MdataSelfToSelfInit();
	
	
	MdataStringCaseInit();
	
	MNoMutatorInit();
	
	MNumberEdgeInit();
	MNumberGaussInit();
	MNumberLittleRandomInit();
	MNumberMagicInit();
	MNumberRandomInit();
	MNumberRangeInit();
	MNumberSwapInit();
	MNumberTableInit();

	MSelfInit();
	
	MStringTableInit();

	MBlobTableInit();
}

void in_seed_init(void)
{
	if (g_thread.setSeed)
	{
		g_thread.runSeed = g_thread.setSeed;
	}
	else
		g_thread.runSeed = PL_getTime();
}


void in_seed(int runcount)
{
	PL_seed(g_thread.runSeed + runcount);
}


//超过20亿会出问题
u32 in_getGuassRandom(u32 max)
{
	if (max == 0)
		return 0;
	
	//得到多少bit
	int bitNum = lib_getTotalBit(max);

	//选取在那个bit范围变异
	int num = PL_random_range(0, bitNum);
	
	u32 ret = PL_random_range(0, (1 << num));

	if (ret > max)
		ret = PL_random_range(0, max);

	return ret;
}

s64 in_getGuassRandoms64(int len)
{
	
	//得到多少bit
	int bitNum = len * 8;

	//选取在那个bit范围变异
	int num = PL_random_range(0, bitNum);
	s64 ret = PL_random_range_64((0 - (1 << num)), (1 << num));

	return ret;
}

//很多情况下，权重更为重要
//一半随机，一半高斯 
u32 in_getWeightRandom(u32 max)
{
	if (max == 0)
		return 0;

	int weight = PL_random() % 100;
	
	if (weight > 50)
		return in_getGuassRandom(max);

	return PL_random_range(0, max);
}


u64 in_getMagicNumber0(void)
{
	int weight = PL_random()% 100;
	
	u64 temp = 0;

	//最早获取
	if (weight > 70)
		temp = dict_GetNumber();
	else
		temp = do_GetHookNumber();

	weight = PL_random()% 100;
	//做大小端转换
	if (weight > 70)
		temp = Bswap64(temp);

	weight = PL_random()% 100;
	//做微调
	if (weight > 70)
		temp += PL_random_range( -255, 255);
	
	return temp;
}

u64 in_getMagicNumber(void)
{
	int weight = PL_random()% 100;
	
	u64 temp = in_getMagicNumber0();

	//最早获取
	if (weight > 20)
		return temp;

	u64 temp1 = in_getMagicNumber0();

	if (weight > 15)
		return temp - temp1;

	if (weight > 10)
		return temp + temp1;

	if (weight > 5)
		return temp * temp1;

	if (temp1 != 0)
		return temp / temp1;
	
	return temp;
}


void in_getCorpusBlob(char** blob,int *len)
{
	if ((g_thread.corpusNumber == 0)
		||(g_thread.paraNumber == 0))
	{
		*blob = NULL;
		*len = 0;
		return;
	}
	//选择样本
	int corpus = PL_random()% g_thread.corpusNumber;

	//选择参数
	int para = PL_random()% g_thread.paraNumber;

	*blob = g_thread.corpus[corpus].paraValue[para].value;
	*len = g_thread.corpus[corpus].paraValue[para].len;

	//百分之50返回一部分
	int temp = PL_random()% 2;
	int len1 = 0;
	int pos = 0;

	if ((temp == 1) && (*len != 0))
	{
		
		//长度
		len1 = in_getWeightRandom(*len);
		//开始位置
		pos = in_getWeightRandom(*len - len1);

		*blob = *blob + pos;
		*len = len1;
	}
	return;
		
}


void in_getMagicBlob(char** blob,int *len)
{
	int weight = PL_random()% 100;
	
	if (weight > 90)
	{
		dict_GetBlob(blob, len);
	}
	else if (weight > 80)
	{
		dict_GetString(blob, len);
	}
	else if (weight > 70)
	{
		dict_GetStatic(blob, len);
	}
	else if (weight > 60)
	{
		in_getCorpusBlob(blob, len);
	}
	else
	{
		do_GetHookBlob(blob, len);
	}
}

int in_getLen(SPara* para, int pos)
{
	int weight = PL_random()% 100;

	int len = 0;

	//扩展最终长度

	//gauss
	if (weight > 60)
	{
		len = in_getGuassRandom(para->maxValue);
	}
	//edge
	else if (weight > 30)
	{
		int temp = PL_random_range(7, 24);

		int temp1 = PL_random() % 2;
		
		if (temp1 == 1)
			len = 1 << temp;
		else
			len = (1 << temp) -1;
	}
	//hoolk
	else
	{
		len = do_GetHookNumber();
	}

	//纯随机
	int maxlen = MIN(para->mutatormaxlen + 100,g_global.setMaxMutatorLen);
	if (len > maxlen)
			len = PL_random_range(para->mutatorInitlen, maxlen);

	return len;

}

u32 in_getParaCrc(void)
{
	int i;
	int j;
	u32 crc = 0;
	char* tempcrc = (char*)&crc;
	int k = 0;
	for(i = 0;i < g_thread.paraNumber; i++)
	{
		for(j = 0;j < g_thread.para[i].paraValue.len; j++)
		{
			tempcrc[k] += (u8)g_thread.para[i].paraValue.value[j];
			k++;
			if(k == 4)
				k = 0;
		}
	}
	return crc;
}

int in_getParaHash(void)
{
	char hash[4] = {0};
	int k = 0;
	int i;
	int j;
	
	for(i = 0;i < g_thread.paraNumber;i++)
	{
		for(j = 0;j < g_thread.para[i].paraValue.len; j++)
		{
			hash[k++] = g_thread.para[i].paraValue.value[j];

			if(k == 4)
				k = 0;
		}
	}
	return *(int*)hash;
}


s64 in_getRunCount(void)
{
	return g_thread.runCount;
}


int in_scheduleMutatorWeight(int weight)
{
	if (g_global.setEnableScheduleMutatorWeight == 0)
		return weight;
	
	if (g_thread.runCount < 100000)
		return weight/50;

	if (g_thread.runCount < 1000000)
		return weight/5;
	
	return weight;
}


void in_ParaMutatorNumberReplace64(char* buf, int len, s64 number)
{
	s64 temp = number;

	int tempPos = in_getWeightRandom(len - 8);
	s64 numberSelf = *(s64*)(buf + tempPos);

	int weight = PL_random() % 100;

	if (weight > 70)
		temp = temp + PL_random_range(-50, 50);

	weight = PL_random() % 100;

	if (weight > 80)
		numberSelf = Bswap64(numberSelf);

	int weight1 = PL_random() % 100;

	if (weight1 > 95)
		temp = temp - numberSelf;
	else if (weight1 > 90)
		temp = numberSelf - temp;
	else if (weight1 > 80)
		temp = numberSelf + temp;
	else if (weight1 > 70)
		temp = numberSelf * temp;

	if (weight > 80)
		temp = Bswap64(temp);

	*(s64*)(buf + tempPos) = temp;
}

void in_ParaMutatorNumberReplace32(char* buf, int len, s32 number)
{
	s32 temp = number;

	int tempPos = in_getWeightRandom(len - 4);
	s32 numberSelf = *(s32*)(buf + tempPos);

	int weight = PL_random() % 100;

	if (weight > 70)
		temp = temp + PL_random_range(-50, 50);

	
	weight = PL_random() % 100;
	
	if (weight > 80)
		numberSelf = Bswap32(numberSelf);
	
	int weight1 = PL_random() % 100;

	if (weight1 > 95)
		temp = temp - numberSelf;
	else if (weight1 > 90)
		temp = numberSelf - temp;
	else if (weight1 > 80)
		temp = numberSelf + temp;
	else if (weight1 > 70)
		temp = numberSelf * temp;
	
	if (weight > 80)
		temp = Bswap32(temp);

	*(s32*)(buf + tempPos) = temp;
}

void in_ParaMutatorNumberReplace16(char* buf, int len, s16 number)
{
	s16 temp = number;

	int tempPos = in_getWeightRandom(len - 2);
	s16 numberSelf = *(s16*)(buf + tempPos);

	int weight = PL_random() % 100;

	if (weight > 70)
		temp = temp + PL_random_range(-50, 50);

	weight = PL_random() % 100;

	if (weight > 80)
		numberSelf = Bswap16(numberSelf);

	int weight1 = PL_random() % 100;

	if (weight1 > 95)
		temp = temp - numberSelf;
	else if (weight1 > 90)
		temp = numberSelf - temp;
	else if (weight1 > 80)
		temp = numberSelf + temp;
	else if (weight1 > 70)
		temp = numberSelf * temp;

	if (weight > 80)
		temp = Bswap16(temp);

	*(s16*)(buf + tempPos) = temp;
}

void in_ParaMemoryMutator(SPara* para, int pos, char* buf, int len)
{
	int weight = PL_random() % 100;

	//替换
	if (weight > 90)
	{
		in_mutatorParaGetBuf(para);
		
		PL_memcpy(para->paraValue.value,buf,len);
		para->paraValue.len = len;

	}
	//插入
	else if(weight > 60)
	{
		in_mutatorParaGetBuf(para);

		//选择插入的位置
		int tempPos = in_getWeightRandom(para->mutatorInitlen);

		if ((len + para->mutatorInitlen ) > g_global.setMaxMutatorLen)
			return;

		PL_memcpy(para->paraValue.value ,para->mutatorInitvalue, tempPos);
		PL_memcpy(para->paraValue.value + tempPos, buf, len);
		PL_memcpy(para->paraValue.value + tempPos + len,para->mutatorInitvalue + tempPos,para->mutatorInitlen - tempPos);
		
		para->paraValue.len = para->mutatorInitlen + len;

	}
	//覆盖
	else
	{
		in_mutatorParaGetInitBuf(para);

		//选择替换的位置
		int tempPos = in_getWeightRandom(para->mutatorInitlen);

		if ((tempPos + len ) > g_global.setMaxMutatorLen)
			return;

		PL_memcpy(para->paraValue.value + tempPos, buf, len);
		para->paraValue.len = MAX(para->mutatorInitlen, tempPos + len);
	}
}


#ifdef __cplusplus
}
#endif


