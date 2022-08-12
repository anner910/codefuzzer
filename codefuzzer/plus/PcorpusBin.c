
#include "../core/Core.h"

#include<ctype.h>

#include <dirent.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C"{
#endif

#ifdef CF_Mode_CorpusBin

//只有一个blob参数的时候才支持
void corpus_ReadBin(void)
{
	if (g_global.setInBinCorpusPath == NULL)
		return;
    DIR *dir;
    struct dirent *ptr;
    char base[500];
	char file[500];

	int len;
	char *buf;

	int tempNumber = g_thread.tempCorpusNo;

    if ((dir=opendir(g_global.setInBinCorpusPath)) == NULL)
    {
        perror("Open dir error...");
        exit(1);
    }

    while ((ptr=readdir(dir)) != NULL)
    {
        if(lib_strcmp(ptr->d_name,".")==0 || lib_strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
            continue;
        else if(ptr->d_type == 8)    ///file
        {
			file[0] = 0;
			PL_sprintf(file, "%s/%s",g_global.setInBinCorpusPath,ptr->d_name);

			IO_readFile(file, &buf, &len);

			SCorpus* corpus = &g_thread.corpus[g_thread.tempCorpusNo];
			corpus->paraValue = PL_malloc(1 * sizeof(SParaValue));
			corpus->isNeedFree = Return_Yes;

			corpus->paraValue[0].value = buf;
			corpus->paraValue[0].len = len;
			corpus->paraValue[0].dataType = DataType_blob;

			corpus->corpusWeight = Pc_Weight;
			corpus->corpusHash = 0;

			g_thread.tempCorpusNo++;

        }
    }
    closedir(dir);

	g_thread.corpusNumber = g_thread.tempCorpusNo;
	g_thread.highCorpusNumber = g_thread.tempCorpusNo;

	if ((g_thread.corpusNumber - tempNumber) != 0)
	{
		PL_printf("read corpus number is %d ,from dir %s\r\n", (g_thread.corpusNumber - tempNumber), g_global.setInBinCorpusPath);
	}
    return;
}


void corpus_WriteBin(int corpusNo) 
{
	char file[1000];
	
	if (g_global.setOutBinCorpusPath == NULL)
		return;

	file[0] = 0;
	PL_sprintf(file, "%s/codefuzzer_%x_%d",g_global.setOutBinCorpusPath,in_getParaHash(),corpusNo);

	IO_writeFile(file,g_thread.para[0].paraValue.value, g_thread.para[0].paraValue.len);
  
  return ;
}


#else
void corpus_ReadBin(void)
{

}

void corpus_WriteBin(int corpusNo) 
{

}

#endif

#ifdef __cplusplus
}
#endif


