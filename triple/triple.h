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
    Triple data[MAXSIZE];
    int mu,nu,tu;
}Matrix;

Status MatrixInit(Matrix *m);

Status MatrixPrint(Matrix *m);