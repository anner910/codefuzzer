
#include "../core/Core.h"

//#include<ctype.h>

#ifdef __cplusplus
extern "C"{
#endif

#ifdef CF_Mode_CorpusTxt


int corpus_parseValue(char* Str, char *out) 
{

  int i =0;
  size_t L = 0, R = lib_strlen(Str) - 1; 

  while (L < R && Str[L] != '"') L++;
  if (L >= R) return 0;

  L++;

  for (size_t Pos = L; Pos <= R; Pos++) {
    uint8_t V = (uint8_t)Str[Pos];
    if (!lib_isprint(V) && !lib_isspace(V)) return 0;

	//结束
	if (V =='\"')
		return 1;
		
    if (V =='\\') {
      // Handle '\\'
      if (Pos + 1 <= R && (Str[Pos + 1] == '\\' || Str[Pos + 1] == '"')) {
        out[i++] =Str[Pos + 1];
        Pos++;
        continue;
      }
      // Handle '\xAB'
      if (Pos + 3 <= R && Str[Pos + 1] == 'x'
           && lib_isxdigit(Str[Pos + 2]) && lib_isxdigit(Str[Pos + 3])) {
        char Hex[] = "0xAA";
        Hex[2] = Str[Pos + 2];
        Hex[3] = Str[Pos + 3];
        out[i++] = lib_strtol(Hex, NULL, 16);
        Pos += 3;
        continue;
      }
      return 0;  // Invalid escape.
    } else {
      // Any other character.
      out[i++] = V;
    }
  }
  return 1;
}


char* corpus_getStringValue(char* line)
{
	int i;
	int j;
	char* returnPos = NULL;;
	for(i = 0; ; i++)
	{
		if(line[i] == '=')
		{
			returnPos = line + i + 1;
			break;
		}
	}

	for(j = i; ; j++)
	{
		if((line[j] == '\r') || (line[j] == '\n'))
		{
			line[j] = 0;
			break;
		}
	}

	return returnPos;

}

void corpus_parse(char* line)
{
	int i;
	//一个样本解析开始
	if((line[0] == '#')&&(line[1] == 's'))
	{
		g_thread.tempParaNo = 0;
	     return;
	}

	//参数个数
	if((line[0] == 'p')&&(line[1] == 'a'))
	{
		char* value = corpus_getStringValue(line);
		g_thread.paraNumber = lib_atoi(value);

		SCorpus* corpus = &g_thread.corpus[g_thread.tempCorpusNo];
		corpus->paraValue = PL_malloc(g_thread.paraNumber * sizeof(SParaValue));
		corpus->isNeedFree = Return_Yes;
	    return;
	}

	//样本权重
	if((line[0] == 'w')&&(line[1] == 'e'))
	{
		char* value = corpus_getStringValue(line);

		SCorpus* corpus = &g_thread.corpus[g_thread.tempCorpusNo];
		corpus->corpusWeight = lib_atoi(value);

		schedule_corpusAddToken(g_thread.tempCorpusNo, corpus->corpusWeight);
	    return;
	}

	//一个样本解析结束
	if((line[0] == '#')&&(line[1] == 'e'))
	{
		g_thread.tempCorpusNo++;
	     return;
	}

	//一个参数解析开始
	if((line[0] == '#')&&(line[1] == 'p'))
	{
	     return;
	}

	//一个参数解析结束
	if((line[0] == '#')&&(line[1] == 'o'))
	{
		g_thread.tempParaNo++;
	     return;
	}

	if((line[0] == 't')&&(line[1] == 'y'))
	{
		char* value = corpus_getStringValue(line);
		
		for(i = 0; i < DataType_max; i++)
		{
			if(lib_strcmp(value, dataTypeName[i]) == 0)
				break;
		}

		g_thread.corpus[g_thread.tempCorpusNo].paraValue[g_thread.tempParaNo].dataType = i;
	    return;
	}

	if((line[0] == 'l')&&(line[1] == 'e'))
	{
		char* value = corpus_getStringValue(line);
		g_thread.corpus[g_thread.tempCorpusNo].paraValue[g_thread.tempParaNo].len= lib_atoi(value);
	    return;
	}

	if((line[0] == 'h')&&(line[1] == 'e'))
	{
		char* value = corpus_getStringValue(line);
		
		g_thread.corpus[g_thread.tempCorpusNo].paraValue[g_thread.tempParaNo].value = PL_malloc(g_thread.corpus[g_thread.tempCorpusNo].paraValue[g_thread.tempParaNo].len);
		corpus_parseValue(value, g_thread.corpus[g_thread.tempCorpusNo].paraValue[g_thread.tempParaNo].value);
		return;
	}

}

void corpus_readTxt(void)
{
	int len;
	char *buf;
	int i;
	int j = 0;
	
	IO_readFile(g_thread.setTestCasePath, &buf, &len);

	if(len == 0)
		return;

	if(buf[0] != '#')
	{
		PL_free(buf);
		return;
	}

	//样本0是代码中的样本
	g_thread.tempCorpusNo = 0;
	g_thread.tempParaNo = 0;

	//解析样本
	for(i = 0; i < len; i++)
	{
		g_thread.tempbuf[j++] = buf[i];

		if(buf[i] == '\n')
		{
			g_thread.tempbuf[j] = 0;
			corpus_parse(g_thread.tempbuf);
			j = 0;
		}
	}

	g_thread.corpusNumber = g_thread.tempCorpusNo;
	g_thread.highCorpusNumber = g_thread.tempCorpusNo;

	PL_free(buf);

	if (g_thread.corpusNumber != 0)
	{
		PL_printf("read corpus number is %d ,from file %s\r\n", g_thread.corpusNumber, g_thread.setTestCaseName);
	}
	return;
}



void corpus_printf(char * buf)
{
	if (g_thread.isNeedPrintfCorpus)
		PL_printf("%s", buf);
}

void corpus_writeTxt(char* path, int corpusNo)
{
	g_thread.tempbuf[0] = 0;
	PL_sprintf(g_thread.tempbuf, "#start corpus ---------------------------------\r\n");
	IO_writeFileTail(path, g_thread.tempbuf);
	corpus_printf(g_thread.tempbuf);

	g_thread.tempbuf[0] = 0;
	PL_sprintf(g_thread.tempbuf, "para number	=%d\r\n",g_thread.paraNumber);
	IO_writeFileTail(path, g_thread.tempbuf);
	corpus_printf(g_thread.tempbuf);

	g_thread.tempbuf[0] = 0;
	PL_sprintf(g_thread.tempbuf, "weight		=%d\r\n", llvm_getWeight());
	IO_writeFileTail(path, g_thread.tempbuf);
	corpus_printf(g_thread.tempbuf);
	
	int i;
	for(i = 0;i < g_thread.paraNumber; i++)
	{
		g_thread.tempbuf[0] = 0;
		PL_sprintf(g_thread.tempbuf, "#para%d------\r\n",i);
		IO_writeFileTail(path, g_thread.tempbuf);
		corpus_printf(g_thread.tempbuf);
		
		g_thread.tempbuf[0] = 0;
		PL_sprintf(g_thread.tempbuf, "type is		=%s\r\n",dataTypeName[g_thread.para[i].paraValue.dataType]);
		IO_writeFileTail(path, g_thread.tempbuf);
		corpus_printf(g_thread.tempbuf);

		g_thread.tempbuf[0] = 0;
		PL_sprintf(g_thread.tempbuf, "len is		=%d\r\n",g_thread.para[i].paraValue.len);
		IO_writeFileTail(path, g_thread.tempbuf);
		corpus_printf(g_thread.tempbuf);

		g_thread.tempbuf[0] = 0;
		PL_sprintf(g_thread.tempbuf, "mutator is	=%s\r\n",g_global.g_mutatorModule[g_thread.para[i].mutator]->name);
		IO_writeFileTail(path, g_thread.tempbuf);
		corpus_printf(g_thread.tempbuf);

		//整数打印

		g_thread.tempbuf[0] = 0;
		if(g_thread.para[i].paraValue.dataType == DataType_u8)
		{
			u8 temp = *(u8*)g_thread.para[i].paraValue.value;
			PL_sprintf(g_thread.tempbuf, "number is	=%d,0x%x\r\n",temp,temp);
		}

		if(g_thread.para[i].paraValue.dataType == DataType_u16)
		{
			u16 temp = *(u16*)g_thread.para[i].paraValue.value;
			PL_sprintf(g_thread.tempbuf, "number is	=%d,0x%x\r\n",temp,temp);
		}
		if(g_thread.para[i].paraValue.dataType == DataType_u32)
		{
			u32 temp = *(u32*)g_thread.para[i].paraValue.value;
			PL_sprintf(g_thread.tempbuf, "number is	=%d,0x%x\r\n",temp,temp);
		}
		if(g_thread.para[i].paraValue.dataType == DataType_u64)
		{
			u64 temp = *(u64*)g_thread.para[i].paraValue.value;
			PL_sprintf(g_thread.tempbuf, "number is	=%ld,0x%lx\r\n",temp,temp);
		}

		if(g_thread.para[i].paraValue.dataType == DataType_s8)
		{
			s8 temp = *(s8*)g_thread.para[i].paraValue.value;
			PL_sprintf(g_thread.tempbuf, "number is	=%d,0x%x\r\n",temp,temp);
		}

		if(g_thread.para[i].paraValue.dataType == DataType_s16)
		{
			s16 temp = *(s16*)g_thread.para[i].paraValue.value;
			PL_sprintf(g_thread.tempbuf, "number is	=%d,0x%x\r\n",temp,temp);
		}

		if((g_thread.para[i].paraValue.dataType == DataType_s32)
			||(g_thread.para[i].paraValue.dataType == DataType_NumberRange)
			||(g_thread.para[i].paraValue.dataType == DataType_NumberOnlyTable)
			||(g_thread.para[i].paraValue.dataType == DataType_NumberOutOfTable)
			||(g_thread.para[i].paraValue.dataType == DataType_NumberBasedOnTable))
		{
			s32 temp = *(s32*)g_thread.para[i].paraValue.value;
			PL_sprintf(g_thread.tempbuf, "number is	=%d,0x%x\r\n",temp,temp);
		}

		if(g_thread.para[i].paraValue.dataType == DataType_s64)
		{
			s64 temp = *(s64*)g_thread.para[i].paraValue.value;
			PL_sprintf(g_thread.tempbuf, "number is	=%ld,0x%lx\r\n",temp,temp);
		}

		if(g_thread.para[i].paraValue.dataType == DataType_float)
		{
			float temp = *(float*)g_thread.para[i].paraValue.value;
			PL_sprintf(g_thread.tempbuf, "number is	=%e,0x%x\r\n",temp,(s32)temp);
		}

		if(g_thread.para[i].paraValue.dataType == DataType_double)
		{
			double temp = *(double*)g_thread.para[i].paraValue.value;
			PL_sprintf(g_thread.tempbuf, "number is	=%e,0x%lx\r\n",temp,(s64)temp);
		}

		IO_writeFileTail(path, g_thread.tempbuf);
		corpus_printf(g_thread.tempbuf);

		//hexvalue
		g_thread.tempbuf[0] = 0;
		PL_sprintf(g_thread.tempbuf, "hexvalue is	=\"");
		IO_writeFileTail(path, g_thread.tempbuf);
		corpus_printf(g_thread.tempbuf);
		
		int j;
		int size = 0;
		g_thread.tempbuf[0] = 0;
		
		for(j = 0;j < g_thread.para[i].paraValue.len; j++)
		{
			size += PL_sprintf(g_thread.tempbuf + size, "\\x%02x", (u8)g_thread.para[i].paraValue.value[j]);
		}

		IO_writeFileTail(path, g_thread.tempbuf);
		corpus_printf(g_thread.tempbuf);
		
		g_thread.tempbuf[0] = 0;
		PL_sprintf(g_thread.tempbuf, "\"\r\n");
		IO_writeFileTail(path, g_thread.tempbuf);
		corpus_printf(g_thread.tempbuf);

		//value
		g_thread.tempbuf[0] = 0;
		PL_sprintf(g_thread.tempbuf, "stringvalue is  =\"");
		IO_writeFileTail(path, g_thread.tempbuf);
		corpus_printf(g_thread.tempbuf);

		
		size = 0;
		g_thread.tempbuf[0] = 0;
		
		for(j = 0;j < g_thread.para[i].paraValue.len; j++)
		{
			u8 temp = (u8)g_thread.para[i].paraValue.value[j];
			if((0x20 <= temp) && (temp <= 0x7e))
				size += PL_sprintf(g_thread.tempbuf + size, "%c", (u8)g_thread.para[i].paraValue.value[j]);
			else
				size += PL_sprintf(g_thread.tempbuf + size, "\\x%02x", (u8)g_thread.para[i].paraValue.value[j]);
		}

		IO_writeFileTail(path, g_thread.tempbuf);
		corpus_printf(g_thread.tempbuf);
		
		g_thread.tempbuf[0] = 0;
		PL_sprintf(g_thread.tempbuf, "\"\r\n");
		IO_writeFileTail(path, g_thread.tempbuf);
		corpus_printf(g_thread.tempbuf);


		g_thread.tempbuf[0] = 0;
		PL_sprintf(g_thread.tempbuf, "#over%d------\r\n",i);
		IO_writeFileTail(path, g_thread.tempbuf);
		corpus_printf(g_thread.tempbuf);

	}

	char date[64] = {0};
	PL_getData(date);

	g_thread.tempbuf[0] = 0;
	PL_sprintf(g_thread.tempbuf, "#end   corpus%d ------------%d---%s\r\n", g_thread.highCorpusNumber, corpusNo, date);
	IO_writeFileTail(path, g_thread.tempbuf);
	corpus_printf(g_thread.tempbuf);
}

#else

void corpus_readTxt(void)
{

}

void corpus_writeTxt(char* path, int corpusNo)
{

}


#endif

#ifdef __cplusplus
}
#endif


