#include"slist.h"
void Test1()
{
    SList *sl=SListInit();

    SListPushBack(sl,1);
    SListPushBack(sl,2);
    SListPushBack(sl,3);
    SListPushBack(sl,4);

    SListPrint(sl);
}
int main()
{
    Test1();
    return 0;
}