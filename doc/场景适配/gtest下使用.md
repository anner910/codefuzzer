# 简介

我们可以在gtest工程下编写fuzz用例，使得单元fuzz用例和单元功能用例共存

### 被测代码请参考  

[target.c](../../test/test5/target.c)


### 用例清参考  
[test.cpp](../../test/test5/test.cpp)


```
#ifdef __cplusplus
extern "C"{
#endif


extern void targer(int num, char* blob,int len, char* string);
extern void targer1(int num, char* blob,int len, char* string);

#ifdef __cplusplus
}
#endif




TEST(fuzzTest, Test1)
 {
    printf("Test1 start\r\n");
	
	CodeFuzz_start(0,100,1000000,(char*)"Test1",0)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a = *(u32*)CF_GetU32(0, 0x345678);
		char* string = CF_GetString(1, 
(char*)"changchu!", 10, 0, 1000);
		char* blob = CF_GetBlob(2, 
(char*)"123457", 6, 0, 1000);
		int len = CF_GetMutatorLen(2);

		
		targer(a, blob, len, string);
	}
	CodeFuzz_end()

	printf("Test1 end\r\n");
}
TEST(fuzzTest, Test2)
{
    printf("Test2 start\r\n");
	
	CodeFuzz_start(0,100,1000000,(char*)"Test2",0)
	{
		static int i = 0;
		printf("\r%d",i++);
		fflush(stdout);

		int a = *(u32*)CF_GetU32(0, 0x345678);
		char* string = CF_GetString(1, 
(char*)"changchu!", 10, 0, 1000);
		char* blob = CF_GetBlob(2, 
(char*)"123457", 6, 0, 1000);
		int len = CF_GetMutatorLen(2);

		
		targer1(a, blob, len, string);
	}
	CodeFuzz_end()

	printf("Test2 end\r\n");
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

	CF_SetReportPath((char*)"./");

    int result =  RUN_ALL_TESTS();


    return result;
}


```


### 参考如下操作

```
现在环境里下载gtest
sudo apt-get install libgtest-dev 

解压工具后进入目录
cd codefuzzer/test/test5

编译工具库
cp ../../build.sh ./
chmod 777 build.sh
./build.sh

编译被测程序
gcc -c  target.c  -fsanitize=address -fsanitize-coverage=trace-pc,trace-cmp -O0 -g
gcc target.o -shared -o libtarget.so 

编译测试程序
g++  test.cpp ./libtarget.so   -Wl,--whole-archive  libcodefuzzer.a  -Wl,--no-whole-archive -fsanitize=address -O0 -g -o anner910 -lgtest

运行
./anner910
```
