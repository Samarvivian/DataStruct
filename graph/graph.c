#include"graph.h"
Graph* GraphInit(int vexnum)
{
    Graph* G=(Graph*)malloc(sizeof(Graph));
    G->vex=(char*)malloc(sizeof(char)*vexnum);
    G->ars=(int**)malloc(sizeof(int*)*vexnum);
    G->vexnum=vexnum;
    for(int i=0;i<vexnum;i++)
    {
        G->ars[i]=(int*)malloc(sizeof(int)*vexnum);//建立一个正方形
    }
    G->arsnum=0;
    return G;
}

Status createGraph(Graph *G,char *vex,int *ars)
{
    for(int i=0;i<G->vexnum;i++)
    {
        
        G->vex[i]=vex[i];
        for(int j=0;j<G->vexnum;j++)
        {
            G->ars[i][j]=*(ars+i*G->vexnum+j);
            if(G->ars[i][j]!=0)
            {
                G->arsnum++;
            }   
        }
             
        
        
    }
    G->arsnum/=2;//由于我们这里讨论的是无向表，所以边数被重复计算了两次
    return ok;
}

Status DFS(Graph *G,int *visit,int index)
{
    printf("%c ",G->vex[index]);
    visit[index]=1;//标记这个顶点已经被遍历了
    for(int i=0;i<G->vexnum;i++)
    {
        if(!visit[i]&&G->ars[index][i]==1)
        {
            DFS(G,visit,i);
        }
    }
    return ok;
}