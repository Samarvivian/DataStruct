#include"stack.h"


Status StackInit(SqStack *q)
{
    assert(q);
    q->data=NULL;
    q->top=-1;
    q->capacity=0;

    return ok;
}

Status Stackpush(SqStack *q,SElemType e)
{
    assert(q);

    if(q->top==q->capacity-1)
    {
        int newcapacity=q->capacity==0?4:q->capacity*2;
        SElemType *temp=realloc(q->data,sizeof(SElemType)*newcapacity);
        if(temp==NULL)
        {
            exit(-1);
        } 
        else
        {
            q->data=temp;
            q->capacity=newcapacity;
        }
    }

    q->data[++q->top]=e;
    
    return ok;
}

Status StackDestory(SqStack *q)
{
    assert(q);
    free(q->data);
    q->data=NULL;
    q->top=-1;
    q->capacity=0;
}


Status Stackpop(SqStack *q)
{
    assert(q);
    if(q->top==-1)
    {
        return error;
    }
    else
    {
        
        q->top--;
        return ok;
    }
}

SElemType StackTop(SqStack *q)
{
    assert(q);
    assert(q->top>-1);
    return q->data[q->top];
}

bool StackEmpty(SqStack *q)
{
    return q->top==-1;
}

int StackSize(SqStack *q)
{
    return q->top+1;
}