/*************************************************************************************************************
�Լ�ĳ�����ֵ�����������

ֻ�滻�����Ȳ���
*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataNumberSelf;

int MdataNumberSelfGetCount(SPara* para)
{
	return s_MdataNumberSelf.weight;
}

char* MdataNumberSelfGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	int weight = PL_random() % 100;

	//8λ
	if(weight > 80)
	{
		if(para->mutatorInitlen < 8)
			return para->paraValue.value;
			
		//ѡ���滻��λ��
		int tempPos = in_getWeightRandom(para->mutatorInitlen - 8); 
		s64 tempN = *(s64*)para->paraValue.value;
		in_ParaMutatorNumberReplace64(para->paraValue.value + tempPos, 8, tempN);
	}	

	//��λ
	else if(weight > 50)
	{
		if(para->mutatorInitlen < 2)
			return para->paraValue.value;
			
		//ѡ���滻��λ��
		int tempPos = in_getWeightRandom(para->mutatorInitlen - 2); 
		s16 tempN = *(s16*)para->paraValue.value;
		in_ParaMutatorNumberReplace16(para->paraValue.value + tempPos, 2, tempN);
	}

	//4λ
	else
	{
		if(para->mutatorInitlen < 4)
			return para->paraValue.value;
			
		//ѡ���滻��λ��
		int tempPos = in_getWeightRandom(para->mutatorInitlen - 4); 
		s32 tempN = *(s32*)para->paraValue.value;
		in_ParaMutatorNumberReplace32(para->paraValue.value + tempPos, 4, tempN);

	}
	
	return para->paraValue.value;
}

int MdataNumberSelfGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataNumberSelf =
{
	"MdataNumberSelf",
	MdataNumberSelfGetCount,
	MdataNumberSelfGetValue,
	MdataNumberSelfGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MdataNumberSelfInit(void)
{
	g_global.g_mutatorModule[MdataNumberSelf] = &s_MdataNumberSelf;
}


#ifdef __cplusplus
}
#endif

