#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MBlobTable;

int MBlobTableGetCount(SPara* para)
{
	return s_MBlobTable.weight;
}

char* MBlobTableGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异位置
	int temp = PL_random()% para->count;

	PL_memcpy(para->paraValue.value ,para->table1[temp],para->tablelen[temp]);
	
	para->paraValue.len = para->tablelen[temp];
	return para->paraValue.value;
}

int MBlobTableGetSupport(SPara* para)
{	
	return Return_Yes;
}

SMutator s_MBlobTable =
{
	"MBlobTable",
	MBlobTableGetCount,
	MBlobTableGetValue,
	MBlobTableGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MBlobTableInit(void)
{

	g_global.g_mutatorModule[MBlobTable] = &s_MBlobTable;
}


#ifdef __cplusplus
}
#endif

