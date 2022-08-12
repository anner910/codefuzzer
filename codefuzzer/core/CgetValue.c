

#include "Core.h"

#ifdef __cplusplus
extern "C"{
#endif


char* CF_GetS8( int no, s8 initValue)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_s8;

		//初始b uf
		in_InitBuf(para, (char*)&initValue, 1);
	}

	para->minlen = 1;
	para->maxlen = 1;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetS16(int no, s16 initValue)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_s16;

		//初始b uf
		in_InitBuf(para, (char*)&initValue, 2);
	}

	para->minlen = 2;
	para->maxlen = 2;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetS32(int no, s32 initValue)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_s32;

		//初始b uf
		in_InitBuf(para, (char*)&initValue, 4);
	}

	para->minlen = 4;
	para->maxlen = 4;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetS64(int no, s64 initValue)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_s64;

		//初始b uf
		in_InitBuf(para, (char*)&initValue, 8);
	}

	para->minlen = 8;
	para->maxlen = 8;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetU8( int no, u8 initValue)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_u8;

		//初始b uf
		in_InitBuf(para, (char*)&initValue, 1);
	}

	para->minlen = 1;
	para->maxlen = 1;
	
	return in_mutatorParaGetValue(para);
}


char* CF_GetU16(int no, u16 initValue)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_u16;

		//初始b uf
		in_InitBuf(para, (char*)&initValue, 2);
	}

	para->minlen = 2;
	para->maxlen = 2;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetU32(int no, u32 initValue)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_u32;

		//初始b uf
		in_InitBuf(para, (char*)&initValue, 4);
	}

	para->minlen = 4;
	para->maxlen = 4;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetU64(int no, u64 initValue)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_u64;

		//初始b uf
		in_InitBuf(para, (char*)&initValue, 8);
	}

	para->minlen = 8;
	para->maxlen = 8;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetFloat(int no, float initValue)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_float;

		//初始b uf
		in_InitBuf(para, (char*)&initValue, 4);
	}

	para->minlen = 4;
	para->maxlen = 4;
	
	return in_mutatorParaGetValue(para);
}
char* CF_GetDouble(int no, double initValue)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_double;

		//初始b uf
		in_InitBuf(para, (char*)&initValue, 8);
	}

	para->minlen = 8;
	para->maxlen = 8;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetNumberRange(int no, s32 initValue, int minValue, int maxValue)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_NumberRange;

		//初始b uf
		in_InitBuf(para, (char*)&initValue, 4);
	}

	para->minlen = 4;
	para->maxlen = 4;

	para->minValue = minValue;
	para->maxValue = maxValue;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetNumberOnlyTable(int no, s32 initValue, int* table, int count)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_NumberOnlyTable;

		//初始b uf
		in_InitBuf(para, (char*)&initValue, 4);
	}

	para->minlen = 4;
	para->maxlen = 4;

	para->table = table;
	para->count = count;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetNumberOutOfTable(int no, s32 initValue, int* table, int count)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_NumberOutOfTable;

		//初始b uf
		in_InitBuf(para, (char*)&initValue, 4);
	}

	para->minlen = 4;
	para->maxlen = 4;

	para->table = table;
	para->count = count;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetNumberBasedOnTable(int no, s32 initValue, int* table, int count)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_NumberBasedOnTable;

		//初始b uf
		in_InitBuf(para, (char*)&initValue, 4);
	}

	para->minlen = 4;
	para->maxlen = 4;

	para->table = table;
	para->count = count;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetString(int no, char* initValue, int initLen, int minLen, int maxLen)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_string;

		//初始b uf
		in_InitBuf(para, initValue, initLen);
	}

	para->minlen = minLen;
	para->maxlen = maxLen;

	return in_mutatorParaGetValue(para);
}

char* CF_GetStringOnlyTable(int no, char* initValue, int initLen,int minLen, int maxLen, char** table, int count)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_stringOnlyTable;

		//初始b uf
		in_InitBuf(para, initValue, initLen);
	}

	para->minlen = minLen;
	para->maxlen = maxLen;

	para->table1 = table;
	para->count = count;

	return in_mutatorParaGetValue(para);
}

char* CF_GetStringOutOfTable(int no, char* initValue, int initLen,int minLen, int maxLen, char** table, int count)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_stringOutOfTable;

		//初始b uf
		in_InitBuf(para, initValue, initLen);
	}

	para->minlen = minLen;
	para->maxlen = maxLen;

	para->table1 = table;
	para->count = count;

	return in_mutatorParaGetValue(para);
}

char* CF_GetStringBasedOnTable(int no, char* initValue, int initLen,int minLen, int maxLen, char** table, int count)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_stringBasedOnTable;

		//初始b uf
		in_InitBuf(para, initValue, initLen);
	}

	para->minlen = minLen;
	para->maxlen = maxLen;

	para->table1 = table;
	para->count = count;

	return in_mutatorParaGetValue(para);
}

char* CF_GetBlob(int no, char* initValue, int initLen, int minLen, int maxLen)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_blob;

		//初始b uf
		in_InitBuf(para, initValue, initLen);
	}


	para->minlen = minLen;
	para->maxlen = maxLen;

	//这个要很少使用，仅命令行设置有效
	if (g_cfMaxLen != 0)
		para->maxlen = g_cfMaxLen;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetBlobOnlyTable(int no, char* initValue, int initLen, int minLen, int maxLen, char** table, int* tablelen, int count)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_blobOnlyTable;
		
		//初始b uf
		in_InitBuf(para, initValue, initLen);
	}

	para->minlen = minLen;
	para->maxlen = maxLen;

	para->table1 = table;
	para->tablelen = tablelen;
	para->count = count;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetBlobOutOfTable(int no, char* initValue, int initLen, int minLen, int maxLen, char** table, int* tablelen, int count)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_blobOutOfTable;
		
		//初始b uf
		in_InitBuf(para, initValue, initLen);
	}

	para->minlen = minLen;
	para->maxlen = maxLen;

	para->table1 = table;
	para->tablelen = tablelen;
	para->count = count;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetBlobBasedOnTable(int no, char* initValue, int initLen, int minLen, int maxLen, char** table, int* tablelen, int count)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_blobBasedOnTable;
		
		//初始b uf
		in_InitBuf(para, initValue, initLen);
	}

	para->minlen = minLen;
	para->maxlen = maxLen;

	para->table1 = table;
	para->tablelen = tablelen;
	para->count = count;
	
	return in_mutatorParaGetValue(para);
}

char* CF_GetMySelf(int no, char* initValue, int initLen, int minLen, int maxLen)
{
	SPara* para = &g_thread.para[no];
	if(para->isInit == 0)
	{
		para->paraValue.dataType = DataType_myself;

		//初始b uf
		in_InitBuf(para, initValue, initLen);
	}

	para->minlen = minLen;
	para->maxlen = maxLen;
	
	return in_mutatorParaGetValue(para);
}

int CF_GetMutatorLen(int no)
{
	SPara* para = &g_thread.para[no];
	return para->paraValue.len;
}

void CF_SetMutatorPos(int no, int enable, int pos, int len, int minLen, int maxLen)

{
	SPara* para = &g_thread.para[no];

	para->mutatorPosEnalbe = enable;
	
	para->setmutatorPos = pos;
	para->setmutatorLen = len;
	para->setmutatorminlen = minLen;
	para->setmutatormaxlen = maxLen;

	return;
}

#ifdef __cplusplus
}
#endif


