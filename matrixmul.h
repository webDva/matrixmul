#ifndef MATRIX_MUL
#define MATRIX_MUL

#define MAX_ELEMENTS 1000

typedef struct MatrixStruct {
    int rows;
    int columns;
    float elements[MAX_ELEMENTS];
} Matrix;

int add(Matrix *, Matrix *, Matrix *);
int subtract(Matrix *, Matrix *, Matrix *);
void setRowsColumns(int rows, int columns, Matrix *);
void setElement(int row, int column, float element, Matrix *);

#endif