//测试用例一部分来自libfuzzer test

#include <stdio.h>
#include "codefuzzer.h"
#include <gtest/gtest.h>

#ifdef __cplusplus
extern "C"{
#endif
extern void IO_writeFileTail(char* path, char* buf);


extern int LLVMFuzzerTestOneInput1(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput2(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput3(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput4(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput5(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput6(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput7(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput8(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput9(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput10(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput11(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput12(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput13(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput14(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput15(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput16(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput17(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput18(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput19(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput20(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput21(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput22(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput23(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput24(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput25(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput26(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput27(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput28(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput29(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput30(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput31(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput32(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput33(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput34(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput35(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput36(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput37(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput38(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput39(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput40(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput41(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput42(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput43(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput44(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput45(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput46(const uint8_t *Data, size_t Size);
extern int LLVMFuzzerTestOneInput47(const uint8_t *Data, size_t Size);


#ifdef __cplusplus
}
#endif

//!!!
//  ./anner910 --gtest_filter=*AbsNegAndConstant64Test --count=1000000
TEST(fuzzTest, AbsNegAndConstant64Test)
{

	char* name = (char*)"AbsNegAndConstant64Test";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput1((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//!!!
//  ./anner910 --gtest_filter=*AbsNegAndConstantTest --count=1000000
TEST(fuzzTest, AbsNegAndConstantTest)
{

	char* name = (char*)"AbsNegAndConstantTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput2((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//!!!
//  ./anner910 --gtest_filter=*AccumulateAllocationsTest --count=1000000
TEST(fuzzTest, AccumulateAllocationsTest)
{

	char* name = (char*)"AccumulateAllocationsTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput3((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*BufferOverflowOnInput --count=1000000
TEST(fuzzTest, BufferOverflowOnInput)
{

	char* name = (char*)"BufferOverflowOnInput";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput4((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//  ./anner910 --gtest_filter=*CallerCalleeTest --count=1000000
TEST(fuzzTest, CallerCalleeTest)
{

	char* name = (char*)"CallerCalleeTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput5((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//  ./anner910 --gtest_filter=*CounterTest --count=1000000
TEST(fuzzTest, CounterTest)
{

	char* name = (char*)"CounterTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput6((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//  ./anner910 --gtest_filter=*DivTest --count=1000000
TEST(fuzzTest, DivTest)
{

	char* name = (char*)"DivTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput7((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*DSOTestMain --count=1000000
TEST(fuzzTest, DSOTestMain)
{

	char* name = (char*)"DSOTestMain";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput8((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//  ./anner910 --gtest_filter=*FourIndependentBranchesTest --count=1000000
TEST(fuzzTest, FourIndependentBranchesTest)
{

	char* name = (char*)"FourIndependentBranchesTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput9((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//  ./anner910 --gtest_filter=*FullCoverageSetTest --count=1000000
TEST(fuzzTest, FullCoverageSetTest)
{

	char* name = (char*)"FullCoverageSetTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput10((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//  ./anner910 --gtest_filter=*LeakTest --count=1000000
TEST(fuzzTest, LeakTest)
{

	char* name = (char*)"LeakTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput11((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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



//  ./anner910 --gtest_filter=*LeakTimeoutTest --count=1000000
TEST(fuzzTest, LeakTimeoutTest)
{

	char* name = (char*)"LeakTimeoutTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput12((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//!!!
//  ./anner910 --gtest_filter=*LoadTest --count=1000000
TEST(fuzzTest, LoadTest)
{

	char* name = (char*)"LoadTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput13((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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




//  ./anner910 --gtest_filter=*MemcmpTest14 --count=1000000
TEST(fuzzTest, MemcmpTest14)
{

	char* name = (char*)"MemcmpTest14";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput14((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*NthRunCrashTest --count=1000000
TEST(fuzzTest, NthRunCrashTest)
{

	char* name = (char*)"NthRunCrashTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput15((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*NullDerefOnEmptyTest --count=1000000
TEST(fuzzTest, NullDerefOnEmptyTest)
{

	char* name = (char*)"NullDerefOnEmptyTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput16((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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



//  ./anner910 --gtest_filter=*NullDerefTest --count=1000000
TEST(fuzzTest, NullDerefTest)
{

	char* name = (char*)"NullDerefTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput17((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//  ./anner910 --gtest_filter=*OneHugeAllocTest --count=1000000
TEST(fuzzTest, OneHugeAllocTest)
{

	char* name = (char*)"OneHugeAllocTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput18((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*OutOfMemorySingleLargeMallocTest --count=1000000
TEST(fuzzTest, OutOfMemorySingleLargeMallocTest)
{

	char* name = (char*)"OutOfMemorySingleLargeMallocTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput19((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//  ./anner910 --gtest_filter=*OutOfMemoryTest --count=1000000
TEST(fuzzTest, OutOfMemoryTest)
{

	char* name = (char*)"OutOfMemoryTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput20((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*RepeatedBytesTest --count=1000000
TEST(fuzzTest, RepeatedBytesTest)
{

	char* name = (char*)"RepeatedBytesTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput21((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*RepeatedMemcmp --count=1000000
TEST(fuzzTest, RepeatedMemcmp)
{

	char* name = (char*)"RepeatedMemcmp";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput22((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//!!!
//  ./anner910 --gtest_filter=*ShrinkControlFlowTest --count=1000000
TEST(fuzzTest, ShrinkControlFlowTest)
{

	char* name = (char*)"ShrinkControlFlowTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput23((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//!!!
//  ./anner910 --gtest_filter=*ShrinkValueProfileTest --count=1000000
TEST(fuzzTest, ShrinkValueProfileTest)
{

	char* name = (char*)"ShrinkValueProfileTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput24((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//!!!
//  ./anner910 --gtest_filter=*SignedIntOverflowTest --count=1000000
TEST(fuzzTest, SignedIntOverflowTest)
{

	char* name = (char*)"SignedIntOverflowTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput25((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*SimpleCmpTest --count=1000000
TEST(fuzzTest, SimpleCmpTest)
{

	char* name = (char*)"SimpleCmpTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput26((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*SimpleDictionaryTest --count=1000000
TEST(fuzzTest, SimpleDictionaryTest)
{

	char* name = (char*)"SimpleDictionaryTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput27((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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



//  ./anner910 --gtest_filter=*SimpleHashTest --count=1000000
TEST(fuzzTest, SimpleHashTest)
{

	char* name = (char*)"SimpleHashTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput28((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*SimpleTest --count=1000000
TEST(fuzzTest, SimpleTest)
{

	char* name = (char*)"SimpleTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput29((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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



//  ./anner910 --gtest_filter=*SimpleThreadedTest --count=1000000
TEST(fuzzTest, SimpleThreadedTest)
{

	char* name = (char*)"SimpleThreadedTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput30((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*SingleMemcmpTest --count=1000000
TEST(fuzzTest, SingleMemcmpTest)
{

	char* name = (char*)"SingleMemcmpTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput31((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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



//  ./anner910 --gtest_filter=*SingleStrcmpTest --count=1000000
TEST(fuzzTest, SingleStrcmpTest)
{

	char* name = (char*)"SingleStrcmpTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput32((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*SingleStrncmpTest --count=1000000
TEST(fuzzTest, SingleStrncmpTest)
{

	char* name = (char*)"SingleStrncmpTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput33((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//!!!
//  ./anner910 --gtest_filter=*SpamyTest --count=1000000
TEST(fuzzTest, SpamyTest)
{

	char* name = (char*)"SpamyTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput34((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*StrcmpTest35 --count=1000000
TEST(fuzzTest, StrcmpTest35)
{
	char* name = (char*)"StrcmpTest35";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput35((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*StrncmpOOBTest --count=1000000
TEST(fuzzTest, StrncmpOOBTest)
{
	char* name = (char*)"StrncmpOOBTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput36((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*StrncmpTest37 --count=1000000
TEST(fuzzTest, StrncmpTest37)
{
	char* name = (char*)"StrncmpTest37";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput37((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*StrstrTest --count=1000000
TEST(fuzzTest, StrstrTest)
{
	char* name = (char*)"StrstrTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput38((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//  ./anner910 --gtest_filter=*SwapCmpTest --count=1000000
TEST(fuzzTest, SwapCmpTest)
{
	char* name = (char*)"SwapCmpTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput39((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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



//  ./anner910 --gtest_filter=*Switch2Test --count=1000000
TEST(fuzzTest, Switch2Test)
{
	char* name = (char*)"Switch2Test";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput40((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*SwitchTest --count=1000000
TEST(fuzzTest, SwitchTest)
{
	char* name = (char*)"SwitchTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput41((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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



//  ./anner910 --gtest_filter=*ThreadedLeakTest --count=1000000
TEST(fuzzTest, ThreadedLeakTest)
{
	char* name = (char*)"ThreadedLeakTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput42((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//!!!
//  ./anner910 --gtest_filter=*ThreadedTest43 --count=1000000
TEST(fuzzTest, ThreadedTest43)
{
	char* name = (char*)"ThreadedTest43";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput43((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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



//  ./anner910 --gtest_filter=*TimeoutEmptyTest --count=1000000
TEST(fuzzTest, TimeoutEmptyTest)
{
	char* name = (char*)"TimeoutEmptyTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput44((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//  ./anner910 --gtest_filter=*TimeoutTest45 --count=1000000
TEST(fuzzTest, TimeoutTest45)
{
	char* name = (char*)"TimeoutTest45";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput45((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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

//no
//  ./anner910 --gtest_filter=*TraceMallocTest --count=1000000
TEST(fuzzTest, TraceMallocTest)
{
	char* name = (char*)"TraceMallocTest";
    printf("%s start\r\n",name);

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)"44444", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);
		LLVMFuzzerTestOneInput46((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


//no
//  ./anner910 --gtest_filter=*TestAdd --count=1000000
TEST(fuzzTest, TestAdd)
{
	char* name = (char*)"TestAdd";
    printf("%s start\r\n",name);

	char aaa[10] = {0};

	CodeFuzz_start_cmd(name)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* a = CF_GetBlob(0,(char*)aaa, 10, 0, 1000);
		int len = CF_GetMutatorLen(0);
		
		LLVMFuzzerTestOneInput47((const uint8_t *)a, len);
	}
	CodeFuzz_end()

	if(CF_isOk())
	{
		char tempbuf[256];
		tempbuf[0] = 0;
		sprintf(tempbuf, "%s is not found branch----------------\r\n",name);
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


