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

matrixNN matrixNN::transpose(){
	matrixNN m_new(ndim);
	for (int i=0; i<ndim; i++){
		for (int j=0; j<ndim; j++){
				m_new.SetElement(i,j, matrix[j][i]);
			}
	}
	return m_new;
}

double matrixNN::Determinant()
{
	if (ndim == 1){return matrix[0][0];}
	else if (ndim == 2){
		return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	}
	else if (ndim == 3){
		double a_0 = (matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]);
		double a_1 = (matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]);
		double a_2 = (matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]);
		return matrix[0][0]*a_0 - matrix[0][1]*a_1 + matrix[0][2]*a_2;
	}
	else{
		cout << "Please Provide a matrix with Dimension 3 or smaller!" << endl;
		return 0;
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

// constructor for nxn matrix allocation 
matrixNN::matrixNN(int n)
{
  cout<<" matrixNN: default constructor called"<<endl;
  ndim=n;
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
  /*for (int i=0; i<ndim; i++){
		delete [] matrix[i];
	}
	delete [] matrix;*/
}; 

// Operators //

// equal operator
matrixNN matrixNN::operator = (matrixNN &m)
{
	ndim = m.GetDimension();
	for (int i=0; i<ndim; i++){
		for (int j=0; j<ndim; j++){
				matrix[i][j] = m.GetElement(i,j);
			}
	}
	return *this;
}

matrixNN matrixNN::operator = (matrixNN *m)
{
	ndim = m->GetDimension();
	for (int i=0; i<ndim; i++){
		for (int j=0; j<ndim; j++){
				matrix[i][j] = m->GetElement(i,j);
			}
	}
	return *this;
}

// Matrix addition
matrixNN matrixNN::operator + (matrixNN &m)
{
	matrixNN m_new(m);
	ndim = m.GetDimension();	
	m_new.SetDimension(ndim);
	
	for (int i=0; i<ndim; i++){
		for (int j=0; j<ndim; j++){
				m_new.SetElement(i, j, matrix[i][j] + m.GetElement(i,j));
			}
	}
	return m_new;
}

// Matrix addition in place 
matrixNN matrixNN::operator += (matrixNN &m)
{
	for (int i=0; i<ndim; i++){
		for (int j=0; j<ndim; j++){
				matrix[i][j] += m.GetElement(i,j);
			}
	}
	return *this;
}

// Matrix subtraction
matrixNN matrixNN::operator - (matrixNN &m)
{
	matrixNN m_new(m);
	ndim = m.GetDimension();	
	m_new.SetDimension(ndim);
	
	for (int i=0; i<ndim; i++){
		for (int j=0; j<ndim; j++){
				m_new.SetElement(i, j, matrix[i][j] - m.GetElement(i,j));
			}
	}
	return m_new;
}

// Matrix subtraction in place 
matrixNN matrixNN::operator -= (matrixNN &m)
{
	for (int i=0; i<ndim; i++){
		for (int j=0; j<ndim; j++){
				matrix[i][j] -= m.GetElement(i,j);
			}
	}
	return *this;
}

// Matrix multiplication 
matrixNN matrixNN::operator * (matrixNN &m)
{
	if (ndim == m.GetDimension()){
			matrixNN m_new(3);
			m_new.SetDimension(ndim);
			
			for (int i=0; i<ndim; i++){
				for (int j=0; j<ndim; j++){
					double elem = 0;
					for (int n=0; n < ndim; n++){
						elem += matrix[i][n] * m.GetElement(n,j);

					};
					m_new.SetElement(i, j, elem);
				};
			};
			cout << "Multiplication Done" << endl;
			return m_new;
	}
	
	else{
		cout << "Dimensions are not equal!" << endl;
		matrixNN m_new; // return empty matrix
		return m_new;
	};
	
}


// Matrix-vector multiplication 
vecNd matrixNN::operator * (vecNd &v)
{
	if (ndim == v.GetDimension()){
			vecNd v_new(v);
			v_new.SetN(ndim);
			
			for (int i=0; i<ndim; i++){
					double elem = 0;
					for (int n=0; n < ndim; n++){
						elem += matrix[i][n] * v.GetComponent(n);
					};
					v_new.SetComponent(i, elem);
			};
			cout << "Multiplication Done" << endl;
			return v_new;
	}
	
	else{
		cout << "Dimensions are not equal!" << endl;
		vecNd v_new; // return empty matrix
		return v_new;
	};
	
}

