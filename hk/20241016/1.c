//（1）建立栈并进行元素（8，9，5，4）入栈，实现链栈的建立及入栈的基本操作；
//（2）实现元素（9，5）的出栈，实现链栈的出栈的操作；
//（5）有操作菜单

#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

#define ok 1

typedef int Status;
typedef int ElemType;
typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
    
    
}StackNode;

typedef struct Stack
{
    StackNode *bottom;//指向栈底
    StackNode *top;//指向栈顶
}Stack;

Status StackInit(Stack *stack)
{
    stack->bottom=stack->top=NULL;
    return ok;
}
Status StackPush(Stack *stack,ElemType x)
{
    assert(stack);
    StackNode *newnode=(StackNode*)malloc(sizeof(StackNode));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->data=x;
    newnode->next=NULL;

    if(stack->top==NULL)//栈为空
    {
        stack->bottom=stack->top=newnode;
        
    }
    else
    {
        
        stack->top->next=newnode;
        stack->top=newnode;
    }
    return ok;
}

Status StackPop(Stack *stack)
{
    assert(stack);
    if(!stack->top)//处理栈空
    {
        perror("栈已空\n");
        exit(-1);
    }
    else
    {
        //注意要分成栈里还剩一个元素，与剩两个及以上元素的情况

        if(stack->bottom!=stack->top)
        {
            StackNode *newnode=stack->bottom;
            while(newnode->next!=stack->top)
            {
                newnode=newnode->next;
            }
            newnode->next=stack->top->next;
            StackNode *p=stack->top;
            free(p);
            p=NULL;
            stack->top=newnode;
        }
        else
        {
            stack->bottom=stack->top=NULL;
        }
        
        
    }
    return ok;
}

Status StackPrint(Stack stack)
{
    assert(&stack);
    StackNode *next=stack.bottom;
    while(next)
    {
        printf("%d->",next->data);
        next=next->next;
    }
    printf("NULL\n");
    return ok;
    
}

Status StackDestroy(Stack *stack)//销毁栈，防止占用太多内存
{
    StackNode *next=stack->bottom;
    while(next)
    {
        free(next);
        next=next->next;
    }
    stack->bottom=stack->top=NULL;
    return ok;
}

void menu()
{
    printf("-----------操作,请选择-----------\n");
    printf("-----1.入栈----2.出栈---0.放弃------\n");
}
int main()
{
    Stack ST;
    StackInit(&ST);

    // StackPush(&ST,1);
    // StackPush(&ST,2);
    // StackPush(&ST,3);
    // StackPush(&ST,4);
    // StackPush(&ST,5);

    // StackPrint(ST);

    // StackPop(&ST);
    // StackPop(&ST);
    // StackPop(&ST);
    // StackPop(&ST);
    // StackPop(&ST);

    // StackPrint(ST);

    int choice=0;//储存选择的选项
    menu();
    scanf("%d",&choice);

    int element=0;//储存入栈出栈的元素

    while(choice)
    {
        if(choice==1)
        {
            printf("请输入想要入栈的元素:");
            scanf("%d",&element);

            StackPush(&ST,element);
            StackPrint(ST);
        }

        else if(choice==2)
        {
            StackPop(&ST);
            StackPrint(ST);
        }

        else
        {
            printf("输入错误，请重新输入\n");
        }
        menu();
        scanf("%d",&choice);


    }
    StackDestroy(&ST);

    return 0;
}