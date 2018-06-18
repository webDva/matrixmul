#include "matrixmul.h"

int main(int argc, char const *argv[])
{
    Matrix A, B;

    A.rows = 2; A.columns = 2;
    B.rows = 2; B.columns = 2;

    Matrix C = add(A, B);

    return 0;
}
