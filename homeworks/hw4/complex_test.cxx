// Demonstration of complex class

#include "complex.h"

#include <iostream>  
#include <cmath>

using namespace std;

int main(){
	// declare variables
	double a, b, c, d;
	
	// ask users for two complex numbers
	cout << "Provide the 1st complex number, c1: " << endl;
	cout << "Real Part: ";
	cin >> a;
	cout << "Imaginary Part: ";
	cin >> b;
	
	cout << "Provide the 2nd complex number, c2: " << endl;
	cout << "Real Part: ";
	cin >> c;
	cout << "Imaginary Part: ";
	cin >> d;
	
	// declare two complex numbers
	complex c1(a, b);
	complex c2(c, d);
	
	cout << endl << "1st Complex Number: " << endl;
	c1.Print();
	cout << "Absolute Value: " << c1.abs_value() << endl;
	
	cout << endl << "2nd Complex Number: " << endl;
	c2.Print();
	cout << "Absolute Value: " << c2.abs_value() << endl;
	
	cout << endl << "Addition, c1+c2:" << endl;
	(c1+c2).Print();
	
	cout << endl << "Subtraction, c1-c2:" << endl;
	(c1-c2).Print();
	
	cout << endl << "Multiplication, c1*c2:" << endl;
	(c1*c2).Print();
	
	cout << endl << "Division, c1/c2:" << endl;
	(c1/c2).Print();
};
