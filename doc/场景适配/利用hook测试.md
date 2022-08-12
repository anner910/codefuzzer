# 简介

我们可以通过hook技术，对想要被测的程序进行hook

这样，就不需要构造复杂的调用上下文，也不需要构造初始参数   就能够完成对被测程序的fuzz

这种应用既可以应用到真实环境，也可以应用到原有的单元功能测试环境里

### 被测函数代码请参考  

[target.c](../../test/test12/target.c)


### 调用被测代码的程序请参考 
[test.c](../../test/test12/test.c)


### hook文件
[hook.c](../../test/test12/hook.c)

```
int DobbyHook(void *function_address, void *replace_call, void **origin_call);

extern void targer(int num, char* blob,int len, char* string);
void (*g_targer)(int num, char* blob,int len, char* string);

void my_target(int num, char* blob,int len, char* string)
{
	printf("fuzz target start\r\n");
	
	CodeFuzz_start(0, 100, 100000, "test_target", 0)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a1 = *(u32*)CF_GetU32(0, num);
		char* string1 = CF_GetString(1, string, strlen(string) + 1, 1, 1000);
		char* blob1 = CF_GetBlob(2, blob, len, 0, 1000);
		int len1 = CF_GetMutatorLen(2);

		
		g_targer(a1, blob1, len1, string1);
	}
	CodeFuzz_end()

	printf("fuzz target end\r\n");
}

void hook_init(void)
{
	DobbyHook((void *)&targer, (void *)my_target, (void **)&g_targer);
}

```


### 参考如下操作

编译dobbyhook
```
下载
git clone https://github.com/jmpews/Dobby.git --depth=1 

编译
cd Dobby
mkdir build
cd build
cmake ..
make
```
然后可以看到libdobby.so


编译运行



```
cd test/test12/
gcc -c  ../../codefuzzer/core/*.c ../../codefuzzer/mutator/*.c  ../../codefuzzer/plus/*.c hook.c -g -O0 -fsanitize=address -I ../../codefuzzer/;g++ target.c test.c *.o -o anner910 -fsanitize=address -fsanitize-coverage=trace-pc,trace-cmp -O0 -g -I ../../codefuzzer/ ./libdobby.so;rm *.o


./anner910

```


### 总结

能够看到，原有的程序只需调用hook_init初始化函数即可

我们对被测程序进行hook,当原有程序正常调用到被测程序时，就会跳转到我们替换好的hook函数
我们再hook函数里，利用传进来的参数作为初始参数，编写fuzz代码完成对真实的函数进行fuzz测试

