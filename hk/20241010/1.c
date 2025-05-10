//循环队列删除元素
#define ok 1
#define error -1
typedef int ElemType;
typedef int Status;
typedef struct Queue
{
    ElemType *data;
    int front;
    int rear;
    int capacity;
}Queue;
Status QueueInit(Queue *q,int size)
{
    Queue *temp=(Quque*)malloc(sizeof(Queue)*(size+1));
    if(!temp)
    {
        return error;
    }
    q->data=temp;
    q->front=q->rear=0;
    q->capacity=size;
    return ok;
}
Status QueueDelete(Queue *q)
{
    assert(q);
    q->front=(q->front+1)%(q->capacity+1);//用于front位于最后一个结点需要循环回去时
    return ok;
}
