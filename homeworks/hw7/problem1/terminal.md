```console
(root_env) ubuntu@ubuntu2204:problem1$ g++ -o matrix matrix.cxx -lgsl -lgslcblas `root-config --cflags --libs`
(root_env) ubuntu@ubuntu2204:problem1$ ./matrix 
Program Start
Matrix 1:
nrow: 3, ncol: 3
 1 3 3
 1 4 3
 1 3 4

Matrix 2:
nrow: 3, ncol: 3
 1 2 7
 4 6 8
 5 6 1

Inverse of Matrix 2:
nrow: 3, ncol: 3
 3.5 -3.33333 2.16667
 -3 2.83333 -1.66667
 0.5 -0.333333 0.166667

Program End
```
