
#include <stdio.h>
#include "codefuzzer.h"



extern void targer(int num, char* blob,int len, char* string);
void call_target(void)
{
	int i;
	for (i = 0; i< 1000000; i++)
	{
		printf("%d\r",i);
		CF_ForPassive((char*)"test_target", 0);
			
		int a = *(u32*)CF_GetU32(0, 0x345678);
		char* string = CF_GetString(1, (char*)"changchu!", 10, 1, 1000);
		char* blob = CF_GetBlob(2, (char*)"123457", 6, 0, 1000);
		int len = CF_GetMutatorLen(2);

		targer(a, blob, len, string);
	}
}


int main(int argc,char *argv[])
{
	
	call_target();
}


