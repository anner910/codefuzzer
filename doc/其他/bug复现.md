# codefuzzer

### 场景1
请参考
[简单使用举例1](./简单使用举例1.md)  

在被测代码的某个分支里，增加下边栈溢出代码  
int a[10] = {0}; a[5] = a[10];  

运行后，我们得到如test_target_crash_ceda6583这样的样本文件

复现的时候就是将下列代码修改，然后再次编译运行

```
CodeFuzz_start(0,100,1000000,(char*)"test_target_crash_ceda6583",1)
```

### 场景2
请参考
[简单使用举例2](./简单使用举例2.md)   

在被测代码的某个分支里，增加下边栈溢出代码  
int a[10] = {0}; a[5] = a[10];  

运行后，我们得到如test_target_crash_ceda6583这样的样本文件  

复现的方式参考下列命令行
```
./anner910 -m 1 -n test_target_crash_ceda6583
```