# 简介

由于工具提供的都是源码，并进行了windows的适配，因此工具可以用来测试windows的函数

## windows + clang + codefuzzer

### 从下列链接下载windows版本的llvm并安装
https://releases.llvm.org/download.html#3.7.0

### 被测代码请参考  

[target.c](../../test/test11/target.c)


### 用例清参考  
[test.c](../../test/test11/test.c)


```
extern void targer(int num, char* blob,int len, char* string);

void test_target(void)
{
	printf("test_target start\r\n");
	
	CodeFuzz_start(0, 100, 100000, "test_target", 0)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a = *(u32*)CF_GetU32(0, 0x345678);
		char* string = CF_GetString(1, 
"changchu!", 10, 1, 1000);
		char* blob = CF_GetBlob(2, 
"123457", 6, 0, 1000);
		int len = CF_GetMutatorLen(2);

		
		targer(a, blob, len, string);
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
cd codefuzzer/test/test11

"c:\Program Files\LLVM\bin\clang.exe"  -c  ../../codefuzzer/core/*.c ../../codefuzzer/mutator/*.c ../../codefuzzer/plus/*.c -g -O0 -fsanitize=address

"c:\Program Files\LLVM\bin\clang.exe" target.c test.c *.o -o anner910.exe -fsanitize=address -fsanitize-coverage=trace-pc,trace-cmp -O0 -g -I ../../codefuzzer/ 


运行
anner910.exe
```
