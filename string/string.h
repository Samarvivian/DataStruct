#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define error 0
#define ok 1
#define MAXSIZE 1000//在这里我们实现静态顺序串

typedef int SElemType;
typedef int Status;
typedef struct SqString
{
    int data[MAXSIZE];
    int len;//表示串长度
}SqString;

SqString* SqStringInit(void);

int SqStringlen(SqString *str);

bool SqStringEmpty(SqString *str);

bool SqStringEqual(SqString *str1,SqString *str2);
