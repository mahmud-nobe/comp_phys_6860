// include necessary libraries for basic functions.
# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

// declare global constants
const double pi = 3.14159265359;

int main(){
	// declare variables
	double deg;
	double rad;
	
	// taking inputs from user
	cout << "Please give an angle in Degree: ";
	cin >> deg;
	
	// calculate the angle in radians using the appropriate formula
	rad = deg * pi / 180; 
	
	// show output with 2 digits after decimal
	cout << "The angle in Radian is: " << fixed << setprecision(2) << rad << endl;
	
	return 0;
};
