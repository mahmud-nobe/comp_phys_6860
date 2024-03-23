## Project 2: Linear Algebra Classes

### 1. N-d Vector Class: vecNd

Class implementation of n-dimensional vector using cpp pointer array.

#### Members:
- ndim: number of dimension
- *x: pointer array to store each components

#### Member Functions:
- Print: show the dimension and vector components
- Length: return the magnitude of the vector
- scaler_prod: return the result of a scaler product with another vector

#### Operators:
- **+** scaler addition of two vectors
- **+=** scaler addition of two vectors(in place)
- **-** scaler subtraction of two vectors
- **-=** scaler subtraction of two vectors (in place)
- **/** division by a scaler number
- **/=** division by a scaler number (in place)

- \text{*} (vecNd &v) vector-vector cross product
- \text{*} (matrixNN &m) vector-matrix multiplication

### 2. NxN Matrix Class: matrixNN

Class implementation of n-dimensional square matrix using cpp double pointer array.

#### Members:
- ndim: number of dimension
- **matrix: pointer double array: first pointer array stores the row and each row is a pointer array for all its element

#### Member Functions:
- Print: show the dimension and matrix elements
- Determinant: return the determinant of the matrix
- transpose: return the transpose of the matrix, $A^T_{ij} = A_{ji}$
- removeRowCol(r, c): return a (n-1)-dimensional matrix $A(r|c)$ by removing row r and column c.
- getCofactor(r, c): return the cofactor of element (r,c), $C_{r,c} = (-1)^{r+c} det(A(r|c))$
- inverse: return the inverse matrix, $M^{-1} = \frac{1}{det(M)}\,Adj(M)$

#### Operators:
- **+** scaler addition of two vectors
- **+=** scaler addition of two vectors(in place)
- **-** scaler subtraction of two vectors
- **-=** scaler subtraction of two vectors (in place)
- **/** division by a scaler number
- **/=** division by a scaler number (in place)

- \text{*} (vecNd &v) vector-vector cross product
- \text{*} (matrixNN &m) vector-matrix multiplication

Prepare a Linear Algebra Classes, n-dim vector vecNd and a nxn matrix matrixNN classes. The vecNd class can either use a c++ array or (you can rewrite the in class exercise) the STL vector. The matrix class should use the STL vector. Provide standard functions like Print() and the appropriate setters and getters, as well as special constructors for the 2d and 3d cases. Define all the proper operators and also allow vector with matrix multiplication (of course you should check if dimension if that operation is allowed, same for the vector-vector and matrix-matrix cases). Define the scalar and vector product for vecNd (restrict the vector product for simplicity to 2 and 3 dimension). For the matrix class, include the calculation of the determinant and if you feel adventures try to implement the inverse for a 3x3 matrix (for simplicity, you can restrict your matrix class to integers only).  Use the test matrix:

1 2 7
4 6 8
5 6 1

with a determinant of -12 and the inverse of

7/2  -10/3 13/6
-3 17/6 -5/3
1/2 -1/3 1/6
