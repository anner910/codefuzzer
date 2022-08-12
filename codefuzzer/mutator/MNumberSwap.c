#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MNumberSwap;

int MNumberSwapGetCount(SPara* para)
{
	return s_MNumberSwap.weight;
}

char* MNumberSwapGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	if(para->paraValue.dataType == DataType_u8)
		*(u8*)para->paraValue.value = Bswap8(*(u8*)para->mutatorInitvalue);

	if(para->paraValue.dataType == DataType_u16)
		*(u16*)para->paraValue.value = Bswap16(*(u16*)para->mutatorInitvalue);

	if(para->paraValue.dataType == DataType_u32)
		*(u32*)para->paraValue.value = Bswap32(*(u32*)para->mutatorInitvalue);

	if(para->paraValue.dataType == DataType_u64)
		*(u64*)para->paraValue.value = Bswap64(*(u64*)para->mutatorInitvalue);

	if(para->paraValue.dataType == DataType_s8)
		*(s8*)para->paraValue.value = Bswap8(*(u8*)para->mutatorInitvalue);

	if(para->paraValue.dataType == DataType_s16)
		*(s16*)para->paraValue.value = Bswap16(*(u16*)para->mutatorInitvalue);

	if(para->paraValue.dataType == DataType_s32)
		*(s32*)para->paraValue.value = Bswap32(*(u32*)para->mutatorInitvalue);

	if(para->paraValue.dataType == DataType_s64)
		*(s64*)para->paraValue.value = Bswap64(*(u64*)para->mutatorInitvalue);

	if(para->paraValue.dataType == DataType_float)
		*(float*)para->paraValue.value = Bswap32(*(u32*)para->mutatorInitvalue);

	if(para->paraValue.dataType == DataType_double)
		*(double*)para->paraValue.value = Bswap64(*(u64*)para->mutatorInitvalue);

	if(para->paraValue.dataType == DataType_NumberOutOfTable)
		*(s32*)para->paraValue.value = Bswap32(*(u32*)para->mutatorInitvalue);

	if(para->paraValue.dataType == DataType_NumberBasedOnTable)
		*(s32*)para->paraValue.value = Bswap32(*(u32*)para->mutatorInitvalue);
		
	return para->paraValue.value;
}


int MNumberSwapGetSupport(SPara* para)
{
	return Return_Yes;
}


SMutator s_MNumberSwap =
{
	"MNumberSwap",
	MNumberSwapGetCount,
	MNumberSwapGetValue,
	MNumberSwapGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MNumberSwapInit(void)
{
	g_global.g_mutatorModule[MNumberSwap] = &s_MNumberSwap;
}


#ifdef __cplusplus
}
#endif

