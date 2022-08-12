#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MBlobDict;

int MBlobDictGetCount(SPara* para)
{
	return s_MBlobDict.weight;
}

char* MBlobDictGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异位置
	int temp = PL_random()% para->count;

	PL_memcpy(para->paraValue.value ,para->table1[temp],para->tablelen[temp]);
	
	para->paraValue.len = para->tablelen[temp];
	return para->paraValue.value;
}

int MBlobDictGetSupport(SPara* para)
{	
	return Return_No;
}

SMutator s_MBlobDict =
{
	"MBlobDict",
	MBlobDictGetCount,
	MBlobDictGetValue,
	MBlobDictGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MBlobDictInit(void)
{

	g_global.g_mutatorModule[MBlobDict] = &s_MBlobDict;
}


#ifdef __cplusplus
}
#endif

