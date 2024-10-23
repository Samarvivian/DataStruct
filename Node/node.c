#include"node.h"
Status GetElem(LinkList L,int i,ElemType *e)
{
    LinkList cur=L->next;
    int j=0;
    while(cur||j<i)
    {
        cur=cur->next;
        ++j;
    }
    if(!cur||j>i)
    {
        return error;
    }
    *e=cur->data;
    return ok;

}

Status ListInsert(LinkList L,int i,ElemType e)
{
    LinkList cur,newnode;
    cur=L->next;
    int j=1;
    while(cur&&j<i)
    {
        cur=cur->next;
        ++j;
    }
    if(!cur||j>i)
    {
        return error;
    }
    newnode=(LinkList*)malloc(sizeof(node));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->data=e;
    newnode->next=cur->next;
    cur->next=newnode;
    return ok;
}

Status ListDelete(LinkList L,int i,ElemType *e)
{
    LinkList cur=L->next;
    int j=1;
    while(cur&&j<i)
    {
        cur=cur->next;
        ++j;
    }
    if(!cur||j>i)
    {
        return error;
    }
    LinkList q=cur->next;
    cur->next=q->next;
    *e=q->data;
    free(q);

    return ok;
}

Status CreateListHead(LinkList *L)
{
    LinkList cur;
    srand(time(0));//产生随机化种子
    *L=(LinkList*)malloc(sizeof(node));
    if(!*L)
    {
        exit(-1);
    }
    (*L)->next=NULL;
    cur->data=rand()%100+1;//产生100以内的数字
    cur->next=(*L)->next;
    (*L)->next=cur;

    return ok;
}

Status CreateListTail(LinkList *L)
{
    LinkList cur;
    LinkList r=*L;
    srand(time(0));//产生随机化种子
    *L=(LinkList*)malloc(sizeof(node));
    if(!*L)
    {
        exit(-1);
    }
    
    cur->data=rand()%100+1;//产生100以内的数字
    r->next=cur->next;
    r=cur;


    r->next=NULL;
    return ok;
}

Status ClearList(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;
    while(p)
    {
        q=p->next;==
        free(p);
        p=q;
    }
    (*L)->next=NULL;

    return ok;
}
