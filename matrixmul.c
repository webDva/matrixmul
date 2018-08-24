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
    clearMatrix(C);

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

void setElement(int row, int column, float element, Matrix *matrix) {

    matrix->elements[row * matrix->columns + column] = element;

    return;
}

float getElement(int row, int column, Matrix *matrix) {
    return matrix->elements[row * matrix->columns + column];
}

void clearMatrix(Matrix *matrix) {

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        matrix->elements[i] = 0;
    }

    return;
}

int multiply(Matrix *matrixA, Matrix *matrixB, Matrix *matrixC) {

    // un-equal number of columns and rows yield an error value
    if (matrixA->columns != matrixB->rows) {
        return -1;
    }

    // set the result matrix's rows and columns numbers and initialize its elements to zero
    setRowsColumns(matrixA->rows, matrixB->columns, matrixC);
    clearMatrix(matrixC);

    for (int i = 0; i < matrixC->rows * matrixC->columns; i++) {
        for (int j = 0, k = 0, m = 0; j < matrixA->columns; j++) {
            matrixC->elements[i] += getElement(k, j, matrixA) * getElement(j, m, matrixB);
            k++;
            m++;
        }
    }

    return 0;
}