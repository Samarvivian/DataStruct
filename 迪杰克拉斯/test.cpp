#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX_SIZE 5
#define ok 1
#define false -1
#define MAX 32767
typedef struct Graph
{
	char* vex;//顶点
	int** ars;//边
	int vexnum;//顶点数
	int arsnum;//边数
}Graph;

typedef int Status;

int getMin(int* D, int* S, Graph* G)
{
	int min = MAX;
	int index = 0;
	for (int i = 0; i < G->vexnum; i++)
	{
		if (S[i] == 0 && min > D[i])
		{
			min = D[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(Graph* G, int index)
{
	//定义一个数组记录从定点到其他顶点的最短路径是否求得
	//求得返回1，没求得暂时记为0
	int* S = (int*)malloc(sizeof(int) * G->vexnum);

	//定义一个数组记录所在顶点的前驱结点的索引
	int* P = (int*)malloc(sizeof(int) * G->vexnum);

	//定义一个数组记录最短路径长度
	int* D = (int*)malloc(sizeof(int) * G->vexnum);

	//初始化
	for (int i = 0; i < G->vexnum; i++)
	{
		if (i == index)
		{
			S[i] = 1;
		}
		else
		{
			S[i] = 0;
		}
	}

	for (int i = 0; i < G->vexnum; i++)
	{
		if (G->ars[index][i] > 0 && G->ars[index][i] < MAX)
		{
			P[i] = index;//有路径可达
		}
		else
		{
			P[i] = -1;
		}
	}

	for (int i = 0; i < G->vexnum; i++)
	{
		if (G->ars[index][i] > 0 && G->ars[index][i] < MAX)
		{
			D[i] = G->ars[index][i];
		}
		else
		{
			D[i] = MAX;
		}
		if (i == index)
		{
			D[i] = 0;
		}
	}
	
	//检验这三个数组初始化是否成功
	/*for (int i = 0; i < G->vexnum; i++)
	{
		printf("%d %d %d\n", S[i], P[i], D[i]);
	}*/

	for (int i = 0; i < G->vexnum - 1; i++)
	{
		index = getMin(D, S, G);
		//更新S数组
		S[index] = 1;
		//更新D数组和p数组
		for (int j = 0; j < G->vexnum; j++)
		{
			if (S[j] == 0 && D[index] + G->ars[index][j] < D[j])
			{
				D[j] = D[index] + G->ars[index][j];
				P[j] = index;
			}
		}

	}
	for (int i = 0; i < G->vexnum; i++)
	{
		printf("%d %d %d\n", S[i], P[i], D[i]);
	}
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
			if (G->ars[i][j] == 1)
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
	printf("%c ", G->vex[index]);
	visit[index] = 1;//证明已经被访问过了

	for (int i = 0; i < G->vexnum; i++)
	{
		if (!visit[i] && G->ars[index][i] >0&&G->ars[index][i]<MAX)
		{
			DFS(G, i, visit);
		}
	}

	return ok;
}


int main()
{
	Graph* G = GraphInit(7);
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
	int ars[7][7] =
	{
		0, 12, MAX, MAX, MAX, 16, 14,
		12, 0, 10, MAX, MAX, 7, MAX,
		MAX, 10, 0, 3, 5, 6, MAX,
		MAX, MAX, 3, 0, 4, MAX, MAX,
		MAX, MAX, 5, 4, 0, 2, 8,
		16, 7, 6, MAX, 2, 0, 9,
		14, MAX, MAX, MAX, 8, 9, 0
	};

	createGraph(G, "1234567", (int*)ars);
	DFS(G, 0, visit);
	printf("\n");

	dijkstra(G, 0);

	return 0;
}