#include"queue.h"
void Test()
{
    Queue qt;
    QueueInit(&qt);
    QueuePush(&qt,1);
    QueuePush(&qt,2);
    QueuePush(&qt,3);
    QueuePush(&qt,4);
    QueuePush(&qt,5);
    QueuePop(&qt);
    QueuePop(&qt);
    QueuePop(&qt);
    QueuePop(&qt);
    QueuePop(&qt);
    QueueDestory(&qt);
}

int main()
{
    Test();
    return 0;
}