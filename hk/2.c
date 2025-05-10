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

Status ListDelete(Sqlist *q,ElemType x,ElemType y)
{
    int i=0,j=0;
    while((q->data[i+1]<=x)&&(i<q->length))
    {
        i++;
    }
    j=i;
    while((q->data[j]<=y)&&(j<q->length))
    {
        j++;
    }
    int k1=i,k2=j;
    while(k2<q->length)
    {
        q->data[k1+1]=q->data[k2];
        k1++;
        k2++;
    }
    q->length-=j-i;
    return ok;
}

