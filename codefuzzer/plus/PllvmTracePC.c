#include "../core/Core.h"


#ifdef __cplusplus
extern "C"{
#endif

#ifdef CF_Mode_TracePc

// gcc and clang -fsanitize-coverage=trace-pc
void __sanitizer_cov_trace_pc() 
{

    if(g_thread.llvmEnable == 0)
        return;

    uintptr_t PC = (uintptr_t)(__builtin_return_address(0));
    llvm_doTracePc(PC); 
}

// clang -fsanitize-coverage=trace-pc-guard
void __sanitizer_cov_trace_pc_guard(uint32_t *Guard) 
{
    if(g_thread.llvmEnable == 0)
        return;

    uintptr_t PC = (uintptr_t)(__builtin_return_address(0));
    llvm_doTracePc(PC); 
}


#endif

#ifdef __cplusplus
}
#endif

