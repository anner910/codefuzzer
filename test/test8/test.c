
#include <stdio.h>
#include "codefuzzer.h"



extern void IO_readFile(char* path, char** buf, int* len);
extern void IO_writeFile(char* path, char* buf, int len);


void targer(char * path);

void test_target(void)
{
	printf("test_target start\r\n");

	char* buf ;
	int len;

	IO_readFile((char*)"./src.txt", &buf, &len);
	
	CodeFuzz_start_cmd((char*)"test_target")
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);




		char* fuzzBuf = CF_GetBlob(0, buf, len, 0, 100000);
		int fuzzLen = CF_GetMutatorLen(0);


		IO_writeFile((char*)"./fuzz.txt", fuzzBuf, fuzzLen);

		
		targer((char*)"./fuzz.txt");
	}
	CodeFuzz_end()

	if(buf)
		free(buf);

	printf("test_target end\r\n");

}


int main(int argc,char *argv[])
{
	CF_Cmd(argc, argv);
	
	test_target();
	
}


