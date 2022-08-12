
#include <stdio.h>

#include "codefuzzer.h"


#ifdef __cplusplus
extern "C"{
#endif


extern void targer(int num, char* blob,int len, char* string);

void test_target(void)
{
	printf("call target start\r\n");
		
	targer(1234, "567789", 6, "anner910");

	printf("call target end\r\n");
}

extern void hook_init(void);
int main(int argc,char *argv[])
{		
	hook_init();
	test_target();
}

#ifdef __cplusplus
}
#endif

