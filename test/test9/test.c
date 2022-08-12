
#include <stdio.h>
#include "codefuzzer.h"



extern int targer(int number);


void test_target(void)
{
	printf("test_target start\r\n");
	
	CodeFuzz_start_cmd((char*)"test_target")
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int number = *(s32*)CF_GetNumberRange(0, 10, 1, 100);
		
		if (targer(number) != 0)
		{
			//发现bug,写样本文件
			CF_CrashShow();
			printf("bug been found\r\n");
			break;
		}
	}
	CodeFuzz_end()

	printf("test_target end\r\n");

}


int main(int argc,char *argv[])
{
	CF_Cmd(argc, argv);
	
	test_target();
	
}


