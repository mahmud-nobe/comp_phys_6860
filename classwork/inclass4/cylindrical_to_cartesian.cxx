#include <iostream>  
#include <cmath>

using namespace std;
const double PI = 3.1419;

int main(){
	double x, y, z;
	double rho, theta;
	double theta_rad;
	
	cout << "Give the cylindrical coordinate:" << endl;
	cout << "rho: ";
	cin >> rho;
	cout << "theta (deg): ";
	cin >> theta;
	cout << "z: ";
	cin >> z;

	
	theta_rad = theta * PI / 180;
	x = rho * cos(theta_rad) ;
	y = rho * sin(theta_rad) ;
	
	cout << "Cartesian Coordinate (x,y,z):" << endl;
	cout << "x: " << x << ", y: " << y << ", z: " << z << endl;

	return 0;
};

