```console
(base) ubuntu@ubuntu2204:project2$ g++ -o linAlTest vecNd.cxx matrixNN.cxx linAlTest.cxx 
(base) ubuntu@ubuntu2204:project2$ ./linAlTest 
 vecNd: user defined 3d constructor called
 vecNd: user defined 3d constructor called
 vecNd: user defined 3d constructor called

Vector v1:
VecNd Clas:
 Dimension = 3
 x[0] = 1
 x[1] = 2
 x[2] = 7


Vector v2:
VecNd Clas:
 Dimension = 3
 x[0] = 4
 x[1] = 6
 x[2] = 8


Dot Product v1 x v2: 72


 vecNd: user defined constructor with dimension
 vecNd: user defined copy constructor called!
Cross Product v1 x v2:
VecNd Clas:
 Dimension = 3
 x[0] = -26
 x[1] = 20
 x[2] = -2


Test Matrix M1:
matrixNN Clas:
 dimension = 3
 1 2 7
 4 6 8
 5 6 1
Matrix element M1(1,2): 8

Determinant of M1: -12

Multiplication Done
Matrix Multiplication: M1 * M1
matrixNN Clas:
 dimension = 3
 44 56 30
 68 92 84
 34 52 84

 vecNd: user defined constructor with dimension
Multiplication Done
 vecNd: user defined copy constructor called!
Multiplication: v1 * M1
VecNd Clas:
 Dimension = 3
 x[0] = 44
 x[1] = 56
 x[2] = 30

Removing Row=1, Col=1 from M1
matrixNN Clas:
 dimension = 2
 1 7
 5 1

Cofactor (1,1): -34


Inverse of Matrix 1:
matrixNN Clas:
 dimension = 3
 3.5 -3.33333 2.16667
 -3 2.83333 -1.66667
 0.5 -0.333333 0.166667

 Program end!
 matrixNN: default destructor called
 matrixNN: default destructor called
 vecNd: default destructor called
 matrixNN: default destructor called
 matrixNN: default destructor called
 vecNd: default destructor called
 vecNd: default destructor called
 vecNd: default destructor called
 vecNd: default destructor called
```
