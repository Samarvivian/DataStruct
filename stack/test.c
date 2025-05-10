#include"stack.h"
void Test1()
{
    SqStack ps;
    StackInit(&ps);
    push(&ps,1);
    push(&ps,2);
    push(&ps,3);
    push(&ps,4);
    push(&ps,5);

    Top(&ps);
}

int main()
{
    Test1();
    return 0;
}