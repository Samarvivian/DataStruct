#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define ok 1
#define error 0

typedef int ElemType;
typedef int Status;
typedef struct SqList
{
    ElemType *data;
    int size;
    int capacity;
}Sq;

Status SqlistInit(Sq *sq)
{
    sq->data=NULL;
    sq->size=sq->capacity=0;
    return ok;
}

Status SqlistInsert(Sq *sq,ElemType e)
{
    assert(sq);
    if(sq->size==sq->capacity)
    {
        int newcapacity=sq->capacity==0?5:sq->capacity*2;
        ElemType *temp=(ElemType*)malloc(sizeof(ElemType)*newcapacity);
        if(!temp)
        {
            exit(-1);
        }
        sq->data=temp;
        sq->capacity=newcapacity;
    }
    sq->data[sq->size]=e;
    sq->size++;
    return ok;

}

Status SqlistAdd(Sq *sq)
{
    assert(sq);
    
    sq->data[4]=sq->data[3];
    sq->data[3]=9;
    sq->size++;
    return ok;
}

void SqlistPrint(Sq sq)
{
    assert(&sq);
    int i=0;
    for(i=0;i<sq.size;i++)
    {
        printf("%d ",sq.data[i]);
    }
    printf("\n");
}

Status SqlistDelete(Sq *sq)
{
    assert(sq);
    sq->data[3]=sq->data[4];
    
    sq->size--;
    return ok;
}

Status SqlistDestory(Sq *sq)
{
    free(sq->data);
    sq->data=NULL;
    sq->size=sq->capacity=0;
    return ok;
}

int main()
{
    Sq sq;
    SqlistInit(&sq);
    SqlistInsert(&sq,2);
    SqlistInsert(&sq,3);
    SqlistInsert(&sq,4);
    SqlistInsert(&sq,5);

    SqlistPrint(sq);

    SqlistAdd(&sq);
    SqlistPrint(sq);

    SqlistDelete(&sq);
    SqlistPrint(sq);

    SqlistDestory(&sq);

    return 0;
}

