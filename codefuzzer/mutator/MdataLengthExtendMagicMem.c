/*************************************************************************************************************

使用专有字符串扩展长度  

00，01, ff,  fe

来自魔法内存

从末尾添加

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataLengthExtendMagicMem;

int MdataLengthExtendMagicMemGetCount(SPara* para)
{
	return in_scheduleMutatorWeight(s_MdataLengthExtendMagicMem.weight);
}

char* MdataLengthExtendMagicMemGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	int len = in_getLen(para, pos);

	if (len < para->mutatorInitlen)
		len = PL_random_range(para->mutatorInitlen,para->mutatormaxlen);

	char*value;
	int unitlen;

	in_getMagicBlob(&value, &unitlen);

	int i;
	int j;
	int kkk = para->mutatorInitlen;
	int over = 0;

	if (unitlen == 0)
		over =1;

	for(i = 0;; i++)
	{
		for(j = 0; j < unitlen; j++)
		{
			if (kkk >= len)
			{
				over = 1;
				break;
			}
			para->paraValue.value[para->mutatorInitlen + j + i*unitlen] = value[j];
			kkk++;
		}
		if(over)
			break;
	}

	para->paraValue.len = len;

	return para->paraValue.value;
}


int MdataLengthExtendMagicMemGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataLengthExtendMagicMem =
{
	"MdataLengthExtendMagicMem",
	MdataLengthExtendMagicMemGetCount,
	MdataLengthExtendMagicMemGetValue,
	MdataLengthExtendMagicMemGetSupport,
	Return_Yes,
	Mutator_BaseWeight/10,
};

void MdataLengthExtendMagicMemInit(void)
{

	g_global.g_mutatorModule[MdataLengthExtendMagicMem] = &s_MdataLengthExtendMagicMem;
}


#ifdef __cplusplus
}
#endif

