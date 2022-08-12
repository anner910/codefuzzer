/*************************************************************************************************************
´¿Ëæ»ú

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MNumberRandom;

int MNumberRandomGetCount(SPara* para)
{
	return s_MNumberRandom.weight;
}

char* MNumberRandomGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	u64 temp = PL_random_64();

	PL_memcpy(para->paraValue.value ,(char*)&temp, para->mutatorInitlen);
	
	return para->paraValue.value;
}

int MNumberRandomGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MNumberRandom =
{
	"MNumberRandom",
	MNumberRandomGetCount,
	MNumberRandomGetValue,
	MNumberRandomGetSupport,
	Return_Yes,
	Mutator_BaseWeight/2,
};

void MNumberRandomInit(void)
{

	g_global.g_mutatorModule[MNumberRandom] = &s_MNumberRandom;
}


#ifdef __cplusplus
}
#endif

