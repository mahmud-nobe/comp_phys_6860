// Implementation of our matrixNN class

#include "matrixNN.h"
#include "vecNd.h"

#include <iostream>  
#include <cmath>

using namespace std;

// Member Functions //
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

// Constructors // 

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

// 3x3 matrix constructor using row vector
matrixNN::matrixNN(vecNd &r1, vecNd &r2, vecNd &r3)
{
	// allocate memory for the matrix
	ndim = 3;
	matrix = new double *[ndim];
	for (int i=0; i<ndim; i++){
		matrix[i] = new double[ndim];
	}
	
	for (int i=0; i<ndim; i++){
		matrix[0][i] = r1.GetComponent(i);
		matrix[1][i] = r2.GetComponent(i);
		matrix[2][i] = r3.GetComponent(i);
	} 
	
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

// Operators //

// Matrix addition
matrixNN matrixNN::operator + (matrixNN &m)
{
	matrixNN m_new();
	ndim = m.GetDimension();	
	m_new.SetDimension(ndim);
	
	for (int i=0; i<ndim; i++){
		for (int j=0; j<ndim; j++){
				m_new.SetElement(i, j, matrix[i][j] + m.GetElement(i,j))
			}
	}
	return m_new;
}

// Matrix addition in place 
matrixNN matrixNN::operator += (matrixNN &m)
{
	for (int i=0; i<ndim; i++){
		for (int j=0; j<ndim; j++){
				matrix[i][j] += m.GetElement(i,j)
			}
	}
	return *this;
}

// Matrix subtraction
matrixNN matrixNN::operator - (matrixNN &m)
{
	matrixNN m_new();
	ndim = m.GetDimension();	
	m_new.SetDimension(ndim);
	
	for (int i=0; i<ndim; i++){
		for (int j=0; j<ndim; j++){
				m_new.SetElement(i, j, matrix[i][j] - m.GetElement(i,j))
			}
	}
	return m_new;
}

// Matrix subtraction in place 
matrixNN matrixNN::operator -= (matrixNN &m)
{
	for (int i=0; i<ndim; i++){
		for (int j=0; j<ndim; j++){
				matrix[i][j] -= m.GetElement(i,j)
			}
	}
	return *this;
}


