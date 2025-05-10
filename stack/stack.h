#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

#define error 0
#define ok 1

typedef int SElemType;
typedef int Status;
typedef struct stack 
{
    SElemType *data;
    int top;//用于指向栈顶指针，栈为空时为-1，栈中含有一个元素时为0
    int capacity;
}SqStack;

Status StackInit(SqStack *q);

Status Stackpush(SqStack *q,SElemType e);

Status StackDestory(SqStack *q);

Status Stackpop(SqStack *q,SElemType *e);

SElemType StackTop(SqStack *q);

bool StackEmpty(SqStack *q);

int StackSize(SqStack *q);