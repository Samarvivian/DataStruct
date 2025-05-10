#include"triple.h"

Status MatrixInit(Matrix *m)
{
    m->mu=0;
    m->nu=0;
    m->tu=0;
    int mu=0,nu=0,tu=0;
    int i=0,j=0;
    int e=0;
    assert(m);
    printf("请输入矩阵的行数：");
    scanf("%d",&mu);
    printf("请输入矩阵的列数:");
    scanf("%d",&nu);

    if((mu<=0)||(nu<=0))
    {
        return error;
    }
    else
    {
        
        m->mu=mu;
        m->nu=nu;
        printf("请输入想要存放非零元素的个数：");
        scanf("%d",&tu);
        

        if(tu<0)
        {
            return error;
        }
        else
        {
            m->tu=tu;
            int k=0;
            for(k=1;k<=tu;k++)
            {
                printf("请输入想要存放非零元素的行数:");
                scanf("%d",&i);
                printf("请输入想要存放非零元素的列数:");
                scanf("%d",&j);
                printf("请输入非零元素的值:");
                scanf("%d",&e);
                m->data[k].i=i;
                m->data[k].j=j;
                m->data[k].e=e;
            }
        }
    }
    return ok;
}

Status MatrixPrint(Matrix *m)
{
    assert(m);
    int k=0;

    printf("i\tj\te\n");

    for(k=1;k<=m->tu;k++)
    {
        printf("%d\t%d\t%d",m->data[k].i,m->data[k].j,m->data[k].e);
        printf("\n");
    }
    return ok;
}

Status MatrixReverse1(Matrix *m,Matrix *n)
{
    assert(m&&n);
    n->mu=m->nu;
    n->nu=m->mu;
    n->tu=m->tu;

    if(n->tu)//非零元素个数不为0
    {
        int q=1;
        int p=1;
        int x=1,y=0;
        for(x=1;x<=m->nu;x++)//遍历整个矩阵列
        {
            for(y=1;y<=m->tu;y++)//遍历整个三元组
            {
                if(x==m->data[p].j)
                {
                    n->data[q].i=m->data[p].j;
                    n->data[q].j=m->data[p].i;
                    n->data[q].e=m->data[p].e;
                    q++;
                    p++;
                }
            }
        }
    }
    return ok;
}

Status MatrixReverse2(Matrix *m,Matrix *n)
{
    assert(m&&n);

    int number=m->nu;
    int* num[number];
    int* cpot[number];

    n->mu=m->nu;
    n->nu=m->mu;
    n->tu=m->tu;

    assert(n->tu);

    
    for(int i=1;i<=m->nu;i++)
    {
        num[i]=0;//初始化
    }

    for(int i=1;i<=m->tu;i++)
    {
        //遍历整个三元组
        int x=m->data[i].j;
        ++num[i];//num数组用来储存矩阵中每一列非零元素的个数
    }

    cpot[1]=1;//cpot表示每一列第一个非零元素在n.data中的序号
    for(int i=2;i<=m->nu;i++)
    {
        cpot[i]=num[i-1]+cpot[i-1];
    }

    for(int i=1;i<=m->tu;i++)
    {
        int col=m->data[i].j;
        int q=cpot[col];
        n->data[q].i=m->data[i].j;
        n->data[q].j=m->data[i].i;
        n->data[q].e=m->data[i].e;
        cpot[col]++;//千万不要是q++,不然再次循环进去时q会被覆盖掉
    }
    return ok;
}

Status MatrixMutiple(Matrix *m,Matrix *n)
{
    assert(m&&n);
    
}