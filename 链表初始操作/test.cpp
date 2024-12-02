#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
};

//打印,带头节点
void NodePrint1(Node* node)
{
	Node* next = node->next;
	while (next)
	{
		printf("%d->", next->data);
		next = next->next;
	}
	printf("NULL");
}

//打印,不带头节点
void NodePrint2(Node* node)
{
	Node* next = node;
	while (next)
	{
		printf("%d->", next->data);
		next = next->next;
	}
	printf("NULL");
}

//插入，带头节点
void NodeInsert1(Node** node,int data)
{
	//新建结点
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	//链表为空
	if (!((*node)->next))
	{
		newnode->next = (*node)->next;
		(*node)->next = newnode;
	}
	else
	{
		//找到尾结点
		Node* next = (*node)->next;
		while (next->next)
		{
			next = next->next;
		}
		newnode->next = next->next;
		next->next = newnode;
	}
}

//插入，不带头节点
void NodeInsert2(Node** node, int data)
{
	//新建结点
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;

	//链表为空
	if (!(*node))
	{
		(*node)=newnode;
	}
	else
	{
		//找到尾结点
		Node* next = (*node);
		while (next->next)
		{
			next = next->next;
		}
		newnode->next = next->next;
		next->next = newnode;
	}
}

void Test1()
{
	//有头节点的链表声明
	Node* node= (Node*)malloc(sizeof(Node));
	node->next = NULL;

	//插入
	NodeInsert1(&node, 1);
	NodeInsert1(&node, 2);
	NodeInsert1(&node, 3);
	NodeInsert1(&node, 4);
	NodeInsert1(&node, 5);

	//打印
	NodePrint1(node);
}

void Test2()
{
	//无头节点的链表声明
	Node* node = NULL;
	

	//插入
	NodeInsert2(&node, 1);
	NodeInsert2(&node, 2);
	NodeInsert2(&node, 3);
	NodeInsert2(&node, 4);
	NodeInsert2(&node, 5);

	//打印
	NodePrint2(node);
}

int main()
{
	Test2();
	return 0;
}