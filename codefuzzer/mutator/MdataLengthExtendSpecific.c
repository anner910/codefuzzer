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
extern SMutator s_MdataLengthExtendSpecific;

int MdataLengthExtendSpecificGetCount(SPara* para)
{
	return in_scheduleMutatorWeight(s_MdataLengthExtendSpecific.weight);
}

char* MdataLengthExtendSpecificGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	int len = in_getLen(para, pos);

	if (len < para->mutatorInitlen)
		len = PL_random_range(para->mutatorInitlen,para->mutatormaxlen);


	u8 aaa;
	char*value;
	int unitlen;
	int temp = PL_random()%4;

	if (temp == 0)
		aaa = 0x00;

	if (temp == 1)
		aaa = 0x01;

	if (temp == 2)
		aaa = 0xff;

	if (temp == 3)
		aaa = 0xfe;

	unitlen = 1;
	value = (char*)&aaa;

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


int MdataLengthExtendSpecificGetSupport(SPara* para)
{
	return Return_Yes;
}

SMutator s_MdataLengthExtendSpecific =
{
	"MdataLengthExtendSpecific",
	MdataLengthExtendSpecificGetCount,
	MdataLengthExtendSpecificGetValue,
	MdataLengthExtendSpecificGetSupport,
	Return_Yes,
	Mutator_BaseWeight/10,
};

void MdataLengthExtendSpecificInit(void)
{

	g_global.g_mutatorModule[MdataLengthExtendSpecific] = &s_MdataLengthExtendSpecific;
}


#ifdef __cplusplus
}
#endif

