/*************************************************************************************************************

���������м�ֵ0

���ѡ�񳤶�ֵ0



*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataBitZero;

int MdataBitZeroGetCount(SPara* para)
{
	return s_MdataBitZero.weight;
}

char* MdataBitZeroEdgeGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);


	int len = PL_random_range(0, para->mutatorInitlen * 8 - 1);
	int weight = PL_random()%2;
	int i;

	if (weight == 1)
	{
		for(i = 0; i< len; i++)
		{
			BitZero(para->paraValue.value, i);
		}
	}
	else
	{
		for(i = 0; i< len; i++)
		{
			BitZero(para->paraValue.value, para->mutatorInitlen * 8 - 1 - i);
		}

	}
	
	return para->paraValue.value;
}

char* MdataBitZeroRandomGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);


	//��ʼλ��
	int start_pos = in_getWeightRandom(para->mutatorInitlen * 8 - 1);

	//���쳤��
	int len = in_getWeightRandom(para->mutatorInitlen * 8 - start_pos);

	if (len == 0)
		len = 1;
	

	int i;

	for(i = 0; i < len; i++)
	{
		BitZero(para->paraValue.value, start_pos + i);
	}

	
	return para->paraValue.value;
}



char* MdataBitZeroGetValue(SPara* para, int pos)
{
	int temp = PL_random() % 100;

	if(temp > 60)
		return MdataBitZeroEdgeGetValue(para, pos);
	else
		return MdataBitZeroRandomGetValue(para, pos);
}

int MdataBitZeroGetSupport(SPara* para)
{
	//��ʼ����Ϊ0��֧��
	if (para->mutatorInitlen == 0)
		return Return_No;
	
	return Return_Yes;
}

SMutator s_MdataBitZero =
{
	"MdataBitZero",
	MdataBitZeroGetCount,
	MdataBitZeroGetValue,
	MdataBitZeroGetSupport,
	Return_Yes,
	Mutator_BaseWeight/4,
};

void MdataBitZeroInit(void)
{

	g_global.g_mutatorModule[MdataBitZero] = &s_MdataBitZero;
}


#ifdef __cplusplus
}
#endif

