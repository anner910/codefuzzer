/*************************************************************************************************************
使用魔法数字插入或者部分替换
*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataNumberHook;

int MdataNumberHookGetCount(SPara* para)
{
	return s_MdataNumberHook.weight;
}

char* MdataNumberHookReplaceGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	int weight = PL_random() % 100;
	s64 temp = do_GetHookNumber();

	//8位
	if(weight > 80)
	{
		if(para->mutatorInitlen < 8)
			return para->paraValue.value;
			
		//选择替换的位置
		int tempPos = in_getWeightRandom(para->mutatorInitlen - 8); 
		s64 tempN = temp;
		in_ParaMutatorNumberReplace64(para->paraValue.value + tempPos, 8, tempN);
	}	

	//两位
	else if(weight > 50)
	{
		if(para->mutatorInitlen < 2)
			return para->paraValue.value;
			
		//选择替换的位置
		int tempPos = in_getWeightRandom(para->mutatorInitlen - 2); 
		s16 tempN = temp;
		in_ParaMutatorNumberReplace16(para->paraValue.value + tempPos, 2, tempN);
	}

	//4位
	else
	{
		if(para->mutatorInitlen < 4)
			return para->paraValue.value;
			
		//选择替换的位置
		int tempPos = in_getWeightRandom(para->mutatorInitlen - 4); 
		s32 tempN = temp;
		in_ParaMutatorNumberReplace32(para->paraValue.value + tempPos, 4, tempN);

	}
	
	return para->paraValue.value;
}


char* MdataNumberHookInsertGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);
	u64 tempN = do_GetHookNumber();

	int weight = PL_random() % 100;

	//8位
	if(weight > 80)
	{
		if(para->mutatorInitlen + 8 > g_global.setMaxMutatorLen)
		{
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
			para->paraValue.len = para->mutatorInitlen;
			return para->paraValue.value;
		}
			
		//选择插入的位置
		int tempPos = in_getWeightRandom(para->mutatorInitlen);
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue,tempPos);
		
		PL_memset(para->paraValue.value + tempPos, 0, 8);
		in_ParaMutatorNumberReplace64(para->paraValue.value + tempPos, 8, tempN);
		
		PL_memcpy(para->paraValue.value + tempPos + 8, para->mutatorInitvalue + tempPos,para->mutatorInitlen - tempPos);

		para->paraValue.len = para->mutatorInitlen + 8;

	}

	//两位
	else if(weight > 50)
	{
		if(para->mutatorInitlen + 2 > g_global.setMaxMutatorLen)
		{
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
			para->paraValue.len = para->mutatorInitlen;
			return para->paraValue.value;
		}
			
		//选择替换的位置
		int tempPos = in_getWeightRandom(para->mutatorInitlen);

		PL_memcpy(para->paraValue.value, para->mutatorInitvalue,tempPos);

		PL_memset(para->paraValue.value + tempPos, 0, 2);
		in_ParaMutatorNumberReplace16(para->paraValue.value + tempPos, 2, tempN);
		
		PL_memcpy(para->paraValue.value + tempPos + 2, para->mutatorInitvalue + tempPos,para->mutatorInitlen - tempPos);

		para->paraValue.len = para->mutatorInitlen + 2;

	}

	//4位
	else
	{
		if(para->mutatorInitlen + 4 > g_global.setMaxMutatorLen)
		{
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
			para->paraValue.len = para->mutatorInitlen;
			return para->paraValue.value;
		}
			
		//选择替换的位置
		int tempPos = in_getWeightRandom(para->mutatorInitlen);

		PL_memcpy(para->paraValue.value, para->mutatorInitvalue,tempPos);

		PL_memset(para->paraValue.value + tempPos, 0, 4);
		in_ParaMutatorNumberReplace32(para->paraValue.value + tempPos, 4, tempN);
		
		PL_memcpy(para->paraValue.value + tempPos + 4, para->mutatorInitvalue + tempPos,para->mutatorInitlen - tempPos);

		para->paraValue.len = para->mutatorInitlen + 4;

	}
	
	return para->paraValue.value;
}


char* MdataNumberHookGetValue(SPara* para, int pos)
{
	int temp = PL_random() % 100;

	if(temp > 40)
		return MdataNumberHookReplaceGetValue(para, pos);
	else
		return MdataNumberHookInsertGetValue(para, pos);
}

int MdataNumberHookGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataNumberHook =
{
	"MdataNumberHook",
	MdataNumberHookGetCount,
	MdataNumberHookGetValue,
	MdataNumberHookGetSupport,
	Return_Yes,
	Mutator_BaseWeight*2,
};

void MdataNumberHookInit(void)
{
	g_global.g_mutatorModule[MdataNumberHook] = &s_MdataNumberHook;
}


#ifdef __cplusplus
}
#endif

