#ifndef MATRIX_MUL
#define MATRIX_MUL

// Constant(s)

#define MAX_ELEMENTS 100

// Type(s)

typedef struct MatrixStruct {
    int rows;
    int columns;
    float elements[MAX_ELEMENTS];
} Matrix;

// Function declarations

int add(Matrix *, Matrix *, Matrix *);
int subtract(Matrix *, Matrix *, Matrix *);
void setRowsColumns(int rows, int columns, Matrix *);
void setElement(int row, int column, float element, Matrix *);
float getElement(int row, int column, Matrix *);
void clearMatrix(Matrix *);
int multiply(Matrix *matrixA, Matrix *matrixB, Matrix *matrixC);

// Function implementations

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

    matrix->elements[(row - 1) * matrix->columns + (column - 1)] = element;

    return;
}

float getElement(int row, int column, Matrix *matrix) {
    return matrix->elements[(row - 1) * matrix->columns + (column - 1)];
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

    for (int i = 1; i <= matrixC->rows; i++) {
        for (int j = 1; j <= matrixC->columns; j++) {
            for (int k = 1; k <= matrixA->columns; k++) {
                setElement(i, j, getElement(i, j, matrixC) + getElement(i, k, matrixA) * getElement(k, j, matrixB), matrixC);
            }
        }
    }

    return 0;
}

#endif