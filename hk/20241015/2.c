//59	假设以不带头结点的循环链表表示队列并且只设一个指针指向队尾元素结点（注意不设头指针）。
//试编写相应的入队和出队算法

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define ok 1

typedef int Status;
typedef int ElemType;
typedef struct Node
{
    struct Node *next;
    ElemType data;
    
}Node;

typedef struct Queue
{
    Node *Tail;
}Queue;

Status QueueInit(Queue *q)
{
    q->Tail=NULL;
    
    
    return ok;
}

Status QueuePrint(Queue q)
{
    
    
    if(q.Tail)//要注意这里需要看q.Tail是否指向空，即队列是否为空
    {
        Node *next=q.Tail->next;
        while(next!=q.Tail)
        {
            printf("%d->",next->data);
            next=next->next;
        }   
        printf("%d->",q.Tail->data);
    }
    printf("NULL\n");
    return ok;
}

Status QueuePush(Queue *q,ElemType x)
{
    assert(q);
    Node *newnode=(Node*)malloc(sizeof(Node));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->data=x;

    if(q->Tail==NULL)
    {
        newnode->next=newnode;//形成循环
    }
    else
    {
        newnode->next=q->Tail->next;
        q->Tail->next=newnode;
    }
    q->Tail=newnode;//更新尾指针

    return ok;
}

Status QueuePop(Queue *q)
{
    assert(q);
    assert(q->Tail);
    if(q->Tail->next!=q->Tail)//判断是否只剩一个元素
    {
        Node *newnode=q->Tail->next;
        Node *next=newnode->next;
        free(newnode);
        newnode=NULL;
        q->Tail->next=next;
    }
    else
    {
        
        free(q->Tail);
        q->Tail=NULL;
    }
    return ok;
}

int main()
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q,1);
    QueuePush(&q,2);
    QueuePush(&q,3);
    QueuePush(&q,4);

    QueuePrint(q);

    QueuePop(&q);
    QueuePop(&q);
    QueuePop(&q);
    QueuePop(&q);

    QueuePrint(q);

    return 0;
}
