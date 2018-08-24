#include "matrixmul.h"

int main(int argc, char const *argv[])
{

    static Matrix A, B, C;

    setRowsColumns(2, 2, &A);
    setRowsColumns(2, 2, &B);

    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.columns; j++) {
            setElement(i, j, 3, &A);
            setElement(i, j, 6, &B);
        }
    }

    subtract(&A, &B, &C);
    multiply(&A, &B, &C);

    return 0;
}
