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

void inorder(TreeNode *tree,int *size)
{
    if(!tree)
    {
        return;
    }
    else
    {
        
        inorder(tree->lchild,size);
        (*size)++;
        inorder(tree->rchild,size);
    }
}