/*************************************************************************************************************

使用其他样本数据直接交换

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataCorpusSwap;

int MdataCorpusSwapGetCount(SPara* para)
{
	return s_MdataCorpusSwap.weight;
}

char* MdataCorpusSwapGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	char* blob;
	int len;

	in_getCorpusBlob(&blob, &len);


	PL_memcpy(para->paraValue.value, blob, len);

	para->paraValue.len = len;
	return para->paraValue.value;
}

int MdataCorpusSwapGetSupport(SPara* para)
{

	return Return_Yes;
}

SMutator s_MdataCorpusSwap =
{
	"MdataCorpusSwap",
	MdataCorpusSwapGetCount,
	MdataCorpusSwapGetValue,
	MdataCorpusSwapGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MdataCorpusSwapInit(void)
{

	g_global.g_mutatorModule[MdataCorpusSwap] = &s_MdataCorpusSwap;
}


#ifdef __cplusplus
}
#endif

