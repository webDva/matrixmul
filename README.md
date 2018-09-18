# What is *matrixmul*?

I'm creating a portable C matrix multiplication library as a precursor for a portable neural network library that can fit on microcontrollers for embedded devices, hence portable. That means that this library will adhere to standard C as much as possible, neglecting to use system calls that wouldn't facilitate portability across the myriad of microcontrollers, being careful with its underlying assumptions.

As this software is being made for microcontrollers, with matrices so small and possibly few, performance speed-wise is inconsequential. This library instead focuses on being simple to use and integrate into a project that involves microcontrollers.

# Documentation

## Definitions

### `typedef struct MatrixStruct Matrix`

A struct or type for implementing matrices. Matrices are in row-major order and the elements are in a one-dimensional array. These `Matrix` structs are meant to be statically memory allocated as they are meant to live on embedded systems.

#### Struct members

* `unsigned char rows` - The number of rows the matrix has.
* `unsigned char columns` - The number of columns the matrix has.
* `float elements[MAX_ELEMENTS]` - An array of floating point numbers that are the matrix's elements. The array is bounded by the maximum number of elements a matrix can have, `MAX_ELEMENTS`.

### `MAX_ELEMENTS`

As matrices have to be statically declared, `MAX_ELEMENTS` defines the total number of elements a matrix can have. The default value is `100`.

## Library functions

### `int multiply(Matrix *matrixA, Matrix *matrixB, Matrix *matrixC)`

Multiplies two `Matrix`s and stores the result in another `Matrix`. Internally uses `clearMatrix`.

Returns `-1` if the number of columns of the first matrix is not equal to the number of rows of the second matrix. Returns `0` otherwise.

#### Parameters

* `Matrix *matrixA` - A pointer to one of the two matrices to multiply.
* `Matrix *matrixB` - A pointer to one of the two matrices to multiply.
* `Matrix *matrixC` - The result matrix.

### `void clearMatrix(Matrix *)`

Sets all the elements of a given matrix to be zero. Useful for reusing matrices.

#### Parameters

* `Matrix *` - A pointer to the matrix to clear.

### `void setRowsColumns(unsigned char rows, unsigned char columns, Matrix *)`

Sets a `Matrix`'s `rows` and `columns` fields.

#### Parameters

* `unsigned char rows` - The number of rows to set the matrix to.
* `unsigned char columns` - The number of columns to set the matrix to.
* `Matrix *` - A pointer to the matrix to modify.

### `void setElement(unsigned char row, unsigned char column, float element, Matrix *)`

Used for setting a `Matrix`'s elements.

#### Parameters

* `unsigned char row` - The row of where to set the new element.
* `unsigned char column` - The column of where to set the new element.
* `float element` - The element to place.
* `Matrix *` - A pointer to the matrix to modify.

### `float getElement(unsigned char row, unsigned char column, Matrix *)`

Retrieves a matrix's element given a row and column.

#### Parameters

* `unsigned char row` - The row to retrieve the element from.
* `unsigned char column` - The column to retrieve the element from.
* `Matrix *` - A pointer to the matrix whose element is to be retrieved.

# Setup and installation

For adhering to this project's goal of being easy to use, the entire library is located in a single header file, `matrixmul.h`. To use this library for some task, include the header file with the directive `#include "matrixmul.h"`.

# Testing

`test.c` is used to facilitate testing of the library. This will help with evaluating the performance of the mechanisms of the library. An example for operating `test.c`, using the `gcc` (GNU Compiler Collection) program:

```
gcc -g test.c matrixmul.h -o test.exe
```

The following is a list of conditions that `test.c` should create.

### Creating `Matrix` constructs using static memory allocation

The statement `static Matrix A, B, C;` should create three `Matrix` structures in the program's data segment prior to program initialization.

### Setting a matrix's number of rows and columns

``` C
setRowsColumns(2, 2, &A);
setRowsColumns(2, 2, &B);
```

The above statements should set the `A` and `B` matrices' numbers of rows and columns to both be two, thereby creating two two-by-two matrix constructs.

### Setting a matrix's elements

``` C
setElement(1, 1, 2, &A);
setElement(1, 2, 1, &A);
setElement(2, 1, 0, &A);
setElement(2, 2, 3, &A);

setElement(1, 1, 1, &B);
setElement(1, 2, 0, &B);
setElement(2, 1, 1, &B);
setElement(2, 2, 2, &B);
```

The above statements should set the elements in `A` to be [2 1 / 0 3] and the elements in `B` to be [1 0 / 1 2].

### Multiplying matrices

The statement `multiply(&A, &B, &C);` should multiply the aforementioned `A` and `B` matrices and store the result in the `C` matrix. `C` should now be a two-by-two matrix with the elements [3 2 / 3 6].