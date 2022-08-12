/*************************************************************************************************************
wanghao creat at beijing in 2022
6482543@qq.com
License. See LICENSE for details.

v.1.0.0 2022-08-12
*************************************************************************************************************/

#ifndef Codefuzzer_H
#define Codefuzzer_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


#ifdef __cplusplus
extern "C"{
#endif

/*************************************************************************************************************
define
*************************************************************************************************************/
#ifndef u8
typedef uint8_t  u8;
#endif
#ifndef u16
typedef uint16_t u16;
#endif
#ifndef u32
typedef uint32_t u32;
#endif
#ifndef u64
typedef uint64_t u64;
#endif
#ifndef s8
typedef int8_t 	s8;
#endif
#ifndef s16
typedef int16_t s16;
#endif
#ifndef s32
typedef int32_t s32;
#endif
#ifndef s64
typedef int64_t s64;
#endif

#define CF_Mode_IO
#define CF_Mode_Leak
#define CF_Mode_Hook
#define CF_Mode_TracePc
#define CF_Mode_Crash
#define CF_Mode_CorpusTxt


#ifndef _WIN32
//#define CF_Mode_Kcov  //�ں˰�װ��kcov֮���ٴ�
#define CF_Mode_CMD
#define CF_Mode_CorpusBin

#endif

/*************************************************************************************************************
config
*************************************************************************************************************/
extern void CF_SetMaxParaNumber(int number);
extern void CF_SetMaxMutatorLen(int len);
extern void CF_SetMaxPcNumber(int number);
extern void CF_SetMaxCorpusNumber(int number);

extern void CF_SetEnableLeak(int enable);
//Ĭ�Ϲر�----0�ر� 1��ӡ�����ͷŹ���2��ӡ�����ͷ�ջ
extern void CF_SetDebugLeak(int enable);

extern void CF_SetReportPath(char* path);

//����������ʱ����bug��ʱ�䣬Ĭ��180��
extern void CF_SetTimeOut(int time);


extern void CF_SetCloseAllMutator(void);
//1��  0�ر�
extern void CF_SetOpenOneMutator(int noM, int value);

//���ñ����㷨Ȩ��
extern void CF_SetOneMutatorWeight(int noM, int weight);

//��������Ȩ��
//Ĭ�� 1  pc 30, 2 edge 3 , 3 cycle 10, 4 path 1
extern void CF_SetCorpusWeight(int mode, int weight);


extern void CF_SetCloseAllParaMutator(int no);
//0 ��  1 �ر�
extern void CF_SetOpenOneParaMutator(int no, int noM, int value);



//0Ϊ����������죬101Ϊ�����죬1-100Ϊ����Ƶ�ʱ��죬Ĭ��Ϊ0
extern void CF_SetParaMutatorFrequency(int no, int number);


extern void CF_Cmd(int argc,char *argv[]);
extern void CF_CrashShow(void);

//weightΪ0Ϊû�������������Ч��Ȩ���ۼӣ�   ֻ����ѭ�����е�����Ч
extern void CF_SetNewFeacher(int weight);

//���ü�ش��ڴ���䣬MΪ��λ   0Ϊ�����,Ĭ��1024M
extern void CF_SetCheckLargeMemorySize(int size);

//���ü�ش��ڴ�ʹ�ã�MΪ��λ   0Ϊ�����,Ĭ��1024M
extern void CF_SetCheckLargeMemoryUse(int size);

//��ָ��crash��ӡ�����ڣ�Ĭ�Ͽ���
extern void CF_SetPrintCrashCorpus(int enable);

//��ֻ��һ��������������blobʱ��֧������bin����·��
extern void CF_SetInBinCorpusPath(char* path);
extern void CF_SetOutBinCorpusPath(char* path);

//һЩ���ȱ��죬�ٿ�ʼ100�����ʱ���ͱ���Ȩ�أ�����߱����ٶ�
extern void CF_SetEnableScheduleMutatorWeight(int enable);

/*************************************************************************************************************
getvalue
*************************************************************************************************************/
//���ó�ʼ�������ֱ��죬��Getϵ�к���֮ǰ���ã�������ʱ������Ҫ����
extern void	 CF_SetMutatorPos(int no, int enable, int pos, int len, int minLen, int maxLen);

/* char* blob = CF_GetBlob(2, "123457", 6, 0, 1000) */
//int len = CF_GetMutatorLen(2);
extern int   CF_GetMutatorLen(int no);
extern char* CF_GetS8( int no, s8 initValue);
extern char* CF_GetS16(int no, s16 initValue);
//int a = *(s32*)CF_GetS32(0, 0x345678);
extern char* CF_GetS32(int no, s32 initValue);
extern char* CF_GetS64(int no, s64 initValue);
extern char* CF_GetU8( int no, u8 initValue);
extern char* CF_GetU16(int no, u16 initValue);
extern char* CF_GetU32(int no, u32 initValue);
extern char* CF_GetU64(int no, u64 initValue);
extern char* CF_GetFloat(int no, float initValue);
extern char* CF_GetDouble(int no, double initValue);

//��Χ���죬�����߽�ֵ
//CF_GetNumberRange(0, 100, 0, 1000)
extern char* CF_GetNumberRange(int no, s32 initValue, int minValue, int maxValue);

//ֻ��ö����߱���
//int table[] = {5678,55555,7890123,44444,4321,88888888};
//CF_GetNumberOnlyTable(0,44444, table,6)
extern char* CF_GetNumberOnlyTable(int no, s32 initValue, int* table, int count);

//ֻ��ö����߱���
//int table[] = {5678,55555,7890123,44444,4321,88888888};
//CF_GetNumberOutOfTable(0,12345, table,6)
extern char* CF_GetNumberOutOfTable(int no, s32 initValue, int* table, int count);

//��ö��Ϊ��ʼֵ����
//int table[] = {5678,55555,7890123,44444,4321,88888888};
//CF_GetNumberBasedOnTable(0,44444, table,6)
extern char* CF_GetNumberBasedOnTable(int no, s32 initValue, int* table, int count);

/* char* string = CF_GetString(0, "changchu!", 10, 0, 1000)*/
extern char* CF_GetString(int no, char* initValue, int initLen, int minLen, int maxLen);

//ֻ��ö����߱���
//char* table[] = {"5678","55555","7890123","44444","4321","88888888"};
//CF_GetStringOnlyTable(0, "55555", 6,0, 1000, table, 6)
extern char* CF_GetStringOnlyTable(int no, char* initValue, int initLen,int minLen, int maxLen, char** table, int count);

//ֻ��ö����߱���
//char* table[] = {"5678","55555","7890123","44444","4321","88888888"};
//CF_GetStringOutOfTable(0, "11111", 6,0, 1000, table, 6)
extern char* CF_GetStringOutOfTable(int no, char* initValue, int initLen,int minLen, int maxLen, char** table, int count);

//��ö��Ϊ��ʼֵ����
//char* table[] = {"5678","55555","7890123","44444","4321","88888888"};
//CF_GetStringBasedOnTable(0, "55555", 6,0, 1000, table, 6)
extern char* CF_GetStringBasedOnTable(int no, char* initValue, int initLen,int minLen, int maxLen, char** table, int count);

/* char* blob = CF_GetBlob(2, "123457", 6, 0, 1000) */
//int len = CF_GetMutatorLen(2);
extern char* CF_GetBlob(int no, char* initValue, int initLen, int minLen, int maxLen);

//ֻ��ö����߱���\
//char* table[] = {"\x05\x06\x07\x00","\x00\xff\xff\x00","7890123","44444","4321","\x00\x00\x00\x00\x00\x00"};
//int tableLen[] = {4, 4, 7, 5, 4, 6};
//CF_GetBlobOnlyTable(3, "44444", 5, 0, 1000, table, tableLen, 6);
extern char* CF_GetBlobOnlyTable(int no, char* initValue, int initLen, int minLen, int maxLen, char** table, int* tablelen, int count);

//ֻ��ö����߱���
//char* table[] = {"\x05\x06\x07\x00","\x00\xff\xff\x00","7890123","44444","4321","\x00\x00\x00\x00\x00\x00"};
//int tableLen[] = {4, 4, 7, 5, 4, 6};
//CF_GetBlobOutOfTable(3, "12345", 5, 0, 1000, table, tableLen, 6);
extern char* CF_GetBlobOutOfTable(int no, char* initValue, int initLen, int minLen, int maxLen, char** table, int* tablelen, int count);

//��ö��Ϊ��ʼֵ����
//char* table[] = {"\x05\x06\x07\x00","\x00\xff\xff\x00","7890123","44444","4321","\x00\x00\x00\x00\x00\x00"};
//int tableLen[] = {4, 4, 7, 5, 4, 6};
//CF_GetBlobBasedOnTable(3, "44444", 5, 0, 1000, table, tableLen, 6);
extern char* CF_GetBlobBasedOnTable(int no, char* initValue, int initLen, int minLen, int maxLen, char** table, int* tablelen, int count);


extern char* CF_GetMySelf(int no, char* initValue, int initLen, int minLen, int maxLen);


/*************************************************************************************************************
for
*************************************************************************************************************/

extern void CF_SetRunSeed(int seed);
extern void CF_SetRunTime(int time);
extern void CF_SetRunCount(u64 count);
extern void CF_SetTestCaseName(char* name);
extern void CF_SetRunMode(int mode);

extern void CF_Start(void);
extern void CF_End(void);
extern void CF_ForStart(void);
extern int  CF_ForEnd(void);

extern void CF_Fork(void);
extern int  CF_IsFather(void);
extern void CF_Exit(void);
extern void CF_Wait(void);
extern int  CF_isOk(void);


#define CodeFuzz_start(seed,time,count,name,mode) \
	{\
		CF_Fork();\
		if (!CF_IsFather())\
		{\
			CF_SetRunSeed(seed);\
			CF_SetRunTime(time);\
			CF_SetRunCount(count);\
			CF_SetTestCaseName(name);\
			CF_SetRunMode(mode);\
			CF_Start();\
			for (;;)\
			{\
				CF_ForStart();\


#define CodeFuzz_end() \
				if (CF_ForEnd() != 0)\
					break;\
			}\
			CF_End();\
			CF_Exit();\
		}\
		CF_Wait();\
	}\

extern char* g_cfTestCaseName;

#define CodeFuzz_start_cmd(name) \
	{\
		CF_Fork();\
		if (!CF_IsFather())\
		{\
			if (g_cfTestCaseName) \
				CF_SetTestCaseName(g_cfTestCaseName);\
			else\
				CF_SetTestCaseName(name);\
			CF_Start();\
			for (;;)\
			{\
				CF_ForStart();\



extern void CF_ForPassive(char* testcase, int mode);
extern void CF_OverPassive(void);


#ifdef __cplusplus
	}
#endif

#endif

