//对于字符串S，请设计算法，去除其中重复的字符，并保持字符相对顺序不改变。
//例如S=“aaccbbbhh”,输出“acbh”。S=“abbgaa”,输出“abg”。
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#define ok 1
#define error 0

typedef int status;
typedef struct Node
{
    char data;
    struct Node *next;
}Node;//用链表来储存去重后的字符



status NodeInsert(Node **node,char data)
{
    assert(node);
    Node* newnode=(Node*)malloc(sizeof(Node));
    if(!newnode)
    {
        exit(-1);
    }
    newnode->data=data;
    newnode->next=NULL;
    if(!(*node))
    {
        (*node)=newnode;
        
    }
    else
    {
        Node* temp=(*node);
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return ok;
}

status NodePrint(Node *node)
{
    
    Node* next=node;
    while(next)
    {
        printf("%c",next->data);
        next=next->next;
    }
    printf("\n");
    return ok;
}

status NodeFind(Node *node,char x)
{
    assert(node);
    Node *newnode=node;
    while(newnode)
    {
        if(newnode->data==x)
        {
            return ok;
        }
        newnode=newnode->next;
    }
    return error;
}
status Remove(char *data,Node **node)
{
    
    NodeInsert(node,data[0]);
    int i=0,j=0;
    int len=strlen(data);
    
    while(i<len)
    {
        if(data[i]==data[j])
        {
            i++;
        }
        else
        {
            if(NodeFind(*node,data[i]))
            {
                i++;
            }
            else
            {
                j++;
                NodeInsert(node,data[i]);
                i++;
            }
        }
    }
    return ok;
}

int main()
{
    char data[]="abbgaa";
    Node *node=NULL;
    

    Remove(data,&node);

    printf("去重后的字符是:");
    NodePrint(node);

    return 0;
}