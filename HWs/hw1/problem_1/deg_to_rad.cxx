# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

const double pi = 3.14159265359;

int main(){
	double deg;
	double rad;
	
	
	cout << "Please give an angle in Degree: ";
	cin >> deg;
	
	rad = deg * pi / 180; 
	cout << "The angle in Radian is: " << fixed << setprecision(2) << rad << endl;
	
	return 0;
};
