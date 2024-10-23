//假设以不带头结点的循环链表表示队列并且只设一个指针指向队尾元素结点
//（注意不设头指针）。试编写相应的入队和出队算法。
#define ok 1
#define error 0
typedef int ElemType;
typedef int Status;
typedef struct node
{
    struct node* next;
    ElemType data;
}node;
typedef struct Queue
{
    node *rear;
    int size;
    int capacity;
    

}Queue;
Status QueueInit(Queue *q,int newcapacity)
{
    assert(q);
    q->rear=*q;
    q->size=0;
    q->capacity=newcapacity;
    return ok;
}
Status QueueInsert(Queue *q,ElemType val)
{
    assert(q);
    if(q->size==q->capacity)
    {
        return error;
    }
    node* temp=(node*)realloc(q->rear,sizeof(node));
    if(!temp)
    {
        exit(-1);
    }
    temp->data=val;
    temp->next=(*q);
    q->rear->next=temp;
    q->rear=temp;
    return ok;

}
Status QueueDelete(Queue *q)
{
    if(!q->size)
    {
        return error;
    }
    node *temp=q->rear;
    
    free(q->rear);
    q->rear=temp->next;
    return ok;
}