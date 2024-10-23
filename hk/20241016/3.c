//请你实现一个循环队列，该循环队列可利用的空间大小等于n个int型变量的大小。实现以下功能：
//push x：将xxx加入到循环队列尾端。若循环队列已满，输出"full"(不含引号)，
//否则不输出任何内容。保证xxx为int型整数。
//    front：输出队首元素，队首不出队。若队列为空，输出"empty"(不含引号)。
//    pop：输出队首元素，且队首出队。若队列为空，输出"empty"(不含引号)。

#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

#define ok 1
#define error -1

typedef int Status;
typedef int ElemType;
typedef struct circlequeue
{
    ElemType *data;//定义一个数组存储数据
    int front;//队头
    int tail;//队尾
    
    int capacity;//定义能够储存的元素容量
}Queue;

Status queueinit(Queue *queue,int n)
{
    queue->data=(ElemType*)malloc(sizeof(ElemType)*(n+1));
    if(!queue->data)
    {
        exit(-1);
    }
    queue->front=queue->tail=0;
    
    queue->capacity=n+1;
    //容量必须是n+1,防止判空与判满的判断条件重复

    //在这里我把数组元素全部置成0，表示默认没有入队
    for(int i=0;i<queue->capacity;i++)
    {
        queue->data[i]=0;
    }
    return ok;
}

Status queuepush(Queue *queue,ElemType x)
{
    assert(queue);
    if((queue->tail+1)%(queue->capacity)==queue->front)
    {
        //这是队满的条件
        perror("full\n");
        return error;
    }
    else
    {
        
        queue->data[queue->tail]=x;
        int num=(queue->tail+1)%(queue->capacity);//用于处理tail在末尾的特殊情况
        queue->tail=num;
        
    }
    return ok;
}

ElemType queuefront(Queue queue)
{
    assert(&queue);
    if(queue.front==queue.tail)
    {
        //队空的条件
        perror("Empty\n");
        exit(-1);
    }
    else
    {
        return queue.data[queue.front];
    }
}

ElemType queuepop(Queue *queue)
{
    assert(queue);
    if(queue->front==queue->tail)
    {
        //队空的条件
        perror("Empty\n");
        exit(-1);
    }
    else
    {
        ElemType e=queue->data[queue->front];
        queue->data[queue->front]=0;
        queue->front=(queue->front+1)%(queue->capacity);
        return e;
    }
}

Status queueprint(Queue queue)
{
    assert(&queue);
    //需要加上打印终止的条件
    int x=queue.front;
    while(x!=queue.tail)
    {
        printf("%d->",queue.data[x]);
        x=(x+1)%(queue.capacity);
    }
    printf("NULL\n");
    return ok;
}

int main()
{
    int n=0;
    printf("请输入你循环队列的容量:");
    scanf("%d",&n);
    Queue q;

    queueinit(&q,n);

    queuepush(&q,1);
    
    queuepush(&q,2);
    
    queuepush(&q,3);
    

    queueprint(q);

    queuepop(&q);
    queueprint(q);
    queuepop(&q);
    queueprint(q);
    queuepop(&q);
    queueprint(q);

    queueprint(q);

    return 0;
}
