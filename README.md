# matrixmul

🚧 under construction (in early development) 🚧

## What is matrixmul?

I'm creating a portable C matrix multiplication library as a precursor for a portable neural network library that can fit on microcontrollers for embedded devices, hence portable. That means that I will adhere to standard C as much as possible, neglecting to use system calls that wouldn't facilitate portability across the myriad of microcontrollers. I'll also endeavor to be careful about my underlying assumptions.

# Documentation

# Functions

### `int multiply(Matrix *matrixA, Matrix *matrixB, Matrix *matrixC)`

Multiplies a `Matrix` *matrixA* by a `Matrix` *matrixB* and stores the result in the `Matrix` *matrixC*.

Returns `-1` if the number of columns of **A** is not equal to the number of rows of **B** and returns `0` otherwise.