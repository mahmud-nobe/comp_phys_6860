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
  cout<<"Vector v1:"<<endl;
  v1.Print();
  cout<<endl;
  
  cout<<endl;
  cout<<"Vector v2:"<<endl;
  v2.Print();
  cout<<endl;
  
  cout<<endl;
  cout<<"Dot Product v1 x v2: "<< v1.scaler_prod(v2) << endl;
  cout<<endl;
  
  cout<<endl;
  vecNd v1_v2 = v1 * v2;
  cout<<"Cross Product v1 x v2:"<<endl;
  v1_v2.Print();
  cout<<endl;
  
	matrixNN mat1(v1,v2,v3);
	
	cout<<endl;
  cout<<"Test Matrix M1:"<<endl;
	mat1.Print();
	cout << "Matrix element M1(1,2): " << mat1.GetElement(1,2) << endl;
	cout<<endl;
	
	cout << "Determinant of M1: " << mat1.Determinant() <<endl;
	cout<<endl;
	
	matrixNN mat2 = mat1 * mat1;
	cout << "Matrix Multiplication: M1 * M1" << endl;
	mat2.Print();
	cout<<endl;
	
	
	vecNd v1_m1 = v1 * mat1;
	cout << "Multiplication: v1 * M1" << endl;
	v1_m1.Print();
	cout<<endl;

	
	matrixNN mat3 = mat1.removeRowCol(1,1);
	cout << "Removing Row=1, Col=1 from M1" << endl;
	mat3.Print();
	cout<<endl;
	
	cout << "Cofactor (1,1): " << mat1.getCofactor(1,1) <<endl;
	cout<<endl;

	cout << endl << "Inverse of Matrix 1:" << endl;
	matrixNN mat1_inv = mat1.inverse();
	mat1_inv.Print();
	cout<<endl;
	
  cout<<" Program end!"<<endl;
}
