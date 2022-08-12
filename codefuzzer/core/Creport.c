#include "Core.h"

#ifdef __cplusplus
extern "C"{
#endif


char * g_version="version is v.1.0.0 2022-08-12";

void report_setPath(char* path)
{
	if(path == NULL)
	{
		g_global.setReportPath[0] = 0;
		return;
	}

	char date[64] = {0};
	char tempbuf[256] = {0};
	PL_getData(date);

	g_global.setReportPath[0] = 0;
	PL_sprintf(g_global.setReportPath, "%s_codefuzzerRepport_%s",path, date);
	
	tempbuf[0] = 0;
	PL_sprintf(tempbuf, "********************************************\r\n");
	IO_writeFileTail(g_global.setReportPath, tempbuf);

	tempbuf[0] = 0;
	PL_sprintf(tempbuf, "codefuzzer report   %s\r\n", date);
	IO_writeFileTail(g_global.setReportPath, tempbuf);

    tempbuf[0] = 0;
	PL_sprintf(tempbuf, "%s\r\n",g_version);
	IO_writeFileTail(g_global.setReportPath, tempbuf);

	tempbuf[0] = 0;
	PL_sprintf(tempbuf, "********************************************\r\n");
	IO_writeFileTail(g_global.setReportPath, tempbuf);
}

void report_addTestCase(char* reason)
{
	if(g_global.setReportPath[0] == 0)
		return;
	
	char tempbuf[256] = {0};
	
	tempbuf[0] = 0;
	PL_sprintf(tempbuf, "--------------testcase is:%s\r\n", g_thread.setTestCaseName);
	IO_writeFileTail(g_global.setReportPath, tempbuf);

	tempbuf[0] = 0;
	PL_sprintf(tempbuf, "reason    is      :%s\r\n", reason);
	IO_writeFileTail(g_global.setReportPath, tempbuf);

	tempbuf[0] = 0;
	PL_sprintf(tempbuf, "runcount is       :%ld\r\n", g_thread.runCount);
	IO_writeFileTail(g_global.setReportPath, tempbuf);

	tempbuf[0] = 0;
	int time = PL_getTime();
	time = time - g_thread.startTime;
	PL_sprintf(tempbuf, "runtime  is       :%d\r\n", time);
	IO_writeFileTail(g_global.setReportPath, tempbuf);

	tempbuf[0] = 0;
	PL_sprintf(tempbuf, "Coverage pc is    :%d\r\n", g_thread.pcTotal);
	IO_writeFileTail(g_global.setReportPath, tempbuf);

	tempbuf[0] = 0;
	PL_sprintf(tempbuf, "Coverage cycle is :%d\r\n", g_thread.cycleTotal);
	IO_writeFileTail(g_global.setReportPath, tempbuf);

	tempbuf[0] = 0;
	PL_sprintf(tempbuf, "Coverage edge is  :%d\r\n", g_thread.edgeTotal);
	IO_writeFileTail(g_global.setReportPath, tempbuf);

	tempbuf[0] = 0;
	PL_sprintf(tempbuf, "Coverage hash is  :%d\r\n", g_thread.hashTotal);
	IO_writeFileTail(g_global.setReportPath, tempbuf);

	tempbuf[0] = 0;
	PL_sprintf(tempbuf, "all corpus is     :%d\r\n", g_thread.corpusNumber);
	IO_writeFileTail(g_global.setReportPath, tempbuf);

	tempbuf[0] = 0;
	PL_sprintf(tempbuf, "number hook is    :%d\r\n", g_thread.numNumber);
	IO_writeFileTail(g_global.setReportPath, tempbuf);

	tempbuf[0] = 0;
	PL_sprintf(tempbuf, "blob hook is      :%d\r\n", g_thread.blobNumber);
	IO_writeFileTail(g_global.setReportPath, tempbuf);

}

void report_andCrashWrite(char* reason)
{
	if(g_thread.memHasInit == 0)
		return;

	g_thread.isHasCrash++;

	char tempbuf[512] = {0};
	PL_sprintf(tempbuf, "%s_crash_%08x_%s",g_thread.setTestCaseName, in_getParaCrc(),reason);

	if(g_global.SetPrintCrashCorpus)
		g_thread.isNeedPrintfCorpus = 1;
	else
		g_thread.isNeedPrintfCorpus = 0;
	corpus_writeTxt(tempbuf, 1);

	report_addTestCase(reason);
}

void report_asan(char* report)
{
	char* des = NULL;
	if(__asan_get_report_description)
		des = __asan_get_report_description();

	//记录asan报告
	char tempbuf[512] = {0};
	PL_sprintf(tempbuf, "%s_asan_%08x_%s",g_thread.setTestCaseName, in_getParaCrc(), des);
	IO_writeFileTail(tempbuf, report);

	PL_printf("\r\nCrashHandler because asan \r\n");
	//记录crash样本
	report_andCrashWrite(des);
}

#ifdef __cplusplus
}
#endif


