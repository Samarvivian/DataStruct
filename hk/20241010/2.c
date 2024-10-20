//判别开闭括号是否配对出现
char suit(char a)
{
    if(a=='}')
    {
        return '{';
    }
    if(a==']')
    {
        return '[';
    }
    if(a==')')
    {
        return '(';
    }
    return 0;
}
bool check(char *num)
{
    int len=strlen(num);
    if(!len)
    {
        return false;
    }
    if(len%2==1)
    {
        return false;
    }
    char b[len+1];
    memset(b,0,strlen(b));
    int i=0,top=0;
    char e=0;
    for(i=0;i<len;i++)
    {
        e=suit(num[i]);
        if(e)
        {
            if(top==0||e!=b[top-1])
            {
                return false;
            }
            else
            {
                top--;
            }
        }
        else
        {
            b[top++]=num[i];
        }
    }
    if(top)
    {
        return false;
    }
    return true;
}