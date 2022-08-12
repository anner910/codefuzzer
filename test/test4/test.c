
#include <stdio.h>
#include "codefuzzer.h"

extern void targer(char* blob,int len);
void test_target(void)
{
	printf("test_target start\r\n");
	
	CF_SetReportPath((char*)"./");

	CodeFuzz_start(0,100,1000000,(char*)"test_target",0)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"123457", 6, 1, 1000);
		int len = CF_GetMutatorLen(0);

		
		targer(blob, len);
	}
	CodeFuzz_end()

	printf("test_target end\r\n");

}


int main(int argc,char *argv[])
{
	
	test_target();
	
}


