



#include "Core.h"

#ifdef __cplusplus
extern "C"{
#endif

int lib_isprint(u8 v)
{
	if ((0x20 <= v) && (v <= 0x7e))
		return 1;
	return 0;
}

int lib_isspace(u8 v)
{
	if ((v == ' ') 
		|| (v == '\t')
		|| (v == '\n')
		|| (v == '\v')
		|| (v == '\f')
		|| (v == '\r'))
		return 1;
	return 0;
}

int lib_isxdigit(u8 v)
{
	if (('0' <= v) && (v <= '9'))
		return 1;
	if (('a' <= v) && (v <= 'f'))
		return 1;
	if (('A' <= v) && (v <= 'F'))
		return 1;
	return 0;
}

int lib_isdigit(u8 v)
{
	if (('0' <= v) && (v <= '9'))
		return 1;

	return 0;
}


#define LONG_MIN (-2147483647 - 1)
#define LONG_MAX (2147483647)

#define ERANGE 111
#define EINVAL 222


int errno111;

long lib_strtol(const char * nptr, char ** endptr, int base) 
{ 
    const char *s; 
    unsigned long acc; 
    char c; 
    unsigned long cutoff; 
    int neg, any, cutlim; 
        s = nptr; 
    do { 
        c = *s++; 
    } while (lib_isspace((unsigned char)c)); 
    if (c == '-') { 
        neg = 1; 
        c = *s++;         //去掉前导空格和+ - 符号 
    } else { 
        neg = 0; 
        if (c == '+') 
            c = *s++; 
    } 
    //判断进制,并去除前导0x或者0 
    if ((base == 0 || base == 16) && 
        c == '0' && (*s == 'x' || *s == 'X') && 
        ((s[1] >= '0' && s[1] <= '9') || 
        (s[1] >= 'A' && s[1] <= 'F') || 
        (s[1] >= 'a' && s[1] <= 'f'))) { 
        c = s[1]; 
        s += 2; 
        base = 16; 
    } 
    if (base == 0) 
        base = c == '0' ? 8 : 10; 
    acc = any = 0; 
    if (base < 2 || base > 36) 
        goto noconv; 
    
 /*判断溢出的方法:
 cutoff为系统能够表示的最大数除以base的结果，也就是当前进制能够表示的最大有效的数。
例如32为系统下长整形的范围是[-2147483648..2147483647]，如果base是10的话，则cutoff就是
214748364，而cutlim就是7(正整数)或者8(负整数)。如果当前算得的值大于cutoff就溢出了，或者等于cutoff但是下一位大于cutlim也就溢出了
*/
       cutoff = neg ? (unsigned long)-(LONG_MIN + LONG_MAX) + LONG_MAX 
        : LONG_MAX; 
    cutlim = cutoff % base; 
    cutoff /= base; 
    for ( ; ; c = *s++) { 
        if (c >= '0' && c <= '9') 
            c -= '0'; 
        else if (c >= 'A' && c <= 'Z') 
            c -= 'A' - 10; 
        else if (c >= 'a' && c <= 'z') 
            c -= 'a' - 10; 
        else 
            break; 
        if (c >= base) 
            break;                       
        //如果溢出则设置any为负数
        
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim)) 
            any = -1; 
        else { 
            any = 1; 
            acc *= base; 
            acc += c; 
        } 
    } 
    if (any < 0) {         //如果溢出就返回最大能表示的值
        acc = neg ? LONG_MIN : LONG_MAX; 
        errno111 = ERANGE; 
    } else if (!any) { 
noconv: 
        errno111 = EINVAL; 
    } else if (neg) 
        acc = -acc; 
    if (endptr != NULL)   
        *endptr = (char *)(any ? s - 1 : nptr); 
    return (acc); 
}


char* lib_itoa(int num,char* str,int radix)
{/*索引表*/
    char index[]="0123456789ABCDEF";
    unsigned unum;/*中间变量*/
    int i=0,j,k;
    /*确定unum的值*/
    if(radix==10&&num<0)/*十进制负数*/
    {
        unum=(unsigned)-num;
        str[i++]='-';
    }
    else unum=(unsigned)num;/*其他情况*/
    /*转换*/
    do{
        str[i++]=index[unum%(unsigned)radix];
        unum/=radix;
       }while(unum);
    str[i]='\0';
    /*逆序*/
    if(str[0]=='-')
        k=1;/*十进制负数*/
    else
        k=0;
     
    for(j=k;j<=(i-1)/2;j++)
    {       char temp;
        temp=str[j];
        str[j]=str[i-1+k-j];
        str[i-1+k-j]=temp;
    }
    return str;
}



int lib_memcmp(void *d,void *s,size_t n)
{
	int i;
	char* dd = (char*)d;
	char* ss = (char*)s;
	for(i = 0; i < n; i++)
	{
		if(dd[i] != ss[i])
			return 1;
	}

	return 0;
}

int lib_strcmp(void *d,void *s)
{
	int i;
	char* dd = (char*)d;
	char* ss = (char*)s;
	for(i = 0;; i++)
	{
		if (dd[i] == 0)
			if (ss[i] != 0)
				return 1;

		if (ss[i] == 0)
			if (dd[i] != 0)
				return 1;

		if (ss[i] == 0)
			if (dd[i] == 0)
				return 0;
		
		if(dd[i] != ss[i])
			return 1;
	}

	return 0;
}


int lib_strnlen(const char* s, int len)
{
	int i;
	for (i = 0; (i < len) && s[i]; i++);
	
	return i;
}



int lib_strlen(const char* s)
{
	int i;
	for (i = 0; s[i]; i++);
	return i;
}

int lib_strlen1(const char* s,const char* s1)
{
	int i;
	for (i = 0; s[i]&&s1[i]; i++);
	return i;
}

u32 lib_getTotalBit(u32 max)
{
	int i;
	for(i = 0; i < 32; i++)
	{
		if (max >= (1 << (32 - i)))
			return 32 - i;
	}
	return 0;
}

int lib_atoi(const char *nptr)
{
        int c;              /* current char */
        int total;         /* current total */
        int sign;           /* if '-', then negative, otherwise positive */

        /* skip whitespace */
        while ( lib_isspace((int)(unsigned char)*nptr) )
            ++nptr;

        c = (int)(unsigned char)*nptr++;
        sign = c;           /* save sign indication */
        if (c == '-' || c == '+')
            c = (int)(unsigned char)*nptr++;    /* skip sign */

        total = 0;

        while (lib_isdigit(c)) {
            total = 10 * total + (c - '0');     /* accumulate digit */
            c = (int)(unsigned char)*nptr++;    /* get next char */
        }

        if (sign == '-')
            return -total;
        else
            return total;   /* return result, negated if necessary */
}

#ifdef __cplusplus
}
#endif

