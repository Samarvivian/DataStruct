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
        (*tree)->flag=0;
        //递归
        createTree(&((*tree)->lchild),data,index);
        createTree(&((*tree)->rchild),data,index);
    }
    return ok;
}

StackNode* StackInit()
{
    StackNode *node=(StackNode*)malloc(sizeof(StackNode));
    if(!node)
    {
        exit(-1);
    }
    node->next=NULL;
    node->tree=NULL;

    return node;
}

Status StackPush(StackNode* stack,TreeNode *tree)
{
    assert(stack&&tree);

    StackNode *newnode=(StackNode*)malloc(sizeof(StackNode));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->tree=tree;

    newnode->next=stack->next;
    stack->next=newnode;

    return ok;
}

bool IsEmpty(StackNode* stack)
{
    assert(stack);
    return stack->next==NULL;
}

StackNode* StackPop(StackNode* stack)
{
    assert(stack);

    if (!IsEmpty(stack))
    {
        StackNode* node=stack->next;
        stack->next=node->next;
        return node;
    }
}

//前序和中序本质方法都一样，都是用栈的先进后出原理实现
//都是先放进去根结点
//然后寻找它的左节点
//再次寻找这个结点的左节点
//直到没有左节点，就把这个结点出栈，再次回到这个结点的根节点
//寻找根节点的右节点，依次递推
//不同的是，前序是进栈时就打印，中序是出栈时才打印

void preorder(StackNode* stack,TreeNode* tree)
{
    assert(stack&&tree);

    TreeNode *node=tree;
    while(node||!IsEmpty(stack))//注意这里必须是两个条件
    {
        if(node)
        {
            printf("%c",node->data);
            StackPush(stack,node);
            node=node->lchild;
        }
        else
        {
            node=StackPop(stack)->tree;
            node=node->rchild;
        }

    }
}

void inorder(StackNode* stack,TreeNode* tree)
{
    assert(stack&&tree);

    TreeNode *node=tree;
    while(node||!IsEmpty(stack))
    {
        if(node)
        {
            
            StackPush(stack,node);
            node=node->lchild;
        }
        else
        {
            
            node=StackPop(stack)->tree;
            printf("%c",node->data);
            node=node->rchild;
        }

    }
}

//后序遍历也需要不断寻找左子树
//但是当找到左子树为空时，还要去访问它的右子树
//若没有右子树，就把它出栈
//并且在访问右子树时，还要设一个指针去查看是否已经被访问过

StackNode* getPop(StackNode* stack)
{
    assert(stack);

    if(IsEmpty(stack))
    {
        return NULL;
    }
    else
    {
        return stack->next;
    }
}

void postorder(StackNode* stack,TreeNode* tree)
{
    assert(stack&&tree);

    TreeNode *node=tree;
    while(node||!IsEmpty(stack))
    {
        if(node)
        {
            StackPush(stack,node);
            node=node->lchild;
        }
        else
        {
            node=getPop(stack)->tree;
            if((node->rchild->flag==0)&&(node->rchild))
            {
                node=node->rchild;
                node->flag=1;
                StackPush(stack,node);
            }
            else
            {
                node=StackPop(stack)->tree;
                printf("%c",node->data);
            }
        }
    }
}