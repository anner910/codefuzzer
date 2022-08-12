# codefuzzer

### 被测代码请参考  

[target.c](../../test/test4/target.c)


### 用例清参考  
[test.c](../../test/test4/test.c)


```
extern void targer(char* blob,int len);
void test_target(void)
{
	printf("test_target start\r\n");
	
	CF_SetReportPath("./");
	
	CodeFuzz_start(0,100,1000000,"test_target",0)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, "123457", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);

		
		targer(blob, len);
	}
	CodeFuzz_end()

	printf("test_target end\r\n");

}


int main(int argc,char *argv[])
{
	
	test_target();
	
}

```


### 参考如下操作

```
解压工具后进入目录
cd codefuzzer/test/test4

编译
gcc -c  ../../codefuzzer/core/*.c ../../codefuzzer/plus/*.c ../../codefuzzer/mutator/*.c -g -O0 -fsanitize=address;g++ target.c test.c *.o -o anner910 -fsanitize=address -fsanitize-coverage=trace-pc,trace-cmp -O0 -g -I ../../codefuzzer/ -lgtest;rm *.o

运行
./anner910
```
