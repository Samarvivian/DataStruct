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
			if (G->ars[i][j] > 1&&G->ars[i][j]<MAX)
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
		if (!visit[i] && G->ars[index][i]>0&&G->ars[index][i]<MAX)
		{
			DFS(G, i, visit);
		}
	}

	return ok;
}

//弗洛伊德算法
Status Folyd(Graph* G)
{
	//建立一个数组记录当前结点的上一个结点
	int** P = (int**)malloc(sizeof(int*) * G->vexnum);
	//建立一个数组记录从所在顶点到当前节点的最短路径
	int** D = (int**)malloc(sizeof(int*) * G->vexnum);
	for (int i = 0; i < G->vexnum; i++)
	{
		P[i]= (int*)malloc(sizeof(int) * G->vexnum);
		D[i]= (int*)malloc(sizeof(int*) * G->vexnum);
	}
	for (int i = 0; i < G->vexnum; i++)
	{
		for (int j = 0; j < G->vexnum; j++)
		{
			D[i][j] = G->ars[i][j];
		}
	}
	for (int i = 0; i < G->vexnum; i++)
	{
		for (int j = 0; j < G->vexnum; j++)
		{
			if (D[i][j] > 0 && D[i][j] < MAX)
			{
				P[i][j] = i;
			}
			else 
			{
				P[i][j] = -1;
			}
		}
	}
	//关键步骤
	for (int i = 0; i < G->vexnum; i++)
	{
		for (int j = 0; j < G->vexnum; j++)
		{
			for (int k = 0; k < G->vexnum; k++)
			{
				if (D[j][i] + D[i][k] < D[j][k])
				{
					D[j][k] = D[j][i] + D[i][k];
					P[j][k] = P[i][k];
				}
			}
		}
		
	}

	for (int i = 0; i < G->vexnum; i++)
	{
		for (int j = 0; j < G->vexnum; j++)
		{
			printf("%d ", P[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < G->vexnum; i++)
	{
		for (int j = 0; j < G->vexnum; j++)
		{
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
	return ok;
}

int main()
{
	Graph* G = GraphInit(4);
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
	int ars[4][4] =
	{
		0, 1, MAX, 3,
		1, 0, 2, 2,
		MAX, 2, 0, 8,
		3, 2, 8, 0
	};

	createGraph(G, "1234", (int*)ars);
	DFS(G, 0, visit);
	printf("\n");

	Folyd(G);
	return 0;
}