#define MAXSIZE 1000
#define error 0
#define ok 1
typedef int SElemType;
typedef int Status;
typedef struct 
{
    SElemType data[MAXSIZE];
    int top1;
    int top2;
}SqStack;

Status push(SqStack *q,int numstack,SElemType e)
{
    if(q->top1+1==q->top2)
    {
        return error;
    }
    else
    {
        if(numstack==1)
        {
            q->data[++q->top1]=e;
        }
        if(numstack==2)
        {
            q->data[--q->top2]=e;
        }
        return ok;
    }
}
