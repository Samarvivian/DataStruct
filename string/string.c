#include"string.h"
SqString* SqStringInit(void)
{
    SqString *str=(SqString*)malloc(sizeof(SqString));
    if(!str)
    {
        exit(-1);
    }
    memset(str->data,0,sizeof(str->data));//将数组中的元素全部初始化为0
    str->len=0;
    return str;
}

int SqStringlen(SqString *str)
{
    return str->len;
}

bool SqStringEmpty(SqString *str)
{
    return str->len==0;
}

bool SqStringEqual(SqString *str1,SqString *str2)
{
    return (strcmp(str1->data,str2->data2)==0);
}