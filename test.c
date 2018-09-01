#include "matrixmul.h"

int main(int argc, char const *argv[])
{

    static Matrix A, B, C;

    setRowsColumns(2, 2, &A);
    setRowsColumns(2, 2, &B);

    setElement(1, 1, 2, &A);
    setElement(1, 2, 1, &A);
    setElement(2, 1, 0, &A);
    setElement(2, 2, 3, &A);

    setElement(1, 1, 1, &B);
    setElement(1, 2, 0, &B);
    setElement(2, 1, 1, &B);
    setElement(2, 2, 2, &B);

    multiply(&A, &B, &C);

    return 0;
}
