/*************************************************************************************************************
edge变异

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MNumberEdge;

int MNumberEdgeGetCount(SPara* para)
{
	return s_MNumberEdge.weight;
}

char* MNumberEdgeGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	int bitTotal = para->mutatorInitlen * 8;

	int bit = PL_random_range(1, bitTotal);

	int a = PL_random()%2;

	s64 temp = 0;
		
	if(a) 
		temp = 1 << bit;
	else
		temp = 1 - (1 << bit);

	//再小范围随机一下
	temp = temp + PL_random_range( -255, 255);

	if(para->paraValue.dataType == DataType_u8)
		*(u8*)para->paraValue.value = temp;

	if(para->paraValue.dataType == DataType_u16)
		*(u16*)para->paraValue.value = temp;

	if(para->paraValue.dataType == DataType_u32)
		*(u32*)para->paraValue.value = temp;

	if(para->paraValue.dataType == DataType_u64)
		*(u64*)para->paraValue.value = temp;

	if(para->paraValue.dataType == DataType_s8)
		*(s8*)para->paraValue.value = temp;

	if(para->paraValue.dataType == DataType_s16)
		*(s16*)para->paraValue.value = temp;

	if(para->paraValue.dataType == DataType_s32)
		*(s32*)para->paraValue.value = temp;

	if(para->paraValue.dataType == DataType_s64)
		*(s64*)para->paraValue.value = temp;

	if(para->paraValue.dataType == DataType_float)
		*(float*)para->paraValue.value = temp;

	if(para->paraValue.dataType == DataType_double)
		*(double*)para->paraValue.value = temp;

	if(para->paraValue.dataType == DataType_NumberOutOfTable)
		*(s32*)para->paraValue.value = temp;

	if(para->paraValue.dataType == DataType_NumberBasedOnTable)
		*(s32*)para->paraValue.value = temp;
	
	return para->paraValue.value;
}

int MNumberEdgeGetSupport(SPara* para)
{
	return Return_Yes;
}


SMutator s_MNumberEdge =
{
	"MNumberEdge",
	MNumberEdgeGetCount,
	MNumberEdgeGetValue,
	MNumberEdgeGetSupport,
	Return_Yes,
	Mutator_BaseWeight/4,
};

void MNumberEdgeInit(void)
{

	g_global.g_mutatorModule[MNumberEdge] = &s_MNumberEdge;
}


#ifdef __cplusplus
}
#endif

