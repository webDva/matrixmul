#include "matrixmul.h"

/*
*   ad-hoc memory allocation. uses the sbrk() function to allocate data segment space
*/
void *initializeMemory(int size) {
    
    void *pointer; // will contain the starting location of the newly allocated memory
    pointer = sbrk(0);

    if (sbrk(size) == (void *) - 1) {
        return 0; // on error, return 0
    }

    return pointer;
}

Matrix add(Matrix A, Matrix B) {

    Matrix C;

    C.rows = A.rows;
    C.columns = A.columns;

    C.elements = initializeMemory(sizeof(double) * (C.rows * C.columns));

    for (int i = 0; i < (A.rows * B.columns); i++) {
        C.elements[i] = A.elements[i] + B.elements[i];
    }

    return C;
}