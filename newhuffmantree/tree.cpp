#include"tree.hpp"


HFtree* HuffmanTreeInit(int n)
{
    
    
    HFtree* T=(HFtree*)malloc(sizeof(HFtree));
    if(!T)
    {
        exit(-1);
    }

    //对T->tree进行扩容，个数为原来结点的个数的两倍-1
    T->tree=(TreeNode*)malloc(sizeof(TreeNode)*(2*n-1));
    if(!T->tree)
    {
        exit(-1);
    }
    T->len=n;

    //遍历
    for(int i=0;i<T->len;i++)
    {
        T->tree[i].weight=0;
        
        T->tree[i].parent=0;
        T->tree[i].lchild=-1;
        T->tree[i].rchild=-1;
    }
    return T;
}

int* selectMin(HFtree *T)
{
    //运用动态分配的思想找到最小值
    int min=10000;
    int secondmin=10000;
    int minIndex=0;
    int secondminIndex=0;
    

    //遍历找到最小值
    //必须保证这个结点没有父节点，这样找到的最小值才有意义
    for(int i=0;i<T->len;i++)
    {
        // if(T->tree[i].weight<=min&&T->tree[i].parent==0)
        // {
        //     min=T->tree[i].weight;
        //     minIndex=i;
        // }

        if(T->tree[i].parent==0)
        {
            if(T->tree[i].weight<min)
            {
                min=T->tree[i].weight;
                minIndex=i;
            }
        }
    }
    

    //遍历找到次小值
    //必须保证这个结点没有父节点，这样找到的最小值才有意义
    for(int i=0;i<T->len;i++)
    {
        // if(T->tree[i].weight<=secondmin&&i!=minIndex&&T->tree[i].parent==0)
        // {
        //    secondmin=T->tree[i].weight;
        //    secondminIndex=i;
        // }

        if(T->tree[i].parent==0 && i!=minIndex)
        {
            if(T->tree[i].weight<secondmin)
            {
                secondmin=T->tree[i].weight;
                secondminIndex=i;
            }
        }
    }
    int *res=(int*)malloc(sizeof(int)*2);
    res[0]=minIndex;
    res[1]=secondminIndex;
    return res;
}

Status createHFTree(HFtree* T)
{
    printf("输入前n个结点的权值:\n");
    for(int i=0;i<T->len;i++)
    {
        scanf("%d",&(T->tree[i].weight));
        
    }
    getchar();
    int minIndex=0;
    int secondminIndex=0;
    int *res;
    //找到当前的最小值与次小值，并且为它们创建父节点
    //从第len个长度的下标开始储存哈夫曼树

    int len=T->len*2-1;
    for(int i=T->len;i<len;i++)
    {
        res=selectMin(T);
        minIndex=res[0];
        secondminIndex=res[1];

        //开始储存
        T->tree[i].weight=T->tree[minIndex].weight+T->tree[secondminIndex].weight;
        T->tree[i].lchild=minIndex;
        T->tree[i].rchild=secondminIndex;
        T->tree[i].parent=0;
        
        //创建父节点
        T->tree[minIndex].parent=i;
        T->tree[secondminIndex].parent=i;
        T->len++;
    }
    return ok;
}

Status encode(HFtree* T,hfmantreecode hc,int n)
{
    hc=(hfmantreecode)malloc(sizeof(char*)*(n+1));
    if(!hc)
    {
        exit(-1);
    }
    //这个cd的分配大小非常关键，因为一个叶子节点到根节点最多最多也就是n的路径长度
    //所以储存01编码的数组大小最多最多就是n
    char* cd=(char*)malloc(sizeof(char)*n);
    if(!cd)
    {
        exit(-1);
    }
    cd[n-1]='\0';//储存结束符
    //开始遍历
    for(int i=0;i<n;i++)
    {
        int start=n-1;
        //叶子结点
        int child=i;
        //对应的父结点
        int parent=T->tree[i].parent;
        //循环，直到根节点为止
        while(parent!=0)
        {
            --start;
            if(T->tree[parent].lchild==i)
            {
                cd[start]='0';
            }
            if(T->tree[parent].rchild==i)
            {
                cd[start]='1';
            }
            //更新叶子和父节点
            child=parent;
            parent=T->tree[parent].parent;
        }
        //将cd中的01编码储存起来
        hc[i]=(char*)malloc(sizeof(char)*(n-start));
        if(!hc[i])
        {
            exit(-1);
        }
        strcpy(hc[i],&cd[start]);
    }
    printf("输出叶子结点及其哈夫曼编码为:\n");
    for(int i=0;i<n;i++)
    {
        printf("%c",Alphabet[i]);
        printf("%s",hc[i]);
        printf("\n");
    }
    
    return ok;
}
void preorder(HFtree* T,int index)
{
    if(index!=-1)
    {
        printf("%d ",T->tree[index].weight);

        //因为我们在创建哈夫曼树这个函数中是用左右孩子储存下标，所以这里递归的index应该传入左右孩子
        preorder(T,T->tree[index].lchild);
        preorder(T,T->tree[index].rchild);
    }
}