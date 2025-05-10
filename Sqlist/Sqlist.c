#include"Sqlist.h"
Status GetElem(Sqlist q,int i,ElemType *e)
{
    if((i<1)||(i>q.length)||(q.length==0))
    {
        return error;
    }
    else
    {
        *e=q.data[i-1];
    }
    return ok;
}

Status SqlistInsert(Sqlist *q,int i,ElemType e)
{
    if(q->length==MAXSIZE)
    {
        return error;
    }
    else if(i<1||i>q->length)
    {
        return error;
    }
    else if(i<q->length)
    {
        for(int j=q->length;j>=i-1;j--)
        {
            q->data[j+1]=q->data[j];
        }
    }
    q->data[i-1]=e;
    q->length++;
    return ok;

}

Status SqlistDelete(Sqlist *q,int i,ElemType* e)
{
    if(q->length==0)
    {
        return error;
    }
    if(i<1||i>q->length)
    {
        return error;
    }
    *e=q->data[i-1];
    if(i<q->length)
    {
        for(int j=i-1;j<q->length;j++)
        {
            q->data[j]=q->data[j+1];
        }
    }
    q->length--;

    return ok;
}