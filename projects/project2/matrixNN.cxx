// Implementation of our matrixNN class

#include "matrixNN.h"

#include <iostream>  
#include <cmath>

using namespace std;

// default constructor
matrixNN::matrixNN()
{
  cout<<" matrixNN: default constructor called"<<endl;
  ndim=0;
  matrix = new double *[ndim];
	for (int i=0; i<ndim; i++){
		matrix[i] = new double[ndim];
	}
}

// 2x2 matrix constructor
matrixNN::matrixNN(double a1, double a2, double b1, double b2)
{
	// allocate memory for the matrix
	ndim = 2;
	matrix = new double *[ndim];
	for (int i=0; i<ndim; i++){
		matrix[i] = new double[ndim];
	}
	matrix[0][0] = a1, matrix[0][1] = a2;
	matrix[1][0] = b1, matrix[1][1] = b2;
}

// 3x3 matrix constructor
matrixNN::matrixNN(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3)
{
	// allocate memory for the matrix
	ndim = 3;
	matrix = new double *[ndim];
	for (int i=0; i<ndim; i++){
		matrix[i] = new double[ndim];
	}
	matrix[0][0] = a1, matrix[0][1] = a2, matrix[0][2] = a3;
	matrix[1][0] = b1, matrix[1][1] = b2, matrix[1][2] = b3;
	matrix[2][0] = c1, matrix[2][1] = c2, matrix[2][2] = c3;
}

// Destructor
matrixNN::~matrixNN() 
{
  cout<<" matrixNN: default destructor called"<<endl;
  for (int i=0; i<ndim; i++){
		delete [] matrix[i];
	}
	delete [] matrix;
}; 

void matrixNN::Print()
{
  cout<<"matrixNN Clas:"<<endl;
  cout<<" dimension = "<<ndim<<endl;
  for (int i=0; i<ndim; i++){
  	for (int j=0; j<ndim; j++){
  		cout << " " << matrix[i][j];
  	}
  	cout << endl;
	}
}
