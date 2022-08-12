/*************************************************************************************************************

随机连续位置字母大写

随机连续自己小写

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataStringCase;

int MdataStringCaseGetCount(SPara* para)
{
	return s_MdataStringCase.weight;
}

char* MdataStringCaseGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//开始位置
	int start = 0;
	//长度
	int len = 0;
	//大写还是小写
	int isbig = 0;

	start = in_getWeightRandom(para->mutatorInitlen - 1);
	len = in_getGuassRandom(para->mutatorInitlen - start);
	isbig = PL_random()%2;


	int i;
	for(i = 0; i < len; i++)
	{
		if(isbig)
		{
			//小写变大写
			if((97 <= para->paraValue.value[start + i]) 
				&&(para->paraValue.value[start + i] <= 122))
				para->paraValue.value[start + i] -= 32;
		}
		else
		{
			//大写变小写
			if((65 <= para->paraValue.value[start + i]) 
				&&(para->paraValue.value[start + i] <= 90))
				para->paraValue.value[start + i] += 32;

		}
	}

	return para->paraValue.value;
}

int MdataStringCaseGetSupport(SPara* para)
{
	//初始长度为0不支持
	if (para->mutatorInitlen == 0)
		return Return_No;
	
	//初始长度为0不支持
	return Return_Yes;
}


SMutator s_MdataStringCase =
{
	"MdataStringCase",
	MdataStringCaseGetCount,
	MdataStringCaseGetValue,
	MdataStringCaseGetSupport,
	Return_Yes,
	Mutator_BaseWeight/4,
};

void MdataStringCaseInit(void)
{

	g_global.g_mutatorModule[MdataStringCase] = &s_MdataStringCase;
}


#ifdef __cplusplus
}
#endif

