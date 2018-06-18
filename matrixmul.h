#ifndef MATRIX_MUL
#define MATRIX_MUL

#define MAX_ELEMENTS 1000

typedef struct MatrixStruct {
    int rows;
    int columns;
    float elements[MAX_ELEMENTS];
} Matrix;

int add(Matrix *, Matrix *, Matrix *);

#endif