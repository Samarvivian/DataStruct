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

Status ListChange(LinkList *heada,LinkList *headb,int i,int len,int j)
{
    int k1=1,k2=1;
    LinkList cura=(*heada)->next;
    LinkList curb=(*headb)->next;
    while(cura->next&&k1<i-1)
    {
        cura=cura->next;
        k1++;
    }
    while(curb->next&&k2<j-1)
    {
        curb=curb->next;
        k2++;
    }
    int k=1;
    ElemType e=0;
    while(k<=len)
    {
        e=cura->next->data;
        LinkList q=cura->next;
        cura->next=cura->next->next;
        free(q);

        LinkList newnode=(LinkList *)malloc(sizeof(node));
        if(!newnode)
        {
            return error;
        }
        newnode->data=e;
        curb->next=newnode->next;
        curb->next=newnode;

        k++;
        


    }
    return ok;
}