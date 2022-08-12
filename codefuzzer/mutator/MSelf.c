#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif

extern SMutator s_MSelf;

int MSelfGetCount(SPara* para)
{
	return s_MSelf.weight;
}

char* MSelfGetValue(SPara* para, int pos)
{
	in_mutatorParaGetInitBuf(para);

	//选取变异位置

	PL_memcpy(para->paraValue.value , "self", 5);
	
	para->paraValue.len = 5;
	return para->paraValue.value;
}

int MSelfGetSupport(SPara* para)
{
	if(para->paraValue.dataType == DataType_myself)
		return Return_Yes;
	
	return Return_No;
}

SMutator s_MSelf =
{
	"MSelf",
	MSelfGetCount,
	MSelfGetValue,
	MSelfGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MSelfInit(void)
{

	g_global.g_mutatorModule[MSelf] = &s_MSelf;
}


#ifdef __cplusplus
}
#endif

