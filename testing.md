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