
#include <stdio.h>

#include "codefuzzer.h"

#ifdef __cplusplus
extern "C"{
#endif

extern void targer(int num, char* blob,int len, char* string);
void test_target(void)
{
	printf("test_target start\r\n");

	char adc[1000];
	
	CodeFuzz_start_cmd((char*)"test_target")
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a = *(u32*)CF_GetU32(0, 0x345678);
		CF_SetMutatorPos(1, 1, 0, 10, 10, 10);
		char* string = CF_GetString(1, (char*)"changchu!", 10, 1, 1000);
		char* blob = CF_GetBlob(2, (char*)adc, 1000, 0, 1000);
		int len = CF_GetMutatorLen(2);

		
		targer(a, blob, len, string);
	}
	CodeFuzz_end()

	printf("test_target end\r\n");
}


int main(int argc,char *argv[])
{
	CF_Cmd(argc, argv);
		
	test_target();
}


#ifdef __cplusplus
}
#endif

