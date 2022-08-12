/*************************************************************************************************************
´¿Ëæ»ú

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MNumberRange;

int MNumberRangeGetCount(SPara* para)
{
	return s_MNumberRange.weight;
}

char* MNumberRangeGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	*(s32*)para->paraValue.value = PL_random_range(para->minValue,para->maxValue);

	return para->paraValue.value;
}

int MNumberRangeGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MNumberRange =
{
	"MNumberRange",
	MNumberRangeGetCount,
	MNumberRangeGetValue,
	MNumberRangeGetSupport,
	Return_Yes,
	(Mutator_BaseWeight*5),
};

void MNumberRangeInit(void)
{

	g_global.g_mutatorModule[MNumberRange] = &s_MNumberRange;
}


#ifdef __cplusplus
}
#endif

