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

// default constructor
complex::complex(){
	cout << "Default Constructor Called!" << endl;
	// set default value
	real = 0;
	imaginary = 0;
};

// constructor with given value
complex::complex(double real_n, double imag_n){
	real = real_n; 
	imaginary = imag_n;
};

// destructor
complex::~complex(){
	cout << "Destructor is Called!" << endl;
}
