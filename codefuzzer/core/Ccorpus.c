
#include "Core.h"

#ifdef __cplusplus
extern "C"{
#endif

void corpus_call(int corpusNo)
{
	SCorpus* corpus = &g_thread.corpus[corpusNo];

	//清理参数
	int i;
	in_memoryClearParaMutatorBuf();
	in_memoryClearParaInitBuf();

	int paraNumber = g_thread.paraNumber;

	g_thread.paraNumber = 0; // 需要重新计算

	
	for(i = 0;i < paraNumber;i++)
	{
		SParaValue* paraValue = &corpus->paraValue[i];
		
		if(paraValue->dataType == DataType_s8)
		{
			CF_GetS8(i, *(s8*)paraValue->value);
		}

		if(paraValue->dataType == DataType_s16)
		{
			CF_GetS16(i, *(s16*)paraValue->value);
		}

		if(paraValue->dataType == DataType_s32)
		{
			CF_GetS32(i, *(s32*)paraValue->value);
		}

		if(paraValue->dataType == DataType_s64)
		{
			CF_GetS64(i, *(s64*)paraValue->value);
		}

		if(paraValue->dataType == DataType_u8)
		{
			CF_GetU8(i, *(u8*)paraValue->value);
		}

		if(paraValue->dataType == DataType_u16)
		{
			CF_GetU16(i, *(u16*)paraValue->value);
		}

		if(paraValue->dataType == DataType_u32)
		{
			CF_GetU32(i, *(u32*)paraValue->value);
		}

		if(paraValue->dataType == DataType_u64)
		{
			CF_GetU64(i, *(u32*)paraValue->value);
		}

		if(paraValue->dataType == DataType_float)
		{
			CF_GetFloat(i, *(float*)paraValue->value);
		}

		if(paraValue->dataType == DataType_double)
		{
			CF_GetDouble(i, *(double*)paraValue->value);
		}

		if(paraValue->dataType == DataType_NumberRange)
		{
			CF_GetNumberRange(i, *(s32*)paraValue->value, 0, 0);
		}

		if(paraValue->dataType == DataType_NumberOnlyTable)
		{
			CF_GetNumberOnlyTable(i, *(s32*)paraValue->value, NULL, 0);
		}

		if(paraValue->dataType == DataType_NumberOutOfTable)
		{
			CF_GetNumberOutOfTable(i, *(s32*)paraValue->value, NULL, 0);
		}

		if(paraValue->dataType == DataType_NumberBasedOnTable)
		{
			CF_GetNumberBasedOnTable(i, *(s32*)paraValue->value, NULL, 0);
		}

		if(paraValue->dataType == DataType_string)
		{
			CF_GetString(i, paraValue->value, paraValue->len, 0, 0);
		}

		if(paraValue->dataType == DataType_stringOnlyTable)
		{
			CF_GetStringOnlyTable(i, paraValue->value, paraValue->len, 0, 0, NULL, 0);
		}

		if(paraValue->dataType == DataType_stringOutOfTable)
		{
			CF_GetStringOutOfTable(i, paraValue->value, paraValue->len, 0, 0, NULL, 0);
		}

		if(paraValue->dataType == DataType_stringBasedOnTable)
		{
			CF_GetStringBasedOnTable(i, paraValue->value, paraValue->len, 0, 0, NULL, 0);
		}

		if(paraValue->dataType == DataType_blob)
		{
			CF_GetBlob(i, paraValue->value, paraValue->len, 0, 0);
		}

		if(paraValue->dataType == DataType_blobOnlyTable)
		{
			CF_GetBlobOnlyTable(i, paraValue->value, paraValue->len, 0, 0, NULL, NULL, 0);
		}

		if(paraValue->dataType == DataType_blobOutOfTable)
		{
			CF_GetBlobOutOfTable(i, paraValue->value, paraValue->len, 0, 0, NULL, NULL, 0);
		}

		if(paraValue->dataType == DataType_blobBasedOnTable)
		{
			CF_GetBlobBasedOnTable(i, paraValue->value, paraValue->len, 0, 0, NULL, NULL, 0);
		}

		if(paraValue->dataType == DataType_myself)
		{
			CF_GetMySelf(i, paraValue->value, paraValue->len, 0, 0);
		}
	}

	in_memoryClearParaMutatorBuf();
	return;
}

void corpus_getSwitch(void)
{
	if (g_thread.runCount < g_thread.corpusNumber)
		return;
		
	if((((g_thread.runCount + Switch_Count/2) % Switch_Count) == 0)
		||(((g_thread.runCount + Switch_Count/4) % Switch_Count) == 0)
		||(((g_thread.runCount + Switch_Count/8) % Switch_Count) == 0))
	{
		
		//记录样本  最后一个样本位置作为临时空间
		SCorpus* corpus = &g_thread.corpus[g_global.setMaxCorpusNumber];
		if (corpus->paraValue == NULL)
		{
			corpus->paraValue = PL_malloc(g_thread.paraNumber * sizeof(SParaValue));
			PL_memset(corpus->paraValue,0, g_thread.paraNumber * sizeof(SParaValue));
			corpus->isNeedFree = Return_Yes;
		}

		int i;
		for(i = 0;i < g_thread.paraNumber;i++)
		{
			if (corpus->paraValue[i].value)
			{
				PL_free(corpus->paraValue[i].value);
				corpus->paraValue[i].value = NULL;
			}
		}
		
		for(i = 0;i < g_thread.paraNumber;i++)
		{
			corpus->paraValue[i].dataType = g_thread.para[i].paraValue.dataType;
			corpus->paraValue[i].len = g_thread.para[i].paraValue.len;

			corpus->paraValue[i].value = PL_malloc(corpus->paraValue[i].len);
			PL_memcpy(corpus->paraValue[i].value,g_thread.para[i].paraValue.value,corpus->paraValue[i].len);
		}

	}

}

int corpus_wash(void)
{
	int i, j, no, len = 0;
	//遍历所有样本
	for (i = 0; i < g_thread.corpusNumber; i++)
	{
		SCorpus* corpus = &g_thread.corpus[i];

		if (corpus->isBeenWash == 1)
			continue;

		//找到长度最长的参数
		for (j = 0; j < g_thread.paraNumber; j++)
		{
			if (corpus->paraValue[j].len > len)
			{
				no = j;
				len = corpus->paraValue[j].len;
			}
		}

		//只要长度大于20,就可以洗了
		if ((len >= 20) && (len/2 > g_thread.para[no].minlen))
		{
			g_thread.isWashing = 1;
			g_thread.washCorpusPos = i;
			g_thread.washParaPos = no;
			g_thread.washLen = len/2;
			g_thread.washhash = corpus->corpusHash;
			
			//记录样本  最后一个样本位置作为临时空间
			SCorpus* tempCorpus = &g_thread.corpus[g_global.setMaxCorpusNumber];
			if (tempCorpus->paraValue == NULL)
			{
				tempCorpus->paraValue = PL_malloc(g_thread.paraNumber * sizeof(SParaValue));
				PL_memset(tempCorpus->paraValue,0, g_thread.paraNumber * sizeof(SParaValue));
				tempCorpus->isNeedFree = Return_Yes;
			}

			int m;
			for(m = 0;m < g_thread.paraNumber;m++)
			{
				if (tempCorpus->paraValue[m].value)
				{
					PL_free(tempCorpus->paraValue[m].value);
					tempCorpus->paraValue[m].value = NULL;
				}
			}
			
			for(m = 0;m < g_thread.paraNumber;m++)
			{
				tempCorpus->paraValue[m].dataType = corpus->paraValue[m].dataType;
				tempCorpus->paraValue[m].len = corpus->paraValue[m].len;
				if (m == no)
					tempCorpus->paraValue[m].len = tempCorpus->paraValue[m].len / 2;
				
				tempCorpus->paraValue[m].value = PL_malloc(tempCorpus->paraValue[m].len);
				PL_memcpy(tempCorpus->paraValue[m].value,corpus->paraValue[m].value,tempCorpus->paraValue[m].len);
			}
			return 1;
			
		}
		//不需要洗了，也就是洗完了
		else
			corpus->isBeenWash = 1;

	}
	return 0;

}

void corpus_start(void)
{
	g_thread.isWashing = 0;
	g_thread.isruncorpus = 0;
	g_thread.isruncorpusNo = 0;

	//复现样本模式
	if(g_thread.setmode > 0)
	{
		if(g_thread.setmode > g_thread.corpusNumber)
		{
			PL_printf("only has %d corpus ,error exit\r\n", g_thread.corpusNumber);
			PL_exit(0);
		}

		//重置参数
		corpus_call(g_thread.setmode - 1);

		g_thread.isNeedWriteCorpus = 0;
		g_thread.isMustRecordCorpus = 0;
		g_thread.isNeedRecordCorpus = 0;
		g_thread.isNoNeedMutator = 1;
		return;
	}


	//第0次
	if(g_thread.runCount == 0)
	{
		g_thread.paraNumber = 0;
		
		g_thread.isNeedWriteCorpus = 0;
		g_thread.isMustRecordCorpus = 1;
		g_thread.isNeedRecordCorpus = 0;
		g_thread.isNoNeedMutator = 1;
		return;
	}

	//运行样本
	if((0 < g_thread.runCount) 
		&& (g_thread.runCount < g_thread.corpusNumber))
	{
		//重置参数
		corpus_call(g_thread.runCount - 1);

		g_thread.isNeedWriteCorpus = 0;
		g_thread.isMustRecordCorpus = 0;
		g_thread.isNeedRecordCorpus = 0;
		g_thread.isNoNeedMutator = 1;

		g_thread.isruncorpus = 1;
		g_thread.isruncorpusNo = g_thread.runCount - 1;
		return;
	}

	//每一万次洗一下，选一个洗，洗短长度,连续洗10次
	if((g_thread.runCount > Wash_Count) 
		&& ((g_thread.runCount % Wash_Count) > 5)
		&& ((g_thread.runCount % Wash_Count) < 15))
	{
		if (corpus_wash() == 1)
		{
			//重置参数
			corpus_call(g_global.setMaxCorpusNumber);
			g_thread.isNeedWriteCorpus = 1;
			g_thread.isMustRecordCorpus = 0;
			g_thread.isNeedRecordCorpus = 1;
			g_thread.isNoNeedMutator = 1;
			return;
		}
	}

	

	//每200次调度样本
	if((g_thread.runCount > 0) 
		&& ((g_thread.runCount % Switch_Count) == 0))
	{
		int no = schedule_corpus();

		//重置参数
		corpus_call(no);
	}

	//多次变异，基于变异值二次变异
	if((((g_thread.runCount + Switch_Count/2) % Switch_Count) == 0)
		||(((g_thread.runCount + Switch_Count/4) % Switch_Count) == 0)
		||(((g_thread.runCount + Switch_Count/8) % Switch_Count) == 0))
	{

		//重置参数
		corpus_call(g_global.setMaxCorpusNumber);
	}

	//正式变异

	g_thread.isNeedWriteCorpus = 1;
	g_thread.isMustRecordCorpus = 0;
	g_thread.isNeedRecordCorpus = 1;
	g_thread.isNoNeedMutator = 0;
	return;
}


void corpus_end(void)
{
	//第一次运行，没有样本，那就打印
	if((g_thread.runCount == 0) && (llvm_isHasFeacher() == 0))
	{
		PL_printf("\r\nnot found new trace-pc,please add -fsanitize-coverage=trace-pc to compile the code\r\n");
	}

	//没有参数，直接推出
	if(g_thread.paraNumber == 0)
		return;

	//从代码里读出来的样本也要赋值hash
	if (g_thread.isruncorpus == 1)
	{
		g_thread.corpus[g_thread.isruncorpusNo].corpusHash  = g_thread.temp_hash;
	}

	//正在洗样本
	if (g_thread.isWashing == 1)
	{
		//洗成功了，降低样本长度，还需要继续洗
		if ((g_thread.temp_hash != 0) && (g_thread.temp_hash == g_thread.washhash) && (llvm_isHasFeacher() == 0))
		{
			g_thread.corpus[g_thread.washCorpusPos].paraValue[g_thread.washParaPos].len = g_thread.washLen;
			return;
		}
		//这个样本不需要洗了
		else
		{	
			g_thread.corpus[g_thread.washCorpusPos].isBeenWash = 1;

		}
	}

	//是否有样本，
	if((llvm_isHasFeacher() == 0) && (g_thread.isMustRecordCorpus == 0))
		return;

	//到达样本总数的2/3,低权值样本直接抛弃
	if ((g_thread.corpusNumber >= (g_global.setMaxCorpusNumber*2/3))
		&&(llvm_getWeight() < PcCycle_Weight))
		return;
	
	//这里应该样本开始样本淘汰
	if (g_thread.corpusNumber >= g_global.setMaxCorpusNumber)
		return;

	if((g_thread.isMustRecordCorpus == 1) 
	   || ((llvm_isHasFeacher())&&(g_thread.isNeedWriteCorpus == 1)))
	{

		//记录样本
		SCorpus* corpus = &g_thread.corpus[g_thread.corpusNumber];
		corpus->paraValue = PL_malloc(g_thread.paraNumber * sizeof(SParaValue));
		corpus->isNeedFree = Return_Yes;
		corpus->corpusWeight = llvm_getWeight();
		corpus->corpusHash = g_thread.temp_hash;

		schedule_corpusAddToken(g_thread.corpusNumber, llvm_getWeight());

		int i;
		for(i = 0;i < g_thread.paraNumber;i++)
		{
			corpus->paraValue[i].dataType = g_thread.para[i].paraValue.dataType;
			corpus->paraValue[i].len = g_thread.para[i].paraValue.len;

			corpus->paraValue[i].value = PL_malloc(corpus->paraValue[i].len);

			PL_memcpy(corpus->paraValue[i].value,g_thread.para[i].paraValue.value,corpus->paraValue[i].len);
		}

		if(g_thread.isNeedWriteCorpus)
		{
			if (llvm_getWeight() >= PcCycle_Weight)
			{
				g_thread.highCorpusNumber++;

				g_thread.isNeedPrintfCorpus = 0;
				corpus_writeTxt(g_thread.setTestCasePath, g_thread.corpusNumber);
				//写bin
				corpus_WriteBin(g_thread.corpusNumber);
			}
		}

		g_thread.corpusNumber++;
	}
}

#ifdef __cplusplus
}
#endif


