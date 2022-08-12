/*************************************************************************************************************
使用魔法内存插入或者替换一部分
*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataMemoryStaticString;

int MdataMemoryStaticStringGetCount(SPara* para)
{
	return s_MdataMemoryStaticString.weight;
}

char* MdataMemoryStaticStringGetValue(SPara* para, int pos)
{
	char* buf;
	int len;

	dict_GetStatic(&buf, &len);
	in_ParaMemoryMutator(para, pos, buf, len);

	return para->paraValue.value;
}

int MdataMemoryStaticStringGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataMemoryStaticString =
{
	"MdataMemoryStaticString",
	MdataMemoryStaticStringGetCount,
	MdataMemoryStaticStringGetValue,
	MdataMemoryStaticStringGetSupport,
	Return_Yes,
	Mutator_BaseWeight/2,
};

void MdataMemoryStaticStringInit(void)
{
	g_global.g_mutatorModule[MdataMemoryStaticString] = &s_MdataMemoryStaticString;
}


#ifdef __cplusplus
}
#endif

