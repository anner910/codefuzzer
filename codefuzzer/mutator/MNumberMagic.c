#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MNumberMagic;

int MNumberMagicGetCount(SPara* para)
{
	return s_MNumberMagic.weight;
}

char* MNumberMagicGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	//
	u64 temp = in_getMagicNumber();

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


int MNumberMagicGetSupport(SPara* para)
{
	return Return_Yes;
}


SMutator s_MNumberMagic =
{
	"MNumberMagic",
	MNumberMagicGetCount,
	MNumberMagicGetValue,
	MNumberMagicGetSupport,
	Return_Yes,
	Mutator_BaseWeight*2,
};

void MNumberMagicInit(void)
{

	g_global.g_mutatorModule[MNumberMagic] = &s_MNumberMagic;
}


#ifdef __cplusplus
}
#endif

