#include"graph.h"
int main()
{
    Graph *G=GraphInit(5);
    //printf("\n");
    int* visit=(int*)malloc(sizeof(int)*G->vexnum);
    if(!visit)
    {
        exit(-1);
    }
    //初始化
    for(int i=0;i<G->vexnum;i++)
    {
        visit[i]=0;
    }
    int ars[5][5]=
    {
        0,1,1,1,0,
        1,0,1,1,1,
        1,1,0,0,0,
        1,1,0,0,1,
        0,1,0,1,0
    };
    createGraph(G,"ABCDE",(int*)ars);
    DFS(G,visit,0);
    return 0;
}