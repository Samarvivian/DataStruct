#include"crosslist.h"
Status CrossListInit(crosslist *L,ElemType *A,int m,int n)
{
    assert(L&A);

    int i=0,j=0,sum=0;

    L->mu=m;
    L->nu=n;

    //为十字链表的列链表和行链表开辟空间
    L->rhead=(QLink*)malloc(sizeof(QLink)*(m+1));
    if(!L->rhead)
    {
        exit(-1);
    }
    L->chead=(QLink*)malloc(sizeof(QLink)*(n+1));
    if(!L->chead)
    {
        exit(-1);
    }

    //初始化行链表和列链表
    for(i=0;i<m;i++)
    {
        L->rhead[i]=NULL;
    }
    for(j=0;j<n;j++)
    {
        L->chead[j]=NULL;
    }

    //遍历矩阵，找到非零元素
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(A[i*n+j]!=0)
            {
                sum++;//计数器，计算非零元素个数
                QLNode *newnode=(QLNode*)malloc(sizeof(QLNode));
                if(!newnode)
                {
                    exit(-1);
                }
                newnode->row=i+1;
                newnode->col=j+1;
                newnode->e=A[i*n+j];

                //更新行指向
                if(L->rhead[i]==NULL||L->rhead[i]->col>j)
                {
                    newnode->right=L->rhead[i];
                    L->rhead[i]=newnode;
                }
                else
                {
                    QLNode*next=L->rhead[i];
                    while(next->right && next->right->col<j)
                    {
                        next=next->right;
                    }
                    next->right=newnode->right;
                    next->right=newnode;
                }

                //更新列指向
                if(L->chead[j]=NULL||L->chead[j]->right>i)
                {
                    newnode->down=L->chead[j];
                    L->chead[j]=newnode;

                }
                else
                {
                    QLNode*next=L->rhead[j];
                    while(next->down && next->down->row<i)
                    {
                        next=next->down;
                    }
                    next->down=newnode->down;
                    next->down=newnode;
                }
            }
        }
    }
    L->tu=sum;
    return ok;
}