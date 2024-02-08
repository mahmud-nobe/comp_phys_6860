// include necessary libraries for basic functions.
# include <iostream>
# include <iomanip>
# include <math.h>

using namespace std;

// declare global constants
const double g = 9.81;
const double pi = M_PI;

template <typename func>
double secant_diff(func f_x, double x, double stepsize){
	double derivative = ( f_x(x+stepsize) - f_x(x) ) / stepsize;
	return derivative;
}

double sinx(double x){
	return sin(x);
};

int main(){
	// declare variables
	double x, stepsize;
	double inputs[5] = {0, pi/4, pi/2, 3*pi/4, pi};
	double analytic_soln, numerical_soln;
	
	// taking inputs from user
	cout << "Please provide the stepsize, h: ";
	cin >> stepsize;
	
	for(int i=0; i<5; i++){
		x = inputs[i];
		analytic_soln = cos(x);
		numerical_soln = secant_diff(sinx, x, stepsize);
		cout << endl << "At x = " << x << endl;
		cout << "Analytical soln: " << analytic_soln << endl;
		cout << "Numerical Soln: " << numerical_soln << endl;
		cout << "Relative Error: " << abs(analytic_soln - numerical_soln)/analytic_soln << endl;
	}
	
	return 0;
};
