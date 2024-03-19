// Demonstrating vec2dclass5.cxx
// implemention via our vec2d class
// implemenntation using a modular
// approach, via header and source
// file of the class

#include "vecNd.h"
#include <iostream>  
#include <cmath>

using namespace std;

int main( )
{ 
  // declare dynamically and 
  //set a new variable of type vec2d
  vecNd myFirstVecNd(2.0,1.0);

  cout<<endl;
  cout<<"First Vector:"<<endl;
  myFirstVecNd.Print();
  cout<<endl;
  
  // (i) vecNd *mySecondVecNd=(vecNd*) myFirstVecNd;
  // (ii) the same but with a new ...
  ////vecNd *mySecondVecNd=new vecNd();
  // (ii) *mySecondVecNd=*myFirstVecNd; or mySecondVecNd=myFirstVecNd;
  ////*mySecondVecNd=*myFirstVecNd;
  vecNd mySecondVecNd= myFirstVecNd;
  mySecondVecNd.Print();
  
  //delete myFirstVecNd;				
  // (i) delete mySecondVecNd; // not working since no "new" is used
  //delete mySecondVecNd; 
  // (ii)( does not work why?
  // vecNdTest(1487) malloc: *** error for object 0x7f8f48c03ab0: pointer being freed was not allocated
  // *** set a breakpoint in malloc_error_break to debug
  // Abort
  // Solution: Copy constructor and = assignment operator have to be user defined
  // since we have a pointer in our class !!!
  cout<<endl;
  cout<<" Program end!"<<endl;
}
