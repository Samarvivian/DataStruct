#include"tree.h"
int main(int argc,char *argv[])
{
    TreeNode *tree;
    int index=0;
    createTree(&tree,argv[1],&index);

    preOrder(tree);
    printf("\n");

    inorder(tree);
    printf("\n");

    postorder(tree);
    printf("\n");

    return 0;
}