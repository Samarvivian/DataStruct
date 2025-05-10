#include"tree.h"
int main(int argc,char *argv[])
{
    TreeNode *tree;
    int index=0;
    createTree(&tree,argv[1],&index);

    int size=0;
    inorder(tree,&size);
    printf("该树的结点数为：%d",size);

    return 0;
}