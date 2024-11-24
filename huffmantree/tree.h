#include<stdlib.h>
#include<stdio.h>
typedef struct TreeNode
{
    int weight;//表示权重
    int father;//父结点
    int lchild;
    int rchild;
}TreeNode;

typedef struct HFTree
{
    TreeNode *data;
    int len;//用数组储存哈夫曼树，表示结点的个数
}HFTree;

HFTree* HFTreeInit(int *weight,int len);//初始化哈夫曼树

int* selectMin(HFTree *T);//找到最小值和次小值

void createHFTree(HFTree *T);//创建哈夫曼树

void Preorder(HFTree *T,int index);//用先序遍历哈夫曼树