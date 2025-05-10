#include<assert.h>
typedef int Status;
typedef int ElemType;
typedef struct QLNode
{
    int row,col;//非零元素的行标和列标
    ElemType e;
    struct QLNode *right,*down;
    
    
}QLNode,*QLink;

typedef struct crosslist
{
    QLink *rhead,*chead;
    int mu,nu,tu;
}crosslist;

Status CrossListInit(crosslist *L,ElemType *A,int m,int n);
//用M*N的矩阵来初始化十字链表