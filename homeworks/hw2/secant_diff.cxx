// include necessary libraries for basic functions.
# include <iostream>
# include <iomanip>
# include <math.h>

using namespace std;

// declare global constants
const double pi = M_PI;

template <typename func> // using a class that can be used for different datatypes

/* function for differentiation using brute force secant methods 
for function f_x at the point x using the given stepsize.
The smaller the stepsize, the better the estimate.
*/
double secant_diff(func f_x, double x, double stepsize){
	double derivative = ( f_x(x+stepsize) - f_x(x) ) / stepsize;
	return derivative;
}

// function for sin(x)
double sinx(double x){
	return sin(x);
};

int main(){
	// declare variables
	double x, stepsize;
	double analytic_soln, numerical_soln;
	// our point of interests
	double inputs[5] = {0, pi/4, pi/2, 3*pi/4, pi};
	
	// taking inputs from user
	cout << "Please provide the stepsize, h: ";
	cin >> stepsize;
	
	// loop through all our point of interest
	for(int i=0; i<5; i++){
		x = inputs[i];
		
		// analytically diff of sin(x) = cos(x)
		analytic_soln = cos(x);
		
		// numerical soln using the secant_diff function
		numerical_soln = secant_diff(sinx, x, stepsize);
		
		// Print the both answers and their relative error
		cout << endl << "At x = " << x << endl;
		cout << "Analytical soln: " << analytic_soln << endl;
		cout << "Numerical Soln: " << numerical_soln << endl;
		cout << "Relative Error: " << abs(analytic_soln - numerical_soln)/analytic_soln << endl;
	}
	
	return 0;
};
