#include"tree.h"
HFTree* HFTreeInit(int *weight,int len)
{

    HFTree* T=(HFTree*)malloc(sizeof(HFTree));
    if(!T)
    {
        exit(-1);
    }
    T->data=(TreeNode*)malloc(sizeof(TreeNode)*(2*len-1));
    if(!(T->data))
    {
        exit(-1);
    }
    T->len=len;
    for(int i=0;i<T->len;i++)
    {
        T->data[i].weight=weight[i];
        T->data[i].father=0;
        T->data[i].lchild=-1;
        T->data[i].rchild=-1;
    }
    return T;
}

int* selectMin(HFTree *T)
{
    //初始化最小值和次小值
    int min=10000;
    int secondmin=1000;

    //初始化最小值和次小值索引
    int minindex=0;
    int secondminindex=0;

    for(int i=0;i<T->len;i++)
    {
        if(T->data[i].father==0)
        {
            //必须要让父节点为零，这样找到的最小值才有意义
            if(T->data[i].weight<min)=
            {
                min=T->data[i].weight;
                minindex=i;
            }
        }
    }
    for(int i=0;i<T->len;i++)
    {
        if((T->data[i].father==0)&&(minindex!=i))
        {
            //必须要让父节点为零，这样找到的次小值才有意义
            if(T->data[i].weight<min)
            {
                secondmin=T->data[i].weight;
                secondminindex=i;
            }
        }
    }
    //用数组储存最小值与次小值并返回
    int* res=(int*)malloc(sizeof(int)*2);
    res[0]=minindex;
    res[1]=secondminindex;
    return res;
}

void createHFTree(HFTree *T)
{
    int* res=0;//每次用来接收最大值和次大值
    int minIndex=0;
    int secondminIndex=0;
    int len=2*(T->len)-1;

    for(int i=T->len;i<len;i++)
    {
        //从T->len开始存储新数据
        res=selectMin(T);
        minIndex=res[0];
        secondminIndex=res[1];

        T->data[i].weight=T->data[minIndex].weight+T->data[secondminIndex].weight;
        T->data[i].lchild=minIndex;
        T->data[i].rchild=secondminIndex;
        T->data[minIndex].father=i;
        T->data[secondminIndex].father=i;
        T->len++;
    }
}

void Preorder(HFTree *T,int index)
{
    if(index!=-1)
    {
        printf("%d",T->data[index].weight);
        Preorder(T,T->data[index].lchild);
        Preorder(T,T->data[index].rchild);
    }
}