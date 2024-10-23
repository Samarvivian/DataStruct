#include"array.h"

Status ArrayInit(Array *array,int a,int b)
{
    assert(array);
    array->data=(ElemType*)malloc(sizeof(ElemType)*(a*b));
    if(!array->data)
    {
        exit(-1);
    }
    array->a=a;
    array->b=b;

    return ok;
}

Status ArrayDestory(Array *array)
{
    free(array->data);
    array->data=NULL;//养成好习惯，避免悬挂指针
    array->a=0;
    array->b=0;

    return ok;
}

Status ArrayAssign(Array *array,ElemType e,int i,int j)
{
    assert(array);
    assert(array->data);

    if(i>=0&&i<array->a&&j>=0&&j<array->b)
    {
        num=i*array->a+j;
        array->data[num]=e;
        return ok;
    }
    else
    {
        return error;
    }
}

Status ArrayValue(Array *array,ElemType *e,int i,int j)
{
    assert(array);
    assert(array->data);

    if(i>=0&&i<array->a&&j>=0&&j<array->b)
    {
        num=i*array->a+j;
        *e=array->data[num];
        return ok;
    }
    else
    {
        return error;
    }
}