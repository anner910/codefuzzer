# 简介

我们可以将codefuzzer做简单的适配，就能运行Libfuzzer测试用例

### 被测代码请参考  

[target.c](../../test/test10/target.c)


### LLVMFuzzerTestOneInput用例清参考  
[test.c](../../test/test10/test.c)


### codefuzzer适配代码请参考

[fuzzer.c](../../test/test10/fuzzer.c)

```

__attribute__((weak)) int LLVMFuzzerInitialize(int *argc, char ***argv);
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size);


void test_target(void)
{
	printf("test_target start\r\n");
	
	CodeFuzz_start_cmd((char*)"test_target")
	{
		static int i =0;
		printf("\r%d",i++);
		fflush(stdout);

		char* blob = CF_GetBlob(0, (char*)"123457", 6, 0, 1000);
		int len = CF_GetMutatorLen(0);

		LLVMFuzzerTestOneInput(blob, len);
	}
	CodeFuzz_end()

	printf("test_target end\r\n");
}


int main(int argc,char *argv[])
{
	CF_Cmd(argc, argv);

	if (LLVMFuzzerInitialize)
		LLVMFuzzerInitialize(&argc, &argv);
	
	test_target();
}

```


### 参考如下操作

```
cd codefuzzer/test/test10


rm *.o

codefuzzer代码和适配代码fuzz.c一起编译成libfuzzer.a
gcc -c  ../../codefuzzer/core/*.c ../../codefuzzer/mutator/*.c ../../codefuzzer/plus/*.c ./fuzzer.c -g -O0 -I ../../codefuzzer/
ar -rcs libfuzzer.a *.o

#编译测试用例
gcc target.c test.c -o anner910 -fsanitize=address -fsanitize-coverage=trace-pc,trace-cmp -O0 -g -I ../../codefuzzer/ -Wl,--whole-archive  libfuzzer.a  -Wl,--no-whole-archive

运行
./anner910 --count=100000
```
