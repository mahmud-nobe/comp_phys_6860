// This is the header file
// of our matrixNN class
// if we want to use our vector class
// which we should/need for matrix
// vector operations we have to include
// the header too

#ifndef MATRIX_H
#define MATRIX_H

#include "vecNd.h"

class matrixNN
{
  private:

  int ndim;

  public:

  // constructor
  matrixNN(); //default
 
  // destructor
  ~matrixNN();

  void Print();
};
 
#endif // MATRIX_H
