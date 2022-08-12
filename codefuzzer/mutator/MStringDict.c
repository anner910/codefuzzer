#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MStringDict;

int MStringDictGetCount(SPara* para)
{
	return s_MStringDict.weight;
}

char* MStringDictGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异位置
	int temp = PL_random()% para->count;
	int len = lib_strlen(para->table1[temp]) + 1;

	PL_memcpy(para->paraValue.value ,para->table1[temp], len);
	
	para->paraValue.len = len;
	return para->paraValue.value;
}

int MStringDictGetSupport(SPara* para)
{	
	return Return_No;
}

SMutator s_MStringDict =
{
	"MStringDict",
	MStringDictGetCount,
	MStringDictGetValue,
	MStringDictGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MStringDictInit(void)
{
	g_global.g_mutatorModule[MStringDict] = &s_MStringDict;
}


#ifdef __cplusplus
}
#endif

