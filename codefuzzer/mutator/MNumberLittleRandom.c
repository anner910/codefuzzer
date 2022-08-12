/*************************************************************************************************************
基于样本小范围变异

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MNumberLittleRandom;

int MNumberLittleRandomGetCount(SPara* para)
{
	return s_MNumberLittleRandom.weight;
}

char* MNumberLittleRandomGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	s64 temp = PL_random_range( -255, 255);

	if(para->paraValue.dataType == DataType_u8)
		*(u8*)para->paraValue.value += temp;

	if(para->paraValue.dataType == DataType_u16)
		*(u16*)para->paraValue.value += temp;

	if(para->paraValue.dataType == DataType_u32)
		*(u32*)para->paraValue.value += temp;

	if(para->paraValue.dataType == DataType_u64)
		*(u64*)para->paraValue.value += temp;

	if(para->paraValue.dataType == DataType_s8)
		*(s8*)para->paraValue.value += temp;

	if(para->paraValue.dataType == DataType_s16)
		*(s16*)para->paraValue.value += temp;

	if(para->paraValue.dataType == DataType_s32)
		*(s32*)para->paraValue.value += temp;

	if(para->paraValue.dataType == DataType_s64)
		*(s64*)para->paraValue.value += temp;

	if(para->paraValue.dataType == DataType_float)
		*(float*)para->paraValue.value += temp;

	if(para->paraValue.dataType == DataType_double)
		*(double*)para->paraValue.value += temp;

	if(para->paraValue.dataType == DataType_NumberOutOfTable)
		*(s32*)para->paraValue.value += temp;

	if(para->paraValue.dataType == DataType_NumberBasedOnTable)
		*(s32*)para->paraValue.value += temp;

	return para->paraValue.value;
}

int MNumberLittleRandomGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MNumberLittleRandom =
{
	"MNumberLittleRandom",
	MNumberLittleRandomGetCount,
	MNumberLittleRandomGetValue,
	MNumberLittleRandomGetSupport,
	Return_Yes,
	Mutator_BaseWeight/2,
};

void MNumberLittleRandomInit(void)
{

	g_global.g_mutatorModule[MNumberLittleRandom] = &s_MNumberLittleRandom;
}


#ifdef __cplusplus
}
#endif

