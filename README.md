# matrixmul

🚧 under construction (in early development) 🚧

## What is matrixmul?

I'm creating a portable C matrix multiplication library as a precursor for a portable neural network library that can fit on microcontrollers for embedded devices, hence portable. That means that I will adhere to standard C as much as possible, neglecting to use system calls that wouldn't facilitate portability across the myriad of microcontrollers. I'll also endeavor to be careful about my underlying assumptions.

# Documentation

## Definitions

### `typedef struct MatrixStruct Matrix`

A struct or type for implementing matrices.

#### Struct members

* `int rows` - The number of rows the matrix has.
* `int columns` - The number of columns the matrix has.
* `float elements[MAX_ELEMENTS]` - An array of floating point numbers that are the matrix's elements.

### `MAX_ELEMENTS`

As matrices have to be statically declared, `MAX_ELEMENTS` defines the total number of elements a matrix can have. The default value is `1000`.

## Functions

### `int multiply(Matrix *matrixA, Matrix *matrixB, Matrix *matrixC)`

Multiplies a `Matrix` *matrixA* by a `Matrix` *matrixB* and stores the result in the `Matrix` *matrixC*. Internally uses `clearMatrix`.

Returns `-1` if the number of columns of *matrixA* is not equal to the number of rows of *MatrixB* and returns `0` otherwise.

### `void clearMatrix(Matrix *)`

Sets all the elements of the given matrix to zero. Useful for reusing matrices.