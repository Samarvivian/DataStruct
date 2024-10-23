#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define error 0
#define ok 1



typedef int Status;
typedef struct SqString
{
    char *data;
    int len;//表示串长度
}SqString;

SqString* SqStringInit(void);

Status SqStringAssign(SqString *str,char *data);//将data数组里的元素赋值给字符串

Status SqStringPrint(SqString str);

void forcematch(SqString *master,SqString *sub);//字符串暴力匹配

Status KMP(SqString *str,SqString *sub,int pos);//KMP算法，从第pos个位置开始匹配

// int SqStringlen(SqString *str);

// bool SqStringEmpty(SqString *str);

// bool SqStringEqual(SqString *str1,SqString *str2);
