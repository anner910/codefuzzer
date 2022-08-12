/*************************************************************************************************************
1.插入连续多个byte (最多255)

2.插入连续多个byte，值每次++

3.插入连续多个byte，值每次--

4.插入连续多个byte，值每次相同


*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MdataByteMulInsert;

int MdataByteMulInsertGetCount(SPara* para)
{
	return in_scheduleMutatorWeight(s_MdataByteMulInsert.weight);
}

char* MdataByteMulInsertContinueAddGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	//插入长度
	int changelen = in_getGuassRandom(255);

	int len = para->mutatorInitlen + changelen;

	if (len > g_global.setMaxMutatorLen)
	{
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
		para->paraValue.len = para->mutatorInitlen;
		return para->paraValue.value;
	}

	para->paraValue.len = len;

	//选取插入位置
	int temp = in_getWeightRandom(para->mutatorInitlen);

	PL_memcpy(para->paraValue.value, para->mutatorInitvalue, temp);

	int i;
	char a = PL_random_byte();
	for (i = 0; i < changelen; i++)
		para->paraValue.value[temp + i] = a++;
	
	PL_memcpy(para->paraValue.value + temp + changelen, para->mutatorInitvalue + temp, para->mutatorInitlen - temp);

	return para->paraValue.value;
}

char* MdataByteMulInsertContinueDelGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	//插入长度
	int changelen = in_getGuassRandom(255);

	int len = para->mutatorInitlen + changelen;

	if (len > g_global.setMaxMutatorLen)
	{
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
		para->paraValue.len = para->mutatorInitlen;
		return para->paraValue.value;
	}

	para->paraValue.len = len;

	//选取插入位置
	int temp = in_getWeightRandom(para->mutatorInitlen);

	PL_memcpy(para->paraValue.value, para->mutatorInitvalue, temp);

	int i;
	char a = PL_random_byte();
	for (i = 0; i < changelen; i++)
		para->paraValue.value[temp + i] = a--;
	
	PL_memcpy(para->paraValue.value + temp + changelen, para->mutatorInitvalue + temp, para->mutatorInitlen - temp);

	return para->paraValue.value;
}

char* MdataByteMulInsertContinueSameGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	//插入长度
	int changelen = in_getGuassRandom(255);

	int len = para->mutatorInitlen + changelen;

	if (len > g_global.setMaxMutatorLen)
	{
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
		para->paraValue.len = para->mutatorInitlen;
		return para->paraValue.value;
	}

	para->paraValue.len = len;

	//选取插入位置
	int temp = in_getWeightRandom(para->mutatorInitlen);

	PL_memcpy(para->paraValue.value, para->mutatorInitvalue, temp);

	int i;
	char a = PL_random_byte();
	for (i = 0; i < changelen; i++)
		para->paraValue.value[temp + i] = a;
	
	PL_memcpy(para->paraValue.value + temp + changelen, para->mutatorInitvalue + temp, para->mutatorInitlen - temp);

	return para->paraValue.value;
}


char* MdataByteMulInsertContinueGetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	//插入长度
	int changelen = in_getGuassRandom(255);

	int len = para->mutatorInitlen + changelen;

	if (len > g_global.setMaxMutatorLen)
	{
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
		para->paraValue.len = para->mutatorInitlen;
		return para->paraValue.value;
	}

	para->paraValue.len = len;

	//选取插入位置
	int temp = in_getWeightRandom(para->mutatorInitlen);

	PL_memcpy(para->paraValue.value, para->mutatorInitvalue, temp);

	int i;
	for (i = 0; i < changelen; i++)
		para->paraValue.value[temp + i] = PL_random_byte();
	
	PL_memcpy(para->paraValue.value + temp + changelen, para->mutatorInitvalue + temp, para->mutatorInitlen - temp);

	return para->paraValue.value;
}

char* MdataByteMulInsertGetValue(SPara* para, int pos)
{
	int weight = PL_random()% 100;

	if (weight > 85)
		return MdataByteMulInsertContinueAddGetValue(para, pos);

	if (weight > 70)
		return MdataByteMulInsertContinueDelGetValue(para, pos);

	if (weight > 55)
		return MdataByteMulInsertContinueSameGetValue(para, pos);
		
	return MdataByteMulInsertContinueGetValue(para, pos);
}


int MdataByteMulInsertGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataByteMulInsert =
{
	"MdataByteMulInsert",
	MdataByteMulInsertGetCount,
	MdataByteMulInsertGetValue,
	MdataByteMulInsertGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MdataByteMulInsertInit(void)
{
	g_global.g_mutatorModule[MdataByteMulInsert] = &s_MdataByteMulInsert;
}

#ifdef __cplusplus
}
#endif

