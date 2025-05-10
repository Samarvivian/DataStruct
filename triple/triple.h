#include<stdio.h>
#include<assert.h>

#define MAXSIZE 1000
#define ok 1
#define error 0
typedef int ElemType;
typedef int Status;
typedef struct Triple
{
    int i,j;
    ElemType e;//非零元素的值
}Triple;

typedef struct Matrix
{
    Triple data[MAXSIZE+1];//data[0]不用
    int mu,nu,tu;
    //这里的mu,nu表示的是矩阵的行数和列数
    //上面的i,j表示的才是三元组的行数和列数
}Matrix;

Status MatrixInit(Matrix *m);

Status MatrixPrint(Matrix *m);

Status MatrixReverse1(Matrix *m,Matrix *n);//遍历三元组求逆置矩阵

Status MatrixReverse2(Matrix *m,Matrix *n);//用列求行求逆置矩阵

Status MatrixMutiple(Matrix *m,Matrix *n);//矩阵乘法