#ifndef MATRIX_MUL
#define MATRIX_MUL

typedef struct MatrixStruct {
    int rows;
    int columns;
    double *elements;
} Matrix;

void *initializeMemory(int);
Matrix add(Matrix, Matrix);

#endif