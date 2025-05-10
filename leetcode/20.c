#include<stdbool.h>
char suit(char *s)
{
    if(*s=='}')
    {
        return '{';
    }
    if(*s==']')
    {
        return '[';
    }
    if(*s==')')
    {
        return '(';
    }
    return 0;
}

bool isvalid(char* s)
{
    int len=strlen(s);
    if(len%2==1)
    {
        return false;
    }
    char stk[len+1];
    int top=0;
    char e=0;
    

    while(s)
    {
        e=suit(s);
        if(e)
        {
            if(top==0||e!=stk[top-1])
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
            stk[top++]=*s;
            s++;
        }
    }
    if(stk)
    {
        return false;
    }
    return true;

}