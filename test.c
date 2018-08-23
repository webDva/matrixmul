#include "matrixmul.h"

int main(int argc, char const *argv[])
{

    static Matrix A, B, C;

    setRowsColumns(2, 2, &A);
    setRowsColumns(2, 2, &B);

    for (int i = 0; i < A.rows * A.columns; i++) {
        A.elements[i] = 3;
        B.elements[i] = 6;
    }

    subtract(&A, &B, &C);

    return 0;
}
