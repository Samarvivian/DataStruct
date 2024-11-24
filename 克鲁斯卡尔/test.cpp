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

//建立一个维护边数的数组
typedef struct Edge
{
	int start;
	int end;
	int weight;
}Edge;

typedef int Status;

Edge* EdgeInit(Graph* G)
{
	int index = 0;
	Edge* edge = (Edge*)malloc(sizeof(Edge) * G->arsnum);
	for (int i = 0; i < G->vexnum; i++)
	{
		for (int j = i + 1; j < G->vexnum; j++)
		{
			if (G->ars[i][j] != MAX)
			{
				edge[index].start = i;
				edge[index].end = j;
				edge[index].weight = G->ars[i][j];
				index++;
			}
		}
	}
	return edge;
}

//对维护边数的数组的元素重新进行大小排序
Status sort(Graph* G, Edge* edge)
{
	int len = G->arsnum;
	//选择排序
	for (int i = len - 1; i > 0; i--)
	{
		int max = edge[i].weight;
		int index = i;
		for (int j = 0; j < i; j++)
		{
			if (edge[j].weight > max)
			{
				max = edge[j].weight;
				index = j;
			}
		}
		Edge temp=edge[index];
		edge[index] = edge[i];
		edge[i] = temp;
	}
	return ok;
}

Status kruskal(Graph* G)
{
	//构建辅助数组检验是否构成封闭回路
	int* connect = (int*)malloc(sizeof(int) * G->vexnum);
	//先把这个数组中的元素初始化为各个顶点的值
	for (int i = 0; i < G->vexnum; i++)
	{
		connect[i] = i;
	}
	Edge* edge = EdgeInit(G);
	sort(G, edge);
	for (int i = 0; i < G->vexnum; i++)
	{
		int start = connect[edge[i].start];
		int end = connect[edge[i].end];
		if (start != end)
		{
			printf("V%c--->V%c,weight=%d\n", G->vex[edge[i].start], G->vex[edge[i].end],edge[i].weight);
		}

		//更新数组
		for (int j = 0; j < G->vexnum; j++)
		{
			if (connect[j] == end)
			{
				connect[j] = start;
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
			if (G->ars[i][j] > 0 && G->ars[i][j] < MAX)
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
		if (!visit[i] && G->ars[index][i] > 0 && G->ars[index][i] < MAX)
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

	kruskal(G);

	return 0;
}