typedef enum{atom,list}ElemTag;
//atom==0,原子 list==1，子表
typedef struct GLNode
{
    ElemTag tag;//标志域
    union 
    {
        ElemType data;
        struct 
        {
            struct GLNode *hp,*tp;//指向表头与表尾
        }ptr;
        
    };
    
}GLNode;
