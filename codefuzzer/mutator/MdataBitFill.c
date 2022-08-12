/*************************************************************************************************************

从两边向中间值1

随机选择长度值1
*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataBitFill;

int MdataBitFillGetCount(SPara* para)
{
	return s_MdataBitFill.weight;
}

char* MdataBitFillEdgeGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	int len = PL_random_range(0, para->mutatorInitlen * 8 - 1);
	int weight = PL_random()%2;
	int i;

	if (weight == 1)
	{
		for(i = 0; i< len; i++)
		{
			BitFill(para->paraValue.value, i);
		}
	}
	else
	{
		for(i = 0; i< len; i++)
		{
			BitFill(para->paraValue.value, para->mutatorInitlen * 8 - 1 - i);
		}

	}
	
	return para->paraValue.value;
}

char* MdataBitFillRandomGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);


	//开始位置
	int start_pos = in_getWeightRandom(para->mutatorInitlen * 8 - 1);

	//变异长度
	int len = in_getWeightRandom(para->mutatorInitlen * 8 - start_pos);

	if (len == 0)
		len = 1;
	

	int i;

	for(i = 0; i < len; i++)
	{
		BitFill(para->paraValue.value, start_pos + i);
	}

	
	return para->paraValue.value;
}



char* MdataBitFillGetValue(SPara* para, int pos)
{
	int temp = PL_random() % 100;

	if(temp > 60)
		return MdataBitFillEdgeGetValue(para, pos);
	else
		return MdataBitFillRandomGetValue(para, pos);
}


int MdataBitFillGetSupport(SPara* para)
{
	//初始长度为0不支持
	if (para->mutatorInitlen == 0)
		return Return_No;

	return Return_Yes;
}

SMutator s_MdataBitFill =
{
	"MdataBitFill",
	MdataBitFillGetCount,
	MdataBitFillGetValue,
	MdataBitFillGetSupport,
	Return_Yes,
	Mutator_BaseWeight/4,
};

void MdataBitFillInit(void)
{

	g_global.g_mutatorModule[MdataBitFill] = &s_MdataBitFill;
}


#ifdef __cplusplus
}
#endif

