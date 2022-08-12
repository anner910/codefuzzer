

#include "../core/Core.h"


#ifdef __cplusplus
extern "C"{
#endif

#ifdef CF_Mode_IO

void IO_readFile(char* path, char** buf, int* len)
{
	int InputLen;
	char *Buf;
	FILE *In = fopen(path, "r");
	{
		*len = 0;
		*buf = NULL;
		if (!In) return;
	}
	
	fseek(In, 0, SEEK_END);
	
	InputLen = ftell(In);
	fseek(In, 0, SEEK_SET);
	
	Buf = (char*)PL_malloc(InputLen + 1);
	
	fread(Buf, 1, InputLen, In);
	fclose(In);

	Buf[InputLen] = 0;
	*len = InputLen + 1;
	*buf = Buf;
	return;
}

void IO_writeFileTail(char* path, char* buf)
{

  FILE *Out = fopen(path, "a+");
  if (!Out) return;
  fprintf(Out, "%s", buf);
  fclose(Out);
}

void IO_writeFile(char* path, char* buf, int len)
{

  FILE *Out = fopen(path, "w");
  if (!Out) return;
  fwrite(buf, len, 1, Out);
  fclose(Out);
}

#else

void IO_readFile(char* path, char** buf, int* len)
{
	*len = 0;
	*buf = NULL;

	return;
}

void IO_writeFileTail(char* path, char* buf)
{

}

void IO_writeFile(char* path, char* buf, int len)
{

}

#endif



#ifdef __cplusplus
}
#endif


