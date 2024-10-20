#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

#define error 0
#define ok 1

typedef int QElemType;
typedef int Status;

typedef struct QueueNode{
     struct QueueNode *next;
    QElemType data;
}QueueNode;

typedef struct Queue
{
    QueueNode *head;
    QueueNode *tail;
}Queue;

Status QueueInit(Queue *q);

Status QueueDestory(Queue *q);

Status QueuePush(Queue *q,QElemType e);

Status QueuePop(Queue *q);

bool QueueEmpty(Queue *q);

QElemType QueueFront(Queue *q);

QElemType QueueTail(Queue *q);

int QueueSize(Queue *q);