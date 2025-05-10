#include"queue.h"
Status QueueInit(Queue *q)
{
    assert(q);
    q->head=NULL;
    q->tail=NULL;

    return ok;
}

Status QueueDestory(Queue *q)
{
    assert(q);
    QueueNode *cur=q->head;
    while(cur)
    {
        QueueNode *next=cur->next;
        free(cur);
        cur=next;
    }
    q->head=q->tail=NULL;
    return ok;
}

Status QueuePush(Queue *q,QElemType e)
{
    assert(q);
    QueueNode *temp=(QueueNode*)malloc(sizeof(QueueNode));
    temp->data=e;
    temp->next=NULL;

    if(q->head==NULL)
    {
        q->head=q->tail=temp;
    }
    else
    {
        q->tail->next=temp;
        q->tail=temp;
    }
    return ok;
}

Status QueuePop(Queue *q)
{
    assert(q);
    assert(q->head!=NULL);

    QueueNode *temp=q->head->next;
    free(q->head);
    q->head=temp;

    if(q->head==NULL)
    {
        q->tail=NULL;
    }
    return ok;
}

bool QueueEmpty(Queue *q)
{
    return q->head==NULL;
}

QElemType QueueFront(Queue *q)
{
    assert(q);
    assert(!QueueEmpty(q));
    return q->head->data;
}

QElemType QueueTail(Queue *q)
{
    assert(q);
    assert(!QueueEmpty(q));
    return q->tail->data;
}

int QueueSize(Queue *q)
{
    int count=0;
    QueueNode *temp=q->head;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    return count;
}