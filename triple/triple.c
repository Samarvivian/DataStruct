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
            for(k=0;k<tu;k++)
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

    printf("i   j   e\n");

    for(k=0;k<m->tu;k++)
    {
        printf("%d  %d  %d",m->data[k].i,m->data[k].j,m->data[k].e);
        printf("\n");
    }
    return ok;
}