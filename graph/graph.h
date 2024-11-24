#include<stdlib.h>
#include<stdio.h>
#define ok 1

typedef int Status;
typedef struct Graph
{
    char *vex;//顶点
    int **ars;//边
    int vexnum;//顶点数
    int arsnum;//边数
}Graph;

Graph* GraphInit(int vex);//初始化图

Status createGraph(Graph *G,char *vex,int *ars);//创建图

Status DFS(Graph *G,int *visit,int index);//深度优先遍历