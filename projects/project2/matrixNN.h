// This is the header file
// of our matrixNN class
// if we want to use our vector class
// which we should/need for matrix
// vector operations we have to include
// the header too

#ifndef MATRIX_H
#define MATRIX_H

// forward declaration 
// instead of #include "vecNd.h"
// class vecNd;
#include "vecNd.h"

class matrixNN
{
  private:

  int ndim;
  double **matrix;

  public:

  // constructor
  matrixNN(); //default
  // 2x2 matrix constructor
  matrixNN(double a1, double a2, double b1, double b2); 
  // 3x3 matrix constructor
  matrixNN(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3);
  // 3x3 matrix with 3 row vectors
  matrixNN(vecNd &r1, vecNd &r2, vecNd &r3);
 
  // destructor
  ~matrixNN();
  
  // operators
  matrixNN operator + (matrixNN &m); // matrix addition
  matrixNN operator += (matrixNN &m); // matrix addition in place
  matrixNN operator - (matrixNN &m); // subtraction addition
  matrixNN operator -= (matrixNN &m); // subtraction addition in place
  
  // getter functions
  int GetDimension() {return ndim;}
  double GetElement(int r, int c){return (double) matrix[r][c];}
  
  // setter functions
  void SetDimension(n) {ndim = n;}
  void SetElement(int r, int c, double elem) {matrix[r][c] = elem;}
  
  // member functions
  void Print();
};
 
#endif // MATRIX_H
