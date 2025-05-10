#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX_SIZE 5
#define ok 1
#define false -1
typedef struct Graph
{
	char* vex;//顶点
	int** ars;//边
	int vexnum;//顶点数
	int arsnum;//边数
}Graph;
typedef struct Queue
{
	int front;
	int end;
	int arr[MAX_SIZE];
}Queue;
typedef int Status;

Queue* QueueInit()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (!q)
	{
		exit(-1);
	}
	q->front = q->end = 0;
	//在这里这样初始化是错误的
	//q->arr = { 0 };
	memset(q->arr, 0, sizeof(q->arr));
	return q;
}

bool IsFull(Queue* q)
{
	return (q->end + 1) % MAX_SIZE == q->front;
}

bool IsEmpty(Queue* q)
{
	return q->end == q->front;
}

Status QueuePush(Queue* q,int num)
{
	if (IsFull(q))
	{
		return false;
	}
	else
	{
		q->arr[q->end++] = num;
		return ok;
	}
}

int QueuePop(Queue *q)
{
	if (IsEmpty(q))
	{
		return false;
	}
	else
	{
		return q->arr[q->front++];
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

Status createGraph(Graph* G, const char* vex,int *ars)
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

Status DFS(Graph* G,int index,int *visit)
{
	//任意寻找一个下标开始遍历
	printf("%c ", G->vex[index]);
	visit[index] = 1;//证明已经被访问过了
	
	for (int i = 0; i < G->vexnum; i++)
	{
		if (!visit[i] && G->ars[index][i]==1)
		{
			DFS(G, i, visit);
		}
	}
	
	return ok;
}

Status BFS(Graph* G,int index,int *visit)
{
	//类似于树的层次遍历
	Queue* q = QueueInit();
	printf("%c ", G->vex[index]);
	visit[index] = 1;
	QueuePush(q, index);
	while (!IsEmpty(q))
	{
		int i = QueuePop(q);
		for (int j = 0; j < G->vexnum; j++)
		{
			if (!visit[j] && G->ars[i][j])
			{
				printf("%c ", G->vex[j]);
				visit[j] = 1;
				QueuePush(q, j);
			}
		}
	}
	return ok;
}

int main()
{
	Graph* G = GraphInit(5);
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
	int ars[5][5] =
	{
		0,1,1,1,0,
		1,0,1,1,1,
		1,1,0,0,0,
		1,1,0,0,1,
		0,1,0,1,0
	};
	
	createGraph(G, "ABCDE", (int*)ars);
	DFS(G, 0, visit);
	printf("\n");
	
	int visit1[5] = { 0 };
	BFS(G, 0, visit1);

	return 0;
}