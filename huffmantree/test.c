#include"tree.h"
int main()
{
    int weight[]={1,2,3,4};
    int len=4;

    HFTree* T=HFTreeInit(weight,len);
    createHFTree(T);
    Preorder(T,T->len-1);

    return 0;
}