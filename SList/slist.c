#include"slist.h"
SList* SListInit()
{
    SList *sl=(SList*)malloc(sizeof(SList));
    if(!sl)
    {
        exit(-1);
    }
    sl->prev=sl;
    sl->tail=sl;

    return sl;
}

Status SListPushBack(SList *sl,ElemType x)
{
    //因为这是带有哨兵位的头节点的链表
    //sl就是一个指向头节点的头指针
    //如果在初始化传入参数时，应该是指针的指针
    //但是在尾插的时候，改变的是sl指向的结构体的前驱和后继
    //没有改变sl
    //所以只需要传入一级指针

    assert(sl);
    SList* newnode=(SList*)malloc(sizeof(SList));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->data=x;

    SList *node=sl->prev;//原来最后一个结点
    
    node->tail=newnode;
    newnode->prev=node;
    newnode->tail=sl;
    sl->prev=newnode;

    return ok;
}

Status SListPrint(SList *sl)
{
    assert(sl);

    SList *node=sl->tail;
    while(node!=sl)
    {
        printf("%d",node->data);
        node=node->tail;
    }
    printf("\n");
    return ok;
}