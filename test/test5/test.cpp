
#include <stdio.h>
#include "codefuzzer.h"

#include <gtest/gtest.h>


#ifdef __cplusplus
extern "C"{
#endif


extern void targer(int num, char* blob,int len, char* string);
extern void targer1(int num, char* blob,int len, char* string);

#ifdef __cplusplus
}
#endif


TEST(fuzzTest, Test1)
 {
    printf("Test1 start\r\n");
	
	CodeFuzz_start(0,100,1000000,(char*)"Test1",0)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a = *(u32*)CF_GetU32(0, 0x345678);
		char* string = CF_GetString(1, (char*)"changchu!", 10, 0, 1000);
		char* blob = CF_GetBlob(2, (char*)"123457", 6, 0, 1000);
		int len = CF_GetMutatorLen(2);

		
		targer(a, blob, len, string);
	}
	CodeFuzz_end()

	printf("Test1 end\r\n");
}
TEST(fuzzTest, Test2)
{
    printf("Test2 start\r\n");
	
	CodeFuzz_start(0,100,1000000,(char*)"Test2",0)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a = *(u32*)CF_GetU32(0, 0x345678);
		char* string = CF_GetString(1, (char*)"changchu!", 10, 0, 1000);
		char* blob = CF_GetBlob(2, (char*)"123457", 6, 0, 1000);
		int len = CF_GetMutatorLen(2);

		
		targer1(a, blob, len, string);
	}
	CodeFuzz_end()

	printf("Test2 end\r\n");
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

	CF_SetReportPath((char*)"./");

    int result =  RUN_ALL_TESTS();


    return result;
}




