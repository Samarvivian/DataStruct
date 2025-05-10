//请通过匹配找出子串T在主串S中首次出现的位置（索引从0开始），
//例如主串S=“abbcdefggde”,子串T=“def”,则应该返回5。
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#define ok 1
#define error -1
typedef int Status;

typedef struct String
{
    char *data;
    int len;
}String;

String* StringInit()
{
    
    String *str=(String*)malloc(sizeof(String));
    if(!str)
    {
        exit(-1);
    }
    str->data=NULL;
    str->len=0;
    return str;
}

Status StringAssign(String* str,char *data)
{
    assert(str);
    if(str->data)
    {
        free(str->data);
    }
    char *next=data;
    int len=0;
    while(*next)
    {
        len++;
        next++;
    }
    if(!len)
    {
        str->data=NULL;
        str->len=0;
    }
    else
    {
        next=data;
        str->data=(char*)malloc(sizeof(char)*(len+1));
        if(!str->data)
        {
            exit(-1);
        }
        str->len=len;
        int i=0;
        while(i<len)
        {
            str->data[i]=(*next);
            i++;
            next++;
        }
        str->data[len]='\0';
    }
    return ok;
}

Status StringPrint(String str)
{
    int i=0;
    for(i=0;i<str.len;i++)
    {
        printf("%c",str.data[i]);
    }
    printf("\n");
    return ok;
}

Status Getnext(String *str,int *next)
{
    assert(str&&next);
    next[0]=-1;
    next[1]=0;

    int k=0;
    int j=2;

    while(j<str->len)
    {
        if((k==-1)||(str->data[j-1]==str->data[k]))
        {
            //解法1
            // next[j]=k+1;
            // k++;
            // j++;

            //优化后的解法2
            k++;
            next[j]=(str->data[j]!=str->data[k])?k:next[k];
            j++;
        }
        else
        {
            k=next[k];//回溯
        }
    }
    return ok;
}
Status KMP(String *str,String *sub)
{
    

    assert(str&&sub);
    int len1=str->len;
    int len2=sub->len;

    int *next=(int*)malloc(sizeof(int)*len2);
    if(!next)
    {
        exit(-1);
    }
    Getnext(sub,next);

    int i=0;
    int j=0;

    while(i<len1&&j<len2)
    {
        if((j==-1)||(str->data[i]==sub->data[j]))
        {
            //要包含当第一个字符就开始不匹配的情况
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
    if(j==len2)
    {
        //匹配成功
        return i-j;
    }
    else
    {
        return -1;
    }
}

int main()
{
    String *s1=StringInit();
    String *s2=StringInit();

    StringAssign(s1,"abbcdefggde");
    StringAssign(s2,"def");

    StringPrint(*s1);
    StringPrint(*s2);

    if(KMP(s1,s2)!=-1)
    {
        printf("匹配成功，子串的下标为%d\n",KMP(s1,s2));
    }
    else
    {
        printf("匹配失败\n");
    }

    return 0;
}