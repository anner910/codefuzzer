#include "../core/Core.h"


#ifdef __cplusplus
extern "C"{
#endif

#ifdef CF_Mode_Hook

// gcc       -fsanitize=address -fsanitize-coverage=trace-cmp
// clang    -fsanitize=address -fsanitize-coverage=trace-cmp,trace-div,trace-gep
// https://blog.csdn.net/zhang14916/article/details/100924489

void __sanitizer_cov_trace_cmpd(double Arg1, double Arg2) 
{
    uintptr_t PC = (uintptr_t)(__builtin_return_address(0));

    do_addNumber(PC, *(uint64_t*)&Arg1, *(uint64_t*)&Arg2);
}

void __sanitizer_cov_trace_cmpf(float Arg1, float Arg2) 
{
    uintptr_t PC = (uintptr_t)(__builtin_return_address(0));
    do_addNumber(PC, *(uint32_t*)&Arg1, *(uint32_t*)&Arg2);
}

void __sanitizer_cov_trace_cmp8(uint64_t Arg1, uint64_t Arg2) 
{
    uintptr_t PC = (uintptr_t)(__builtin_return_address(0));

    do_addNumber(PC, Arg1, Arg2);
}

void __sanitizer_cov_trace_const_cmp8(uint64_t Arg1, uint64_t Arg2) 
{
    uintptr_t PC = (uintptr_t)(__builtin_return_address(0));

    do_addNumber(PC, Arg1, Arg2);
}


void __sanitizer_cov_trace_cmp4(uint32_t Arg1, uint32_t Arg2) 
{
    uintptr_t PC = (uintptr_t)(__builtin_return_address(0));

    do_addNumber(PC, Arg1, Arg2);
}

void __sanitizer_cov_trace_const_cmp4(uint32_t Arg1, uint32_t Arg2) 
{
    uintptr_t PC = (uintptr_t)(__builtin_return_address(0));

    do_addNumber(PC, Arg1, Arg2);
}

void __sanitizer_cov_trace_cmp2(uint16_t Arg1, uint16_t Arg2) 
{
    uintptr_t PC = (uintptr_t)(__builtin_return_address(0));

    do_addNumber(PC, Arg1, Arg2);
}


void __sanitizer_cov_trace_const_cmp2(uint16_t Arg1, uint16_t Arg2) 
{
    uintptr_t PC = (uintptr_t)(__builtin_return_address(0));

    do_addNumber(PC, Arg1, Arg2);
}


void __sanitizer_cov_trace_cmp1(uint8_t Arg1, uint8_t Arg2) 
{
    return;
}

void __sanitizer_cov_trace_const_cmp1(uint8_t Arg1, uint8_t Arg2) 
{
    return;
}

void __sanitizer_cov_trace_switch(uint64_t Val, void *Cases) 
{

    uintptr_t PC = (uintptr_t)(__builtin_return_address(0));
    uint64_t * aaa = (uint64_t*)Cases;
    uint64_t N = aaa[0];

    size_t i;
    for (i = 0; i < N; i++) 
    {
        do_addNumber(PC + i, aaa[i+2], Val);
    }
}

void __sanitizer_cov_trace_div4(uint32_t Val) 
{
    uintptr_t PC = (uintptr_t)(__builtin_return_address(0));
    do_addNumber(PC, Val, Val);
}

void __sanitizer_cov_trace_div8(uint64_t Val) 
{
    uintptr_t PC = (uintptr_t)(__builtin_return_address(0));

    do_addNumber(PC, Val, Val);
}

void __sanitizer_cov_trace_gep(uintptr_t Idx) 
{
    uintptr_t PC = (uintptr_t)(__builtin_return_address(0));

    do_addNumber(PC, Idx, Idx);
}

void __sanitizer_weak_hook_memcmp(void *caller_pc, const void *s1,
          const void *s2, size_t n, int result) 
{

    if(n <= 1)
        return;

    do_addBlob((uintptr_t)caller_pc, (const char*)s1, n, (const char*)s2, n);
}

void __sanitizer_weak_hook_strncmp(void *caller_pc, const char *s1,
           const char *s2, size_t n, int result) 
{
    int n1 = lib_strnlen(s1, n);
    int n2 = lib_strnlen(s2, n);

    do_addBlob((uintptr_t)caller_pc, s1, n1, s2, n2);
}

void __sanitizer_weak_hook_strcmp(void *caller_pc, const char *s1,
           const char *s2, int result) 
{
    int n1 = lib_strlen1(s1,s2);

    do_addBlob((uintptr_t)caller_pc, s1, n1, s2, n1);
}

void __sanitizer_weak_hook_strncasecmp(void *called_pc, const char *s1,
               const char *s2, size_t n, int result) 
{
    do_addBlob((uintptr_t)called_pc, s1, n, s2, n);
}

void __sanitizer_weak_hook_strcasecmp(void *called_pc, const char *s1,
              const char *s2, int result) 
{
    int n1 = lib_strlen(s1);
    int n2 = lib_strlen(s2);

    do_addBlob((uintptr_t)called_pc, s1, n1, s2, n2);
}

void __sanitizer_weak_hook_strstr(void *called_pc, const char *s1,
          const char *s2, char *result)
{

    int n1 = lib_strlen(s1);
    int n2 = lib_strlen(s2);

    do_addBlob((uintptr_t)called_pc, s1, n1, s2, n2);
}

void __sanitizer_weak_hook_strcasestr(void *called_pc, const char *s1,
              const char *s2, char *result) 
{

    int n1 = lib_strlen(s1);
    int n2 = lib_strlen(s2);

    do_addBlob((uintptr_t)called_pc, s1, n1, s2, n2);
}

void __sanitizer_weak_hook_memmem(void *called_pc, const void *s1, size_t len1,
          const void *s2, size_t len2, void *result) 
{

    if((len1 <= 1) && (len2 <= 1))
        return;


    do_addBlob((uintptr_t)called_pc, (const char*)s1, len1, (const char*)s2, len2);
}
#endif


#ifdef __cplusplus
}
#endif

