#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MNumberTable;

int MNumberTableGetCount(SPara* para)
{
	return s_MNumberTable.weight;
}

char* MNumberTableGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异位置
	int temp = PL_random()% para->count;

	PL_memcpy(para->paraValue.value ,(char*)&para->table[temp], 4);
	
	para->paraValue.len = 4;
	return para->paraValue.value;
}

int MNumberTableGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MNumberTable =
{
	"MNumberTable",
	MNumberTableGetCount,
	MNumberTableGetValue,
	MNumberTableGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MNumberTableInit(void)
{

	g_global.g_mutatorModule[MNumberTable] = &s_MNumberTable;
}


#ifdef __cplusplus
}
#endif

