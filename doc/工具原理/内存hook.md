# codefuzzer

工具目前支持的内存hook

```
       

void __sanitizer_cov_trace_cmp8(uint64_t Arg1, uint64_t Arg2) 
void __sanitizer_cov_trace_const_cmp8(uint64_t Arg1, uint64_t Arg2) 
void __sanitizer_cov_trace_cmp4(uint32_t Arg1, uint32_t Arg2) 
void __sanitizer_cov_trace_const_cmp4(uint32_t Arg1, uint32_t Arg2) 
void __sanitizer_cov_trace_cmp2(uint16_t Arg1, uint16_t Arg2) 
void __sanitizer_cov_trace_const_cmp2(uint16_t Arg1, uint16_t Arg2) 
void __sanitizer_cov_trace_cmp1(uint8_t Arg1, uint8_t Arg2) 
void __sanitizer_cov_trace_const_cmp1(uint8_t Arg1, uint8_t Arg2) 
void __sanitizer_cov_trace_switch(uint64_t Val, void *Cases) 
void __sanitizer_cov_trace_div4(uint32_t Val) 
void __sanitizer_cov_trace_div8(uint64_t Val) 
void __sanitizer_cov_trace_gep(uintptr_t Idx) 
void __sanitizer_weak_hook_memcmp(void *caller_pc, const void *s1,
                                  const void *s2, size_t n, int result) 
void __sanitizer_weak_hook_strncmp(void *caller_pc, const char *s1,
                                   const char *s2, size_t n, int result) 
void __sanitizer_weak_hook_strcmp(void *caller_pc, const char *s1,
                                   const char *s2, int result) 
void __sanitizer_weak_hook_strncasecmp(void *called_pc, const char *s1,
                                       const char *s2, size_t n, int result) 
void __sanitizer_weak_hook_strcasecmp(void *called_pc, const char *s1,
                                      const char *s2, int result) 
void __sanitizer_weak_hook_strstr(void *called_pc, const char *s1,
                                  const char *s2, char *result)
void __sanitizer_weak_hook_strcasestr(void *called_pc, const char *s1,
                                      const char *s2, char *result) 
void __sanitizer_weak_hook_memmem(void *called_pc, const void *s1, size_t len1,
                                  const void *s2, size_t len2, void *result) 
```

       