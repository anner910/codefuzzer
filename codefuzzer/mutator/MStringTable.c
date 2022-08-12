#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MStringTable;

int MStringTableGetCount(SPara* para)
{
	return s_MStringTable.weight;
}

char* MStringTableGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异位置
	int temp = PL_random()% para->count;
	int len = lib_strlen(para->table1[temp]) + 1;

	PL_memcpy(para->paraValue.value ,para->table1[temp], len);
	
	para->paraValue.len = len;
	return para->paraValue.value;
}

int MStringTableGetSupport(SPara* para)
{	
	return Return_Yes;
}

SMutator s_MStringTable =
{
	"MStringTable",
	MStringTableGetCount,
	MStringTableGetValue,
	MStringTableGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MStringTableInit(void)
{

	g_global.g_mutatorModule[MStringTable] = &s_MStringTable;
}


#ifdef __cplusplus
}
#endif

