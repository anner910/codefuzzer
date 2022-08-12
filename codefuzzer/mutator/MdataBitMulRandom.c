/*************************************************************************************************************

随机多bit反转


*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataBitMulRandom;

int MdataBitMulRandomGetCount(SPara* para)
{
	return s_MdataBitMulRandom.weight;
}

char* MdataBitMulRandomGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//获取变异个数
	int changnum = PL_random_range(1, 6);

	int i;
	for (i = 0; i < changnum; i++)
	{
		int temp_pos = in_getWeightRandom(para->mutatorInitlen * 8 - 1);
		BitFlip(para->paraValue.value, temp_pos);
	}

	
	return para->paraValue.value;
}


int MdataBitMulRandomGetSupport(SPara* para)
{

	//初始长度为0不支持
	if (para->mutatorInitlen == 0)
		return Return_No;
	
	//初始长度为0不支持
	return Return_Yes;
}

SMutator s_MdataBitMulRandom =
{
	"MdataBitMulRandom",
	MdataBitMulRandomGetCount,
	MdataBitMulRandomGetValue,
	MdataBitMulRandomGetSupport,
	Return_Yes,
	Mutator_BaseWeight/2,
};

void MdataBitMulRandomInit(void)
{

	g_global.g_mutatorModule[MdataBitMulRandom] = &s_MdataBitMulRandom;
}


#ifdef __cplusplus
}
#endif

