#include "../core/Core.h"


#ifdef __cplusplus
extern "C"{
#endif

#ifdef CF_Mode_Leak

void leak_crash(void)
{
    int a = 0;    
    int b = (a+5) / a;
}
void leak_malloc_hook(const void *p, size_t size)
{
    //¼ì²â´óÄÚ´æ·ÖÅä
    if ((g_global.SetCheckLargeMemorySize != 0)
        &&(g_thread.internalOperation == 0)
        &&(size >= g_global.SetCheckLargeMemorySize << 20))
    {
        PL_printf("\r\nCrashHandler because check larger memory malloc, size is %zu \r\n",size);
        report_andCrashWrite("LargerMemoryMalloc");

        if (__sanitizer_print_stack_trace)
        {
            PL_printf("\r\n-----Codefuzzer PL_printf stack trace start\r\n");
            __sanitizer_print_stack_trace();
            PL_printf("\r\n------Codefuzzer PL_printf stack trace end\r\n");
        }
        PL_exit(Exit_No_LargeMemorySize);
    }

    if(g_global.setEnableLeak == 0)
        return;

    if(g_thread.llvmEnable == 0)
        return;

    if(g_thread.internalOperation == 1)
        return;

    if(g_global.setDebugLeak > 0)
    {
        PL_printf("\r\n------malloc %p size %zu\r\n",p, size);
        if(g_global.setDebugLeak > 1)
        {
            if (__sanitizer_print_stack_trace)
                __sanitizer_print_stack_trace();
        }
    }

    g_thread.mallocCount++;
}

void leak_free_hook(const void *p)
{
    if(g_global.setEnableLeak == 0)
        return;

    if(g_thread.llvmEnable == 0)
        return;

    if(g_thread.internalOperation == 1)
        return;

    if(g_global.setDebugLeak > 0)
    {
        PL_printf("\r\n------free %p\r\n",p);

        if(g_global.setDebugLeak > 1)
        {
            if (__sanitizer_print_stack_trace)
                __sanitizer_print_stack_trace();
        }
    }

    g_thread.freeCount++;
	
}

void leak_CheckLargeMemoryUse(void)
{
    while (1) 
    {
        PL_sleep(1);
        size_t Peak = PL_GetPeakRSSMb();

        if ((g_global.SetCheckLargeMemoryUse != 0)
            &&(Peak >= g_global.SetCheckLargeMemoryUse))
        {
            PL_printf("\r\nCrashHandler because check larger memory use, size is %zu \r\n",Peak);

            if (__sanitizer_print_memory_profile)
                __sanitizer_print_memory_profile(95, 8);

            report_andCrashWrite("LargerMemoryUse");
            PL_exit(Exit_No_LargeMemoryUse);
        }
    }
}

void leak_init(void)
{
    if(g_global.setEnableLeak == 0)
        return;

    if(g_global.isInitLeak == 0)
        g_global.isInitLeak = 1;
    else
        return;

    if(__sanitizer_install_malloc_and_free_hooks)
        __sanitizer_install_malloc_and_free_hooks(leak_malloc_hook, leak_free_hook);
    
    g_thread.checkCount = 10;

    PL_pthread_create(leak_CheckLargeMemoryUse);
}


void leak_do(void)
{
    if(g_global.setEnableLeak == 0)
        return;

    if(g_thread.mallocCount != g_thread.freeCount)
    {
        g_thread.checkCount--;

        if(g_thread.checkCount < 0)
            return;

        PL_printf("malloc is %d; free is %d\r\n", g_thread.mallocCount, g_thread.freeCount);

        if(__lsan_disable)
            __lsan_disable();

        if(__lsan_enable)
            __lsan_enable();

        if(__lsan_do_recoverable_leak_check)
            if(__lsan_do_recoverable_leak_check())
            {
                PL_printf("\r\nCrashHandler because check memory leak \r\n");
                report_andCrashWrite("MemoryLeak");
                PL_exit(Exit_No_LeakCheck);
            }
    }

    g_thread.mallocCount = 0;
    g_thread.freeCount = 0;

}

#else

void leak_init(void)
{

}

void leak_do(void)
{

}

#endif


#ifdef __cplusplus
}
#endif


