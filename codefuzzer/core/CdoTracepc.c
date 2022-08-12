#include "Core.h"

#ifdef __cplusplus
extern "C"{
#endif

int llvm_isHasFeacher(void) 
{
	return g_thread.hasNewFeather;
}

int llvm_getWeight(void) 
{
	return g_thread.featherWeight;
}

void llvm_ClearFeacher(void) 
{
	g_thread.hasNewFeather = 0;
	g_thread.featherWeight = 0;
	return;
}

void llvm_doTracePc(uintptr_t PC) 
{
	int Idx = PC % g_global.setMaxPcNumber;

	//pc
	if(g_thread.llvm.trace_pc[Idx] == 0)
	{
		g_thread.llvm.trace_pc[Idx] = PC;
		if (g_global.setPcWeight)
		{
			g_thread.hasNewFeather = 1;
			g_thread.featherWeight +=g_global.setPcWeight;
		}
		g_thread.pcTotal++;
	}

	//hash
	//cycl
	g_thread.llvm.trace_pc_count[Idx]++;
	if (g_thread.llvm.trace_pc_count[Idx] == 1)
	{
		g_thread.llvm.hash += PC;
		g_thread.llvm.idx[g_thread.llvm.idxCount++] = Idx;
	}

	//edge
	uintptr_t temp_pc = g_thread.llvm.old_pc ^ (PC << 10);
	
	//相反跳转做个偏移
	if (PC < g_thread.llvm.old_pc)
		temp_pc = temp_pc + 16807;
	
	int edag_Idx = temp_pc % g_global.setMaxPcNumber;
	g_thread.llvm.old_pc = PC;
	
	if(g_thread.llvm.trace_pc_edge[edag_Idx] == 0)
	{
		g_thread.llvm.trace_pc_edge[edag_Idx] = temp_pc;
		
		if (g_global.setEdgeWeight)
		{
			g_thread.hasNewFeather = 1;
			g_thread.featherWeight +=g_global.setEdgeWeight;
		}

		g_thread.edgeTotal++;
	}
}

void llvm_do_bit(int idx, int bit) 
{
	if (bit == 0)
		return;
	bit = bit -1;
	if ((g_thread.llvm.trace_pc_count_bit[idx] & (1<<bit)) == 0)
	{
		if (g_global.setCycleWeight)
		{
			g_thread.hasNewFeather = 1;
			g_thread.featherWeight +=g_global.setCycleWeight;
		}
		g_thread.llvm.trace_pc_count_bit[idx] = g_thread.llvm.trace_pc_count_bit[idx] | (1<<bit);
		g_thread.cycleTotal++;
	}
}
int g_bitmap[32]= 
{
2,
3,
4,
5,
6,
7,
8,
9,
10,
11,
12,
13,
14,
15,
16,
32,
33,
63,
64,
65,
255,
256,
257,
1023,
1024,
1025,
32767,
32768,
32769,
65534,
65535,
65536,
};

void llvm_do(void) 
{
	//没有使用trace-pc
	if (g_thread.llvm.hash == 0)
		return;
	
	//hash
	int hash_Idx = g_thread.llvm.hash % g_global.setMaxPcNumber;
	if(g_thread.llvm.trace_pc_hash[hash_Idx] == 0)
	{
		g_thread.llvm.trace_pc_hash[hash_Idx] = g_thread.llvm.hash;
		if (g_global.setPathWeight)
		{
			g_thread.hasNewFeather = 1;
			g_thread.featherWeight +=g_global.setPathWeight;
		}

		g_thread.hashTotal++;
	}

	//cycl

	int i;
	for (i = 0; i < g_thread.llvm.idxCount; i++)
	{
		int temp = g_thread.llvm.idx[i];
		int count = g_thread.llvm.trace_pc_count[temp];

		int j;

		for (j = 0; j< 32; j++)
		{
			if (count < g_bitmap[j])
			{
				llvm_do_bit(temp, j);
				break;
			}
		}

		if (j == 16)
			llvm_do_bit(temp, j);

		g_thread.llvm.idx[i] = 0;
		g_thread.llvm.trace_pc_count[temp] = 0;
	}

	g_thread.temp_hash = g_thread.llvm.hash;
	
	g_thread.llvm.idxCount = 0;
	g_thread.llvm.hash= 0;
	g_thread.llvm.old_pc = 0;
}


#ifdef __cplusplus
}
#endif

