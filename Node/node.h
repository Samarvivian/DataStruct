#include<stdlib.h>
#define ok 1
#define error 0
typedef int Status;
typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node* next;
}node;
typedef struct node *LinkList;

Status GetElem(LinkList L,int i,ElemType *e);//找到第i个元素

Status ListInsert(LinkList L,int i,ElemType e);//在第i个位置之前插入e

Status ListDelete(LinkList L,int i,ElemType *e);//删除第i个结点的元素

Status CreateListHead(LinkList *L);//头插法，随机产生数字

Status CreateListTail(LinkList *L);//尾插法

Status ClearList(LinkList *L);//销毁链表