// Complex Class Implementation
// Implementation of complex class member functions

# include "complex.h"

#include <iostream>  
#include <cmath>

using namespace std;

void complex::Print(){
	cout << "Real Part: " << real << endl;
	cout << "Imaginary Part: " << imaginary << endl;
	cout << "Complex Number: " << real << " + " << imaginary << "i " << endl;
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
	// dummy function
	// cout << "Destructor is Called!" << endl;
}

// operator: addition in place 
complex complex::operator+=(complex &c){
	real += c.real;
	imaginary += c.imaginary;
	
	return *this;
};

// operator: addition
complex complex::operator+(complex &c){
	return complex(real+c.real, imaginary+c.imaginary);
};

// operator: subtruction in place 
complex complex::operator-=(complex &c){
	real -= c.real;
	imaginary -= c.imaginary;
	
	return *this;
};

// operator: subtraction
complex complex::operator-(complex &c){
	return complex(real-c.real, imaginary-c.imaginary);
};

// operator: multiplication in place 
complex complex::operator*=(complex &c){
	double real_part, imag_part; 
	real_part = real*c.real - imaginary*c.imaginary; // ac-bd
	imag_part = real*c.imaginary + imaginary*c.real;  // ad+bc
	
	real = real_part; imaginary = imag_part;
	return *this;
};

// operator: multiplication
complex complex::operator*(complex &c){
	double real_part, imag_part; 
	real_part = real*c.real - imaginary*c.imaginary; // ac-bd
	imag_part = real*c.imaginary + imaginary*c.real; // ad+bc
	return complex(real_part, imag_part);
};


// operator: division in place 
complex complex::operator/=(complex &c){
	double real_part, imag_part; 
	// ac+bd / abs(c+di)^2
	real_part = (real*c.real + imaginary*c.imaginary) / (c.abs_value()*c.abs_value()); 
	// bc-ad / abs(c+di)^2
	imag_part = (imaginary*c.real - real*c.imaginary) / (c.abs_value()*c.abs_value());
	
	real = real_part; imaginary = imag_part;
	return *this;
};

// operator: division
complex complex::operator/(complex &c){
	double real_part, imag_part; 
	// ac+bd / abs(c+di)^2
	real_part = (real*c.real + imaginary*c.imaginary) / (c.abs_value()*c.abs_value()); 
	// bc-ad / abs(c+di)^2
	imag_part = (imaginary*c.real - real*c.imaginary) / (c.abs_value()*c.abs_value());
	return complex(real_part, imag_part);
};

