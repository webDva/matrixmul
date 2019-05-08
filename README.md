# NOTICE

This project has been canceled and the project has been superseded by other efforts that more align with the project's goals.

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

* [Functional/specification testing](/testing.md)

# Contributors

* [A list of contributors](/contributors.md)
