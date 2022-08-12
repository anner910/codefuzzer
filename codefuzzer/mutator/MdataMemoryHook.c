/*************************************************************************************************************
使用魔法内存插入或者替换一部分
*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataMemoryHook;

int MdataMemoryHookGetCount(SPara* para)
{
	return s_MdataMemoryHook.weight;
}

char* MdataMemoryHookGetValue(SPara* para, int pos)
{
	char* buf;
	int len;

	do_GetHookBlob(&buf, &len);
	in_ParaMemoryMutator(para, pos, buf, len);

	return para->paraValue.value;
}

int MdataMemoryHookGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataMemoryHook =
{
	"MdataMemoryHook",
	MdataMemoryHookGetCount,
	MdataMemoryHookGetValue,
	MdataMemoryHookGetSupport,
	Return_Yes,
	Mutator_BaseWeight*2,
};

void MdataMemoryHookInit(void)
{
	g_global.g_mutatorModule[MdataMemoryHook] = &s_MdataMemoryHook;
}


#ifdef __cplusplus
}
#endif


