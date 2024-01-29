// include necessary libraries for basic functions.
# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

// declare global constants
const double pi = 3.14159265359;

int main(){
	// declare variables
	double farenhite;
	double celcius;
	
	// taking inputs from user
	cout << "Please give the temperature in Farenhite: ";
	cin >> farenhite;
	
	if (farenhite < -460){
		cout << "Sorry, the temperature range is invalid." << endl;
		return 0;
	}
	// calculate the angle in radians using the appropriate formula
	celcius = (farenhite - 32) * 5 / 9; 
	
	// show output with 2 digits after decimal
	cout << "The angle in Radian is: " << fixed << setprecision(2) << celcius << endl;
	
	return 0;
};
