//	问题描述：
//设计一个校园导游程序，为来访的客人提供各种信息咨询服务。
//	基本要求：
//（1）	设计你所在的学校的校园平面图，所含景点不少于5个。
// 以图中顶点表示校内各景点，存放景点的名称、代号、简介等信息；
// 以边表示路径，存放路径长度等相关信息。
//（2）	为来访客人提供图中任意景点相关信息的咨询。
//（3）	为来访客人提供图中任意景点的问路查询，即查询任意两个景点之间的一条最短的简单路径。

#define ok 1
#define size 5//定义景点个数
#define MAX 256
#define max 32767
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int Status;
//建立顶点结构体，存放景点的名称、代号、简介等信息
typedef struct Vex
{
	char* name;//顶点名称
	int index;//代号
	char* intro;//简介
};
//建立边结构体,存放路径长度等相关信息
typedef struct ARS
{
	int arsnum;//有效边的个数
	int** ars;
};
//建立图结构体
typedef struct Graph
{
	Vex* vex;
	ARS Ars;
}Graph;

Status getMin(Graph* G, int* D, int* S)
{
	int min = max;
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (!S[i] && min > D[i])
		{
			min = D[i];
			index = i;
		}
	}
	return index;
}
//迪杰克拉斯算法
Status dijkstra(Graph* G, int index,int des)
{
	//建立一个数组记录从所定结点到当前结点的最短路径是否找到
	int* S = (int*)malloc(sizeof(int) * size);
	//建立一个数组记录当前结点的前驱结点
	int* P = (int*)malloc(sizeof(int) * size);
	//建立一个数组记录从所定结点到当前结点的最短路径
	int* D = (int*)malloc(sizeof(int) * size);

	//初始化
	for (int i = 0; i < size; i++)
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

	for (int i = 0; i < size; i++)
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

	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			D[i] = 0;
		}
		else if (G->Ars.ars[index][i] > 0 && G->Ars.ars[index][i] < MAX)
		{
			D[i] = G->Ars.ars[index][i];
		}
		else
		{
			D[i] = max;
		}
	}


	for (int i = 0; i < size - 1; i++)
	{
		int newindex = getMin(G, D, S);
		S[newindex] = 1;
		for (int j = 0; j < size; j++)
		{
			if (!S[j] && G->Ars.ars[newindex][j] + D[newindex] < D[j])
			{
				D[j] = G->Ars.ars[newindex][j] + D[newindex];
				P[j] = newindex;
			}
		}

	}
	/*for (int i = 0; i < size; i++)
	{
		printf("%d %d %d\n", S[i], P[i], D[i]);
	}
	printf("结点%d到其他结点的最短路径分别为：\n", index);*/
	/*for (int i = 0; i < size; i++)
	{
		if (P[i] == index)
		{
			printf("%s--->%s,路径长为%d\n", G->vex[index].name, G->vex[i].name, D[i]);
		}
		else if (P[i] != -1 && P[i] != index)
		{
			printf("%s--->%s--->%s,路径长为%d\n", G->vex[index].name, G->vex[P[i]], G->vex[i].name, D[i]);
		}

	}*/

	for (int i = 0; i < size; i++)
	{
		if (i == des)
		{
			if (P[i] == index)
			{
				printf("从%s到%s,最短路径长为%d\n", G->vex[index].name, G->vex[i].name, D[i]);
			}
			else if (P[i] != -1 && P[i] != index)
			{
				printf("从%s到%s到%s,最短路径长为%d\n", G->vex[index].name, G->vex[P[i]].name, G->vex[i].name, D[i]);
			}
		}
	}
	return ok;
}

//初始化图
Graph* GraphInit()
{
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vex = (Vex*)malloc(sizeof(Vex)*size);
	

	
	for (int i = 0; i < size; i++)
	{
		G->vex[i].name=(char*)malloc(sizeof(char)*MAX);
		G->vex[i].index = 0;
		G->vex[i].intro = (char*)malloc(sizeof(char)*MAX);
	}

	
	
	G->Ars.ars = (int**)malloc(sizeof(int*) * size);
	for (int j = 0; j < size; j++)
	{
		G->Ars.ars[j] = (int*)malloc(sizeof(int) * size);
	}
	G->Ars.arsnum = 0;
		
	
	return G;
}

//构建图
Status createGraph(Graph* G,int* arr)
{
	G->vex[0].name = (char*)"饭堂";
	G->vex[0].index = 1;
	G->vex[0].intro =(char*) "饭很好吃";

	G->vex[1].name = (char*)"图书馆";
	G->vex[1].index = 2;
	G->vex[1].intro=(char*)"学习的好地方";

	G->vex[2].name = (char*)"日月湖";
	G->vex[2].index = 3;
	G->vex[2].intro = (char*)"美丽";

	G->vex[3].name = (char*)"教学楼";
	G->vex[3].index = 4;
	G->vex[3].intro = (char*)"上课的地方";

	G->vex[4].name = (char*)"宿舍";
	G->vex[4].index = 5;
	G->vex[4].intro = (char*)"世界一流宿舍";

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			G->Ars.ars[i][j] = *(arr + i * size + j);
			if (G->Ars.ars[i][j] > 0 && G->Ars.ars[i][j] < max)
			{
				G->Ars.arsnum++;
			}
		}
		
	}
	return ok;
}

//为来访客人提供图中任意景点相关信息的咨询
void Intro(Graph* G)
{
	printf("-------欢迎来到暨南大学------");
	printf("\n");
	printf("请输入你想要查询的景点的代号,以零结束:\n");
	printf("1.饭堂\n");
	printf("2.图书馆\n");
	printf("3.日月湖\n");
	printf("4.教学楼\n");
	printf("5.宿舍\n");
	int index = 0;
	scanf_s("%d", &index);
	while (index != 0)
	{
		if (index >= 1&&index<=5)
		{
			printf("%s---%s\n", G->vex[index - 1].name, G->vex[index - 1].intro);
		}
		else
		{
			printf("输入错误，请重试\n");
		}
		printf("请继续输入:");
		scanf_s("%d", &index);
	}
}

//为来访客人提供图中任意景点的问路查询，即查询任意两个景点之间的一条最短的简单路径
void Found(Graph* G)
{
	int index = 0,des = 0;
	printf("请输入你想要查询的两个景点路线的代号:\n");
	printf("1.饭堂\n");
	printf("2.图书馆\n");
	printf("3.日月湖\n");
	printf("4.教学楼\n");
	printf("5.宿舍\n");
	scanf_s("%d %d", &index, &des);
	while (index >= 1 && index <= 5 && des >= 1 && des <= 5 && index != des)
	{
		dijkstra(G, index - 1, des - 1);
		printf("请再次输入:");
		scanf_s("%d %d", &index, &des);
	}
	
}

int main()
{
	Graph* G = GraphInit();
	int arr[5][5] =
	{
		0,6,5,2,max,
		6,0,7,8,9,
		5,7,0,8,9,
		2,max,8,0,max,
		max,3,9,max,0
	};
	createGraph(G,(int*)arr);
	Intro(G);
	printf("\n");
	Found(G);
	return 0;
}

