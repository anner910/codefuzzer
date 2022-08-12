/*************************************************************************************************************
使用魔法内存插入或者替换一部分
*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataMemoryNumberString;

int MdataMemoryNumberStringGetCount(SPara* para)
{
	return s_MdataMemoryNumberString.weight;
}

char* MdataMemoryNumberStringGetValue(SPara* para, int pos)
{
	char buf[32] = {0};
	
	s32 temp = in_getMagicNumber();

	lib_itoa(temp, buf,10);

	int len = strlen(buf);

	int weight = PL_random()% 100;
	if (weight > 80)
		len = len + 1;
	
	in_ParaMemoryMutator(para, pos, buf, len);

	return para->paraValue.value;
}

int MdataMemoryNumberStringGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataMemoryNumberString =
{
	"MdataMemoryNumberString",
	MdataMemoryNumberStringGetCount,
	MdataMemoryNumberStringGetValue,
	MdataMemoryNumberStringGetSupport,
	Return_Yes,
	Mutator_BaseWeight/2,
};

void MdataMemoryNumberStringInit(void)
{
	g_global.g_mutatorModule[MdataMemoryNumberString] = &s_MdataMemoryNumberString;
}


#ifdef __cplusplus
}
#endif


