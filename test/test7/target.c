#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


typedef struct TTarger{
	int len;
	char* value;
	struct TTarger* next;
} STarger;



void targer(STarger* data)
{
	int aaa = 0;
	int i = 0;

	STarger* temp = data;
	
	for (; temp != NULL; temp = temp->next)
	{
		if((temp->len >= 7) && (memcmp(temp->value, "beijing",7) == 0))
		{
			aaa++;
		}

		if((temp->len >= 8) && (memcmp(temp->value, "shanghai",8) == 0))
		{
			aaa++;
		}

		if((temp->len >= 9) && (memcmp(temp->value, "changchun",9) == 0))
		{
			aaa++;
		}

		if((temp->len >= 5) && (memcmp(temp->value, "jilin",5) == 0))
		{
			aaa++;
		}

		if((temp->len >= 8) && (memcmp(temp->value, "anner910",8) == 0))
		{
			aaa++;
		}
	}

	if(aaa == 1)
	{
		static int bbb =0;
		if (bbb == 0)
		{
			bbb =1;
			printf("\r\n111---------    %d \r\n",aaa);
		}
	}

	if(aaa == 2)
	{
		static int bbb =0;
		if (bbb == 0)
		{
			bbb =1;
			printf("\r\n222---------    %d \r\n",aaa);
		}
	}

	if(aaa == 3)
	{
		static int bbb =0;
		if (bbb == 0)
		{
			bbb =1;
			printf("\r\n333---------    %d \r\n",aaa);
		}
	}

	if(aaa == 4)
	{
		static int bbb =0;
		if (bbb == 0)
		{
			bbb =1;
			printf("\r\n444---------    %d \r\n",aaa);
		}
	}

	if (aaa >= 5)
	{
		int a[10] = {0};
		a[5] = a[10];
	}

	return;
}




