
#include <stdio.h>
#include "codefuzzer.h"
#include "../../codefuzzer/core/Core.h"
#include <gtest/gtest.h>


#ifdef __cplusplus
extern "C"{
#endif
extern void IO_writeFileTail(char* path, char* buf);

extern void blob0(char* blob, int len);

extern void dataa0(char* data, int len);
extern void dataa1(char* data, int len);
extern void dataa2(char* data, int len);
extern void dataa3(char* data, int len);
extern void dataa4(char* data, int len);
extern void dataa5(char* data, int len);
extern void dataa6(char* data, int len);
extern void dataa7(char* data, int len);
extern void dataa8(char* data, int len);
extern void dataa9(char* data, int len);
extern void dataa10(char* data, int len);

extern void dataa11(char* data, int len);
extern void dataa12(char* data, int len);
extern void dataa133(char* data, int len);
extern void dataa13(char* data, int len);
extern void dataa14(char* data, int len);
extern void dataa15(char* data, int len);
extern void dataa16(char* data, int len);


extern void datab0(char* data, int len);
extern void datab1(char* data, int len);
extern void datab2(char* data, int len);
extern void datab3(char* data, int len);
extern void datab4(char* data, int len);
extern void datab5(char* data, int len);
extern void datab6(char* data, int len);
extern void datab7(char* data, int len);
extern void datab8(char* data, int len);
extern void datab9(char* data, int len);
extern void datab10(char* data, int len);
extern void datab11(char* data, int len);
extern void datab12(char* data, int len);






extern void data10(char* data, int len);
extern void data1010(char* data, int len);
extern void data9(char* data, int len);
extern void data99(char* data, int len);
extern void data8(char* data, int len);
extern void data77(char* data, int len);
extern void data7(char* data, int len);
extern void data6(char* data, int len);
extern void data55(char* data, int len);
extern void data5(char* data, int len);
extern void data4(char* data, int len);
extern void data3(char* data, int len);
extern void data33(char* data, int len);
extern void data2(char* data, int len);
extern void data1(char* data, int len);
extern void data0(char* data, int len);



extern void number4(int num);
extern void number3(int num);
extern void number2(int num);
extern void number11(int num);
extern void number1(int num);
extern void number00(int num);
extern void number0(int num);

extern void string0(char* string);


#ifdef __cplusplus
}
#endif

//./anner910 --gtest_filter=*test_MBlobTable
TEST(fuzzTest, test_MBlobTable)
{

	char* name = (char*)"test_MBlobTable";
    printf("%s start\r\n",name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MBlobTable, 1);//MBlobTable

	char* table[] = {(char*)"5678",(char*)"55555",(char*)"7890123",(char*)"44444",(char*)"4321",(char*)"88888888"};
	int tablelen[] = {4,5,7,5,4,8};
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlobBasedOnTable(0,(char*)"44444", 5, 0, 1000, table, tablelen, 6);
		int len = CF_GetMutatorLen(0);
		blob0(a,len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n",name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n",name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
		

	printf("%s end\r\n",name);
}

//./anner910 --gtest_filter=*test_MdataBitFill
TEST(fuzzTest, test_MdataBitFill)
{
	char* name = (char*)"MdataBitFill";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataBitFill, 1);//MdataBitFill
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"\x00\x00\x00\x00\x00\x00\x00\x00", 8, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa0(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}

//./anner910 --gtest_filter=*test_MdataBitMulRandom
TEST(fuzzTest, test_MdataBitMulRandom)
{
	char* name = (char*)"MdataBitMulRandom";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataBitMulRandom, 1);//MdataBitMulRandom
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0BEIJINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa1(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}



//./anner910 --gtest_filter=*test_MdataBitOneRandom
TEST(fuzzTest, test_MdataBitOneRandom)
{
	char* name = (char*)"MdataBitOneRandom";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataBitOneRandom, 1);//MdataBitOneRandom
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0BEIJINGchun", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa2(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}

//./anner910 --gtest_filter=*test_MdataBitZero
TEST(fuzzTest, test_MdataBitZero)
{
	char* name = (char*)"MdataBitZero";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataBitZero, 1);//MdataBitZero
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"\x00\x00\x00\x00\x00\x0f\xf0\x00", 8, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa3(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}



//./anner910 --gtest_filter=*test_MdataByteMulInsert
TEST(fuzzTest, test_MdataByteMulInsert)
{
	char* name = (char*)"MdataByteMulInsert";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataByteMulInsert, 1);//MdataByteMulInsert
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0BEIJINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa4(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataByteMulRandom
TEST(fuzzTest, test_MdataByteMulRandom)
{
	char* name = (char*)"MdataByteMulRandom";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataByteMulRandom, 1);//MdataByteMulRandom
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0BEIJINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa5(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}



//./anner910 --gtest_filter=*test_MdataByteOneInsert
TEST(fuzzTest, test_MdataByteOneInsert)
{
	char* name = (char*)"MdataByteOneInsert";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataByteOneInsert, 1);//MdataByteOneInsert
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhangEIJINGchun", 15, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa6(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}



//./anner910 --gtest_filter=*test_MdataByteOneRandom
TEST(fuzzTest, test_MdataByteOneRandom)
{
	char* name = (char*)"MdataByteOneRandom";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataByteOneRandom, 1);//MdataByteOneRandom
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhangBEIJINGchun", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa7(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataLengthExtendMagicMem
TEST(fuzzTest, test_MdataLengthExtendMagicMem)
{
	char* name = (char*)"MdataLengthExtendMagicMem";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataLengthExtendMagicMem, 1);//MdataLengthExtendMagicMem
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhangBEIJINGchun", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa8(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataLengthExtendSpecific
TEST(fuzzTest, test_MdataLengthExtendSpecific)
{
	char* name = (char*)"MdataLengthExtendSpecific";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataLengthExtendSpecific, 1);//MdataLengthExtendSpecific
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhangBEIJINGchun", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa9(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataLengthRepeatSelfInsert
TEST(fuzzTest, test_MdataLengthRepeatSelfInsert)
{
	char* name = (char*)"MdataLengthRepeatSelfInsert";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataLengthRepeatSelfInsert, 1);//MdataLengthRepeatSelfInsert
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhangBEIJINGchun", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa10(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataLengthRepeatSelfTail
TEST(fuzzTest, test_MdataLengthRepeatSelfTail)
{
	char* name = (char*)"MdataLengthRepeatSelfTail";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataLengthRepeatSelfTail, 1);//MdataLengthRepeatSelfTail
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhangBEIJINGchun", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa11(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataMemoryDictBlob
TEST(fuzzTest, test_MdataMemoryDictBlob)
{
	char* name = (char*)"MdataMemoryDictBlob";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataMemoryDictBlob, 1);//MdataMemoryDictBlob
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0BEIJINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa12(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataMemoryDictString
TEST(fuzzTest, test_MdataMemoryDictString)
{
	char* name = (char*)"MdataMemoryDictString";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataMemoryDictString, 1);//MdataMemoryDictString
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0BEIJINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa133(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataMemoryHook
TEST(fuzzTest, test_MdataMemoryHook)
{
	char* name = (char*)"MdataMemoryHook";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataMemoryHook, 1);//MdataMemoryHook
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0BEIJINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa13(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataMemoryNumberString
TEST(fuzzTest, test_MdataMemoryNumberString)
{
	char* name = (char*)"MdataMemoryNumberString";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataMemoryNumberString, 1);//MdataMemoryNumberString
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0BEIJINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa14(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataMemoryOtherCorpus
TEST(fuzzTest, test_MdataMemoryOtherCorpus)
{
	char* name = (char*)"MdataMemoryOtherCorpus";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataMemoryOtherCorpus, 1);//MdataMemoryOtherCorpus
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0BEIJINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa15(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataMemoryStaticString
TEST(fuzzTest, test_MdataMemoryStaticString)
{
	char* name = (char*)"MdataMemoryStaticString";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataMemoryStaticString, 1);//MdataMemoryStaticString
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0BEIJINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		dataa16(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataNumberChange
TEST(fuzzTest, test_MdataNumberChange)
{
	char* name = (char*)"MdataNumberChange";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataNumberChange, 1);//MdataNumberChange
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0BEIJINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		datab1(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}

//./anner910 --gtest_filter=*test_MdataNumberDict
TEST(fuzzTest, test_MdataNumberDict)
{
	char* name = (char*)"MdataNumberDict";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataNumberDict, 1);//MdataNumberDict
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0BEIJINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		datab2(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}



//./anner910 --gtest_filter=*test_MdataNumberHook
TEST(fuzzTest, test_MdataNumberHook)
{
	char* name = (char*)"MdataNumberHook";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataNumberHook, 1);//MdataNumberHook
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0BEIJINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		datab3(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataNumberSelf
TEST(fuzzTest, test_MdataNumberSelf)
{
	char* name = (char*)"MdataNumberSelf";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataNumberSelf, 1);//MdataNumberSelf
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0\x39\x57\x36\xf3\x0fINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		datab4(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}



//./anner910 --gtest_filter=*test_MdataNumberSize
TEST(fuzzTest, test_MdataNumberSize)
{
	char* name = (char*)"MdataNumberSize";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataNumberSize, 1);//MdataNumberSize
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0\x39\x57\x36\xf3\x0fINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		datab5(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataNumberString
TEST(fuzzTest, test_MdataNumberString)
{
	char* name = (char*)"MdataNumberString";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataNumberString, 1);//MdataNumberString
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhan0BEIJINGch10", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		datab6(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}



//./anner910 --gtest_filter=*test_MdataReduce
TEST(fuzzTest, test_MdataReduce)
{
	char* name = (char*)"MdataReduce";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataReduce, 1);//MdataReduce
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhangBEIJINGchun", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		datab7(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}



//./anner910 --gtest_filter=*test_MdataSelfToOther
TEST(fuzzTest, test_MdataSelfToOther)
{
	char* name = (char*)"MdataSelfToOther";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataSelfToOther, 1);//MdataSelfToOther
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhangBEIJINGchun", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		datab8(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MdataSelfToSelf
TEST(fuzzTest, test_MdataSelfToSelf)
{
	char* name = (char*)"MdataSelfToSelf";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataSelfToSelf, 1);//MdataSelfToSelf
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhangBEIJINGchun", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		datab9(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}

//./anner910 --gtest_filter=*test_MdataStringCase
TEST(fuzzTest, test_MdataStringCase)
{
	char* name = (char*)"test_MdataStringCase";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MdataStringCase, 1);//MdataStringCase
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"zhangBEIJINGchun", 16, 0, 1000);
		int len = CF_GetMutatorLen(0);

		datab10(blob, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MNumberEdge
TEST(fuzzTest, test_MNumberEdge)
{
	char* name = (char*)"test_MNumberEdge";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MNumberEdge, 1);//MNumberEdge
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a = *(u32*)CF_GetU32(0, 0x345678);

		number4(a);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MNumberGauss
TEST(fuzzTest, test_MNumberGauss)
{
	char* name = (char*)"test_MNumberGauss";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MNumberGauss, 1);//MNumberGauss
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a = *(u32*)CF_GetU32(0, 0x345678);
		number3(a);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}


//./anner910 --gtest_filter=*test_MNumberLittleRandom
TEST(fuzzTest, test_MNumberLittleRandom)
{
	char* name = (char*)"test_MNumberLittleRandom";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MNumberLittleRandom, 1);//MNumberLittleRandom
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a = *(u32*)CF_GetU32(0, 0x345678);
		number2(a);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
		

	printf("%s end\r\n", name);
}

//./anner910 --gtest_filter=*test_MNumberMagic
TEST(fuzzTest, test_MNumberMagic)
{
	char* name = (char*)"test_MNumberMagic";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MNumberMagic, 1);//MNumberMagic
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a = *(u32*)CF_GetU32(0, 0x345678);
		number11(a);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}

//./anner910 --gtest_filter=*test_MNumberRandom
TEST(fuzzTest, test_MNumberRandom)
{
	char* name = (char*)"test_MNumberRandom";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MNumberRandom, 1);//MNumberRandom
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a = *(u32*)CF_GetU32(0, 0x345678);
		number1(a);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);
	}
		

	printf("%s end\r\n", name);
}

//./anner910 --gtest_filter=*test_MNumberSwap
TEST(fuzzTest, test_MNumberSwap)
{
	char* name = (char*)"test_MNumberSwap";
    printf("%s start\r\n", name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MNumberSwap, 1);//MNumberSwap
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a = *(u32*)CF_GetU32(0, 0x345678);
		number00(a);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n", name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
		

	printf("%s end\r\n", name);
}

//./anner910 --gtest_filter=*test_MNumberTable
TEST(fuzzTest, test_MNumberTable)
{

	char* name = (char*)"test_MNumberTable";
    printf("%s start\r\n",name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MNumberTable, 1);//MNumberTable

	int table[] = {5678,55555,7890123,44444,4321,88888888};
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a = *(u32*)CF_GetNumberOnlyTable(0,44444, table,6);
		number0(a);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n",name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n",name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
		

	printf("%s end\r\n",name);
}

//./anner910 --gtest_filter=*test_MStringTable
TEST(fuzzTest, test_MStringTable)
{

	char* name = (char*)"test_MStringTable";
    printf("%s start\r\n",name);

	CF_SetCloseAllMutator();
	CF_SetOpenOneMutator(MStringTable, 1);//MStringTable

	char* table[] = {(char*)"5678",(char*)"55555",(char*)"7890123",(char*)"44444",(char*)"4321",(char*)"88888888"};
	
	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetStringBasedOnTable(0,(char*)"44444", 6, 0, 1000, table, 6);
		string0(a);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch\r\n",name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
	else
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is found branch\r\n",name);
		IO_writeFileTail((char*)"./fuzzResult", tempbuf);

	}
		

	printf("%s end\r\n",name);
}



int main(int argc, char* argv[])
{
	CF_Cmd(argc, argv);
    testing::InitGoogleTest(&argc, argv);

    int result =  RUN_ALL_TESTS();


    return result;
}


