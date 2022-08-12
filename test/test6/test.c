
#include <stdio.h>
#include "codefuzzer.h"

typedef struct {
	int type;
	char value[32];
	int type1;
	char value1[32];
} STarger;


void targer(STarger* data);

void test_target(void)
{
	printf("test_target start\r\n");
	
	CodeFuzz_start_cmd((char*)"test_target")
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		STarger temp;

		memset(&temp, 0, sizeof(STarger));

		temp.type = *(u32*)CF_GetU32(0, 1);
		char* aaa = CF_GetBlob(1, (char*)"12345700000000000000000000000000", 32, 32, 32);
		memcpy(temp.value,aaa , 32);
		temp.type1 = *(u32*)CF_GetU32(2, 2);
		char *bbb = CF_GetBlob(3, (char*)"75432100000000000000000000000000", 32, 32, 32);
		memcpy(temp.value1, bbb, 32);

		
		targer(&temp);
	}
	CodeFuzz_end()

	printf("test_target end\r\n");

}

void targer1(STarger* data);

void test_target1(void)
{
	printf("test_target1 start\r\n");
	
	CodeFuzz_start_cmd((char*)"test_target1")
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		STarger temp;
		memset(&temp, 0, sizeof(STarger));
		temp.type = 1;
		memcpy(temp.value,(char*)"12345700000000000000000000000000" , 32);
		temp.type1 = 2;
		memcpy(temp.value1,(char*)"75432100000000000000000000000000" , 32);
		

		STarger *bbb = (STarger *)CF_GetBlob(0, (char*)&temp, sizeof(STarger), sizeof(STarger), sizeof(STarger));
		targer(bbb);
	}
	CodeFuzz_end()

	printf("test_target1 end\r\n");

}


int main(int argc,char *argv[])
{
	CF_Cmd(argc, argv);
	
	test_target();
	test_target1();
	
}


