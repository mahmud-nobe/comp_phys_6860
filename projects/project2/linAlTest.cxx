// demonstrating our two classes 

#include "matrixNN.h"
// since vecNd.h is already
// include in matrixNN.h
// but one can still include it
//#include "vecNd.h"
#include <iostream>  
#include <cmath>

using namespace std;

int main( )
{ 
  // declare vectors
	vecNd v1(1,2,7);
	vecNd v2(4,6,8);
	vecNd v3(5,6,1);
	
	cout<<endl;
  cout<<"Vector 1:"<<endl;
  v1.Print();
  cout<<endl;
  
	matrixNN mat1(v1,v2,v3);
	
	cout<<endl;
  cout<<"Test Matrix:"<<endl;
	mat1.Print();
	cout << "Matrix element (2,2): " << mat1.GetElement(2,2) << endl;
	cout<<endl;
	
	matrixNN mat2 = mat1 * mat1;
	cout << "after Matrix Multiplication: M1 * M1:" << endl;
	mat2.Print();
	cout<<endl;
	
	vecNd vec3 = v1 * mat1;
	cout << "after Multiplication: v1 * M1" << endl;
	vec3.Print();
	cout<<endl;
	
	mat1.Print();
	cout << "Determinant of Matrix 1: " << mat1.Determinant() <<endl;
	cout<<endl;
	
	matrixNN mat3 = mat1.removeRowCol(1,1);
	mat3.Print();
	cout<<endl;
	
	cout << "Cofactor (1,1): " << mat1.getCofactor(1,1) <<endl;
	cout<<endl;

	matrixNN mat1_inv = mat1.inverse();
	mat1_inv.Print();
	cout<<endl;
	
  cout<<" Program end!"<<endl;
}
