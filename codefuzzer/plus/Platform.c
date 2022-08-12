
#include "../core/Core.h"
#include "time.h"

#ifndef _WIN32
#include <sys/wait.h>
#include <sys/time.h>


#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <pthread.h>

#endif



#ifdef __cplusplus
extern "C"{
#endif

void PL_getData(char* date) 
{
	time_t tmpcal_ptr;
	time(&tmpcal_ptr);

	time_t timestamp = tmpcal_ptr;
	struct tm *info = localtime(&timestamp);

	strftime(date, 64, "%Y%m%d_%H%M%S", info);
    return ;
}


void PL_setTimer(int Seconds) 
{
#ifndef _WIN32

  	struct itimerval value;
	value.it_value.tv_sec = Seconds;
	value.it_value.tv_usec = 0;
	value.it_interval.tv_sec = Seconds;
	value.it_interval.tv_usec = 0;
	setitimer(ITIMER_REAL, &value, NULL); //(2)
#endif

}


int PL_getTime(void)
{
	time_t tmpcal_ptr;
	time(&tmpcal_ptr);

	return tmpcal_ptr;
}


int PL_random(void)
{
	return rand();
}

void PL_seed(int setSeed)
{
	srand(setSeed);
}


void* PL_malloc(size_t size)
{
	g_thread.internalOperation = 1;
	void* temp = malloc(size);
	g_thread.internalOperation = 0;
	
	return temp;
}

void PL_free(void* s)
{
	g_thread.internalOperation = 1;
	free(s);
	g_thread.internalOperation = 0;
	
	return;
}

void* PL_memset(void *s,int ch,size_t n)
{
	return memset(s, ch, n);
}

void* PL_memcpy(void *d,void *s,size_t n)
{
	return memcpy(d, s, n);
}



//64λȡģ
s64 PL_s64_divMode(s64 a,s64 b)
{
	return a%b;
}

uint8_t  Bswap8(uint8_t x)  
{ 
	return x; 
}
uint16_t Bswap16(uint16_t x) 
{ 
	return __builtin_bswap16(x); 
}
uint32_t Bswap32(uint32_t x) 
{ 
	return __builtin_bswap32(x); 
}
uint64_t Bswap64(uint64_t x) 
{ 
	return __builtin_bswap64(x); 
}

int PL_fork(void)
{
#ifndef _WIN32
	return fork();
#else
	return 0;
#endif
}

void PL_exit(int no)
{
#ifndef _WIN32
		exit(no);
#endif
}


int PL_wait(int* sta)
{
#ifndef _WIN32
	return wait(sta);
#endif
	*sta = 0;
	return 0;
}

void PL_sleep(int second)
{
	sleep(second);
}

size_t PL_GetPeakRSSMb(void) 
{
#ifndef _WIN32
  struct rusage usage;
  if (getrusage(RUSAGE_SELF, &usage))
    return 0;
    return usage.ru_maxrss >> 10;
#else
	return 0;
#endif
}

void PL_pthread_create(void* fun)
{
#ifndef _WIN32
	pthread_t ntid;
	pthread_create(&ntid, NULL, (void*)fun, NULL);
#endif
}


#ifdef __cplusplus
}
#endif

