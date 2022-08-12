
#include <stdio.h>
#include "codefuzzer.h"


__attribute__((weak)) int LLVMFuzzerInitialize(int *argc, char ***argv);
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size);


void test_target(void)
{
	printf("test_target start\r\n");
	
	CodeFuzz_start_cmd((char*)"test_target")
	{
		static int i =0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"123457", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);

		LLVMFuzzerTestOneInput(blob, len);
	}
	CodeFuzz_end()

	printf("test_target end\r\n");
}


int main(int argc,char *argv[])
{
	CF_Cmd(argc, argv);

	if (LLVMFuzzerInitialize)
		LLVMFuzzerInitialize(&argc, &argv);
	
	test_target();
}


