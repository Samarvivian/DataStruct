#include"newnode.h"
void Test1()
{
    //有头节点的声明
    // SLTNode* plist=(SLTNode*)malloc(sizeof(SLTNode));
    // if(!plist)
    // {
    //     exit(-1);
    // }
    //plist->next=NULL;

    //无头节点的声明
    SLTNode* plist=NULL;
    
    SLTPushBack2(&plist,1);
    SLTPushBack2(&plist,2);
    SLTPushBack2(&plist,3);
    SLTPushBack2(&plist,4);
    SLTPushBack2(&plist,5);
    SLTPrint(plist);
}

void Test2()
{
    //有头节点的声明
    // SLTNode* plist=(SLTNode*)malloc(sizeof(SLTNode));
    // if(!plist)
    // {
    //     exit(-1);
    // }
    // plist->next=NULL;

    SLTNode* plist=NULL;

    SLTPushHead1(&plist,1);
    SLTPushHead1(&plist,2);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,4);
    SLTPushHead1(&plist,5);

    // SLTPushHead2(&plist,1);
    // SLTPushHead2(&plist,2);
    // SLTPushHead2(&plist,3);
    // SLTPushHead2(&plist,4);
    // SLTPushHead2(&plist,5);

    SLTPrint(plist);

    SLTPopBack(&plist);
    SLTPopBack(&plist);
    SLTPopBack(&plist);
    SLTPopBack(&plist);
    SLTPopBack(&plist);
    
    SLTPrint(plist);
}

void Test3()
{
    SLTNode* plist=NULL;

    SLTPushHead1(&plist,1);
    SLTPushHead1(&plist,2);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,4);
    SLTPushHead1(&plist,5);

    SLTPrint(plist);

    SLTPopHead(&plist);
    SLTPopHead(&plist);
    SLTPopHead(&plist);
    SLTPopHead(&plist);
    SLTPopHead(&plist);

    SLTPrint(plist);
}

void Test4()
{
    SLTNode* plist=NULL;

    SLTPushHead1(&plist,1);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,4);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,5);
    SLTPushHead1(&plist,3);

    SLTPrint(plist);

    SLTNode *ret=SLTFind1(plist,3);
    int i=0;
    while(ret)
    {
        printf("第%d个3的位置为%p\n",i++,ret);
        ret=SLTFind1(ret->next,3);
    }
}

void Test5()
{
    SLTNode* plist=NULL;

    SLTPushHead1(&plist,1);
    SLTPushHead1(&plist,2);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,4);
    SLTPushHead1(&plist,3);
    

    SLTPrint(plist);

    SLTNode* ret=SLTFind1(plist,3);
    while(ret)
    {
        SLTInsert1(&plist,ret,20);
        ret=SLTFind1(ret->next,3);
    }
    SLTPrint(plist);
}

void Test6()
{
    SLTNode* plist=NULL;

    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,2);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,4);
    SLTPushHead1(&plist,3);

    SLTPrint(plist);

    SLTNode* ret=SLTFind1(plist,3);
    while(ret)
    {
        SLTInsertAfter(&plist,ret,20);
        ret=SLTFind1(ret->next,3);
    }
    SLTPrint(plist);
}

void Test7()
{
    SLTNode* plist=NULL;

    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,2);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,4);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,3);

    SLTPrint(plist);

    SLTNode* ret=SLTFind1(plist,3);
    while(ret)
    {
        SLTInsertAfter2(ret,20);
        ret=SLTFind1(ret->next,3);
    }
    SLTPrint(plist);
}

void Test8()
{
    SLTNode* plist=NULL;

    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,2);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,4);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,3);

    SLTPrint(plist);

    SLTNode* ret=SLTFind1(plist,3);
    while(ret)
    {
        SLTErase(&plist,ret);
        ret=SLTFind1(ret->next,3);
    }
    SLTPrint(plist);
}

void Test9()
{
    SLTNode* plist=NULL;

    SLTPushHead1(&plist,4);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,2);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,4);
    SLTPushHead1(&plist,3);
    

    SLTPrint(plist);

    SLTNode* ret=SLTFind1(plist,3);
    
    while(ret)
    {
        SLTEraseAfter(ret);
        ret=SLTFind1(ret->next,3);
    }
    SLTPrint(plist);
}

void Test10()
{
    SLTNode* plist=NULL;

    // SLTPushHead1(&plist,6);
    SLTPushHead1(&plist,5);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,5);
    SLTPushHead1(&plist,4);
    SLTPushHead1(&plist,3);
    SLTPushHead1(&plist,2);
    SLTPushHead1(&plist,1);
    

    SLTPrint(plist);

    SLTNode* ret=SLTFind1(plist,3);
 
    while(ret)
    {
        SLTEraseAfter(ret);
        ret=SLTFind1(ret->next,3);
    }
    SLTPrint(plist);

}
int main()
{
    Test9();
    return 0;
}