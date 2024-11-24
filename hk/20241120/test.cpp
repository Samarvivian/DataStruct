//建立一个包含6个结点的有向图，并求顶点v0到其它的最短路径
#include<stdio.h>
#include<stdlib.h>
#define ok 1
#define MAX 32767
typedef struct Graph
{
	char* vex;//顶点
	int vexnum;//顶点数
	int **ars;//边
	int arsnum;//有效边数
};
typedef int Status;

Status getMin(Graph* G, int* D,int* S)
{
	int min = MAX;
	int index = 0;
	for (int i = 0; i < G->vexnum; i++)
	{
		if (!S[i] && min > D[i])
		{
			min = D[i];
			index = i;
		}
	}
	return index;
}
Status dijkstra(Graph* G,int index)
{
	//建立一个数组记录从所定结点到当前结点的最短路径是否找到
	int* S = (int*)malloc(sizeof(int) * G->vexnum);
	//建立一个数组记录当前结点的前驱结点
	int* P = (int*)malloc(sizeof(int) * G->vexnum);
	//建立一个数组记录从所定结点到当前结点的最短路径
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
		if (i == index)
		{
			P[i] = -1;
		}
		else
		{
			P[i] = index;
		}
	}

	for (int i = 0; i < G->vexnum; i++)
	{
		if (i == index)
		{
			D[i] = 0;
		}
		else if (G->ars[index][i] > 0 && G->ars[index][i] < MAX)
		{
			D[i] = G->ars[index][i];
		}
		else
		{
			D[i] = MAX;
		}
	}

	
	for (int i = 0; i < G->vexnum - 1; i++)
	{
		int newindex = getMin(G, D,S);
		S[newindex] = 1;
		for (int j = 0; j < G->vexnum; j++)
		{
			if (!S[j] && G->ars[newindex][j] + D[newindex] < D[j])
			{
				D[j] = G->ars[newindex][j] + D[newindex];
				P[j] = newindex;
			}
		}

	}
	for (int i = 0; i < G->vexnum; i++)
	{
		printf("%d %d %d\n", S[i], P[i], D[i]);
	}
	printf("结点%d到其他结点的最短路径分别为：\n",index);
	for (int i = 0; i < G->vexnum; i++)
	{
		if (P[i] == index)
		{
			printf("V%c--->V%c,weight=%d\n", G->vex[index], G->vex[i], D[i]);
		}
		else if (P[i] != -1 && P[i] != index)
		{
			printf("V%c--->V%c--->V%c,weight=%d\n", G->vex[index], G->vex[P[i]], G->vex[i], D[i]);
		}
	}
	return ok;
}

Graph* GraphInit(int num)
{
	//初始化一个带有六个结点的图
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vex = (char*)malloc(sizeof(char) * num);
	G->vexnum = 6;
	G->ars = (int**)malloc(sizeof(int*) * num);
	for (int i = 0; i < num; i++)
	{
		G->ars[i] = (int*)malloc(sizeof(int) * num);
	}
	G->arsnum = 0;
	return G;
}

Status createGraph(Graph* G,const char* str, int* arr)
{
	for (int i = 0; i < G->vexnum; i++)
	{
		G->vex[i] = str[i];
	}
	for (int i = 0; i < G->vexnum; i++)
	{
		for (int j = 0; j < G->vexnum; j++)
		{
			G->ars[i][j] = *(arr + i * G->vexnum + j);
			if (G->ars[i][j] > 0 && G->ars[i][j] < MAX)
			{
				G->arsnum++;
			}
		}
		
	}
	return ok;
}

Status DFS(Graph* G,int index,int* visit)
{
	printf("%c", G->vex[index]);
	visit[index] = 1;
	for (int i = 0; i < G->vexnum; i++)
	{
		if (G->ars[index][i] > 0 && G->ars[index][i] < MAX && visit[i] != 1)
		{
			DFS(G, i,visit);
		}
	}
	return ok;
}

int main()
{
	Graph* G = GraphInit(6);
	int arr[6][6] =
	{
		0,6,5,2,MAX,MAX,
		6,0,7,MAX,3,MAX,
		5,7,0,8,9,11,
		2,MAX,8,0,MAX,4,
		MAX,3,9,MAX,0,13,
		MAX,MAX,11,4,13,0
	};
	int* visit = (int*)malloc(sizeof(int) * G->vexnum);
	for (int i = 0; i < G->vexnum; i++)
	{
		visit[i] = 0;
	}
	createGraph(G, "ABCDEF", (int*)arr);
	DFS(G, 0,visit);
	printf("\n");
	dijkstra(G, 0);
	return 0;
}