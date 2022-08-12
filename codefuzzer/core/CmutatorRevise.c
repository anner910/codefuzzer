

#include "Core.h"

#ifdef __cplusplus
extern "C"{
#endif


void in_mutatorParaInit(SPara* para)
{
	int i;
	int  allCount = 0;
	
	for(i = 0; i < MMax; i++)
	{
		para->isMSupport[i] = Return_No;
		
		//�����㷨��û�и�ֵ
		if(g_global.g_mutatorModule[i] == NULL)
			continue;
		
		//�����㷨ȫ�ֹر�
		if(g_global.g_mutatorModule[i]->isOpen == Return_No)
			continue;

		//�����㷨��Ա������ر�
		if(para->isMClose[i] == Return_Yes)
			continue;

		//�����㷨��֧�ֱ�����
		if(g_global.g_mutatorModule[i]->getSupport(para) == Return_No)
			continue;

		if (support(para->paraValue.dataType, i) == Return_No)
			continue;

		//�϶�֧����
		para->isMSupport[i] = Return_Yes;

		//�����������
		para->MStartPos[i] = allCount;
		para->MEndPos[i] = para->MStartPos[i] + g_global.g_mutatorModule[i]->getCount(para);
		allCount = para->MEndPos[i];
	}

	para->MAllCount = allCount;
}

void in_mutatorParaRevise(SPara* para)
{
	int i = 0;
	if(para->paraValue.dataType == DataType_NumberOutOfTable)
	{	
		
		for(i = 0; i< para->count; i++)
		{
			if(lib_memcmp(para->paraValue.value, (char*)&para->table[i],4) == 0)
			{
				if(para->idNeedFree == Return_Yes)
				{
					para->idNeedFree = Return_No;
					PL_free(para->paraValue.value);
					para->paraValue.value = NULL;
					para->paraValue.len = 0;
				}
				
				para->paraValue.value = para->mutatorInitvalue;
				para->paraValue.len = para->mutatorInitlen;
			}
		}
	}

	if(para->paraValue.dataType == DataType_stringOutOfTable)
	{	
		for(i = 0; i < para->count; i++)
		{
			para->paraValue.value[para->paraValue.len -1] = 0;
			if((para->paraValue.len == lib_strlen(para->table1[i]) + 1)
				&&(lib_memcmp(para->paraValue.value, para->table1[i],para->paraValue.len) == 0))
			{
				if(para->idNeedFree == Return_Yes)
				{
					para->idNeedFree = Return_No;
					PL_free(para->paraValue.value);
					para->paraValue.value = NULL;
					para->paraValue.len = 0;
				}
				
				para->paraValue.value = para->mutatorInitvalue;
				para->paraValue.len = para->mutatorInitlen;
			}
		}

	}

	if(para->paraValue.dataType == DataType_blobOutOfTable)
	{	
		for(i = 0; i < para->count; i++)
		{
			if((para->paraValue.len == para->tablelen[i])
				&&(lib_memcmp(para->paraValue.value, para->table1[i],para->paraValue.len) == 0))
			{
				if(para->idNeedFree == Return_Yes)
				{
					para->idNeedFree = Return_No;
					PL_free(para->paraValue.value);
					para->paraValue.value = NULL;
					para->paraValue.len = 0;
				}
				
				para->paraValue.value = para->mutatorInitvalue;
				para->paraValue.len = para->mutatorInitlen;
			}
		}

	}

	if(para->paraValue.dataType == DataType_NumberRange)
	{	

		if(!((para->minValue == 0) &&(para->maxValue == 0)))
		{
			s32 aaa = *(s32*)para->paraValue.value;

			if (aaa < para->minValue)
				aaa = PL_random_range(para->minValue,para->maxValue);

			if (aaa > para->maxValue)
				aaa = PL_random_range(para->minValue,para->maxValue);

			*(s32*)para->paraValue.value = aaa;
		}
	}

	//�������·����ڴ棬�����

	//����ĳ������½���
	if((para->paraValue.dataType != DataType_stringOnlyTable) 
		&&(para->paraValue.dataType != DataType_blobOnlyTable))
	{
		if(para->paraValue.len < para->mutatorminlen)
			para->paraValue.len = para->mutatorminlen;

		if(para->paraValue.len > para->mutatormaxlen)
			para->paraValue.len = para->mutatormaxlen;
	}
	
	int len = para->paraValue.len + para->Initlen - para->mutatorInitlen;

	//���ĳ������½���
	if((para->paraValue.dataType != DataType_stringOnlyTable) 
		&&(para->paraValue.dataType != DataType_blobOnlyTable)
		&&(para->maxlen != 0))
	{
		if(len < para->minlen)
			len = para->minlen;

		if(len > para->maxlen)
			len = para->maxlen;
	}

	if(((para->paraValue.dataType == DataType_string) 
		||(para->paraValue.dataType == DataType_stringOutOfTable) 
		||(para->paraValue.dataType == DataType_stringBasedOnTable)) 
		&& (len == 0))
		len = len + 1;
	
	//���·����ڴ�
	char* temp = PL_malloc(len);

	//����ǰ���
	PL_memcpy(temp, para->Initvalue, para->mutatorPos);

	//��������ֵ
	if (len > para->mutatorPos)
	PL_memcpy(temp + para->mutatorPos, para->paraValue.value, MIN(para->paraValue.len, len - para->mutatorPos));


	//��������
	if (len > para->mutatorPos + para->paraValue.len)
	PL_memcpy(temp + para->mutatorPos + para->paraValue.len, para->Initvalue + para->mutatorPos, 
			MIN(para->Initlen - para->mutatorPos - para->mutatorInitlen, len - para->mutatorPos - para->paraValue.len));

	//�������ˣ������ͷ���
	if(para->idNeedFree == Return_Yes)
	{
		para->idNeedFree = Return_No;
		PL_free(para->paraValue.value);
		para->paraValue.value = NULL;
		para->paraValue.len = 0;
	}

	//Ŀǰ�ַ�������\0��β
	if((para->paraValue.dataType == DataType_string) 
		||(para->paraValue.dataType == DataType_stringOutOfTable) 
		||(para->paraValue.dataType == DataType_stringBasedOnTable))
		temp[len - 1] = 0;

	para->paraValue.len = len;
	para->paraValue.value = temp;
	para->idNeedFree = Return_Yes;

}


char* in_mutatorParaGetValue(SPara* para)
{
	if (para->mutatorPosEnalbe)
	{
		para->mutatorminlen = para->setmutatorminlen;
		para->mutatormaxlen = para->setmutatormaxlen;
		para->mutatorLen = para->setmutatorLen;
		para->mutatorPos = para->setmutatorPos;
	}
	else
	{
		para->mutatorminlen = para->minlen;
		para->mutatormaxlen = para->maxlen;
		para->mutatorLen = para->Initlen;
		para->mutatorPos = 0;
	}
	
	//��������������Ӽ�
	if(para->isInit == 0)
	{
		g_thread.paraNumber++;
		in_mutatorParaInit(para);
	}

	//���ݵ��ȣ��������Ƿ���Ҫ����
	int isNoNeedMutator = schedule_paraIsNeedMutator(para);
	
	
	if((para->isInit == 0) 
		|| (g_thread.isNoNeedMutator == 1) 
		|| (isNoNeedMutator == 0)
		|| (para->MAllCount == 0))
	{
		para->isInit = 1;
		//�ó�ʼֵ
		para->paraValue.value = para->mutatorInitvalue;
		para->paraValue.len = para->mutatorInitlen;
		para->mutator = MNoMutator;
	}
	else
	{
		int pos = PL_random() % para->MAllCount;
		int i;

		for(i = 0; i < MMax; i++)
		{
			if(para->isMSupport[i] == Return_No)
				continue;

			if(pos >= para->MEndPos[i])
				continue;

			g_global.g_mutatorModule[i]->getValue(para, pos - para->MStartPos[i]);
			break;
		}

		para->mutator = i;

		//û���κα����㷨֧�֣��������︳��ʼֵ
		if(i == MMax)
		{
			para->paraValue.value = para->mutatorInitvalue;
			para->paraValue.len = para->mutatorInitlen;
			para->mutator = MNoMutator;
		}

		
	}

	in_mutatorParaRevise(para);

	//���ر�����value
	return para->paraValue.value;
}


#ifdef __cplusplus
}
#endif


