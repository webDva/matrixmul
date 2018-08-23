#include "matrixmul.h"

int add(Matrix *A, Matrix *B, Matrix *C) {

    if ((A->rows != B->rows) || (A->columns != B->columns)) {
        return -1;
    }

    C->rows = A->rows;
    C->columns = A->columns;

    for (int i = 0; i < (A->rows * B->columns); i++) {
        C->elements[i] = A->elements[i] + B->elements[i];
    }

    return 0;
}

int subtract(Matrix *A, Matrix *B, Matrix *C) {

    if ((A->rows != B->rows) || (A->columns != B->columns)) {
        return -1;
    }

    C->rows = A->rows;
    C->columns = A->columns;

    for (int i = 0; i < (A->rows * B->columns); i++) {
        C->elements[i] = A->elements[i] - B->elements[i];
    }

    return 0;
}

void setRowsColumns(int rows, int columns, Matrix *matrix) {

    matrix->rows = rows;
    matrix->columns = columns;

    return;
}