//用非递归实现前序和中序和后序二叉树
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
    int flag;//这是在后序中需要用到的标记指针
}TreeNode;
typedef struct StackNode
{
    //用栈实现遍历
    TreeNode *tree;
    struct StackNode *next;
}StackNode;

Status createTree(TreeNode **tree,char *data,int *index);//创建树

StackNode* StackInit();//初始化栈

Status StackPush(StackNode* stack,TreeNode *tree);//入栈

bool IsEmpty(StackNode* stack);//判断栈是否为空

StackNode* StackPop(StackNode* stack);//出栈

StackNode* getPop(StackNode* stack);//拿到栈顶元素

void preorder(StackNode* stack,TreeNode* tree);//前序

void inorder(StackNode* stack,TreeNode* tree);//中序

void postorder(StackNode* stack,TreeNode* tree);//后序