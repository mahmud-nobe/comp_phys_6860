// Complex Class Implementation
// Implementation of complex class member functions

# include "complex.h"

#include <iostream>  
#include <cmath>

using namespace std;

void complex::Print(){
	cout << "Real Part: " << real << endl;
	cout << "Imaginary Part: " << imaginary << endl;
	cout << "Complex Number: " << real << " + i " << imaginary << endl;
};

double complex::abs_value(){
	return sqrt(real*real + imaginary*imaginary);
};
