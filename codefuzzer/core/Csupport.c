

#include "Core.h"

#ifdef __cplusplus
extern "C"{
#endif

//用户新家变异算法，在这里定义支持关系比较简单清晰
int support(int type, int mutator)
{
	if (type == DataType_myself)
	{
		if (mutator == MSelf)
			return Return_Yes;
		else
			return Return_No;
	}

	if (mutator == MSelf)
	{
		if (type == DataType_myself)
			return Return_Yes;
		else
			return Return_No;
	}

	if (type == DataType_NumberOnlyTable)
	{
		if (mutator == MNumberTable)
			return Return_Yes;
		else
			return Return_No;
	}

	if (type == DataType_stringOnlyTable)
	{
		if (mutator == MStringTable)
			return Return_Yes;
		else
			return Return_No;
	}

	if (type == DataType_blobOnlyTable)
	{
		if (mutator == MBlobTable)
			return Return_Yes;
		else
			return Return_No;
	}

	if (mutator == MNumberRange)
	{
		if(type == DataType_NumberRange)
			return Return_Yes;
		else
			return Return_No;
	}

	if (mutator == MStringTable)
	{
		if((type == DataType_stringOnlyTable) 
		||(type == DataType_stringOutOfTable)
		||(type == DataType_stringBasedOnTable))
			return Return_Yes;
		else
			return Return_No;
	}

	if (mutator == MBlobTable)
	{
		if((type == DataType_blobOnlyTable) 
		||(type == DataType_blobOutOfTable)
		||(type == DataType_blobBasedOnTable))
			return Return_Yes;
		else
			return Return_No;
	}

	if (mutator == MNumberTable)
	{
		if((type == DataType_NumberOnlyTable) 
		||(type == DataType_NumberOutOfTable)
		||(type == DataType_NumberBasedOnTable))
			return Return_Yes;
		else
			return Return_No;
	}

	if ((mutator == MNumberEdge)
		||(mutator == MNumberGauss)
		||(mutator == MNumberLittleRandom)
		||(mutator == MNumberMagic)
		||(mutator == MNumberRandom)
		||(mutator == MNumberSwap))
	{
		if((type == DataType_u8) 
		||(type == DataType_u16)
		||(type == DataType_u32)
		||(type == DataType_u64)
		||(type == DataType_s8)
		||(type == DataType_s16)
		||(type == DataType_s32)
		||(type == DataType_s64)
		||(type == DataType_float)
		||(type == DataType_double)
		||(type == DataType_NumberOutOfTable)
		||(type == DataType_NumberBasedOnTable))
			return Return_Yes;
		else
			return Return_No;
	}

	return Return_Yes;
}


//其他函数
#ifdef __cplusplus
}
#endif

