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
  // declare dynamically and 
  //set a new variable of type vec2d
  vecNd *myFirstVecNd=new vecNd(2.0,1.0,3.0);

  cout<<endl;
  cout<<"First Vector:"<<endl;
  myFirstVecNd->Print();
  cout<<endl;
 
  matrixNN *myFirstMatrix = new matrixNN(1,2,3,4,5,6,7,8,9);
  matrixNN mySecondMatrix = *myFirstMatrix;
  cout<<"Matrix via default constructor"<<endl;
  mySecondMatrix.Print();

	vecNd v1(1,3,5);
	matrixNN mat1(v1,v1,v1);
	mat1.Print();
	cout << "elem 2,2: " << mat1.GetElement(2,2) <<endl;
	
	matrixNN mat3 = mySecondMatrix * mySecondMatrix;
	cout << "after Multiplication" << endl;
	mat3.Print();
	
	vecNd vec3 = v1 * mySecondMatrix;
	cout << "after Multiplication" << endl;
	vec3.Print();
	
   
  delete myFirstVecNd;				
  delete myFirstMatrix;

  cout<<" Program end!"<<endl;
}
