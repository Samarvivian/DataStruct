#define MAXSIZE 1000
#define ok 1
#define error 0
typedef int status;
typedef int ElemType;
typedef struct 
{
    ElemType data;
    int cur;//游标
}component,StackLinkList[MAXSIZE];

status LinkList(StackLinkList space)
{
    int i=0;
    for(i=0;i<MAXSIZE-1;i++)
    {
        space[i].cur=i+1;
    }
    space[MAXSIZE-1].cur=0;//目前链表为空，最后一个元素指向0
    return ok;
}

//若备用空间链表非空，则返回分配结点的坐标，否则返回0
int Malloc_SLL(StackLinkList space)
{
    int i=space[0].cur;
    if(space[0].cur)
    {
        space[0].cur=space[i].cur;
    }
    return i;
}

status ListInsert(StackLinkList space,int i,ElemType e)
{
    int j=0,k=0,l=0;
    k=MAXSIZE-1;
    j=Malloc_SLL(space);
    if(j)
    {
        space[j].data=e;
        for(l=1;l<=i-1;i++)
        {
            k=space[k].cur;
        }
        
        space[j].cur=space[k].cur;
        space[k].cur=j;
        return ok;
    }
    return error;
}

//将下标为k的空闲结点回收
status free_ssl(StackLinkList space,int k)
{
    space[k].cur=space[0].cur;
    space[0].cur=k;
}
//删除第i个位置的结点
status ListDeletle(StackLinkList space,int i,ElemType e)
{
    int j=0,k=0,l=0;
    k=MAXSIZE-1;
    for(l=1;l<=i-1;i++)
    {
        k=space[k].cur;
    }
    j=space[k].cur;
    space[k].cur=space[j].cur;
    free_sll(space,j);
    return ok;
}