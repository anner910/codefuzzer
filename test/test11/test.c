
#include <stdio.h>

#include "codefuzzer.h"

extern void targer(int num, char* blob,int len, char* string);

void test_target(void)
{
	printf("test_target start\r\n");
	
	CodeFuzz_start(0, 100, 100000, "test_target", 0)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a = *(u32*)CF_GetU32(0, 0x345678);
		char* string = CF_GetString(1, 
		char* blob = CF_GetBlob(2, 
		int len = CF_GetMutatorLen(2);

		
		targer(a, blob, len, string);
	}
	CodeFuzz_end()

	printf("test_target end\r\n");
}


int main(int argc,char *argv[])
{
		
	test_target();
}

