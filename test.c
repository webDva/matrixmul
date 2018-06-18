#include "matrixmul.h"

int main(int argc, char const *argv[])
{

    static Matrix A, B, C;

    A.rows = 2; A.columns = 2;
    B.rows = 2; B.columns = 2;

    for (int i = 0; i < A.rows * A.columns; i++) {
        A.elements[i] = 3;
        B.elements[i] = 3;
    }

    add(&A, &B, &C);

    return 0;
}
