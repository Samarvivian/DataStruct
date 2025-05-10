#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#define ok 1
typedef int Status;
typedef char ElemType;
typedef struct TreeNode
{
    ElemType data;
    struct TreeNode* lchild;//左孩子
    struct TreeNode* rchild;//右孩子
}TreeNode;

Status createTree(TreeNode** tree, char* data);//创建树

void preOrder(TreeNode* tree);//前序遍历树
