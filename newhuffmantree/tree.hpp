//建立哈夫曼树
//初始化。从终端读入字符集大小n，以及n个字符和n个权值，建立哈夫曼树，并将它存在于文件hfmTree中。
//（2） 编码。利用以建好的哈夫曼树（如不在内存，则从文件hfmTree中读入），对文件的正文进行编码，
//然后将结果存入文件CodeFile中。
//（3） 译码。利用已建好的哈夫曼树将文件CodeFile中的代码进行译码，结果存入在文件TextFile中。

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ok 1

typedef int Status;



typedef struct TreeNode
{
    int weight;//表示权重
    
    int lchild;//左孩子
    int rchild;//右孩子
    int parent;//父亲
   
}TreeNode;

typedef struct HFtree
{
    TreeNode *tree;
    int len;//用数组储存哈夫曼树，len表示原来的结点个数
}HFtree;



HFtree* HuffmanTreeInit(int n);//初始化哈夫曼树

int* selectMin(HFtree *T);//找到最小和次小权重

Status createHFTree(HFtree* T);//建立哈夫曼树

Status encode(HFtree* T,hfmantreecode hc,int n);//哈夫曼编码

void preorder(HFtree* T,int index);//前序遍历哈夫曼树