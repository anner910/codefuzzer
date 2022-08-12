/*************************************************************************************************************
使用魔法内存插入或者替换一部分
*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataMemoryDictString;

int MdataMemoryDictStringGetCount(SPara* para)
{
	return s_MdataMemoryDictString.weight;
}

char* MdataMemoryDictStringGetValue(SPara* para, int pos)
{
	char* buf;
	int len;

	dict_GetString(&buf, &len);
	in_ParaMemoryMutator(para, pos, buf, len);

	return para->paraValue.value;
}

int MdataMemoryDictStringGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataMemoryDictString =
{
	"MdataMemoryDictString",
	MdataMemoryDictStringGetCount,
	MdataMemoryDictStringGetValue,
	MdataMemoryDictStringGetSupport,
	Return_Yes,
	Mutator_BaseWeight/2,
};

void MdataMemoryDictStringInit(void)
{
	g_global.g_mutatorModule[MdataMemoryDictString] = &s_MdataMemoryDictString;
}


#ifdef __cplusplus
}
#endif

