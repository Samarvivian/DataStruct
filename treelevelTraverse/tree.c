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
        printf("%c ",tree->data);
        preOrder(tree->lchild);
        preOrder(tree->rchild);
    }
 
}

QueueNode* QueueInit()
{
    QueueNode *queue=(QueueNode*)malloc(sizeof(QueueNode));
    if(!queue)
    {
        exit(-1);
    }
    queue->next=queue;
    queue->prev=queue;

    return queue;
}

Status enqueue(TreeNode *tree,QueueNode *queue)
{
    assert(tree&&queue);

    QueueNode *newnode=(QueueNode*)malloc(sizeof(QueueNode));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->data=tree;

    QueueNode *tail=queue->prev;//之前的尾结点
    tail->next=newnode;
    newnode->prev=tail;
    newnode->next=queue;
    queue->prev=newnode;

    return ok;
}

bool IsEmpty(QueueNode *queue)
{
    assert(queue);

    return queue->next==queue;
}

QueueNode* dequeue(QueueNode *queue)
{
    assert(queue);
    assert(!IsEmpty(queue));

    QueueNode* node=queue->next;
    queue->next=node->next;
    queue->next->prev=queue;
    return node;
}

void leveltreeTraverse(TreeNode *tree,QueueNode *queue)
{
    assert(tree&&queue);

    enqueue(tree,queue);
    while(!IsEmpty(queue))
    {
        QueueNode* node=dequeue(queue);
        printf("%c ",node->data->data);

        if(node->data->lchild)
        {
            enqueue(node->data->lchild,queue);
        }
        if(node->data->rchild)
        {
            enqueue(node->data->rchild,queue);
        }
    }
}