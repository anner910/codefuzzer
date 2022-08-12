/*************************************************************************************************************

找到原来有数字的字符串数字位置，用字符串数字替换

*************************************************************************************************************/

#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif
extern SMutator s_MdataNumberString;

int MdataNumberStringGetCount(SPara* para)
{
	return s_MdataNumberString.weight;
}

char* MdataNumberString0GetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	//开始位置
	int start = 0;
	//长度
	int len = 0;
	int i;
	
	//随机开始位置
	start = in_getWeightRandom(para->mutatorInitlen - 1);

	//找到第一个字符串整数
	for (i = start;i < para->mutatorInitlen;i++)
	{
		if ((0x30 <=para->mutatorInitvalue[i])
			&&(para->mutatorInitvalue[i] <= 0x39))
			break;
	}

	//没有字符数字
	if(i == para->mutatorInitlen)
	{
		PL_memcpy(para->paraValue.value, para->mutatorInitvalue,para->mutatorInitlen);
		para->paraValue.len = para->mutatorInitlen;
		return para->paraValue.value;
	}

	start = i;
	//找到有多少个字符串整数
	for (i = start;i < para->mutatorInitlen;i++)
	{
		if ((0x30 <=para->mutatorInitvalue[i])
			&&(para->mutatorInitvalue[i] <= 0x39))
			len++;
		else
			break;
	}
	
	if (len > 10)
		len = PL_random_range(1,10);

	char string[25];
	//目前只搞10进制的
	int weight = PL_random()% 100;
	{
		if(weight>70)
		{
			PL_memcpy(string, para->mutatorInitvalue + start, len);
			string[len] = 0;
			int number = lib_atoi(string);
			number = number + PL_random_range( -255, 255);
			lib_itoa(number, string,10);
		}
		else
		{
			int number = in_getMagicNumber();
    		lib_itoa(number, string,10);
		}
	}

	PL_memcpy(para->paraValue.value, para->mutatorInitvalue, start);
	PL_memcpy(para->paraValue.value + start, string, lib_strlen(string));
	PL_memcpy(para->paraValue.value + start + lib_strlen(string), para->mutatorInitvalue + start, para->mutatorInitlen - start);

	return para->paraValue.value;
}


size_t Mutate_ChangeASCIIInteger(uint8_t *Data, size_t Size,
                                                     size_t MaxSize) {
  if (Size > MaxSize) return 0;
  size_t B = PL_random_range(0, Size);
  while (B < Size && !lib_isdigit(Data[B])) B++;
  if (B == Size) return 0;
  size_t E = B;
  while (E < Size && lib_isdigit(Data[E])) E++;
  // now we have digits in [B, E).
  // strtol and friends don't accept non-zero-teminated data, parse it manually.
  uint64_t Val = Data[B] - '0';
  for (size_t i = B + 1; i < E; i++)
    Val = Val * 10 + Data[i] - '0';

  // Mutate the integer value.
  switch(PL_random_range(0, 5)) {
    case 0: Val++; break;
    case 1: Val--; break;
    case 2: Val /= 2; break;
    case 3: Val *= 2; break;
    case 4: Val = PL_random_range(0, Val * Val); break;
    default: ;
  }
  // Just replace the bytes with the new ones, don't bother moving bytes.
  for (size_t i = B; i < E; i++) {
    size_t Idx = E + B - i - 1;
    Data[Idx] = (Val % 10) + '0';
    Val /= 10;
  }
  return Size;
}


char* MdataNumberString1GetValue(SPara* para, int pos)
{
	in_mutatorParaGetBuf(para);

	para->paraValue.len = Mutate_ChangeASCIIInteger(para->paraValue.value, para->paraValue.len, para->maxlen);
	return para->paraValue.value;
}

char* MdataNumberStringGetValue(SPara* para, int pos)
{
    int weight = PL_random()% 100;

    if (weight > 50)
        return MdataNumberString0GetValue(para, pos);

    return MdataNumberString1GetValue(para, pos);
}


int MdataNumberStringGetSupport(SPara* para)
{
	//初始长度为0不支持
	if (para->mutatorInitlen == 0)
		return Return_No;
	
	//初始长度为0不支持
	return Return_Yes;
}


SMutator s_MdataNumberString =
{
	"MdataNumberString",
	MdataNumberStringGetCount,
	MdataNumberStringGetValue,
	MdataNumberStringGetSupport,
	Return_Yes,
	Mutator_BaseWeight,
};

void MdataNumberStringInit(void)
{

	g_global.g_mutatorModule[MdataNumberString] = &s_MdataNumberString;
}


#ifdef __cplusplus
}
#endif

