#include"tree.h"
Status createTree(TreeNode **tree,char *data,int *index)
{
    char ch=0;
    
    ch=data[*index];
    (*index)+=1;

    if(ch=='#')
    {
        *tree=NULL;//定义当字符为'#'时为空树
    }
    else
    {
        (*tree)=(TreeNode*)malloc(sizeof(TreeNode));
        if(!(*tree))
        {
            exit(-1);
        }
        (*tree)->data=ch;
        //递归
        createTree(&((*tree)->lchild),data,index);
        createTree(&((*tree)->rchild),data,index);
    }
    return ok;
}

void preOrder(TreeNode *tree)
{
    if(!tree)
    {
        return;
    }
    else
    {
        printf("%c",tree->data);
        preOrder(tree->lchild);
        preOrder(tree->rchild);
    }
 
}

void inorder(TreeNode *tree)
{
    if(!tree)
    {
        return;
    }
    else
    {
        
        preOrder(tree->lchild);
        printf("%c",tree->data);
        preOrder(tree->rchild);
    }
}

void postorder(TreeNode *tree)
{
    if(!tree)
    {
        return;
    }
    else
    {
        
        preOrder(tree->lchild);
        
        preOrder(tree->rchild);
        printf("%c",tree->data);
    }
}