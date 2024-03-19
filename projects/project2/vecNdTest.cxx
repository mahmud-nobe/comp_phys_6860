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
  vecNd vec3d_1(1,2,3);
  cout << "Example 3D vector:" << endl;
  vec3d_1.Print();
  cout << "Magnitude: " << vec3d_1.Length() << endl; 
  
}
