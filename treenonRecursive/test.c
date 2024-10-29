#include"tree.h"
int main(int argc,char *argv[])
{
    TreeNode *tree;
    int index=0;
    createTree(&tree,argv[1],&index);

    

    StackNode* stack=StackInit();
    preorder(stack,tree);
    printf("\n");
    inorder(stack,tree);
    printf("\n");
    postorder(stack,tree);
    printf("\n");

    return 0;
}