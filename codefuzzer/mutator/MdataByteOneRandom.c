/*************************************************************************************************************
ѡȡһ��byte���

*************************************************************************************************************/


#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataByteOneRandom;

int MdataByteOneRandomGetCount(SPara* para)
{
	return s_MdataByteOneRandom.weight;
}

char* MdataByteOneRandomGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//ѡȡ����λ��
	int temp = in_getWeightRandom(para->mutatorInitlen - 1);
	para->paraValue.value[temp] = PL_random_byte();

	return para->paraValue.value;
}


int MdataByteOneRandomGetSupport(SPara* para)
{
	//��ʼ����Ϊ0��֧��
	if (para->mutatorInitlen == 0)
		return Return_No;
	
	return Return_Yes;
}

SMutator s_MdataByteOneRandom =
{
	"MdataByteOneRandom",
	MdataByteOneRandomGetCount,
	MdataByteOneRandomGetValue,
	MdataByteOneRandomGetSupport,
	Return_Yes,
	Mutator_BaseWeight*2,
};

void MdataByteOneRandomInit(void)
{

	g_global.g_mutatorModule[MdataByteOneRandom] = &s_MdataByteOneRandom;
}


#ifdef __cplusplus
}
#endif

