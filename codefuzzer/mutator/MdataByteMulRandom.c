/*************************************************************************************************************

1.选取多个byte随机替换(最多6个),不连续

2选取连续多个byte随机替换(最多255)

3选取连续多个byte,用相同值替换

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MdataByteMulRandom;

int MdataByteMulRandomGetCount(SPara* para)
{
	return s_MdataByteMulRandom.weight;
}

char* MdataMulByteReplaceRandomGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	if (para->mutatorInitlen == 0)
		return para->paraValue.value;

	//获取变异个数
	int changnum = PL_random_range(2, 6);

	int i;
	for (i = 0; i < changnum; i++)
	{
		//选取变异位置
		int temp = in_getWeightRandom(para->mutatorInitlen - 1);
		para->paraValue.value[temp] = PL_random_byte();
	}

	return para->paraValue.value;
}


char* MdataMulByteReplaceContinueGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	if (para->mutatorInitlen == 0)
		return para->paraValue.value;

	//选取变异位置
	int temppos = in_getWeightRandom(para->mutatorInitlen - 1);

	//选取变异长度
	int changelen = in_getGuassRandom(255);

	if (temppos + changelen > g_global.setMaxMutatorLen)
	{
		return para->paraValue.value;
	}
		
	int i;
	for (i = 0; i < changelen; i++)
		para->paraValue.value[temppos + i] = PL_random_byte();

	return para->paraValue.value;
}

char* MdataMulByteReplaceContinueSameGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	if (para->mutatorInitlen == 0)
		return para->paraValue.value;

	//选取变异位置
	int temppos = in_getWeightRandom(para->mutatorInitlen - 1);

	//选取变异长度
	int changelen = in_getGuassRandom(255);

	if (temppos + changelen > g_global.setMaxMutatorLen)
	{
		return para->paraValue.value;
	}
		
	int i;
	char a = PL_random_byte();
	for (i = 0; i < changelen; i++)
		para->paraValue.value[temppos + i] = a;

	return para->paraValue.value;
}


char* MdataByteMulRandomGetValue(SPara* para, int pos)
{
	int weight = PL_random()% 100;

	if (weight > 70)
		return MdataMulByteReplaceRandomGetValue(para, pos);

	if (weight > 40)
		return MdataMulByteReplaceContinueGetValue(para, pos);
		
	return MdataMulByteReplaceContinueSameGetValue(para, pos);
}


int MdataByteMulRandomGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataByteMulRandom =
{
	"MdataByteMulRandom",
	MdataByteMulRandomGetCount,
	MdataByteMulRandomGetValue,
	MdataByteMulRandomGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MdataByteMulRandomInit(void)
{

	g_global.g_mutatorModule[MdataByteMulRandom] = &s_MdataByteMulRandom;
}


#ifdef __cplusplus
}
#endif

