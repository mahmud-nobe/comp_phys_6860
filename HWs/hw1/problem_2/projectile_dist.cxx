# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

const double g = 9.81;
const double pi = 3.14159265359;

int main(){
	double v_0;
	double angle_deg, angle_rad;
	double dist;
	
	
	cout << "Please provide the following information about the projectile:" << endl;
	cout << "Initial Velocity (in meter/second): "; 
	cin >> v_0;
	
	cout << "Angle with the ground (in degree, between 0 to 180): "; 
	cin >> angle_deg;

	
	angle_rad = angle_deg * pi / 180;
	dist = v_0*v_0 * sin(2*angle_rad) / g; 
	cout << "The horizontal distance in meter is: " << fixed << setprecision(2) << dist << endl;
	
	return 0;
};
