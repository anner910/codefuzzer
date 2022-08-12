/*************************************************************************************************************
高斯分布变异

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MNumberGauss;

int MNumberGaussGetCount(SPara* para)
{
	return s_MNumberGauss.weight;
}

char* MNumberGaussGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	//高斯随机
	s64 temp = in_getGuassRandoms64(para->mutatorInitlen);

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

int MNumberGaussGetSupport(SPara* para)
{
	return Return_Yes;
}


SMutator s_MNumberGauss =
{
	"MNumberGauss",
	MNumberGaussGetCount,
	MNumberGaussGetValue,
	MNumberGaussGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MNumberGaussInit(void)
{

	g_global.g_mutatorModule[MNumberGauss] = &s_MNumberGauss;
}


#ifdef __cplusplus
}
#endif

