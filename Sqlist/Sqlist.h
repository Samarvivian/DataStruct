#define MAXSIZE 20
#define error 0
#define ok 1
#define false 0
typedef int Status;
typedef int ElemType;
typedef struct 
{
   ElemType data[MAXSIZE];
   int length;
}Sqlist;


Status GetElem(Sqlist q,int i,ElemType e);//用e返回第i个元素的值

Status SqlistInsert(Sqlist *q,int i,ElemType *e);//在第i个位置插入e值

Status SqlistDelete(Sqlist *q,int i,ElemType *e);//删除第i个元素，并用e储存