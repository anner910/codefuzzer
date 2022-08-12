/*************************************************************************************************************
对数据某些字段进行替换

1.使用全0

1.1将全0变成随机

2.使用全f

3.使用从0递增

3.使用从随机递增


4.使用从f递减

4.使用从随机递减


5.使用全随机

6.使用样本另一部分

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataSelfToOther;

int MdataSelfToOtherGetCount(SPara* para)
{
	return s_MdataSelfToOther.weight;
}

char* MdataSelfTo0GetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异长度
	int changelen = in_getGuassRandom(para->mutatorInitlen);
	
	if (changelen == 0)
		changelen = 1;

	//选取变异位置
	int changepos = in_getWeightRandom(para->mutatorInitlen - changelen);

	
	PL_memset(para->paraValue.value + changepos, 0, changelen);

	return para->paraValue.value;
}

char* MdataSelf0ToOtherGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异长度
	int changelen = in_getGuassRandom(para->mutatorInitlen);
	
	if (changelen == 0)
		changelen = 1;

	//选取变异位置
	int changepos = in_getWeightRandom(para->mutatorInitlen - changelen);
	int i = 0;
	
	for (i = 0; i < changelen; i++)
	{
		if (para->paraValue.value[changepos + i] == 0)
		para->paraValue.value[changepos + i] = PL_random_byte();
	}

	return para->paraValue.value;
}


char* MdataSelfTofGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异长度
	int changelen = in_getGuassRandom(para->mutatorInitlen);
	
	if (changelen == 0)
		changelen = 1;

	//选取变异位置
	int changepos = in_getWeightRandom(para->mutatorInitlen - changelen);

	PL_memset(para->paraValue.value + changepos, 0xff, changelen);

	return para->paraValue.value;
}

char* MdataSelfToOther0AddGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异长度
	int changelen = in_getGuassRandom(para->mutatorInitlen);
	
	if (changelen == 0)
		changelen = 1;

	//选取变异位置
	int changepos = in_getWeightRandom(para->mutatorInitlen - changelen);
	
	int i;
	u8 data = 0;
	for (i = 0; i < changelen; i++)
	{
		para->paraValue.value[changepos + i] = data++;
	}

	return para->paraValue.value;
}

char* MdataSelfToOtherAddGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异长度
	int changelen = in_getGuassRandom(para->mutatorInitlen);
	
	if (changelen == 0)
		changelen = 1;

	//选取变异位置
	int changepos = in_getWeightRandom(para->mutatorInitlen - changelen);
	
	int i;
	u8 data = PL_random_byte();
	for (i = 0; i < changelen; i++)
	{
		para->paraValue.value[changepos + i] = data++;
	}

	return para->paraValue.value;
}

char* MdataSelfToOtherFDelGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异长度
	int changelen = in_getGuassRandom(para->mutatorInitlen);
	
	if (changelen == 0)
		changelen = 1;

	//选取变异位置
	int changepos = in_getWeightRandom(para->mutatorInitlen - changelen);
	
	int i;
	u8 data = 0xff;
	for (i = 0; i < changelen; i++)
	{
		para->paraValue.value[changepos + i] = data--;
	}

	return para->paraValue.value;
}


char* MdataSelfToOtherDelGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异长度
	int changelen = in_getGuassRandom(para->mutatorInitlen);
	
	if (changelen == 0)
		changelen = 1;

	//选取变异位置
	int changepos = in_getWeightRandom(para->mutatorInitlen - changelen);
	
	int i;
	u8 data = PL_random_byte();
	for (i = 0; i < changelen; i++)
	{
		para->paraValue.value[changepos + i] = data--;
	}

	return para->paraValue.value;
}

char* MdataSelfToRandomGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异长度
	int changelen = in_getGuassRandom(para->mutatorInitlen);
	
	if (changelen == 0)
		changelen = 1;

	//选取变异位置
	int changepos = in_getWeightRandom(para->mutatorInitlen - changelen);
	
	int i;
	for (i = 0; i < changelen; i++)
	{
		para->paraValue.value[changepos + i] = PL_random_byte();
	}

	return para->paraValue.value;
}

char* MdataSelfToOtherFromSelfGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异长度
	int changelen = in_getGuassRandom(para->mutatorInitlen);
	
	if (changelen == 0)
		changelen = 1;

	//选取变异位置
	int changepos = in_getWeightRandom(para->mutatorInitlen - changelen);

	//选取copy位置
	int copypos = PL_random_range(0, para->mutatorInitlen - changelen);
	
	PL_memcpy(para->paraValue.value + changepos, para->mutatorInitvalue + copypos, changelen);

	return para->paraValue.value;
}


char* MdataSelfToOtherGetValue(SPara* para, int pos)
{
	int weight = PL_random()% 100;

	if (weight > 90)
		return MdataSelfTo0GetValue(para, pos);

	if (weight > 80)
		return MdataSelf0ToOtherGetValue(para, pos);

	if (weight > 70)
		return MdataSelfTofGetValue(para, pos);

	if (weight > 60)
		return MdataSelfToOther0AddGetValue(para, pos);

	if (weight > 50)
		return MdataSelfToOtherAddGetValue(para, pos);

	if (weight > 40)
		return MdataSelfToOtherFDelGetValue(para, pos);

	if (weight > 30)
		return MdataSelfToOtherDelGetValue(para, pos);

	if (weight > 20)
		return MdataSelfToRandomGetValue(para, pos);
		
	return MdataSelfToOtherFromSelfGetValue(para, pos);
}


int MdataSelfToOtherGetSupport(SPara* para)
{
	//初始长度为0不支持
	if (para->mutatorInitlen == 0)
		return Return_No;
	
	//初始长度为0不支持
	return Return_Yes;
}

SMutator s_MdataSelfToOther =
{
	"MdataSelfToOther",
	MdataSelfToOtherGetCount,
	MdataSelfToOtherGetValue,
	MdataSelfToOtherGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MdataSelfToOtherInit(void)
{

	g_global.g_mutatorModule[MdataSelfToOther] = &s_MdataSelfToOther;
}


#ifdef __cplusplus
}
#endif

