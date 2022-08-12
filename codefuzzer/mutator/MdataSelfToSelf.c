/*************************************************************************************************************

自己变异自己

字段之间交换，覆盖，插入

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataSelfToSelf;


int MdataSelfToSelfGetCount(SPara* para)
{
	return s_MdataSelfToSelf.weight;
}

char* MdataSelfToSelfGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//找到要copy的数据
	int firstPos = in_getWeightRandom(para->mutatorInitlen - 1);
	int firstLen = in_getGuassRandom(para->mutatorInitlen - firstPos);

	if (firstLen == 0)
		firstLen = 1;

	//得到第二个位置
	int secondPos = in_getWeightRandom(para->mutatorInitlen - 1);
	int secondLen = in_getGuassRandom(para->mutatorInitlen - secondPos);


	int weight = PL_random() % 5;
	

	//从first拷贝数据插入到second
	if (weight == 1)
	{
		if ((para->mutatorInitlen + firstLen) > g_global.setMaxMutatorLen)
		{
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
			para->paraValue.len = para->mutatorInitlen;
			return para->paraValue.value;

		}
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue, secondPos);
		PL_memcpy(para->paraValue.value + secondPos, para->mutatorInitvalue + firstPos, firstLen);
		PL_memcpy(para->paraValue.value + secondPos + firstLen, para->mutatorInitvalue + secondPos, para->mutatorInitlen - secondPos);

		para->paraValue.len = para->mutatorInitlen + firstLen;
	}
	//从second拷贝数据插入到first,并删除first
	else if (weight == 2)
	{
		if (secondPos > firstPos)
		{
		}
		else
		{
			int tempPos = firstPos;
			int tempLen = firstLen;
			
			firstPos = secondPos;
			firstLen = secondLen;

			secondPos = tempPos;
			secondLen = tempLen;
		}

		if ((para->mutatorInitlen + secondLen - firstLen) > g_global.setMaxMutatorLen)
		{
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
			para->paraValue.len = para->mutatorInitlen;
			return para->paraValue.value;

		}
		
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue, firstPos);
		PL_memcpy(para->paraValue.value + firstPos, para->mutatorInitvalue + secondPos, secondLen);
		PL_memcpy(para->paraValue.value + firstPos + secondLen, para->mutatorInitvalue + firstPos + firstLen, para->mutatorInitlen - firstPos - firstLen);

		para->paraValue.len = para->mutatorInitlen + secondLen - firstLen;
	}
	//从first拷贝数据覆盖到second位置
	else if (weight == 1)
	{

		if ((para->mutatorInitlen + secondLen + firstLen) > g_global.setMaxMutatorLen)
		{
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
			para->paraValue.len = para->mutatorInitlen;
			return para->paraValue.value;

		}
		
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue, para->mutatorInitlen);
		PL_memcpy(para->paraValue.value + secondPos, para->mutatorInitvalue + firstPos, firstLen);

		para->paraValue.len = MAX(para->mutatorInitlen + secondLen + firstLen, para->mutatorInitlen);
	}
	//交换
	else
	{
		if ((firstPos + firstLen) <= secondPos)
		{
			
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue, firstPos);
			//拷贝second
			PL_memcpy(para->paraValue.value + firstPos, para->mutatorInitvalue + secondPos, secondLen);
			
			PL_memcpy(para->paraValue.value + firstPos + secondLen, para->mutatorInitvalue + firstPos + firstLen, 
				secondPos - firstPos - firstLen);
			//拷贝first
			PL_memcpy(para->paraValue.value + secondLen + secondPos - firstLen, para->mutatorInitvalue + firstPos, 
				firstLen);

			PL_memcpy(para->paraValue.value + secondLen + secondPos, para->mutatorInitvalue + secondLen + secondPos, 
				para->mutatorInitlen - secondPos - secondLen);

		}
		else if ((secondPos + secondLen) <= firstPos)
		{

			int tempPos = firstPos;
			int tempLen = firstLen;
			
			firstPos = secondPos;
			firstLen = secondLen;

			secondPos = tempPos;
			secondLen = tempLen;
			
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue, firstPos);
			//拷贝second
			PL_memcpy(para->paraValue.value + firstPos, para->mutatorInitvalue + secondPos, secondLen);
			
			PL_memcpy(para->paraValue.value + firstPos + secondLen, para->mutatorInitvalue + firstPos + firstLen, 
				secondPos - firstPos - firstLen);
			//拷贝first
			PL_memcpy(para->paraValue.value + secondLen + secondPos - firstLen, para->mutatorInitvalue + firstPos, 
				firstLen);

			PL_memcpy(para->paraValue.value + secondLen + secondPos, para->mutatorInitvalue + secondLen + secondPos, 
				para->mutatorInitlen - secondPos - secondLen);

		}
		else
		{
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
			para->paraValue.len = para->mutatorInitlen;
			return para->paraValue.value;
		}

	}
	

	return para->paraValue.value;
}

int MdataSelfToSelfGetSupport(SPara* para)
{
	//初始长度为0不支持
	if (para->mutatorInitlen == 0)
		return Return_No;
	
	//初始长度为0不支持
	return Return_Yes;
}

SMutator s_MdataSelfToSelf =
{
	"MdataSelfToSelf",
	MdataSelfToSelfGetCount,
	MdataSelfToSelfGetValue,
	MdataSelfToSelfGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MdataSelfToSelfInit(void)
{

	g_global.g_mutatorModule[MdataSelfToSelf] = &s_MdataSelfToSelf;
}


#ifdef __cplusplus
}
#endif

