/*************************************************************************************************************

�Լ������Լ�

�ֶ�֮�佻�������ǣ�����

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataSelfToSelf;


int MdataSelfToSelfGetCount(SPara* para)
{
	return s_MdataSelfToSelf.weight;
}

char* MdataSelfToSelfGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//�ҵ�Ҫcopy������
	int firstPos = in_getWeightRandom(para->mutatorInitlen - 1);
	int firstLen = in_getGuassRandom(para->mutatorInitlen - firstPos);

	if (firstLen == 0)
		firstLen = 1;

	//�õ��ڶ���λ��
	int secondPos = in_getWeightRandom(para->mutatorInitlen - 1);
	int secondLen = in_getGuassRandom(para->mutatorInitlen - secondPos);


	int weight = PL_random() % 5;
	

	//��first�������ݲ��뵽second
	if (weight == 1)
	{
		if ((para->mutatorInitlen + firstLen) > g_global.setMaxMutatorLen)
		{
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
			para->paraValue.len = para->mutatorInitlen;
			return para->paraValue.value;

		}
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue, secondPos);
		PL_memcpy(para->paraValue.value + secondPos, para->mutatorInitvalue + firstPos, firstLen);
		PL_memcpy(para->paraValue.value + secondPos + firstLen, para->mutatorInitvalue + secondPos, para->mutatorInitlen - secondPos);

		para->paraValue.len = para->mutatorInitlen + firstLen;
	}
	//��second�������ݲ��뵽first,��ɾ��first
	else if (weight == 2)
	{
		if (secondPos > firstPos)
		{
		}
		else
		{
			int tempPos = firstPos;
			int tempLen = firstLen;
			
			firstPos = secondPos;
			firstLen = secondLen;

			secondPos = tempPos;
			secondLen = tempLen;
		}

		if ((para->mutatorInitlen + secondLen - firstLen) > g_global.setMaxMutatorLen)
		{
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
			para->paraValue.len = para->mutatorInitlen;
			return para->paraValue.value;

		}
		
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue, firstPos);
		PL_memcpy(para->paraValue.value + firstPos, para->mutatorInitvalue + secondPos, secondLen);
		PL_memcpy(para->paraValue.value + firstPos + secondLen, para->mutatorInitvalue + firstPos + firstLen, para->mutatorInitlen - firstPos - firstLen);

		para->paraValue.len = para->mutatorInitlen + secondLen - firstLen;
	}
	//��first�������ݸ��ǵ�secondλ��
	else if (weight == 1)
	{

		if ((para->mutatorInitlen + secondLen + firstLen) > g_global.setMaxMutatorLen)
		{
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
			para->paraValue.len = para->mutatorInitlen;
			return para->paraValue.value;

		}
		
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue, para->mutatorInitlen);
		PL_memcpy(para->paraValue.value + secondPos, para->mutatorInitvalue + firstPos, firstLen);

		para->paraValue.len = MAX(para->mutatorInitlen + secondLen + firstLen, para->mutatorInitlen);
	}
	//����
	else
	{
		if ((firstPos + firstLen) <= secondPos)
		{
			
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue, firstPos);
			//����second
			PL_memcpy(para->paraValue.value + firstPos, para->mutatorInitvalue + secondPos, secondLen);
			
			PL_memcpy(para->paraValue.value + firstPos + secondLen, para->mutatorInitvalue + firstPos + firstLen, 
				secondPos - firstPos - firstLen);
			//����first
			PL_memcpy(para->paraValue.value + secondLen + secondPos - firstLen, para->mutatorInitvalue + firstPos, 
				firstLen);

			PL_memcpy(para->paraValue.value + secondLen + secondPos, para->mutatorInitvalue + secondLen + secondPos, 
				para->mutatorInitlen - secondPos - secondLen);

		}
		else if ((secondPos + secondLen) <= firstPos)
		{

			int tempPos = firstPos;
			int tempLen = firstLen;
			
			firstPos = secondPos;
			firstLen = secondLen;

			secondPos = tempPos;
			secondLen = tempLen;
			
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue, firstPos);
			//����second
			PL_memcpy(para->paraValue.value + firstPos, para->mutatorInitvalue + secondPos, secondLen);
			
			PL_memcpy(para->paraValue.value + firstPos + secondLen, para->mutatorInitvalue + firstPos + firstLen, 
				secondPos - firstPos - firstLen);
			//����first
			PL_memcpy(para->paraValue.value + secondLen + secondPos - firstLen, para->mutatorInitvalue + firstPos, 
				firstLen);

			PL_memcpy(para->paraValue.value + secondLen + secondPos, para->mutatorInitvalue + secondLen + secondPos, 
				para->mutatorInitlen - secondPos - secondLen);

		}
		else
		{
			PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
			para->paraValue.len = para->mutatorInitlen;
			return para->paraValue.value;
		}

	}
	

	return para->paraValue.value;
}

int MdataSelfToSelfGetSupport(SPara* para)
{
	//��ʼ����Ϊ0��֧��
	if (para->mutatorInitlen == 0)
		return Return_No;
	
	//��ʼ����Ϊ0��֧��
	return Return_Yes;
}

SMutator s_MdataSelfToSelf =
{
	"MdataSelfToSelf",
	MdataSelfToSelfGetCount,
	MdataSelfToSelfGetValue,
	MdataSelfToSelfGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MdataSelfToSelfInit(void)
{

	g_global.g_mutatorModule[MdataSelfToSelf] = &s_MdataSelfToSelf;
}


#ifdef __cplusplus
}
#endif

