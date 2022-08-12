#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	int type;
	char value[32];
	int type1;
	char value1[32];
} STarger;


void targer(STarger* data)
{
	static int aaa = 0;
	static int bbb = 0;

	
	if(data->type == 0x345679)
	{
		if (memcmp(data->value, "beijing", 7) == 0)
			if (aaa == 0)
			{
				aaa = 1;
				printf(" aaa has ok\r\n");
			}
	}

	if(data->type1 == 0x6633890)
	{
		if (memcmp(data->value1, "shanghai", 8) == 0)
			if (bbb == 0)
			{
				bbb = 1;
				printf(" bbb has ok\r\n");
			}
	}

	return;
}



void targer1(STarger* data)
{
	static int aaa = 0;
	static int bbb = 0;

	
	if(data->type == 0x345679)
	{
		if (memcmp(data->value, "beijing", 7) == 0)
			if (aaa == 0)
			{
				aaa = 1;
				printf(" aaa has ok\r\n");
			}
	}

	if(data->type1 == 0x6633890)
	{
		if (memcmp(data->value1, "shanghai", 8) == 0)
			if (bbb == 0)
			{
				bbb = 1;
				printf(" bbb has ok\r\n");
			}
	}

	return;
}

