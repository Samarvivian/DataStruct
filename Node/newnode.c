#include"newnode.h"
Status SLTPrint(SLTNode *phead)
{
    //assert(phead);这句话在下面的while循环条件中可以再判断
    SLTNode *cur=phead;//用作游标，如果带头节点就是phead->next
    while(cur)
    {
        printf("%d->",cur->data);
        cur=cur->next;
    }
    printf("NULL\n");
    return ok;
}

Status SLTPushBack1(SLTNode **pphead,ElemType x)
{
    //带头节点的尾插，至于为什么要传入二级指针，在接下来不带头节点的插入中再详细说明

    //malloc新节点，存储x
    SLTNode *newnode=(SLTNode *)malloc(sizeof(SLTNode));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->data=x;
    newnode->next=NULL;

    //制作游标，找到最后一个结点
    // SLTNode *cur=(*pphead)->next;
    // while(cur!=NULL)
    // {
    //     cur=cur->next;
    // }
    // cur->next=newnode;
    //这一段是我的错误代码，逻辑很有问题
    //如果链表为空，则cur指向NULL,那么NULL->next是没有意义的

    if(!((*pphead)->next))
    {
        (*pphead)->next=newnode;
    }
    else
    {
        SLTNode *cur=(*pphead)->next;
        while(cur->next)
        {
            cur=cur->next;
        }
        cur->next=newnode;
    }

    return ok;

}

Status SLTPushBack2(SLTNode **pphead,ElemType x)
{
    SLTNode *newnode=(SLTNode *)malloc(sizeof(SLTNode));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->data=x;
    newnode->next=NULL;

    //处理链表为空的特殊情况
    if(!(*pphead))
    {
        (*pphead)=newnode;
    }
    else
    {
        SLTNode *cur=*pphead;
        while(cur->next)
        {
            cur=cur->next;
        }
        cur->next=newnode;
    }
    return ok;
}

Status SLTPushHead1(SLTNode **pphead,ElemType x)
{
    SLTNode *newnode=(SLTNode*)malloc(sizeof(SLTNode));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->data=x;
    newnode->next=(*pphead);
    (*pphead)=newnode;

    return ok;
}

Status SLTPushHead2(SLTNode **pphead,ElemType x)
{
    SLTNode *newnode=(SLTNode*)malloc(sizeof(SLTNode));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->data=x;

    newnode->next=(*pphead)->next;
    (*pphead)->next=newnode;

    return ok;
}

Status SLTPopBack(SLTNode **pphead)
{
    // SLTNode *tail=(*pphead);//用于找到尾结点
    // while(tail->next)
    // {
    //     tail=tail->next;
    // }
    // free(tail);
    // tail=NULL;
    //以上是错误写法
    //仅仅将原来最后一个结点置空是不行的，会导致倒数第二个结点是野指针
    //应该想法设法找到尾结点前面一个结点

    //方法1：
    // SLTNode*tail=(*pphead);
    // while(tail->next->next)
    // {
    //     tail=tail->next;
    // }
    // free(tail->next);
    // tail->next=NULL;

    // //方法2：
    // SLTNode *tail=(*pphead);
    // SLTNode *front=NULL;//设置tail前面一个指针
    // //每次进入循环时，先把tail赋值给front,再递增tail
    // while(tail->next)
    // {
    //     front=tail;
    //     tail=tail->next;
    // }
    // free(tail);
    // tail=NULL;
    // front->next=NULL;

    //以上两种方法都可行，但是却忘记考虑了两种特殊情况
    //1.链表已经为空
    //2.只剩最后一个结点

    //方法1改进：
    // assert(*pphead);
    // if((*pphead)==NULL)
    // {
    //     free(*pphead);
    //     (*pphead)=NULL;
    // }
    // else
    // {
    //     SLTNode*tail=(*pphead);
    
    //     while(tail->next->next)
    //     {
    //         tail=tail->next;
    //     }
    //         free(tail->next);
    //     tail->next=NULL;
        
    // }

    //方法2改进
    assert(*pphead);
    if((*pphead)->next==NULL)
    {
        free(*pphead);
        (*pphead)=NULL;
    }
    else
    {
        SLTNode *tail=(*pphead);
        SLTNode *front=NULL;//设置tail前面一个指针
        //每次进入循环时，先把tail赋值给front,再递增tail
        while(tail->next)
        {
            front=tail;
            tail=tail->next;
        }
        free(tail);
        tail=NULL;
        front->next=NULL;
    }
    

    return ok;
    

}

Status SLTPopHead(SLTNode **pphead)
{
    assert(*pphead);
    
    SLTNode*next=(*pphead)->next;
    free(*pphead);
    (*pphead)=next;

    return ok;

}

SLTNode* SLTFind1(SLTNode *phead,ElemType x)
{
    SLTNode *cur=phead;
    while(cur)
    {
        if(cur->data==x)
        {
            return cur;
        }
        else
        {
            cur=cur->next;
        }
    }
    return NULL;
}

Status SLTInsert1(SLTNode **pphead,SLTNode *pos,ElemType x)
{
    SLTNode *newnode=(SLTNode*)malloc(sizeof(SLTNode));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->data=x;
    if((*pphead)==pos)//pos为第一个结点的特殊情况
    {
        
        newnode->next=(*pphead);
        (*pphead)=newnode;
    }
    else
    {
        SLTNode *posPrev=(*pphead);//找到pos前一个结点
        while(posPrev->next!=pos)
        {
            posPrev=posPrev->next;
        }
        
        
        newnode->next=posPrev->next;
        posPrev->next=newnode;
        
    }
    return ok;

}

Status SLTInsertAfter(SLTNode **pphead,SLTNode *pos,ElemType x)
{
    SLTNode *newnode=(SLTNode*)malloc(sizeof(SLTNode));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->data=x;
    SLTNode *cur=(*pphead);
    while(cur!=pos)
    {
        cur=cur->next;
    }
    newnode->next=cur->next;
    cur->next=newnode;
    return ok;
}

Status SLTInsertAfter2(SLTNode *pos,ElemType x)
{
    //在pos之后插入不需要循环，所以不用传入头节点
    SLTNode *newnode=(SLTNode*)malloc(sizeof(SLTNode));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->data=x;
    newnode->next=pos->next;
    pos->next=newnode;
    return ok;
}

Status SLTErase(SLTNode **pphead,SLTNode *pos)
{
    if(pos==(*pphead))//pos在第一个位置
    {
        SLTNode *next=(*pphead)->next;
        free(*pphead);
        (*pphead)=next;
    }
    else
    {
        SLTNode *posPrev=(*pphead);
        while(posPrev->next!=pos)
        {
            posPrev=posPrev->next;
        }
        posPrev->next=pos->next;
        free(pos);
        pos=NULL;
    }
    return ok;
}

Status SLTEraseAfter(SLTNode *pos)
{
    // assert(pos->next);
    // pos->next=pos->next->next;
    // free(pos->next);
    // pos->next=NULL;
    // return ok;
    //上面的逻辑是不对的

    assert(pos->next);
    SLTNode *next=pos->next;
    pos->next=next->next;
    free(next);
    next=NULL;
    return ok;
}