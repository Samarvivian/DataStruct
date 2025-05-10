#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#define ok 1
typedef int Status;
typedef int ElemType;
typedef struct SList
{
    ElemType data;
    struct SList *prev;
    struct SList *tail;
}SList;

SList* SListInit();//初始化有头双向循环链表

Status SListPushBack(SList *sl,ElemType x);//尾插

Status SListPrint(SList *sl);//打印