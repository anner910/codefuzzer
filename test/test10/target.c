#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


void targer(int num, char* blob,int len)
{
	static int aaa = 0;
	static int aaa1 = 0;
	static int bbb = 0;
	static int bbb1 = 0;
	static int ddd = 0;
	
	if(num == 0x345679)
	{
		if (aaa == 0)
		{
			aaa = 1;
			printf(" num has ok\r\n");

			//int a = 0;
			//int b = a+5/a;
		}
	}

	if(num == 0x678886)
	{
		if (aaa1 == 0)
		{
			aaa1 = 1;
			printf(" num1 has ok\r\n");

			//for(;;)
				//;
		}
	}

	if(len >= 6)
		if(memcmp(blob,"123456",6) == 0)
		{
			if (bbb == 0)
			{
				bbb = 1;
				printf(" blob has ok\r\n");
			}

		}

	if(len >= 6)
		if(memcmp(blob,"jilin!",6) == 0)
		{
			if (bbb1 == 0)
			{
				bbb1 = 1;
				printf(" blob1 has ok\r\n");

				//char* temp = malloc(10);
				//temp = NULL;
			}

		}


	if(len >= 6)
		if(blob[0] == 'l')
			if(blob[1] == 'v')
				if(blob[2] == ' ')
					if(blob[3] == 's')
						if(blob[4] == 'h')
							if(blob[5] == 'u')
								if (ddd == 0)
								{
									ddd = 1;
									printf(" lv shu has ok\r\n");

									//int a[10] = {0};
									//a[5] = a[10];
								}

	return;
}



