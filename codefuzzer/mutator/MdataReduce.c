/*************************************************************************************************************
随机删除某些字段

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MdataReduce;

int MdataReduceGetCount(SPara* para)
{
	return s_MdataReduce.weight;
}

char* MdataReduceGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	//选取删除的位置
	int temppos = in_getWeightRandom(para->mutatorInitlen - 1);

	//选取删除的长度
	int templen = in_getGuassRandom(para->mutatorInitlen - temppos);

	if (templen == 0)
		templen = 1;

	PL_memcpy(para->paraValue.value, para->mutatorInitvalue, temppos);
	PL_memcpy(para->paraValue.value + temppos, para->mutatorInitvalue + temppos + templen, para->mutatorInitlen - temppos - templen);

	para->paraValue.len = para->mutatorInitlen - templen;
	return para->paraValue.value;
}

int MdataReduceGetSupport(SPara* para)
{
	//初始长度为0不支持
	if (para->mutatorInitlen == 0)
		return Return_No;
	
	return Return_Yes;
}

SMutator s_MdataReduce =
{
	"MdataReduce",
	MdataReduceGetCount,
	MdataReduceGetValue,
	MdataReduceGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MdataReduceInit(void)
{

	g_global.g_mutatorModule[MdataReduce] = &s_MdataReduce;
}


#ifdef __cplusplus
}
#endif

