#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MStringHook;

int MStringHookGetCount(SPara* para)
{
	return s_MStringHook.weight;
}

char* MStringHookGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异位置
	int temp = PL_random()% para->count;
	int len = lib_strlen(para->table1[temp]) + 1;

	PL_memcpy(para->paraValue.value ,para->table1[temp], len);
	
	para->paraValue.len = len;
	return para->paraValue.value;
}

int MStringHookGetSupport(SPara* para)
{
	
	return Return_No;
}

SMutator s_MStringHook =
{
	"MStringHook",
	MStringHookGetCount,
	MStringHookGetValue,
	MStringHookGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MStringHookInit(void)
{

	g_global.g_mutatorModule[MStringHook] = &s_MStringHook;
}


#ifdef __cplusplus
}
#endif

