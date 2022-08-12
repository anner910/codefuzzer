
#include <stdio.h>

#include "codefuzzer.h"


#ifdef __cplusplus
extern "C"{
#endif

int DobbyHook(void *function_address, void *replace_call, void **origin_call);

extern void targer(int num, char* blob,int len, char* string);
void (*g_targer)(int num, char* blob,int len, char* string);

void my_target(int num, char* blob,int len, char* string)
{
	printf("fuzz target start\r\n");
	
	CodeFuzz_start(0, 100, 100000, "test_target", 0)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a1 = *(u32*)CF_GetU32(0, num);
		char* string1 = CF_GetString(1, string, strlen(string) + 1, 1, 1000);
		char* blob1 = CF_GetBlob(2, blob, len, 0, 1000);
		int len1 = CF_GetMutatorLen(2);

		
		g_targer(a1, blob1, len1, string1);
	}
	CodeFuzz_end()

	printf("fuzz target end\r\n");
}

void hook_init(void)
{
	DobbyHook((void *)&targer, (void *)my_target, (void **)&g_targer);
}


#ifdef __cplusplus
}
#endif

