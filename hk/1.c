#define ok 1
#define error 0
#define MAXSIZE 20
typedef int ElemType;
typedef int Status;

typedef struct 
{
    ElemType data[MAXSIZE];
    int length;
}Sqlist;

Status ListInsert(Sqlist *q,ElemType e)
{
    int j=0;
    if(q->length==MAXSIZE)
    {
        return error;
    }
    
    else if(e<q->data[q->length])
    {
        for(j=q->length-1;q->data[j]>=e;j--)
        {
            q->data[j+1]=q->data[j];
        }
    }
    q->data[j]=e;
    q->length++;
    return ok;
}
