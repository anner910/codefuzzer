#ifndef Code_H
#define Code_H

#include "../codefuzzer.h"

#ifdef __cplusplus
extern "C"{
#endif

#define MIN(_a,_b) ((_a) > (_b) ? (_b) : (_a))
#define MAX(_a,_b) ((_a) > (_b) ? (_a) : (_b))


#define PL_random_range(min,max) 	((min) + PL_random()%((max) - (min) +1))
#define PL_random_byte() 			(PL_random() % 256)
#define PL_random_64() 				(((0ULL | PL_random())<<33) | ((0ULL | PL_random())<<2) | ((PL_random())&3))
#define PL_random_range_64(min,max) ((min) + PL_s64_divMode(PL_random_64(), ((max) - (min) + 1)))

#define BitFill(_a,_b)    \
		do{\
		char* _bf = (char*)(_a);\
		u32 _pos = (_b);\
		_bf[_pos>>3] |= (128 >> (_pos & 7));\
		}while(0);

#define BitZero(_a,_b)    \
		do{\
		char* _bf = (char*)(_a);\
		u32 _pos = (_b);\
		_bf[_pos>>3] &= ~(128 >> (_pos & 7));\
		}while(0);

#define BitFlip(_a,_b)    \
		do{\
		char* _bf = (char*)(_a);\
		u32 _pos = (_b);\
		_bf[_pos>>3] ^= (128 >> (_pos & 7));\
		}while(0);


#define Pc_Weight 			50
#define PcEdge_Weight 		3
#define PcCycle_Weight 		30
#define PcPath_Weight 		1


#define Switch_Count 		200
#define Wash_Count 			10000

#define Corpus_MaxNumber 	5000
#define Para_MaxNumber 		256
#define Buf_MaxLength 		10000000

#define Pc_MaxNumber 		(1<<20)


#define Default_TimeOut 	600

#define Mutator_BaseWeight 	1000


#define Number_HookCount 	40000
#define Blob_HookCount 	    10000
#define Blob_HookLength 	40

#define Exit_No_LargeMemorySize   100
#define Exit_No_LargeMemoryUse    101
#define Exit_No_LeakCheck    	  102
#define Exit_No_Crash    	      103

void PL_sprintf();

//

#define PL_printf(fmt, ...)  		printf(fmt, ##__VA_ARGS__)
#define PL_sprintf(buf, fmt, ...)  	sprintf(buf, fmt, ##__VA_ARGS__)

extern char* g_cfCorpusPath;
extern int   g_cfMaxLen;




//数据类型
enum DataType
{
	DataType_u8 = 0, 
	DataType_u16, 
	DataType_u32, 
	DataType_u64, 
	DataType_s8, 
	DataType_s16, 
	DataType_s32, 
	DataType_s64, 
	DataType_float,
	DataType_double,

	DataType_NumberRange,
	DataType_NumberOnlyTable,
	DataType_NumberOutOfTable,
	DataType_NumberBasedOnTable,

	DataType_myself,
	
	DataType_string,
	DataType_stringOnlyTable,
	DataType_stringOutOfTable,
	DataType_stringBasedOnTable,

	DataType_blob,
	DataType_blobOnlyTable,
	DataType_blobOutOfTable,
	DataType_blobBasedOnTable,
	
	DataType_max, 
};

extern char* dataTypeName[];
extern char* mutatorTypeName[];


enum MutatorType
{
	MBlobDict = 0,
	MBlobTable,

	MdataBitFill,
	MdataBitMulRandom,
	MdataBitOneRandom,
	MdataBitZero,

	MdataByteMulInsert,
	MdataByteMulRandom,
	MdataByteOneInsert,
	MdataByteOneRandom,

	MdataCorpusSwap,

	MdataLengthExtendMagicMem,
	MdataLengthExtendSpecific,
	MdataLengthRepeatSelfInsert,
	MdataLengthRepeatSelfTail,

	MdataMemoryDictBlob,
	MdataMemoryDictString,
	MdataMemoryHook,
	MdataMemoryNumberString,
	MdataMemoryOtherCorpus,
	MdataMemoryStaticString,

	MdataNumberChange,
	MdataNumberDict,
	MdataNumberHook,
	MdataNumberSelf,
	MdataNumberSize,
	MdataNumberString,

	MdataReduce,

	MdataSelfToOther,
	MdataSelfToSelf,
	
	MdataStringCase,
	
	MNumberEdge,
	MNumberGauss,
	MNumberLittleRandom,
	MNumberMagic,
	MNumberRandom,
	MNumberRange,
	MNumberSwap,
	MNumberTable,

	MSelf,
	MStringDict,
	MStringHook,
	MStringTable,

	MNoMutator,

	MMax,
};

enum ReturnType
{
	Return_No = 0, 
	Return_Yes = 1,
};

typedef struct {
	int dataType;
	int len;
	char* value;

} SParaValue;

typedef struct {
	int isInit;
	SParaValue paraValue;

	int mutatorInitlen;
	char* mutatorInitvalue;
	int isMutatorInitNeedFree;

	int Initlen;
	char* Initvalue;
	int isInitNeedFree;

	int minlen;
	int maxlen;

	//
	int minValue; 
	int maxValue;

	int* table;
	int  count;

	char** table1;
	int*  tablelen;


	int idNeedFree;

	int mutatorFrequency;

	//
	int mutatorPosEnalbe;
	int mutatorPos;
	int mutatorLen;
	int mutatorminlen;
	int mutatormaxlen;

	int setmutatorPos;
	int setmutatorLen;
	int setmutatorminlen;
	int setmutatormaxlen;
	

	union{
	s8 		u_s8;
	s16 	u_s16;
	s32 	u_s32;
	s64 	u_s64;
	u8 		u_u8;
	u16 	u_u16;
	u32 	u_u32;
	u64 	u_u64;
	float 	u_float;
	double 	u_double;
	}u;

	//变异算法相关
	int isMSupport[MMax];
	int isMClose[MMax];
	int MStartPos[MMax];
	int MEndPos[MMax];

	int MAllCount;

	int mutator;
	
} SPara;


typedef struct {
	char* name;
	int (*getCount)(SPara*);
	char* (*getValue)(SPara*, int);
	int (*getSupport)(SPara*);

	int isOpen;
	int weight;
} SMutator;


typedef struct {

	//config
	int setMaxParaNumber;
	int setMaxMutatorLen;
	int setMaxPcNumber;
	int setMaxCorpusNumber;
	int setEnableLeak;
	int setDebugLeak;

	int setPcWeight;
	int setEdgeWeight;
	int setCycleWeight;
	int setPathWeight;

	int SetCheckLargeMemorySize;
	int SetCheckLargeMemoryUse;
	int SetPrintCrashCorpus;

	char* setInBinCorpusPath;
	char* setOutBinCorpusPath;
	int setEnableScheduleMutatorWeight;
	
	char setReportPath[256];
	
	int setTimeout;

	SMutator* g_mutatorModule[MMax];

	//leak
	int isInitLeak;

	//crash
	int isSignalInit;

	//kcov
	int isKcovInit;

} SGlobal;

extern SGlobal g_global;

typedef struct {
	int isNeedFree;
	SParaValue* paraValue;

	int corpusWeight;
	uintptr_t corpusHash;
	int isBeenWash;
} SCorpus;


typedef struct {
	u64 numberA[Number_HookCount];
	u64 numberB[Number_HookCount];
	int numberIdx[Number_HookCount];
	int numberIsHave[Number_HookCount];

	int lenA[Blob_HookCount];
	int lenB[Blob_HookCount];
	char blobA[Blob_HookCount][Blob_HookLength];
	char blobB[Blob_HookCount][Blob_HookLength];
	int blobIdx[Blob_HookCount];
	int blobIsHave[Blob_HookCount];
	
} ShookData;

typedef struct {

	uintptr_t* 	trace_pc;

	uintptr_t* 	trace_pc_count;
	int* 		trace_pc_count_bit;
	int* 		idx;
	int 		idxCount;
	
	uintptr_t* 	trace_pc_edge;
	uintptr_t* 	trace_pc_hash;
	uintptr_t   hash;
	uintptr_t  	old_pc;
}Sllvm;


typedef struct {

	//config
	int setSeed;
	int setTime;
	u64 setCount;
	char* setTestCaseName;
	char setTestCasePath[512];
	int setmode;
	
	//temp
	int isfirst;
	s64 runCount;
	int paraNumber;

	char* tempbuf;
	

	char* mutatorBuf;
	SPara* para;

	int memHasInit;

	int pid;
	int run_ok;
	int runSeed;

	int isHasCrash;

	int isSelfExit;
	//llvm
	Sllvm llvm;
	int hasNewFeather;
	int featherWeight;

	int llvmEnable;
	int pcTotal;
	int cycleTotal;
	int edgeTotal;
	int hashTotal;

	//corpus
	SCorpus* corpus;
	int corpusNumber;
	int highCorpusNumber;

	int tempCorpusNo;
	int tempParaNo;

	int isNeedRecordCorpus;
	int isMustRecordCorpus;
	int isNeedWriteCorpus;

	int isNoNeedMutator;

	int isNeedPrintfCorpus;

	//wash
	int isWashing;
	int washCorpusPos;
	int washParaPos;
	int washLen;
	uintptr_t   washhash;
	uintptr_t   temp_hash;

	int isruncorpus;
	int isruncorpusNo;


	//schedule
	short *tokenH;
	short *tokenM;
	short *tokenL;

	int tokenHpos;
	int tokenMpos;
	int tokenLpos;

	int tokenHtotal;
	int tokenMtotal;
	int tokenLtotal;


	//hook
	ShookData* hookData;
	int numNumber;
	int blobNumber;

	//timeout
	int startTime;

	int mallocCount;
	int freeCount;
	int internalOperation;
	int checkCount;

	//passive
	char* testcasePassiveNow;

} SThread;

extern SThread g_thread;

//init
extern void MdataBitFillInit(void);
extern void MdataBitMulRandomInit(void);
extern void MdataBitOneRandomInit(void);
extern void MdataBitZeroInit(void);

extern void MdataByteMulInsertInit(void);
extern void MdataByteMulRandomInit(void);
extern void MdataByteOneInsertInit(void);
extern void MdataByteOneRandomInit(void);

extern void MdataCorpusSwapInit(void);

extern void MdataLengthExtendMagicMemInit(void);
extern void MdataLengthExtendSpecificInit(void);
extern void MdataLengthRepeatSelfInsertInit(void);
extern void MdataLengthRepeatSelfTailInit(void);


extern void MdataMemoryDictBlobInit(void);
extern void MdataMemoryDictStringInit(void);
extern void MdataMemoryHookInit(void);
extern void MdataMemoryNumberStringInit(void);
extern void MdataMemoryOtherCorpusInit(void);
extern void MdataMemoryStaticStringInit(void);

extern void MdataNumberChangeInit(void);
extern void MdataNumberDictInit(void);
extern void MdataNumberHookInit(void);
extern void MdataNumberSelfInit(void);
extern void MdataNumberSizeInit(void);
extern void MdataNumberStringInit(void);

extern void MdataReduceInit(void);

extern void MdataSelfToOtherInit(void);
extern void MdataSelfToSelfInit(void);

extern void MdataStringCaseInit(void);
extern void MNoMutatorInit(void);


extern void MdataHookInit(void);


extern void MNumberEdgeInit(void);
extern void MNumberGaussInit(void);
extern void MNumberLittleRandomInit(void);
extern void MNumberMagicInit(void);
extern void MNumberRandomInit(void);
extern void MNumberRangeInit(void);
extern void MNumberSwapInit(void);
extern void MNumberTableInit(void);


extern void MSelfInit(void);
extern void MStringTableInit(void);
extern void MBlobTableInit(void);

//internal
extern void in_mutatorInit(void);

extern void in_seed_init(void);
extern void in_seed(int runcount);

extern void in_mutatorParaInit(SPara* para);
extern u32 in_getGuassRandom(u32 max);
extern s64 in_getGuassRandoms64(int len);
extern u32 in_getWeightRandom(u32 max);


extern u64 in_getMagicNumber(void);
extern void in_getCorpusBlob(char** blob,int *len);
extern void in_getMagicBlob(char** blob,int *len);
extern int in_getLen(SPara* para, int pos);
extern u32 in_getParaCrc(void);
extern int in_getParaHash(void);
extern s64 in_getRunCount(void);
extern int in_scheduleMutatorWeight(int weight);


extern void in_ParaMutatorNumberReplace64(char* buf, int len, s64 number);
extern void in_ParaMutatorNumberReplace32(char* buf, int len, s32 number);
extern void in_ParaMutatorNumberReplace16(char* buf, int len, s16 number);
extern void in_ParaMemoryMutator(SPara* para, int pos, char* buf, int len);




//mutatorRevise
extern char* in_mutatorParaGetValue(SPara* para);



//memory
extern void in_memoryClearParaMutatorBuf(void);
extern void in_memoryClearParaInitBuf(void);


extern void in_memoryInit(void);
extern void in_memoryCleanfor(void);
extern void in_memoryClean(void);

extern void in_mutatorParaGetInitBuf(SPara* para);
extern void in_mutatorParaGetBuf(SPara* para);

extern void in_InitBuf(SPara* para, char* value, int len);




//platform
extern void  PL_getData(char* date);
extern void  PL_setTimer(int Seconds);
extern int   PL_getTime(void);
extern void  PL_seed(int setSeed);
extern int   PL_random(void);
extern void* PL_malloc(size_t size);
extern void  PL_free(void* s);
extern void* PL_memset(void *s,int ch,size_t n);
extern void* PL_memcpy(void *d,void *s,size_t n);

extern s64   PL_s64_divMode(s64 a,s64 b);
extern uint8_t  Bswap8(uint8_t x);
extern uint16_t Bswap16(uint16_t x);
extern uint32_t Bswap32(uint32_t x);
extern uint64_t Bswap64(uint64_t x);

extern int PL_fork(void);
extern void PL_exit(int no);
extern int PL_wait(int* sta);
extern void PL_sleep(int second);
extern size_t PL_GetPeakRSSMb(void);
extern void PL_pthread_create(void* fun);



//corpus
extern void corpus_getSwitch(void);
extern void corpus_start(void);
extern void corpus_end(void);

//txt
extern void corpus_readTxt(void);
extern void corpus_writeTxt(char* path, int corpusNo);

//bin
extern void corpus_ReadBin(void);
extern void corpus_WriteBin(int corpusNo);



//trace-pc
extern int llvm_isHasFeacher(void);
extern void llvm_ClearFeacher(void);
extern int llvm_getWeight(void);

extern void llvm_doTracePc(uintptr_t PC);
extern void llvm_do(void);


//io
extern void IO_readFile(char* path, char** buf, int* len);
extern void IO_writeFileTail(char* path, char* buf);
extern void IO_writeFile(char* path, char* buf, int len);


extern void do_addNumber(uintptr_t pc, u64 a, u64 b);
extern void do_addBlob(uintptr_t pc,const char* a,int lenA,const char* b, int lenB);

extern u64 do_GetHookNumber(void);
extern void do_GetHookBlob(char** blob,int *len);


//crash
extern void SetSignalHandler(void);


//schedule
extern int schedule_paraIsNeedMutator(SPara* para);
extern int schedule_corpusGetTokenTotalH(void);
extern int schedule_corpusGetTokenTotalM(void);
extern int schedule_corpusGetTokenTotalL(void);
extern int schedule_corpus(void);
extern void schedule_corpusAddToken(int corpusNo, int weight);

//leak
extern void leak_init(void);
extern void leak_do(void);

//kcov
extern void kcov_init(void);
extern void kcov_start(void);
extern void kcov_end(void);
extern void kcov_clean(void);

//report
extern void report_setPath(char* path);
extern void report_addTestCase(char* reason);
extern void report_andCrashWrite(char* reason);
extern void report_asan(char* report);


//dict
extern u64 dict_GetNumber(void);
extern void dict_GetStatic(char** blob,int *len);
extern void dict_GetString(char** blob,int *len);
extern void dict_GetBlob(char** blob,int *len);


//other
__attribute__((weak))  uintptr_t __asan_get_report_pc();
__attribute__((weak)) char * __asan_get_report_description();
__attribute__((weak)) void __asan_set_error_report_callback(void (*callback)( char*));
__attribute__((weak)) int __sanitizer_install_malloc_and_free_hooks
		(void (*malloc_hook)(const void *,size_t),void (*free_hook)(const void *));
__attribute__((weak)) int __lsan_do_recoverable_leak_check(void);
__attribute__((weak)) void __lsan_disable(void);
__attribute__((weak)) void __lsan_enable(void);

__attribute__((weak)) int __sanitizer_print_memory_profile(size_t a, size_t b);
__attribute__((weak)) int __sanitizer_print_stack_trace(void);


//support

extern int support(int type, int mutator);


//lib


extern int   lib_isprint(u8 v);
extern int   lib_isspace(u8 v);
extern int   lib_isxdigit(u8 v);
extern int   lib_isdigit(u8 v);
extern long  lib_strtol(const char * nptr, char ** endptr, int base);
extern char* lib_itoa(int num,char* str,int radix);

extern int   lib_memcmp(void *d,void *s,size_t n);
extern int   lib_strcmp(void *d,void *s);
extern int   lib_strnlen(const char* s, int len);
extern int   lib_strlen(const char* s);
extern int   lib_strlen1(const char* s,const char* s1);
extern u32   lib_getTotalBit(u32 max);
extern int   lib_atoi(const char *nptr);





#ifdef __cplusplus
	}
#endif

#endif

