#include"tree.hpp"

int main()
{
    

    int choice=0;
    int n=0;
    HFtree* T;
    typedef char** hfmantreecode;
    hfmantreecode hc;

    char Alphabet[128];//用于储存可能出现的字符
    printf("********哈夫曼编码********\n");
    printf("1.输入字符总数\n");
    printf("2.输入字符种类\n");
    printf("3.建立哈夫曼树\n");
    printf("4.进行哈夫曼编码\n");
    printf("5.退出\n");
    printf("请选择1-5:\n");
    scanf("%d",&choice);

    while(choice)
    {
        if(choice==1)
        {
            printf("你想要输入多少种字符?\n");
            scanf("%d",&n);
        }
        if(choice==2)
        {
            printf("请输入这%d种字符\n",n);
            for(int i=0;i<n;i++)
            {
                scanf("%c",&Alphabet[i]);

            }
        }
        if(choice==3)
        {
            T=HuffmanTreeInit(n);
            createHFTree(T);
        }
        if(choice==4)
        {
            encode(T,hc,n);
        }
        else
        {
            break;
        }
    }

    return 0;
}