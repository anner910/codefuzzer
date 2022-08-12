#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>



extern void IO_readFile(char* path, char** buf, int* len);

void targer(char * path)
{
	char* buf = NULL;
	int len;

	IO_readFile(path, &buf, &len);

	if (len > 20)
	{
		if (memcmp(buf + 10, "beijing",7) == 0)
		{
			int a[10] = {0};
			a[5] = a[10];
		}
	}
	if(buf)
		free(buf);

	return;
}




