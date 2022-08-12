



#include "Core.h"

#ifdef __cplusplus
extern "C"{
#endif

void CF_Start(void)
{
	in_seed_init();
	in_memoryInit();
	in_mutatorInit();
	leak_init();
	SetSignalHandler();
	kcov_init();
	
	corpus_readTxt();
	corpus_ReadBin();
	
	g_thread.runCount = -1;
	g_thread.startTime = PL_getTime();
	g_thread.isHasCrash = 0;
	g_thread.isSelfExit = 0;
}

void CF_ForStart(void)
{
	g_thread.runCount++;

	in_seed(g_thread.runCount);

	//在清理内存之前得到变异参数
	corpus_getSwitch();
	in_memoryCleanfor();

	corpus_start();
	llvm_ClearFeacher();

	PL_setTimer(g_global.setTimeout);
	kcov_start();
	g_thread.llvmEnable = 1;
}

int CF_ForEnd(void)
{
	kcov_end();
	g_thread.llvmEnable = 0;
	llvm_do();
	corpus_end();
	
	leak_do();
	
	if(g_thread.runCount == g_thread.setCount)
		return 1;

	//复现模式只跑一次
	if(g_thread.setmode != 0)
		return 1;

	//如果已经执行了设置的时间，则退出
	if(g_thread.setTime > 0)
	{
		int time = PL_getTime();
		if (time > (g_thread.startTime + g_thread.setTime))
			return 1;
	}

	return 0;
}

void CF_End(void)
{
	g_thread.llvmEnable = 0;
		
	//测试结束，清理定时
	PL_setTimer(0);
	report_addTestCase("complete");
	in_memoryClean();
}

void CF_Fork(void)
{
	g_thread.pid = 0;
	g_thread.pid = PL_fork();
}

int CF_IsFather(void)
{
	return g_thread.pid;
}

void CF_Exit(void)
{
	//主动退出
	g_thread.isSelfExit = 1;
	PL_exit(0);
}

void CF_Wait(void)
{
	PL_wait(&g_thread.run_ok);
}

int CF_isOk(void)
{
	if (g_thread.run_ok == 0)
		return 1;
	return 0;
}

void CF_ForPassive(char* testcase, int mode)
{
	if (g_thread.testcasePassiveNow == testcase)
	{
	}
	else
	{
		CF_OverPassive();
		g_thread.testcasePassiveNow = testcase;
	}

	if (g_thread.isfirst > 0)
	{
		CF_ForEnd();
	}

	if (g_thread.isfirst == 0)
	{
		CF_SetReportPath((char*)"./");
		CF_SetRunSeed(0);
		CF_SetRunTime(3600*24);
		CF_SetRunCount(2000000000);
		CF_SetTestCaseName(testcase);
		CF_SetRunMode(mode);
		CF_Start();
	}
	CF_ForStart();
	g_thread.isfirst++;

}

void CF_OverPassive(void)
{
	CF_ForEnd();
	CF_End();
	g_thread.isfirst = 0;
}


//其他函数


#ifdef __cplusplus
}
#endif

