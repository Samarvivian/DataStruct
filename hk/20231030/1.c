#include<stdio.h>
#include<stdlib.h>
#define ok 1
typedef int Status;
typedef char ElemType;
typedef struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}TreeNode;

Status createTree(TreeNode **tree,ElemType *data,int *index)
{
    
    
    ElemType ch=data[*index];
    (*index)++;

    if(ch=='#')
    {
        *tree=NULL;
    }
    else
    {
        (*tree)=(TreeNode*)malloc(sizeof(TreeNode));
        if(!(*tree))
        {
            exit(-1);
        }
        (*tree)->data=ch;
        createTree(&(*tree)->lchild,data,index);
        createTree(&(*tree)->rchild,data,index);
    }
    return ok;
}

void preorder(TreeNode *tree)
{
    //前序遍历二叉树
    if(!tree)
    {
        return;//如果树为空,不打印
    }
    else
    {
        printf("%c",tree->data);
        preorder(tree->lchild);
        preorder(tree->rchild);
    }
}

void ReverseChild(TreeNode **tree)
{
    if((*tree))
    {
        TreeNode *temp=(*tree)->lchild;
        (*tree)->lchild=(*tree)->rchild;
        (*tree)->rchild=temp;

        ReverseChild(&(*tree)->lchild);
        ReverseChild(&(*tree)->rchild);
    }
}

int main(int argc,char *argv[])
{
    TreeNode *tree;
    int index=0;

    createTree(&tree,argv[1],&index);

    printf("前序遍历得到的树为: ");
    preorder(tree);
    printf("\n");

    ReverseChild(&tree);
    printf("经过左右子树的交换后，新得到的树为: ");
    preorder(tree);
    printf("\n");


    return 0;
}