/*************************************************************************************************************
����ĳЩ�ֶΣ�����Ϊsize�߽�

����ĳЩ�ֶΣ�����Ϊhook����

����ĳЩ�ֶΣ�����Ϊ��˹���

���������Լ�

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataLengthRepeatSelfTail;


int MdataLengthRepeatSelfTailGetCount(SPara* para)
{
	return in_scheduleMutatorWeight(s_MdataLengthRepeatSelfTail.weight);
}

char* MdataLengthRepeatSelfTailGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	int len = in_getLen(para, pos);

	if(len <= para->mutatorInitlen)
	{
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
		para->paraValue.len = para->mutatorInitlen;
		return para->paraValue.value;
	}

	//��չλ��
	int changepos = in_getWeightRandom(para->mutatorInitlen);

	if (changepos == 0)
		changepos = 1;

	//��Ԫ����
	int unitlen = in_getGuassRandom(changepos);

	if (unitlen == 0)
		unitlen = 1;


	PL_memcpy(para->paraValue.value, para->mutatorInitvalue, changepos);

	int i;
	int j;
	int kkk = changepos;
	int over = 0;

	char* repeat = para->paraValue.value + changepos - unitlen;
	for(i = 0;; i++)
	{
		for(j = 0; j < unitlen; j++)
		{
			para->paraValue.value[changepos + j + i*unitlen] = repeat[j];
			kkk++;
			if (kkk == len)
			{
				over = 1;
				break;
			}
		}
		if(over)
			break;
	}

	para->paraValue.len = len;

	return para->paraValue.value;
}


int MdataLengthRepeatSelfTailGetSupport(SPara* para)
{
	//��ʼ����Ϊ0��֧��
	if (para->mutatorInitlen == 0)
		return Return_No;
	
	//��ʼ����Ϊ0��֧��
	return Return_Yes;
}

SMutator s_MdataLengthRepeatSelfTail =
{
	"MdataLengthRepeatSelfTail",
	MdataLengthRepeatSelfTailGetCount,
	MdataLengthRepeatSelfTailGetValue,
	MdataLengthRepeatSelfTailGetSupport,
	Return_Yes,
	Mutator_BaseWeight/10,
};

void MdataLengthRepeatSelfTailInit(void)
{

	g_global.g_mutatorModule[MdataLengthRepeatSelfTail] = &s_MdataLengthRepeatSelfTail;
}


#ifdef __cplusplus
}
#endif

