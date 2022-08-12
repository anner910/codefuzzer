
#include "Core.h"

#ifdef __cplusplus
extern "C"{
#endif


int schedule_paraIsNeedMutator(SPara* para)
{
	//不变异
	if(para->mutatorFrequency >= 101)
	{
		return 0;
	}

	//根据设置变异
	if(para->mutatorFrequency > 0)
	{
		int temp = PL_random()%100;

		if (temp < para->mutatorFrequency)
			return 1;
	}

	//整体调度
	int temp1 = PL_random()%100;

	//100%
	if (g_thread.paraNumber == 1)
		return 1;

	//70%
	if (g_thread.paraNumber == 2)
		if(temp1 < 70)
			return 1;
	//50%
	if (g_thread.paraNumber == 3)
		if(temp1 < 50)
			return 1;

	//40%
	if (g_thread.paraNumber == 4)
		if(temp1 < 40)
			return 1;

	//30%
	if (g_thread.paraNumber == 5)
		if(temp1 < 30)
			return 1;

	//25%
	if (g_thread.paraNumber == 6)
		if(temp1 < 25)
			return 1;

	//以后再优化
	if(temp1 < 20)
			return 1;

	return 0;

}


int schedule_corpusGetTokenTotalH(void)
{
	return g_global.setMaxCorpusNumber * 50;
}

int schedule_corpusGetTokenTotalM(void)
{
	return g_global.setMaxCorpusNumber * 50;
}

int schedule_corpusGetTokenTotalL(void)
{
	return g_global.setMaxCorpusNumber * 2;
}

void schedule_corpusAddToken(int corpusNo, int weight)
{
	int i;
	//增加到高级队列
	if (weight >= PcCycle_Weight)
	{	
		if (weight > 200)
			weight = 200;
		
		for(i = 0; i < weight; i++)
		{
			g_thread.tokenH[g_thread.tokenHpos++] = corpusNo;
			g_thread.tokenHtotal++;
			if (g_thread.tokenHpos == schedule_corpusGetTokenTotalH())
				g_thread.tokenHpos = 0;
		}
	}

	//增加到中级队列
	if (weight >= PcEdge_Weight * 2)
	{	
		if (weight > 50)
			weight = 50;
		
		for(i = 0; i < weight; i++)
		{
			g_thread.tokenM[g_thread.tokenMpos++] = corpusNo;
			g_thread.tokenMtotal++;
			if (g_thread.tokenMpos == schedule_corpusGetTokenTotalM())
				g_thread.tokenMpos = 0;
		}
	}

	//增加到低级队列,所有样本都加入低级队列，公平对待

	g_thread.tokenL[g_thread.tokenLpos++] = corpusNo;
	g_thread.tokenLtotal++;
	if (g_thread.tokenLpos == schedule_corpusGetTokenTotalL())
		g_thread.tokenLpos = 0;

}


int schedule_corpus(void)
{

	int temp = PL_random()%100;
	int no = 0;

	//百分之40高优先级队列
	if (temp > 60)
	{
		if(g_thread.tokenHtotal == 0)
			return 0;
		
		if (g_thread.tokenHtotal < schedule_corpusGetTokenTotalH())
			return g_thread.tokenH[PL_random() % g_thread.tokenHtotal];
		else
			return g_thread.tokenH[PL_random() % schedule_corpusGetTokenTotalH()];
	}

	//百分之30中优先级队列
	if (temp > 30)
	{
		if(g_thread.tokenMtotal == 0)
			return 0;
		
		if (g_thread.tokenMtotal < schedule_corpusGetTokenTotalM())
			return g_thread.tokenM[PL_random() % g_thread.tokenMtotal];
		else
			return g_thread.tokenM[PL_random() % schedule_corpusGetTokenTotalM()];
	}

	if(g_thread.tokenLtotal == 0)
		return 0;

	if (g_thread.tokenLtotal < schedule_corpusGetTokenTotalL())
			return g_thread.tokenL[PL_random() % g_thread.tokenLtotal];
		else
			return g_thread.tokenL[PL_random() % schedule_corpusGetTokenTotalL()];


	return 0;

}


#ifdef __cplusplus
}
#endif


