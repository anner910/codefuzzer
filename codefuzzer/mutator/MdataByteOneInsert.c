/*************************************************************************************************************

插入一个随机byte

*************************************************************************************************************/


#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataByteOneInsert;

int MdataByteOneInsertGetCount(SPara* para)
{
	return s_MdataByteOneInsert.weight;
}

char* MdataByteOneInsertGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	int len = para->mutatorInitlen + 1;

	if (len > g_global.setMaxMutatorLen)
	{
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
		para->paraValue.len = para->mutatorInitlen;
		return para->paraValue.value;
	}

	para->paraValue.len = len;

	//选取插入位置
	int temp = in_getWeightRandom(para->mutatorInitlen);

	PL_memcpy(para->paraValue.value, para->mutatorInitvalue, temp);
	para->paraValue.value[temp] = PL_random_byte();
	PL_memcpy(para->paraValue.value + temp + 1, para->mutatorInitvalue + temp, para->mutatorInitlen - temp);

	return para->paraValue.value;
}

int MdataByteOneInsertGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataByteOneInsert =
{
	"MdataByteOneInsert",
	MdataByteOneInsertGetCount,
	MdataByteOneInsertGetValue,
	MdataByteOneInsertGetSupport,
	Return_Yes,
	Mutator_BaseWeight/2,
};

void MdataByteOneInsertInit(void)
{

	g_global.g_mutatorModule[MdataByteOneInsert] = &s_MdataByteOneInsert;
}


#ifdef __cplusplus
}
#endif

