
#include <stdio.h>
#include "codefuzzer.h"

typedef struct TTarger{
	int len;
	char* value;
	struct TTarger* next;
} STarger;

void targer(STarger* data);

void test_target(void)
{
	printf("test_target start\r\n");

	STarger temp[100];

	CF_SetMaxParaNumber(101);
	
	CodeFuzz_start_cmd((char*)"test_target")
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		memset(temp, 0, sizeof(temp));
		int ii;

		for(ii = 0; ii < 100; ii++)
		{
			temp[ii].value = CF_GetBlob(ii, (char*)"gittee", 6, 0, 1000);
			temp[ii].len = CF_GetMutatorLen(ii);
		}	

		int number = *(u32*)CF_GetNumberRange(100, 10, 0, 99);

		temp[0].next = NULL;

		for(ii = 0; ii < number; ii++)
		{
			temp[ii].next = &temp[ii + 1];
			temp[ii + 1].next = NULL;
		}

		
		targer(&temp[0]);
	}
	CodeFuzz_end()

	printf("test_target end\r\n");

}


int main(int argc,char *argv[])
{
	CF_Cmd(argc, argv);
	
	test_target();
	
}


