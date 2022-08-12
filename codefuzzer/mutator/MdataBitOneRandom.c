/*************************************************************************************************************

单bit反转


*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataBitOneRandom;

int MdataBitOneRandomGetCount(SPara* para)
{
	return s_MdataBitOneRandom.weight;
}

char* MdataBitOneRandomGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	int temp_pos = in_getWeightRandom(para->mutatorInitlen * 8 - 1);
	BitFlip(para->paraValue.value, temp_pos);

	return para->paraValue.value;
}


int MdataBitOneRandomGetSupport(SPara* para)
{
	//初始长度为0不支持
	if (para->mutatorInitlen == 0)
		return Return_No;
	
	return Return_Yes;
}

SMutator s_MdataBitOneRandom =
{
	"MdataBitOneRandom",
	MdataBitOneRandomGetCount,
	MdataBitOneRandomGetValue,
	MdataBitOneRandomGetSupport,
	Return_Yes,
	Mutator_BaseWeight/2,
};

void MdataBitOneRandomInit(void)
{

	g_global.g_mutatorModule[MdataBitOneRandom] = &s_MdataBitOneRandom;
}


#ifdef __cplusplus
}
#endif

