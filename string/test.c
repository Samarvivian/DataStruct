#include"string.h"
int main()
{
    SqString *str=SqStringInit();
    SqString *str1=SqStringInit();
    SqStringAssign(str,"hello");
    SqStringAssign(str1,"ll");
    SqStringPrint(*str);
    SqStringPrint(*str1);

    forcematch(str,str1);

    printf("%d",KMP(str,str1,0));
    return 0;
}