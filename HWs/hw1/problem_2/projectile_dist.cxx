// include necessary libraries for basic functions.
# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

// declare global constants
const double g = 9.81;
const double pi = 3.14159265359;

int main(){
	// declare variables
	double v_0;
	double angle_deg, angle_rad;
	double dist;
	
	// taking inputs from user
	cout << "Please provide the following information about the projectile:" << endl;
	cout << "Initial Velocity (in meter/second): "; 
	cin >> v_0;
	
	cout << "Angle with the ground (in degree, between 0 to 180): "; 
	cin >> angle_deg;

	// calculate the angle in radians to use in sine function
	angle_rad = angle_deg * pi / 180;
	
	// calculate the distance in radians using the appropriate formula
	dist = v_0*v_0 * sin(2*angle_rad) / g; 
	
	// show output with 2 digits after decimal
	cout << "The horizontal distance in meter is: " << fixed << setprecision(2) << dist << endl;
	
	return 0;
};
