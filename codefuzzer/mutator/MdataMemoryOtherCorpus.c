/*************************************************************************************************************
使用魔法内存插入或者替换一部分
*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataMemoryOtherCorpus;

int MdataMemoryOtherCorpusGetCount(SPara* para)
{
	return s_MdataMemoryOtherCorpus.weight;
}

char* MdataMemoryOtherCorpusGetValue(SPara* para, int pos)
{
	char* buf;
	int len;

	in_getCorpusBlob(&buf, &len);
	in_ParaMemoryMutator(para, pos, buf, len);

	return para->paraValue.value;
}

int MdataMemoryOtherCorpusGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataMemoryOtherCorpus =
{
	"MdataMemoryOtherCorpus",
	MdataMemoryOtherCorpusGetCount,
	MdataMemoryOtherCorpusGetValue,
	MdataMemoryOtherCorpusGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MdataMemoryOtherCorpusInit(void)
{
	g_global.g_mutatorModule[MdataMemoryOtherCorpus] = &s_MdataMemoryOtherCorpus;
}


#ifdef __cplusplus
}
#endif

