#include"tree.h"
int main(int argc, char* argv[])
{
    TreeNode* tree;
    createTree(&tree, argv[1]);

    preOrder(tree);
    printf("\n");

    return 0;
}