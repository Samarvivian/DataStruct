#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 32767
#define ok 1
#define false -1
//定义顶点指向本身时为0，与另外一个顶点没有联系时为MAX
typedef struct Graph
{
	char* vex;//顶点
	int** ars;//边
	int vexnum;//顶点数
	int arsnum;//边数
}Graph;

typedef struct Edge
{
	char vex;//记录即将被遍历的顶点
	int weight;//记录这个顶点的权值
}Edge;

typedef int Status;

Edge* EdgeInit(Graph* G,int index)
{
	Edge* edge = (Edge*)malloc(sizeof(Edge)*G->vexnum);
	for (int i = 0; i < G->vexnum; i++)
	{
		edge[i].vex = G->vex[index];
		edge[i].weight = G->ars[index][i];
	}
	return edge;
}

Status getMin(Graph* G, Edge* edge)
{
	int index = 0;
	int MIN = MAX;
	for (int i = 0; i < G->vexnum; i++)
	{
		if (edge[i].weight != 0 && MIN > edge[i].weight)
		{
			MIN = edge[i].weight;
			index = i;
		}
	}
	return index;
}

Status Prim(Graph* G)
{
	Edge* edge = EdgeInit(G, 0);
	for (int i = 0; i < G->vexnum-1; i++)
	{
		int min = getMin(G, edge);//找到由起点开始权值最小的其他点
		printf("V%c--->V%c,weight=%d\n", edge[min].vex, G->vex[min], edge[min].weight);
		edge[min].weight = 0;
		for (int j = 0; j < G->vexnum; j++)
		{
			if (G->ars[min][j] < edge[j].weight)
			{
				edge[j].weight = G->ars[min][j];
				edge[j].vex = G->vex[min];
			}
		}
	}
	return ok;
}
Graph* GraphInit(int vex)
{
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vexnum = vex;
	G->vex = (char*)malloc(sizeof(char) * vex);
	G->arsnum = 0;
	G->ars = (int**)malloc(sizeof(int*) * vex);
	for (int i = 0; i < vex; i++)
	{
		G->ars[i] = (int*)malloc(sizeof(int) * vex);//建立一个正方形
	}
	return G;
}

Status createGraph(Graph* G, const char* vex, int* ars)
{
	for (int i = 0; i < G->vexnum; i++)
	{
		G->vex[i] = vex[i];
		for (int j = 0; j < G->vexnum; j++)
		{
			G->ars[i][j] = *(ars + i * G->vexnum + j);
			if (G->ars[i][j] >0 && G->ars[i][j] <MAX)
			{
				G->arsnum++;
			}
		}
	}

	G->arsnum /= 2;//这里因为是无向表，所以每条边被重复计算了两次
	return ok;
}

Status DFS(Graph* G, int index, int* visit)
{
	//任意寻找一个下标开始遍历
	printf("%c\t", G->vex[index]);
	visit[index] = 1;//证明已经被访问过了

	for (int i = 0; i < G->vexnum; i++)
	{
		if (!visit[i] && G->ars[index][i] >0 && G->ars[index][i] < MAX)
		{
			DFS(G, i, visit);
		}
	}

	return ok;
}

int main()
{
	Graph* G = GraphInit(6);
	int* visit = (int*)malloc(sizeof(int) * G->vexnum);
	if (!visit)
	{
		exit(-1);
	}
	//初始化
	for (int i = 0; i < G->vexnum; i++)
	{
		visit[i] = 0;
	}
	int ars[6][6] =
	{
		0,6,1,5,MAX,MAX,
		6,0,5,MAX,3,MAX,
		1,5,0,5,6,4,
		5,MAX,5,0,MAX,2,
		MAX,3,6,MAX,0,6,
		MAX,MAX,4,2,6,0
	};

	createGraph(G, "123456", (int*)ars);
	DFS(G, 0, visit);
	printf("\n");

	Prim(G);

	return 0;
}