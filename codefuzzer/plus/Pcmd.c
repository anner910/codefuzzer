#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

#ifdef CF_Mode_CMD
#include <getopt.h>

int g_cfSeed = 0;
int g_cfTime = 3600*24;
u64 g_cfCount = 20*10000*10000;
int g_cfMode = 0;
int g_cfMaxLen = 0;

char* g_cfTestCaseName = NULL;
char* g_cfReportPath = "./";
char* g_cfCorpusPath = "./";

char* g_cfInBinCorpusPath = NULL;
char* g_cfOutBinCorpusPath = NULL;

int g_cfTimeout = 180;
int g_cfHelp=0;

static const struct option long_option[]={
	{"seed",required_argument,NULL,'s'},
	{"time",required_argument,NULL,'t'},
	{"timeout",required_argument,NULL,'T'},
	{"count",required_argument,NULL,'c'},
	{"Maxlen",required_argument,NULL,'M'},
	{"CorpusPath",required_argument,NULL,'C'},
	{"InBinCorpusPath",required_argument,NULL,'I'},
	{"OutBinCorpusPath",required_argument,NULL,'O'},
	{"mode",required_argument,NULL,'m'},
	{"name",required_argument,NULL,'n'},
	{"reportPath",required_argument,NULL,'r'},
	{"help",no_argument,&g_cfHelp,1},
	{NULL,0,NULL,0}
};


void setCmdPara(void)
{
	CF_SetRunSeed(g_cfSeed);
	CF_SetRunTime(g_cfTime);
	CF_SetRunCount(g_cfCount);
	CF_SetRunMode(g_cfMode);

	CF_SetReportPath(g_cfReportPath);

	CF_SetTimeOut(g_cfTimeout);

	CF_SetInBinCorpusPath(g_cfInBinCorpusPath);
	CF_SetOutBinCorpusPath(g_cfOutBinCorpusPath);
}

void CF_Cmd(int argc,char *argv[])
{
    int opt=0;
    while((opt=getopt_long(argc,argv,"strTcCmMnIO:l",long_option,NULL))!=-1)
    {
        switch(opt)
        {
            case 0:break;
            case 's':
				PL_printf("seed:%s \r\n",optarg);   
				g_cfSeed = lib_atoi(optarg);
				break;
			case 't':
				PL_printf("run time:%s \r\n",optarg);   
				g_cfTime = lib_atoi(optarg);
				break;
			case 'T':
				PL_printf("run timeout:%s \r\n",optarg);   
				g_cfTimeout = lib_atoi(optarg);
				break;
			case 'c':
				PL_printf("count:%s \r\n",optarg);
				g_cfCount = lib_atoi(optarg);
				break;
			case 'M':
				PL_printf("MaxLen:%s \r\n",optarg);
				g_cfMaxLen = lib_atoi(optarg);
				break;
			case 'C':
				PL_printf("Corpus Path:%s \r\n",optarg);   
				g_cfCorpusPath = optarg;
				break;
			case 'I':
				PL_printf("InBinCorpusPath:%s \r\n",optarg);   
				g_cfInBinCorpusPath = optarg;
				break;
			case 'O':
				PL_printf("OutBinCorpusPath:%s \r\n",optarg);   
				g_cfOutBinCorpusPath = optarg;
				break;
			case 'm':
				PL_printf("run mode:%s \r\n",optarg);   
				g_cfMode = lib_atoi(optarg);
				break;
			case 'n':
				PL_printf("testcase`s name:%s \r\n",optarg);
				g_cfTestCaseName = optarg;
				break;
			case 'r':
				PL_printf("report Path:%s \r\n",optarg);
				g_cfReportPath = optarg;
				break;
        }
    }
    if(g_cfHelp)
    {
        PL_printf("--seed \n");
		PL_printf("--time \n");
		PL_printf("--count \n");
		PL_printf("--Maxlen \n");//只对blob有效
		PL_printf("--timeout \n");
		PL_printf("--mode \n");
		PL_printf("--name \n");
		PL_printf("--CorpusPath \n");
		PL_printf("--InBinCorpusPath \n");
		PL_printf("--OutBinCorpusPath \n");
		PL_printf("--reportPath \n");
		PL_printf("--help \n");
		PL_exit(0);
    }

	PL_printf("-------------------\n");
	PL_printf("--seed             is   %d\n", g_cfSeed);
	PL_printf("--time             is   %d\n", g_cfTime);
	PL_printf("--count            is   %ld\n",g_cfCount);
	PL_printf("--Maxlen           is   %d\n", g_cfMaxLen);
	PL_printf("--timeout          is   %d\n", g_cfTimeout);
	PL_printf("--mode             is   %d\n", g_cfMode);
	PL_printf("--name             is   %s\n", g_cfTestCaseName);
	PL_printf("--CorpusPath       is   %s\n", g_cfCorpusPath);
	PL_printf("--InBinCorpusPath  is   %s\n", g_cfInBinCorpusPath);
	PL_printf("--OutBinCorpusPath is   %s\n", g_cfOutBinCorpusPath);
	PL_printf("--reportPath       is   %s\n", g_cfReportPath);
	PL_printf("-------------------\n");

	setCmdPara();
}

#else

char* g_cfTestCaseName = NULL;
char* g_cfCorpusPath = "./";
int   g_cfMaxLen = 0;


void CF_Cmd(int argc,char *argv[])
{
}

#endif

#ifdef __cplusplus
}
#endif


