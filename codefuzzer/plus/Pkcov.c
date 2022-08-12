#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

#ifdef CF_Mode_Kcov

#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>


#define KCOV_INIT_TRACE _IOR('c', 1, unsigned long)
#define KCOV_ENABLE _IO('c', 100)
#define KCOV_DISABLE _IO('c', 101)
#define KCOV_ENTRY_SIZE sizeof(unsigned long)
#define KCOV_PATH "/sys/kernel/debug/kcov"
#define KCOV_TRACE_PC 0
typedef unsigned long cover_t;
#define COVER_SIZE (16 << 20)

int g_kcovFd;

cover_t *g_kcovCover;

void kcov_init(void)
{
	if(g_global.isKcovInit == 0)
		g_global.isKcovInit = 1;
	else
		return;
		
	g_kcovFd = open(KCOV_PATH, O_RDWR);
	if (g_kcovFd == -1)
		perror("open"), exit(1);
	
	if (ioctl(g_kcovFd, KCOV_INIT_TRACE, COVER_SIZE))
		perror("ioctl"), exit(1);
	
	g_kcovCover = (cover_t*)mmap(NULL, COVER_SIZE * KCOV_ENTRY_SIZE,
			       PROT_READ | PROT_WRITE, MAP_SHARED, g_kcovFd, 0);
	if ((void*)g_kcovCover == MAP_FAILED)
		perror("mmap"), exit(1);
}

void kcov_start(void)
{
	if (ioctl(g_kcovFd, KCOV_ENABLE, KCOV_TRACE_PC))
		perror("ioctl"), exit(1);

	__atomic_store_n(&g_kcovCover[0], 0, __ATOMIC_RELAXED);
}

void kcov_end(void)
{
	int n,i;
	n = __atomic_load_n(&g_kcovCover[0], __ATOMIC_RELAXED);
	for (i = 0; i < n; i++)
	{
		PL_printf("0x%jx\n", (uintmax_t)g_kcovCover[i + 1]);
		uintptr_t PC = (uintptr_t)g_kcovCover[i + 1];
		llvm_doTracePc(PC); 
	}

	if (ioctl(g_kcovFd, KCOV_DISABLE, 0))
		perror("ioctl"), exit(1);
}


void kcov_clean(void)
{
	if (close(g_kcovFd))
		perror("close"), exit(1);
}
#else
void kcov_init(void)
{
	
}

void kcov_start(void)
{
	
}

void kcov_end(void)
{
	
}

void kcov_clean(void)
{
	
}

#endif

#ifdef __cplusplus
}
#endif

