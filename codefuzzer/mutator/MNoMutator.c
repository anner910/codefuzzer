/*************************************************************************************************************

µ¥bit·´×ª


*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MNoMutator;

int MNoMutatorGetCount(SPara* para)
{
	return s_MNoMutator.weight;
}

char* MNoMutatorGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	return para->paraValue.value;
}

int MNoMutatorGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MNoMutator =
{
	"MNoMutator",
	MNoMutatorGetCount,
	MNoMutatorGetValue,
	MNoMutatorGetSupport,
	Return_Yes,
	1,
};

void MNoMutatorInit(void)
{

	g_global.g_mutatorModule[MNoMutator] = &s_MNoMutator;
}


#ifdef __cplusplus
}
#endif

