//（3）建立链队列，并实现元素(4,5,7,6,8)入队，实现链队列的建立和入队的基本操作；
//（4）实现元素(5,7)出队，实现链队列的出队的基本操作；
//（5）有操作菜单。

#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

#define ok 1

typedef int Status;
typedef int ElemType;
typedef struct QueueNode
{
    ElemType data;
    struct QueueNode *next;
}QueueNode;
typedef struct Queue
{
    QueueNode *front;//队头
    QueueNode *tail;//队尾
}Queue;

Status QueueInit(Queue *queue)
{
    assert(queue);
    queue->front=queue->tail=NULL;
    return ok;
}

Status QueuePush(Queue *queue,ElemType x)
{
    assert(queue);
    QueueNode *newnode=(QueueNode*)malloc(sizeof(QueueNode));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->data=x;
    newnode->next=NULL;

    if(!queue->tail)//队空
    {
        queue->front=queue->tail=newnode;
    }
    else
    {
        queue->tail->next=newnode;
        queue->tail=newnode;
    }
    return ok;
}

Status QueuePop(Queue *queue)
{
    assert(queue);
    if(!queue->tail)//队空
    {
        perror("队空，无法出队\n");
        exit(-1);
    }
    else
    {
        if(queue->front!=queue->tail)//队列中的元素个数大于0
        {
            QueueNode *next=queue->front;
            queue->front=next->next;
            free(next);
        }
        else
        {
            queue->front=queue->tail=NULL;
        }
    }
    return ok;
}

Status QueuePrint(Queue queue)
{
    QueueNode *next=queue.front;
    while(next)
    {
        printf("%d->",next->data);
        next=next->next;
    }
    printf("NULL\n");
    return ok;
}

Status QueueDestory(Queue *queue)
{
    QueueNode *next=queue->front;
    while(next)
    {
        free(next);
        next=next->next;
    }
    queue->front=queue->tail=NULL;

    return ok;
}

void menu()
{
    printf("-----------操作,请选择-----------\n");
    printf("-----1.入队----2.出队---0.放弃------\n");
}

int main()
{
    Queue q;
    QueueInit(&q);

    // QueuePush(&q,1);
    // QueuePush(&q,2);
    // QueuePush(&q,3);
    // QueuePush(&q,4);
    // QueuePush(&q,5);

    // QueuePrint(q);

    // QueuePop(&q);
    // QueuePop(&q);
    // QueuePop(&q);
    // QueuePop(&q);
    // QueuePop(&q);

    // QueuePrint(q);

    int choice=0;//储存选择的选项
    menu();
    scanf("%d",&choice);

    int element=0;//储存入队出队的元素

    while(choice)
    {
        if(choice==1)
        {
            printf("请输入想要入队的元素:");
            scanf("%d",&element);

            QueuePush(&q,element);
            QueuePrint(q);
        }

        else if(choice==2)
        {
            QueuePop(&q);
            QueuePrint(q);
        }

        else
        {
            printf("输入错误，请重新输入\n");
        }
        menu();
        scanf("%d",&choice);


    }
    QueueDestory(&q);


    return 0;
}