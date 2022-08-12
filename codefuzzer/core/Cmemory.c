#include "Core.h"

#ifdef __cplusplus
extern "C"{
#endif

void in_memoryClearParaMutatorBuf(void)
{
	int i;
	for(i = 0;i< g_thread.paraNumber; i++)
	{
		if(g_thread.para[i].idNeedFree == Return_Yes)
		{
			PL_free(g_thread.para[i].paraValue.value);
			g_thread.para[i].paraValue.len = 0;
			g_thread.para[i].paraValue.value = NULL;
			g_thread.para[i].idNeedFree = Return_No;
		}
	}
}

void in_memoryClearParaInitBuf(void)
{
	int i;
	for(i = 0;i< g_thread.paraNumber; i++)
	{
		if(g_thread.para[i].isInitNeedFree == Return_Yes)
		{
			PL_free(g_thread.para[i].Initvalue);
			g_thread.para[i].Initlen= 0;
			g_thread.para[i].Initvalue = NULL;
			g_thread.para[i].isInitNeedFree = Return_No;
		}

		if(g_thread.para[i].isMutatorInitNeedFree == Return_Yes)
		{
			PL_free(g_thread.para[i].mutatorInitvalue);
			g_thread.para[i].mutatorInitlen= 0;
			g_thread.para[i].mutatorInitvalue = NULL;
			g_thread.para[i].isMutatorInitNeedFree = Return_No;
		}

		g_thread.para[i].isInit = 0;
	}
	
}

void in_memoryInit(void)
{
	//参数内存，因为参数是变化的，一些场合要节省内存
	g_thread.para = (SPara*)PL_malloc(sizeof(SPara) * g_global.setMaxParaNumber);
	PL_memset((char*)g_thread.para, 0, (sizeof(SPara) * g_global.setMaxParaNumber));

	//临时变异buf
	g_thread.mutatorBuf = (char*)PL_malloc(g_global.setMaxMutatorLen + 100);

	//trace-pc
	g_thread.llvm.trace_pc = (uintptr_t*)PL_malloc(sizeof(uintptr_t) * g_global.setMaxPcNumber);
	PL_memset((char*)g_thread.llvm.trace_pc, 0, (sizeof(uintptr_t) * g_global.setMaxPcNumber));

	g_thread.llvm.trace_pc_count = (uintptr_t*)PL_malloc(sizeof(uintptr_t) * g_global.setMaxPcNumber);
	PL_memset((char*)g_thread.llvm.trace_pc_count, 0, (sizeof(uintptr_t) * g_global.setMaxPcNumber));

	g_thread.llvm.trace_pc_count_bit = (int*)PL_malloc(sizeof(int) * g_global.setMaxPcNumber);
	PL_memset((char*)g_thread.llvm.trace_pc_count_bit, 0, (sizeof(int) * g_global.setMaxPcNumber));

	g_thread.llvm.idx = (int*)PL_malloc(sizeof(int) * g_global.setMaxPcNumber);
	PL_memset((char*)g_thread.llvm.idx, 0, (sizeof(int) * g_global.setMaxPcNumber));

	g_thread.llvm.trace_pc_edge = (uintptr_t*)PL_malloc(sizeof(uintptr_t) * g_global.setMaxPcNumber);
	PL_memset((char*)g_thread.llvm.trace_pc_edge, 0, (sizeof(uintptr_t) * g_global.setMaxPcNumber));

	g_thread.llvm.trace_pc_hash = (uintptr_t*)PL_malloc(sizeof(uintptr_t) * g_global.setMaxPcNumber);
	PL_memset((char*)g_thread.llvm.trace_pc_hash, 0, (sizeof(uintptr_t) * g_global.setMaxPcNumber));


	//corpus +1为了存临时样本
	g_thread.corpus = (SCorpus*)PL_malloc(sizeof(SCorpus) * (g_global.setMaxCorpusNumber + 1));
	PL_memset((char*)g_thread.corpus, 0, (sizeof(SCorpus) * (g_global.setMaxCorpusNumber + 1)));

	//schedule
	int tokenTotalH = schedule_corpusGetTokenTotalH();
	int tokenTotalM = schedule_corpusGetTokenTotalM();
	int tokenTotalL = schedule_corpusGetTokenTotalL();
	g_thread.tokenH = (short*)PL_malloc(sizeof(short) * tokenTotalH);
	PL_memset((char*)g_thread.tokenH, 0, (sizeof(short) * tokenTotalH));

	g_thread.tokenM = (short*)PL_malloc(sizeof(short) * tokenTotalM);
	PL_memset((char*)g_thread.tokenM, 0, (sizeof(short) * tokenTotalM));

	g_thread.tokenL = (short*)PL_malloc(sizeof(short) * tokenTotalL);
	PL_memset((char*)g_thread.tokenL, 0, (sizeof(short) * tokenTotalL));
	

	//hook
	g_thread.hookData = (ShookData*)PL_malloc(sizeof(ShookData));
	PL_memset((char*)g_thread.hookData, 0, (sizeof(ShookData)));

	//tempbuf  用于写文件
	g_thread.tempbuf = (char*)PL_malloc(g_global.setMaxMutatorLen *4 + 1000);

	g_thread.memHasInit = 1;
	
}

void in_memoryCleanfor(void)
{
	in_memoryClearParaMutatorBuf();
}

void in_memoryClean(void)
{
	int i;
	g_thread.memHasInit = 0;

	//请参数内存
	in_memoryClearParaMutatorBuf();
	in_memoryClearParaInitBuf();
	
	if(g_thread.para)
	{
		PL_free(g_thread.para);
		g_thread.para = NULL;
	}

	//清临时变异buf
	if(g_thread.mutatorBuf)
	{
		PL_free(g_thread.mutatorBuf);
		g_thread.mutatorBuf = NULL;
	}

	//清reqce-pc
	if(g_thread.llvm.trace_pc)
	{
		PL_free(g_thread.llvm.trace_pc);
		g_thread.llvm.trace_pc = NULL;
	}

	if(g_thread.llvm.trace_pc_count)
	{
		PL_free(g_thread.llvm.trace_pc_count);
		g_thread.llvm.trace_pc_count = NULL;
	}

	if(g_thread.llvm.trace_pc_count_bit)
	{
		PL_free(g_thread.llvm.trace_pc_count_bit);
		g_thread.llvm.trace_pc_count_bit = NULL;
	}

	if(g_thread.llvm.idx)
	{
		PL_free(g_thread.llvm.idx);
		g_thread.llvm.idx = NULL;
	}

	if(g_thread.llvm.trace_pc_edge)
	{
		PL_free(g_thread.llvm.trace_pc_edge);
		g_thread.llvm.trace_pc_edge = NULL;
	}

	if(g_thread.llvm.trace_pc_hash)
	{
		PL_free(g_thread.llvm.trace_pc_hash);
		g_thread.llvm.trace_pc_hash = NULL;
	}

	g_thread.pcTotal = 0;
	g_thread.edgeTotal = 0;
	g_thread.hashTotal = 0;
	g_thread.llvm.idxCount = 0;
	g_thread.llvm.hash = 0;
	g_thread.llvm.old_pc = 0;

	//清样本
	if(g_thread.corpus)
	{
		if(g_thread.corpusNumber != 0)
		{
			for(i = 0;i< g_thread.corpusNumber; i++)
			{
				if(g_thread.corpus[i].paraValue)
				{
					int j;
					for(j = 0;j< g_thread.paraNumber; j++)
					{
						if (g_thread.corpus[i].paraValue[j].value)
							PL_free(g_thread.corpus[i].paraValue[j].value);
						g_thread.corpus[i].paraValue[j].len = 0;
						g_thread.corpus[i].paraValue[j].value = NULL;
					}
					
					PL_free(g_thread.corpus[i].paraValue);
					g_thread.corpus[i].paraValue = NULL;

				}
			}
			
			i = g_global.setMaxCorpusNumber;
			if(g_thread.corpus[i].paraValue)
			{
				int j;
				for(j = 0;j< g_thread.paraNumber; j++)
				{
					if (g_thread.corpus[i].paraValue[j].value)
						PL_free(g_thread.corpus[i].paraValue[j].value);
					g_thread.corpus[i].paraValue[j].len = 0;
					g_thread.corpus[i].paraValue[j].value = NULL;
				}
				
				PL_free(g_thread.corpus[i].paraValue);
				g_thread.corpus[i].paraValue = NULL;

			}
		}
		PL_free(g_thread.corpus);
		g_thread.corpus = NULL;
	}

	PL_free(g_thread.tokenH);
	g_thread.tokenH = NULL;
	PL_free(g_thread.tokenM);
	g_thread.tokenM = NULL;
	PL_free(g_thread.tokenL);
	g_thread.tokenL = NULL;

	g_thread.tokenHpos = 0;
	g_thread.tokenMpos = 0;
	g_thread.tokenLpos = 0;

	g_thread.tokenHtotal = 0;
	g_thread.tokenMtotal = 0;
	g_thread.tokenLtotal = 0;

	//hool
	if(g_thread.hookData)
	{
		PL_free(g_thread.hookData);
		g_thread.hookData = NULL;
	}

	//清临时buf
	if(g_thread.tempbuf)
	{
		PL_free(g_thread.tempbuf);
		g_thread.tempbuf = NULL;
	}

	//leak
	g_thread.mallocCount = 0;
	g_thread.freeCount = 0;

	//请临时数字
	g_thread.paraNumber = 0;
	g_thread.corpusNumber = 0;
	g_thread.highCorpusNumber = 0;

	g_thread.numNumber = 0;
	g_thread.blobNumber = 0;
}

void in_mutatorParaGetInitBuf(SPara* para)
{
	para->idNeedFree = Return_No;
	para->paraValue.value = g_thread.mutatorBuf;
	
	PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
	para->paraValue.len = para->mutatorInitlen;
}

void in_mutatorParaGetBuf(SPara* para)
{
	para->idNeedFree = Return_No;
	para->paraValue.value = g_thread.mutatorBuf;
	para->paraValue.len = para->mutatorInitlen;
}


void in_InitBuf(SPara* para, char* value, int len)
{
	//初始buf
	para->isInitNeedFree = Return_Yes;
	para->Initvalue = PL_malloc(len);
	
	PL_memcpy(para->Initvalue, value, len);
	para->Initlen= len;


	
	//初始化变异buf
	if (para->mutatorPosEnalbe == Return_Yes)
	{
		para->isMutatorInitNeedFree = Return_No;
		para->mutatorInitvalue = para->Initvalue + para->setmutatorPos;
		para->mutatorInitlen= para->setmutatorLen;
	}
	else
	{
		para->isMutatorInitNeedFree = Return_No;
		para->mutatorInitvalue = para->Initvalue;
		para->mutatorInitlen= len;
	}
	
}



#ifdef __cplusplus
}
#endif


