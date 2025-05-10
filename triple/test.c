#include"triple.h"
int main()
{
    Matrix m;
    Matrix n;
    MatrixInit(&m);
    //MatrixInit(&n);
    MatrixPrint(&m);
    MatrixReverse2(&m,&n);
    MatrixPrint(&n);

    return 0;
}