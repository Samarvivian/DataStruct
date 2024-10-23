//1	设s=’I am a teacher’, t=’good’, q=’student’ . 
//求: StrLength(s), StrLength(t), SubString(s,8,7), 
//SubString(t,2,1), Index(s,’a’), Index (s,t), 
//Replace (s, ‘teacher’, q), Concat (SubString (s,6,2), 
//Concat (t, SubString (s,7,8)))

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

#define ok 1
#define error 0

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
    int len=0;
    char *temp=data;
    while(*temp)
    {
        len++;
        temp++;
    }
    if(len==0)
    {
        str->data=NULL;
        str->len=0;
    }
    else
    {
        temp=data;
        str->data=(char*)malloc(sizeof(char)*(len+1));
        if(!str->data)
        {
            exit(-1);
        }
        str->len=len;
        for(int i=0;i<len;i++)
        {
            str->data[i]=(*temp);
            temp++;
        }
    }
    return ok;
}

Status StringPrint(String str)
{
    for(int i=0;i<str.len;i++)
    {
        printf("%c",str.data[i]);
    }
    printf("\n");
    return ok;
}

int StrLength(String str)
{
    // int len=0;
    // char *temp=str.data;
    // while(*temp)
    // {
    //     len++;
    //     temp++;
    // }
    // return len;

    return str.len;
}

String* SubString(String *str,int x,int y)
{
    assert(str);
    String *temp=(String*)malloc(sizeof(String));
    if(!temp)
    {
        exit(-1);
    }
    temp->data=(char*)malloc(sizeof(char)*y);
    temp->len=y;
    int i=0;
    for(i=0;i<y;i++)
    {
        temp->data[i]=str->data[x-1];
        x++;
    }
    return temp;
}

Status Index(String *master,String *sub)
{
    //暴力匹配
    int i=0;
    int j=0;
    while(i<master->len&&j<sub->len)
    {
        if(master->data[i]==sub->data[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;//回溯到这次起始位置的下一个位置
            j=0;//归零
        }
    }
    if(j==sub->len)
    {
        //匹配成功
        return i-j+1;
    }
    else
    {
        return error;
    }
} 

String* Replace(String *str,char *data1,char *data2)
{
    assert(str);
    
    String *temp=StringInit();//定义一个临时字符串
    StringAssign(temp,data1);
    if(!Index(str,temp))
    {
        //先判断主串中有没有目标子串
        printf("没有目标子串，无法替换\n");
        exit(-1);
    }
    //获取所要替换成的子串长度
    int len=strlen(data2);
    
    int i=Index(str,temp)-1;
    int j=0;
    for(j=0;j<len;j++)
    {
        str->data[i]=data2[j];
        i++;
    }
    return str;

}

String* concat(String *str1,String *str2)
{
    assert(str1);
    assert(str2);

    int len1=StrLength(*str1);
    int len2=StrLength(*str2);

    str1->data=(char*)realloc(str1->data,sizeof(char)*(StrLength(*str2)+StrLength(*str1)));
    str1->len=len1+len2;
    if(!str1->data)
    {
        exit(-1);
    }
    int i=0;
    int j=0;
    for(i=len1,j=0;i<len1+len2;i++,j++)
    {
        str1->data[i]=str2->data[j];
    }
    return str1;

}
int main()
{
    String* s=StringInit();
    String* t=StringInit();
    String* c=StringInit();
    
    StringAssign(s,"(xyz)+*");
    StringAssign(t,"(x+y)*y");
    

    StringPrint(*s);
    StringPrint(*t);
    

    

    String *s1=SubString(s,1,2);
    String *s2=SubString(s,3,1);
    String *s3=SubString(s,5,1);
    String *s4=SubString(s,6,1);
    String *s5=SubString(s,7,1);

    

    c=concat (s1, concat(s4,concat(s2,(concat(s3,(concat(s5,s2)))))));
    printf("连接后为：");
    StringPrint(*c);

    return 0;
}