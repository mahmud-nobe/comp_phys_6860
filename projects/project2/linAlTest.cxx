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
  vecNd *myFirstVecNd=new vecNd(2.0,1.0);

  cout<<endl;
  cout<<"First Vector:"<<endl;
  myFirstVecNd->Print();
  cout<<endl;
 
  matrixNN *myFirstMatrix=new matrixNN(1,2,3,4);
  cout<<"Matrix via default constructor"<<endl;
  myFirstMatrix->Print();

   
  delete myFirstVecNd;				
  delete myFirstMatrix;

  cout<<" Program end!"<<endl;
}
