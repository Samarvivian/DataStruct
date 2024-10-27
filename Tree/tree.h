#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#define ok 1
typedef int Status;
typedef char ElemType;
typedef struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild;//左孩子
    struct TreeNode *rchild;//右孩子
}TreeNode;

Status createTree(TreeNode **tree,char *data,int *index);//创建树

void preOrder(TreeNode *tree);//前序遍历树

void inorder(TreeNode *tree);//中序遍历树

void postorder(TreeNode *tree);//后序遍历树