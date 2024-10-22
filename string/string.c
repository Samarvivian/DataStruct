#include"string.h"
SqString* SqStringInit(void)
{
    SqString *str=(SqString*)malloc(sizeof(SqString));
    if(!str)
    {
        exit(-1);
    }
    str->data=NULL;
    str->len=0;
    return str;
}

Status SqStringAssign(SqString *str,char *data)
{
    assert(str);
    int len=0;
    if(str->data)
    {
        free(str->data);//防止野指针出现
    }
    char *temp=data;
    while(*temp)
    {
        len++;
        temp++;
    }
    if(!len)
    {
        str->data=NULL;
        str->len=0;
    }
    else
    {
        str->len=len;
        str->data=(char*)malloc(sizeof(char)*(len+1));//多一个长度用于储存结束符
        temp=data;
        int i=0;
        for(i=0;i<len;i++)
        {
            str->data[i]=(*temp);
            temp++;
        }
    }
    return ok;

}

Status SqStringPrint(SqString str)
{
    int i=0;
    for(i=0;i<str.len;i++)
    {
        printf(i==0?"%c":"->%c",str.data[i]);
    }
    printf("\n");
    return ok;
}

void forcematch(SqString *master,SqString *sub)
{
    //最朴素的做法是，从头开始将主串与子串一一比较
    //如果不匹配，就把主串的指针指向这次起始位置的下一个位置
    //子串的指针归零
    //否则两指针都递增
    int p1=0;
    int p2=0;
    while(p1<master->len&&p2<sub->len)
    {
        if(master->data[p1]==sub->data[p2])
        {
            p1++;
            p2++;
        }
        else
        {
            p1=(p1-p2)+1;
            p2=0;
        }
    }
    if(p2==sub->len)
    {
        printf("匹配成功\n");
    }
    else
    {
        printf("匹配失败\n");
    }
}

Status Getnext(int *next,SqString *sub)
{
    assert(next&&sub);
    // next[0]=-1;
    // next[1]=0;
    // int i=2;
    // int k=0;

    // while(i<sub->len)
    // {
    //     if(k==-1||(sub->data[k]==sub->data[i-1]))
    //     {
    //         //当K回溯到-1时，next[i]==0
    //         next[i]=k+1;
    //         i++;
    //         k++;
    //     }
    //     else
    //     {
    //         k=next[k];
    //     }
    // }

    //next数组优化
    next[0]=-1;
    next[1]=0;
    int i=2;
    int k=0;

    while(i<sub->len)
    {
        if(k==-1||(sub->data[k]==sub->data[i-1]))
        {
            k++;
            //这是关键点
            //如果sub->data[k]==sub->data[i]，因为sub->data[i]已经不匹配了
            //所以sub->data[k]一定不匹配
            //一定还会回溯
            //干脆一次性就让它回到最开始的next
            next[i]=(sub->data[k]!=sub->data[i])?k:next[k];

        }
        else
        {
            k=next[k];
        }
    }
    return ok;
}

Status KMP(SqString *str,SqString *sub,int pos)
{
    assert(str&&sub);

    int len1=str->len;
    int len2=sub->len;

    int i=pos,j=0;

    int *next=(int*)malloc(sizeof(int)*len2);
    if(!next)
    {
        exit(-1);
    }
    Getnext(next,sub);

    while(i<len1&&j<len2)
    {
        if(j==-1||(str->data[i]==sub->data[j]))
        {
            //要包含j==-1这种情况，因为假设第一个字符就不匹配的话，还是要i++,j++
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
        return i-j+1;
    }
    else
    {
        return -1;
    }
}

// int SqStringlen(SqString *str)
// {
//     return str->len;
// }

// bool SqStringEmpty(SqString *str)
// {
//     return str->len==0;
// }

// bool SqStringEqual(SqString *str1,SqString *str2)
// {
//     return (strcmp(str1->data,str2->data2)==0);
// }