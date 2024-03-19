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
  // initialize new vector using 3d
  vecNd vec1(1,2,3);
  cout << "Example 3D vector 1:" << endl;
  vec1.Print();
  cout << "Magnitude: " << vec1.Length() << endl; 
  
  vecNd vec2(4,5,6);
  cout << "Example 3D vector 2:" << endl;
  vec2.Print();
  cout << "Magnitude: " << vec2.Length() << endl;
  
  cout << "Addition in Place: v1 += v2" << endl;
  vec1 += vec2;
  cout << "Vector 1:" << endl;
  vec1.Print();
  
  cout << "Scaler Product: v1 * v2" << endl;
  cout << vec1.scaler_prod(vec2) << endl;
  
}
