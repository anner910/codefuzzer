#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

void blob0(char* blob, int len)
{
	static int aaa = 0;
	if(len >= 7)
		if(memcmp(blob,"7890123", 7) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" blob0 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}

		}
}

void dataa0(char* data, int len)
{
	static int aaa = 0;
	if(len >= 8)
		if(memcmp(data + 4,"\x00\x0f\xff\x00\x00",4) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa0 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void dataa1(char* data, int len)
{
	static int aaa = 0;
	if(len >= 16)
		if(memcmp(data,"zhan1BEIJINGch00",16) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa1 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}


void dataa2(char* data, int len)
{
	static int aaa = 0;
	if(len >= 16)
		if(memcmp(data,"zhan1BEIJINGchun",16) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa2 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}


void dataa3(char* data, int len)
{
	static int aaa = 0;
	if(len >= 8)
		if(memcmp(data + 4,"\x00\x00\x00\x00\x00",4) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa3 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void dataa4(char* data, int len)
{
	static int aaa = 0;
	if(len >= 18)
		if(memcmp(data,"zhan012BEIJINGch10",18) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa4 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void dataa5(char* data, int len)
{
	static int aaa = 0;
	if(len >= 16)
		if(memcmp(data,"zhan1BEIJINGch00",16) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa5 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void dataa6(char* data, int len)
{
	static int aaa = 0;
	if(len >= 16)
		if(memcmp(data,"zhang8EIJINGchun",16) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa6 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void dataa7(char* data, int len)
{
	static int aaa = 0;
	if(len >= 16)
		if(memcmp(data,"zhang8EIJINGchun",16) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa7 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void dataa8(char* data, int len)
{
	static int aaa = 0;
	if(len == 26)
		if(memcmp(data,"zhangBEIJINGchun1234512345",26) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa8 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void dataa9(char* data, int len)
{
	static int aaa = 0;
	if(len == 20)
		if(memcmp(data,"zhangBEIJINGchun\xfe\xfe\xfe\xfe",20) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa9 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void dataa10(char* data, int len)
{
	static int aaa = 0;
	if(len == 25)
		if(memcmp(data,"zhangBEgBEgBEgBEIJINGchun",25) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa10 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void dataa11(char* data, int len)
{
	static int aaa = 0;
	if(len == 25)
		if(memcmp(data,"zhangBEIJINGchunhunhunhun",25) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa11 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void dataa12(char* data, int len)
{
	static int aaa = 0;
	if(len >= 16)
		if(memcmp(data + 4,"88888",5) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa12 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void dataa133(char* data, int len)
{
	static int aaa = 0;
	if(len >= 16)
		if(memcmp(data + 4,"chounmizadi",11) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa133 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}


void dataa13(char* data, int len)
{
	static int aaa = 0;
	if(len >= 16)
		if(memcmp(data + 4,"anner910",8) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa13 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void dataa14(char* data, int len)
{
	static int aaa = 0;

	if (len == 456789)
		return;
	
	if(len >= 16)
		if(memcmp(data + 4,"456789",6) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa14 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void dataa15(char* data, int len)
{
	static int aaa = 0;

	if (len == 456789)
		return;
	
	if(len >= 16)
		if(memcmp(data + 4,"NGch10",6) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa15 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void dataa16(char* data, int len)
{
	static int aaa = 0;

	if (len == 456789)
		return;
	
	if(len >= 16)
		if(memcmp(data + 4,"false",5) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" dataa16 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void datab1(char* data, int len)
{
	static int aaa = 0;
	if(len >= 4)
	{
		int temp = *(int *)(data);
		if(temp == 0x1356321)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" datab1 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
	}
}

void datab2(char* data, int len)
{
	static int aaa = 0;
	if(len >= 12)
	{
		int temp = *(int *)(data + 5);
		if(temp == 0x467893)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" datab2 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
	}
}

void datab3(char* data, int len)
{
	static int aaa = 0;
	if(len >= 12)
	{
		int temp = *(int *)(data + 5);
		temp = temp + 15;
		if(temp == 0x3365748)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" datab3 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
	}
}


void datab4(char* data, int len)
{
	static int aaa = 0;
	if(len >= 12)
	{
		int temp = *(int *)(data + 5);
		temp = temp + 15;
		if(temp == 0x3365748)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" datab4 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
	}
}

void datab5(char* data, int len)
{
	static int aaa = 0;
	if(len == 16)
	{
		int temp = *(int *)(data + 5);
		if(temp == 16)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" datab5 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
	}
}


void datab6(char* data, int len)
{
	static int aaa = 0;

	if (len == 7893456)
		return;
	
	if(len >= 16)
		if(memcmp(data + 4,"7893466",7) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" datab6 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void datab7(char* data, int len)
{
	static int aaa = 0;
	if(len >= 10)
		if(memcmp(data,"zhJINGchun",10) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" datab7 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void datab8(char* data, int len)
{
	static int aaa = 0;
	if(len >= 16)
		if(memcmp(data,"zhang\x04\x05\x06JINGchun",16) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" datab8 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}



void datab9(char* data, int len)
{
	static int aaa = 0;
	if(len >= 16)
		if(memcmp(data,"zchunBEIJINGchun",16) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" datab9 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void datab10(char* data, int len)
{
	static int aaa = 0;
	if(len >= 16)
		if(memcmp(data,"zhangbeijinGchun",16) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" datab10 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}


void data10(char* data, int len)
{
	static int aaa = 0;
	if(len >= 16)
		if(memcmp(data + 4,"anner910",8) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" data10 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}




void data1010(char* data, int len)
{
	static int aaa = 0;
	if(len >= 8)
		if(memcmp(data, "anner910",8) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" data10 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}


void data9(char* data, int len)
{
	static int aaa = 0;
	if(len >= 10)
	{
		int temp = *(int *)(data + 5);
		if(temp == 0x1356321)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" data9 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
	}
}

void data99(char* data, int len)
{
	static int aaa = 0;
	if(len >= 4)
	{
		int temp = *(int *)(data);
		if(temp == 0x1356321)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" data9 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
	}
}



void data8(char* data, int len)
{
	static int aaa = 0;
	if(len >= 16)
		if(memcmp(data,"zhan1BEIJINGch00",16) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" data8 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}












void data3(char* data, int len)
{
	static int aaa = 0;
	if(len >= 20)
		if(memcmp(data,"zhangBEIJINNNNNNNNNN",20) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" data3 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}

void data33(char* data, int len)
{
	static int aaa = 0;
	if(len >= 20)
		if(memcmp(data,"zhangBBBBBEIJINGchun",20) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" data3 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}



void data2(char* data, int len)
{
	static int aaa = 0;
	if(len >= 16)
		if(memcmp(data,"zhangBEIJINzhann",16) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" data2 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}




void data0(char* data, int len)
{
	static int aaa = 0;
	if(len >= 6)
		if(memcmp(data,"123568",6) == 0)
		{
			if (aaa == 0)
			{
				aaa = 1;
				printf(" data0 has ok\r\n");

				int a[10] = {0};
				a[5] = a[10];
			}
		}
}


void number4(int num)
{
	static int aaa = 0;
	if(num == 0xffffffff)
	{
		if (aaa == 0)
		{
			aaa = 1;
			printf(" number4 has ok\r\n");

			int a[10] = {0};
			a[5] = a[10];
		}
	}
}


void number3(int num)
{
	static int aaa = 0;
	if(num > 2000000000)
	{
		if (aaa == 0)
		{
			aaa = 1;
			printf(" number3 has ok\r\n");

			int a[10] = {0};
			a[5] = a[10];
		}
	}
}


void number2(int num)
{
	static int aaa = 0;
	if(num == 0x345679)
	{
		if (aaa == 0)
		{
			aaa = 1;
			printf(" number2 has ok\r\n");

			int a[10] = {0};
			a[5] = a[10];
		}
	}
}

void number11(int num)
{
	static int aaa = 0;
	if(num == 0x66884321)
	{
		if (aaa == 0)
		{
			aaa = 1;
			printf(" number11 has ok\r\n");

			int a[10] = {0};
			a[5] = a[10];
		}
	}
}



void number1(int num)
{
	static int aaa = 0;
	if(num > 2000000000)
	{
		if (aaa == 0)
		{
			aaa = 1;
			printf(" number1 has ok\r\n");

			int a[10] = {0};
			a[5] = a[10];
		}
	}
}

void number00(int num)
{
	static int aaa = 0;

	int temp = __builtin_bswap32(0x345678);
	
	if(num == temp)
	{
		if (aaa == 0)
		{
			aaa = 1;
			printf(" number00 has ok\r\n");

			int a[10] = {0};
			a[5] = a[10];
		}
	}
}



void number0(int num)
{
	static int aaa = 0;
	if(num == 7890123)
	{
		if (aaa == 0)
		{
			aaa = 1;
			printf(" number0 has ok\r\n");

			int a[10] = {0};
			a[5] = a[10];
		}
	}
}


void string0(char* string)
{
	static int aaa = 0;
	if(strcmp(string,"7890123") == 0)
	{
		if (aaa == 0)
		{
			aaa = 1;
			printf(" string0 has ok\r\n");

			int a[10] = {0};
			a[5] = a[10];
		}

	}
}




void targer(int num, char* blob,int len, char* string)
{
	static int aaa = 0;
	static int aaa1 = 0;
	static int bbb = 0;
	static int bbb1 = 0;
	static int ccc = 0;
	static int ccc1 = 0;
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

	if(strcmp(string,"changchun") == 0)
	{
		if (ccc == 0)
		{
			ccc = 1;
			printf(" string has ok\r\n");
		}

	}

	if(strcmp(string,"shanghaiA") == 0)
	{
		if (ccc1 == 0)
		{
			ccc1 = 1;
			printf(" string1 has ok\r\n");
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

									int a[10] = {0};
									a[5] = a[10];
								}

	return;
}


#ifdef __cplusplus
}
#endif

