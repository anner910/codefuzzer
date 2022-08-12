

#include "Core.h"

#ifdef __cplusplus
extern "C"{
#endif

char* dataTypeName[] = 
{
    "u8",
    "u16",
    "u32",
    "u64",
    "s8",
    "s16",
    "s32",
    "s64",
    "float",
    "double",

    "NumberRange",
    "NumberOnlyTable",
    "NumberOutOfTable",
    "NumberBasedOnTable",

    "myself",

    "string",
    "stringOnlyTable",
    "stringOutOfTable",
    "stringBasedOnTable",

    "blob",
    "blobOnlyTable",
    "blobOutOfTable",
    "blobBasedOnTable",
    "max"
};


SGlobal g_global =  
{
    .setMaxParaNumber = Para_MaxNumber, 
    .setMaxMutatorLen = Buf_MaxLength,
    .setMaxPcNumber = Pc_MaxNumber,
    .setMaxCorpusNumber = Corpus_MaxNumber,
    .setEnableLeak = 1,
    .setDebugLeak = 0,

    .setPcWeight 	= Pc_Weight,
    .setEdgeWeight 	= PcEdge_Weight,
    .setCycleWeight	= PcCycle_Weight,
    .setPathWeight 	= PcPath_Weight,

    .SetCheckLargeMemorySize = 1024,
    .SetCheckLargeMemoryUse = 1024,
    .SetPrintCrashCorpus = 1,

    .setEnableScheduleMutatorWeight = 1,

    .setReportPath = {0},

    .setTimeout = Default_TimeOut,

    .g_mutatorModule = {0},

    .isInitLeak = 0,

    .isSignalInit = 0,

    .isKcovInit = 0,
};



SThread g_thread =  
{
    .setSeed = 0, 
    .setTime = 100, 
    .setCount = 1000000,
    .setTestCaseName = "test",
    .setmode = 0,

    .memHasInit = 0,

    .isfirst = 0,

    .testcasePassiveNow = NULL,
}; 


void CF_SetMaxParaNumber(int number)
{
    g_global.setMaxParaNumber = number;
    return;
}

void CF_SetMaxMutatorLen(int len)
{
    g_global.setMaxMutatorLen = len;
    return;
}

void CF_SetMaxPcNumber(int number)
{
    g_global.setMaxPcNumber = number;
    return;
}

void CF_SetMaxCorpusNumber(int number)
{
    g_global.setMaxCorpusNumber = number;
    return;
}

void CF_SetEnableLeak(int enable)
{
    g_global.setEnableLeak = enable;
    return;
}

void CF_SetDebugLeak(int enable)
{
    g_global.setDebugLeak = enable;
    return;
}


void CF_SetReportPath(char* path)
{
    report_setPath(path);
    return;
}

void CF_SetTimeOut(int time)
{
    g_global.setTimeout = time;
    return;
}

void CF_SetCloseAllMutator(void)
{
    in_mutatorInit();

    int i;
    for (i = 0; i< MMax; i++)
    {
        if(g_global.g_mutatorModule[i] == NULL)
            continue;

        g_global.g_mutatorModule[i]->isOpen = Return_No;
    }
    return;
}
void CF_SetOpenOneMutator(int noM, int value)
{
    in_mutatorInit();

    if(g_global.g_mutatorModule[noM] == NULL)
        return;

    g_global.g_mutatorModule[noM]->isOpen = value;
    return;
}

void CF_SetOneMutatorWeight(int noM, int weight)
{
    in_mutatorInit();

    if(g_global.g_mutatorModule[noM] == NULL)
        return;

    g_global.g_mutatorModule[noM]->weight = weight;
    return;
}

void CF_SetCorpusWeight(int mode, int weight)
{
    if (mode == 1)
        g_global.setPcWeight = weight;

    if (mode == 2)
        g_global.setEdgeWeight = weight;

    if (mode == 3)
        g_global.setCycleWeight = weight;

    if (mode == 4)
        g_global.setPathWeight = weight;
}

void CF_SetCloseAllParaMutator(int no)
{
    int i;
    for (i = 0; i< MMax; i++)
    {
        g_thread.para[no].isMClose[no] = Return_Yes;
    }
    return;
}
void CF_SetOpenOneParaMutator(int no, int noM, int value)
{
    g_thread.para[no].isMClose[noM] = value;
    return;
}


void CF_SetParaMutatorFrequency(int no, int number)
{
    g_thread.para[no].mutatorFrequency = number;
    return;
}

void CF_CrashShow(void)
{
    report_andCrashWrite("Manual");
    return;
}

void CF_SetNewFeacher(int weight)
{
    if (weight)
    {
        g_thread.hasNewFeather = 1;
        g_thread.featherWeight +=weight;
    }
    return;
}

void CF_SetCheckLargeMemorySize(int size)
{
    g_global.SetCheckLargeMemorySize = size;
    return;
}

void CF_SetCheckLargeMemoryUse(int size)
{
    g_global.SetCheckLargeMemoryUse = size;
    return;
}

void CF_SetPrintCrashCorpus(int enable)
{
    g_global.SetPrintCrashCorpus = enable;
    return;
}

void CF_SetInBinCorpusPath(char* path)
{
    g_global.setInBinCorpusPath = path;
    return;
}

void CF_SetOutBinCorpusPath(char* path)
{
    g_global.setOutBinCorpusPath = path;
    return;
}

void CF_SetEnableScheduleMutatorWeight(int enable)
{
    g_global.setEnableScheduleMutatorWeight = enable;
    return;
}


void CF_SetRunSeed(int seed)
{
    g_thread.setSeed = seed;
    return;
}

void CF_SetRunTime(int time)
{
    g_thread.setTime = time;
    return;
}

int g_runcount = 0;
int g_count = 0;
void CF_SetRunCount(u64 count)
{
    g_thread.setCount = count;
    return;
}

void CF_SetTestCaseName(char* name)
{
    g_thread.setTestCaseName = name;

    g_thread.setTestCasePath[0] = 0;
    PL_sprintf(g_thread.setTestCasePath, "%s/%s",g_cfCorpusPath, g_thread.setTestCaseName);
    return;
}

void CF_SetRunMode(int mode)
{
    g_thread.setmode = mode;
    return;
}

#ifdef __cplusplus
}
#endif


