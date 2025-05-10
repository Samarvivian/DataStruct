#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#define ok 1
typedef int Status;
typedef char ElemType;
typedef struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}TreeNode;
typedef struct QueueNode
{
    //用带头双向循环链表实现层次遍历二叉树
    TreeNode *data;
    struct QueueNode *prev;
    struct QueueNode *next;
}QueueNode;

Status createTree(TreeNode **tree,char *data,int *index);//创建树

void preOrder(TreeNode *tree);//前序遍历树

QueueNode* QueueInit();//初始化队列

Status enqueue(TreeNode *tree,QueueNode *queue);//入队

bool IsEmpty(QueueNode *queue);//判断是否队空，是空返回真

QueueNode* dequeue(QueueNode *queue);//出队

void leveltreeTraverse(TreeNode *tree,QueueNode *queue);//层次遍历