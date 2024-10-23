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

Status ListMerge(LinkList *a,LinkList *b)
{
    LinkList cura=(*a)->next;
    LinkList curb=(*b)->next;
    LinkList c=(LinkList)malloc(sizeof(node));;
    c->data=0;
    c->next=NULL;
    while(cura->next&&curb->next)
    {
        
        *a=(LinkList)realloc(*a,sizeof(node));
        if(cura->data<=curb->data)
        {
            c->data=cura->data;
            c->next=(*a)->next;
            (*a)->next=c;
        }
        else
        {
            c->data=curb->data;
            c->next=(*a)->next;
            (*a)->next=c;
        }
    }
    while(cura->next)
    {
        *a=(LinkList)realloc(*a,sizeof(node));
        c->data=cura->data;
        c->next=(*a)->next;
        (*a)->next=c;
    }
    while(curb->next)
    {
        *a=(LinkList)realloc(*a,sizeof(node));
        c->data=curb->data;
        c->next=(*a)->next;
        (*a)->next=c;
    }
    c->next=NULL;
    return ok;
}