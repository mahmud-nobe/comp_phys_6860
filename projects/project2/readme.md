## Project 2: Linear Algebra Classes

### 1. N-d Vector Class: vecNd

Class implementation of n-dimensional vector using cpp pointer array.

#### Members:
- ndim: number of dimension
- *x: pointer array to store each components

#### Constructors:
- vecNd(): default
- vecNd(double mx, double my): 2d constructor
- vecNd(double mx, double my, double mz): 3d constructor

#### Member Functions:
- Print: show the dimension and vector components
- Length: return the magnitude of the vector
- scaler_prod(vecNd &v): return the result of a scaler product with another vector

#### Operators:
- **+** scaler addition of two vectors
- **+=** scaler addition of two vectors(in place)
- **-** scaler subtraction of two vectors
- **-=** scaler subtraction of two vectors (in place)
- **/** division by a scaler number
- **/=** division by a scaler number (in place)

- $\text{*}$ (vecNd &v) vector-vector cross product
- $\text{*}$ (matrixNN &m) vector-matrix multiplication

### 2. NxN Matrix Class: matrixNN

Class implementation of n-dimensional square matrix using cpp double pointer array.

#### Members:
- ndim: number of dimension
- **matrix: pointer double array: first pointer array stores the row and each row is a pointer array for all its element

#### Constructors:
- matrixNN(): default constructor
- matrixNN(int n): nxn empty matrix construction for dimension n
- matrixNN(double a1, double a2, double b1, double b2): 2x2 matrix constructor
- matrixNN(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3): 3x3 matrix constructor
- matrixNN(vecNd &r1, vecNd &r2, vecNd &r3): 3x3 matrix with 3 row vectors

#### Member Functions:
- Print: show the dimension and matrix elements
- Determinant: return the determinant of the matrix
- transpose: return the transpose of the matrix, $A^T_{ij} = A_{ji}$
- removeRowCol(r, c): return a (n-1)-dimensional matrix $A(r|c)$ by removing row r and column c.
- getCofactor(r, c): return the cofactor of element (r,c), $C_{r,c} = (-1)^{r+c} det(A(r|c))$
- inverse: return the inverse matrix, $M^{-1} = \frac{1}{det(M)} Adj(M)$

#### Operators:
- **+** scaler addition of two matrices
- **+=** scaler addition of two matrices (in place)
- **-** scaler subtraction of two matrices
- **-=** scaler subtraction of two matrices (in place)
- **/** division by a scaler number
- **/=** division by a scaler number (in place)

- \text{*} (vecNd &v) matrix-vector multiplication
- \text{*} (matrixNN &m) matrix-matrix multiplication

### Example:
#### Test vector:
- $v_1$ = [1,2,7]
- $v_2$ = [4,6,8]
- $v_3$ = [5,6,1]

- $v_1 \cdot v_2$ = 72

- $v_1 \times v_2$ = [-26, 20, -2]
 
#### Test matrix:

- $M_1$:
```math
$$ \begin{pmatrix}
   1 & 2 & 7\\
   4 & 6 & 8\\
   5 & 6 & 1
   \end{pmatrix} $$
```


- det($M_1$) = -12 

- $v_1$ x $M_1$ = [44, 56, 30]

- $M_1$ x $M_1$:
```math
$$ \begin{pmatrix}
   44 & 56 & 30 \\
   68 & 92 & 84 \\
   34 & 52 & 84
   \end{pmatrix} $$
```

- $M_1^{-1}$:
```math
$$ \begin{pmatrix}
   7/2  & -10/3 & 13/6\\
   -3 & 17/6 & -5/3\\
   1/2 & -1/3 & 1/6
   \end{pmatrix} $$
```
