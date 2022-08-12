/*************************************************************************************************************
使用魔法数字替换
*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataNumberChange;

int MdataNumberChangeGetCount(SPara* para)
{
	return s_MdataNumberChange.weight;
}

char* MdataNumberChangeGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);
	u64 temp = in_getMagicNumber();

	int weight = PL_random() % 100;

	//8位
	if(weight > 80)
	{
		PL_memcpy(para->paraValue.value, (char*)&temp, 8);
		para->paraValue.len = 8;

	}

	//两位
	else if(weight > 50)
	{
		u16 temp1 = temp;
		PL_memcpy(para->paraValue.value, (char*)&temp1, 2);
		para->paraValue.len = 2;

	}

	//4位
	else
	{
		u32 temp1 = temp;
		PL_memcpy(para->paraValue.value , (char*)&temp1, 4);

		para->paraValue.len = 4;
	}
	
	return para->paraValue.value;
}

int MdataNumberChangeGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataNumberChange =
{
	"MdataNumberChange",
	MdataNumberChangeGetCount,
	MdataNumberChangeGetValue,
	MdataNumberChangeGetSupport,
	Return_Yes,
	Mutator_BaseWeight/4,
};

void MdataNumberChangeInit(void)
{
	g_global.g_mutatorModule[MdataNumberChange] = &s_MdataNumberChange;
}


#ifdef __cplusplus
}
#endif

