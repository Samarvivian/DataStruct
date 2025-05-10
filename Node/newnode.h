//在原有基础上做一些改进
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define ok 1
#define error 0
typedef int Status;
typedef int ElemType;
typedef struct SListNode
{
    ElemType data;
    struct SListNode* next;
}SLTNode;

Status SLTPrint(SLTNode *phead);

Status SLTPushBack1(SLTNode **pphead,ElemType x);//带头节点的尾插，至于为什么要传入二级指针，在接下来不带头节点的插入中再详细说明

Status SLTPushBack2(SLTNode **pphead,ElemType x);

Status SLTPushHead1(SLTNode **pphead,ElemType x);//无头节点的头插法

Status SLTPushHead2(SLTNode **pphead,ElemType x);//有头节点的头插法

Status SLTPopBack(SLTNode **pphead);//无头节点的尾删法

Status SLTPopHead(SLTNode **pphead);//无头节点的头删法

SLTNode* SLTFind1(SLTNode *phead,ElemType x);//找到链表中值为x的元素，并返回地址

Status SLTInsert1(SLTNode **pphead,SLTNode *pos,ElemType x);//在pos位置前面插入x值的元素

Status SLTInsertAfter(SLTNode **pphead,SLTNode *pos,ElemType x);//在Pos之后插入元素

Status SLTInsertAfter2(SLTNode *pos,ElemType x);//在pos之后插入元素的第二种方法

Status SLTErase(SLTNode **pphead,SLTNode *pos);//删除pos位置的结点

Status SLTEraseAfter(SLTNode *pos);//删除pos位置之后的结点