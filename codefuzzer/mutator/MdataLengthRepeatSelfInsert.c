/*************************************************************************************************************
复制某些字段，长度为size边界

复制某些字段，长度为hook出来

复制某些字段，长度为高斯随机

数据来自自己

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataLengthRepeatSelfInsert;


int MdataLengthRepeatSelfInsertGetCount(SPara* para)
{
	return in_scheduleMutatorWeight(s_MdataLengthRepeatSelfInsert.weight);
}

char* MdataLengthRepeatSelfInsertGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	int	len = in_getLen(para, pos);

	if(len <= para->mutatorInitlen)
	{
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
		para->paraValue.len = para->mutatorInitlen;
		return para->paraValue.value;
	}

	//扩展位置
	int changepos = in_getWeightRandom(para->mutatorInitlen);

	if (changepos == 0)
		changepos = 1;

	//单元长度
	int unitlen = in_getGuassRandom(changepos);

	if (unitlen == 0)
		unitlen = 1;


	//扩展次数
	int time = (len - para->mutatorInitlen) / unitlen;

	if (time == 0)
	{
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
		para->paraValue.len = para->mutatorInitlen;
		return para->paraValue.value;
	}

	PL_memcpy(para->paraValue.value, para->mutatorInitvalue, changepos);

	int i;
	int j;

	char* repeat = para->paraValue.value + changepos - unitlen;
	for(i = 0; i < time; i++)
	{
		for(j = 0; j < unitlen; j++)
		{
			para->paraValue.value[changepos + j + i*unitlen] = repeat[j];
		}
	}

	PL_memcpy(para->paraValue.value + changepos + time * unitlen, para->mutatorInitvalue + changepos, para->mutatorInitlen - changepos);

	para->paraValue.len = para->mutatorInitlen + time * unitlen;
	return para->paraValue.value;
}

int MdataLengthRepeatSelfInsertGetSupport(SPara* para)
{
	//初始长度为0不支持
	if (para->mutatorInitlen == 0)
		return Return_No;
	
	//初始长度为0不支持
	return Return_Yes;
}

SMutator s_MdataLengthRepeatSelfInsert =
{
	"MdataLengthRepeatSelfInsert",
	MdataLengthRepeatSelfInsertGetCount,
	MdataLengthRepeatSelfInsertGetValue,
	MdataLengthRepeatSelfInsertGetSupport,
	Return_Yes,
	Mutator_BaseWeight/10,
};

void MdataLengthRepeatSelfInsertInit(void)
{

	g_global.g_mutatorModule[MdataLengthRepeatSelfInsert] = &s_MdataLengthRepeatSelfInsert;
}


#ifdef __cplusplus
}
#endif

