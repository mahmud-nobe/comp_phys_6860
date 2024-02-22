// Demonstration of complex class

#include "complex.h"

#include <iostream>  
#include <cmath>

using namespace std;

int main(){
	double a = 1.0;
	double b = 2.0;
	
	complex c1(a, b);
	
	c1.Print();
	 
	cout << "Absolute Value: " << c1.abs_value() << endl;
};
