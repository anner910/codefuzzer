#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>



//1-100返回0,其他值返回1    函数再100时实现有问题
int targer(int number)
{
	if ((1<=number)&&(number<100))
		return 0;

	return 1;
}




