#include<stdio.h>
#include<assert.h>

#define ok 1
#define error 0
typedef int Status;
typedef int ElemType;
typedef struct Array
{
    ElemType *data;//存放基地址
    int a;
    int b;
}Array;

Status ArrayInit(Array *array,int a,int b);

Status ArrayDestory(Array *array);

Status ArrayAssign(Array *array,ElemType e,int i,int j);//赋值操作

Status ArrayValue(Array *array,ElemType *e,int i,int j);//用e储存array数组中下标为[i][j]的元素