/*************************************************************************************************************
使用魔法内存插入或者替换一部分
*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataMemoryDictBlob;

int MdataMemoryDictBlobGetCount(SPara* para)
{
	return s_MdataMemoryDictBlob.weight;
}

char* MdataMemoryDictBlobGetValue(SPara* para, int pos)
{
	char* buf;
	int len;

	dict_GetBlob(&buf, &len);
	in_ParaMemoryMutator(para, pos, buf, len);

	return para->paraValue.value;
}

int MdataMemoryDictBlobGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataMemoryDictBlob =
{
	"MdataMemoryDictBlob",
	MdataMemoryDictBlobGetCount,
	MdataMemoryDictBlobGetValue,
	MdataMemoryDictBlobGetSupport,
	Return_Yes,
	Mutator_BaseWeight/2,
};

void MdataMemoryDictBlobInit(void)
{
	g_global.g_mutatorModule[MdataMemoryDictBlob] = &s_MdataMemoryDictBlob;
}


#ifdef __cplusplus
}
#endif

