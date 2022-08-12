
#include <stdio.h>
#include <stdint.h>


extern void targer(int num, char* blob,int len);

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
	if(Size < 4)
		return 0;
	int num = *(int*)Data;

	targer(num, (char*)(Data + 4), Size - 4);
	return 0;
}


