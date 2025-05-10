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

typedef struct StackNode
{
	int data;
	struct StackNode* next;
};

StackNode* StackInit()
{
	StackNode* Node = (StackNode*)malloc(sizeof(StackNode));
	Node->data = 0;
	Node->next = NULL;
	return Node;
}

void StackPush(StackNode* Node, int data)
{
	StackNode* newnode = (StackNode*)malloc(sizeof(StackNode));
	newnode->data = data;
	newnode->next = Node->next;
	Node->next = newnode;
	Node->data++;
}

bool IsEmpty(StackNode* Node)
{
	return Node->next == NULL;
}

int StackPop(StackNode* Node)
{
	if (!IsEmpty(Node))
	{
		StackNode* newnode = Node->next;
		Node->next = newnode->next;
		Node->data--;
		return newnode->data;
	}
	else
	{
		return -1;
	}
}

//计算每个顶点的入度
int* FindInDegrees(Graph* G)
{
	int* indegrees = (int*)malloc(sizeof(int) * G->vexnum);
	//初始化
	for (int i = 0; i < G->vexnum; i++)
	{
		indegrees[i] = 0;
	}
	//计算每个顶点的入度
	for (int i = 0; i < G->vexnum; i++)
	{
		for (int j = 0; j < G->vexnum; j++)
		{
			if (G->ars[i][j] >0&&G->ars[i][j]<MAX)
			{
				//因为是竖着累计，所以不能写成indegress[i]=indegress[i]+1
				indegrees[j] = indegrees[j] + 1;
			}
		}
	}
	return indegrees;
}

void topulogicalsort(Graph* G)
{
	//用一个数组储存入度为0的结点
	int* top = (int*)malloc(sizeof(int) * G->vexnum);
	int* indegrees = FindInDegrees(G);
	int index = 0;
	StackNode* Node = StackInit();
	/*for (int i = 0; i < G->vexnum; i++)
	{
		printf("%d ", indegrees[i]);
	}*/

	//寻找入度为0的结点，即没有前驱的结点，让它入栈
	for (int i = 0; i < G->vexnum; i++)
	{
		if (!indegrees[i])
		{
			StackPush(Node, i);
		}
	}
	while (!IsEmpty(Node))
	{
		//用top数组储存入度为0的结点
		int i = StackPop(Node);
		top[index++] = i;
		//循环一圈，更新indegrees
		for (int j = 0; j < G->vexnum; j++)
		{
			if (G->ars[i][j]>0&&G->ars[i][j]<MAX)
			{
				indegrees[j]--;
				if (!indegrees[j])
				{
					//若发现更新之后有结点的入度为0，就把它入栈，重复过程
					StackPush(Node, j);
				}
			}
		}
	}
	for (int i = 0; i < G->vexnum; i++)
	{
		printf("%c ", G->vex[top[i]]);
	}
	printf("\n");
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
			if (G->ars[i][j] >0&&G->ars[i][j]<MAX)
			{
				G->arsnum++;
			}
		}
	}

	//G->arsnum /= 2;//这里因为是无向表，所以每条边被重复计算了两次
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
	Graph* G = GraphInit(9);
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
	int ars[9][9] =
	{
		0,6,4,5,MAX,MAX,MAX,MAX,MAX,
		MAX,0,MAX,MAX,1,MAX,MAX,MAX,MAX,
		MAX,MAX,0,MAX,1,MAX,MAX,MAX,MAX,
		MAX,MAX,MAX,0,MAX,2,MAX,MAX,MAX,
		MAX,MAX,MAX,MAX,0,MAX,9,7,MAX,
		MAX,MAX,MAX,MAX,MAX,0,MAX,4,MAX,
		MAX,MAX,MAX,MAX,MAX,MAX,0,MAX,2,
		MAX,MAX,MAX,MAX,MAX,MAX,MAX,0,4,
		MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,0

	};
	
	createGraph(G, "012345678", (int*)ars);
	DFS(G, 0, visit);
	printf("\n");

	topulogicalsort(G);

	return 0;
}