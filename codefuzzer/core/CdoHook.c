
#include "Core.h"


#ifdef __cplusplus
extern "C"{
#endif


void do_addNumber(uintptr_t pc, u64 a, u64 b)
{
    if(g_thread.llvmEnable == 0)
        return;

    int idx;

    idx = ((pc << 2) ^ (a + b) % 64) % Number_HookCount;

    g_thread.hookData->numberA[idx] = a;
    g_thread.hookData->numberB[idx] = b;

    if(g_thread.hookData->numberIsHave[idx] == 0)
    {
        g_thread.hookData->numberIdx[g_thread.numNumber] = idx;
        g_thread.hookData->numberIsHave[idx] = 1;
        g_thread.numNumber++;
    }
}

u64 do_GetHookNumber(void)
{
    if(g_thread.numNumber == 0)
        return 0;

    int isAorB = PL_random()% 2;
    int idx = PL_random() % g_thread.numNumber;

    if(isAorB)
        return g_thread.hookData->numberA[g_thread.hookData->numberIdx[idx]];
    else
        return g_thread.hookData->numberB[g_thread.hookData->numberIdx[idx]];

    return 0;
}


void do_addBlob(uintptr_t pc,const char* a,int lenA,const char* b, int lenB)
{
    if(g_thread.llvmEnable == 0)
        return;

    int temp = 0;
    u8* temp1 = (u8*)&temp;
    int i;
    int k = 0;

    if(lenA > Blob_HookLength)
        lenA = Blob_HookLength;

    if(lenB > Blob_HookLength)
        lenB = Blob_HookLength;

    for (i = 0; i< lenA; i++)
    {
        temp1[k] ^= a[i];
        k++;
        if (k == 4)
            k = 0;
    }

    for (i = 0; i< lenB; i++)
    {
        temp1[k] ^= b[i];
        k++;
        if (k == 4)
            k = 0;
    }

    int idx = ((pc << 2) ^ (temp % 1024)) % Blob_HookCount;

    PL_memcpy(g_thread.hookData->blobA[idx], (char*)a, lenA);
    PL_memcpy(g_thread.hookData->blobB[idx], (char*)b, lenB);

    g_thread.hookData->lenA[idx] = lenA;
    g_thread.hookData->lenB[idx] = lenB;

    if(g_thread.hookData->blobIsHave[idx] == 0)
    {
        g_thread.hookData->blobIdx[g_thread.blobNumber] = idx;
        g_thread.hookData->blobIsHave[idx] = 1;
        g_thread.blobNumber++;
    }
}

void do_GetHookBlob(char** blob,int *len)
{
    if(g_thread.blobNumber == 0)
    {
        *blob = NULL;
        *len = 0;
        return;
    }

    int isAorB = PL_random()% 2;
    int idx = PL_random() % g_thread.blobNumber;

    if(isAorB)
    {
        *blob =g_thread.hookData->blobA[g_thread.hookData->blobIdx[idx]];
        *len =g_thread.hookData->lenA[g_thread.hookData->blobIdx[idx]];
    }
    else
    {
        *blob =g_thread.hookData->blobB[g_thread.hookData->blobIdx[idx]];
        *len =g_thread.hookData->lenB[g_thread.hookData->blobIdx[idx]];
    }

    return ;

}

#ifdef __cplusplus
}
#endif

