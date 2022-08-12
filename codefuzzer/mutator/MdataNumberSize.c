/*************************************************************************************************************
ʹ�ñ������滻
*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataNumberSize;

int MdataNumberSizeGetCount(SPara* para)
{
	return s_MdataNumberSize.weight;
}

char* MdataNumberSizeGetValue(SPara* para, int pos)
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
		s64 tempN = para->mutatorInitlen;
		in_ParaMutatorNumberReplace64(para->paraValue.value + tempPos, 8, tempN);
	}	

	//��λ
	else if(weight > 50)
	{
		if(para->mutatorInitlen < 2)
			return para->paraValue.value;
			
		//ѡ���滻��λ��
		int tempPos = in_getWeightRandom(para->mutatorInitlen - 2); 
		s16 tempN = para->mutatorInitlen;
		in_ParaMutatorNumberReplace16(para->paraValue.value + tempPos, 2, tempN);
	}

	//4λ
	else
	{
		if(para->mutatorInitlen < 4)
			return para->paraValue.value;
			
		//ѡ���滻��λ��
		int tempPos = in_getWeightRandom(para->mutatorInitlen - 4); 
		s32 tempN = para->mutatorInitlen;
		in_ParaMutatorNumberReplace32(para->paraValue.value + tempPos, 4, tempN);
	}
	
	return para->paraValue.value;
}

int MdataNumberSizeGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataNumberSize =
{
	"MdataNumberSize",
	MdataNumberSizeGetCount,
	MdataNumberSizeGetValue,
	MdataNumberSizeGetSupport,
	Return_Yes,
	Mutator_BaseWeight/4,
};

void MdataNumberSizeInit(void)
{
	g_global.g_mutatorModule[MdataNumberSize] = &s_MdataNumberSize;
}


#ifdef __cplusplus
}
#endif

