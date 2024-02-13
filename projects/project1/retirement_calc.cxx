// include necessary libraries for basic functions.
# include <iostream>
# include <iomanip>
# include <cmath>
# include <ctime>
# include <bits/stdc++.h>

using namespace std;

int main(){
	// declare variables
	int current_age, retirement_age;
	double starting_money, current_salary;
	double annual_saving, annual_roi;
	
	// get the user inputs
	cout << "What is your current age (round to a number): ";
	cin >> current_age;
	cout << "What is age you want to retire (round to a number): ";
	cin >> retirement_age;
	cout << "What is your starting money (in thousand USD): ";
	cin >> starting_money;
	cout << "What is your current salary (in thousand USD): ";
	cin >> current_salary;
	cout << "How much percentage of current annual income you will save (1-100): ";
	cin >> annual_saving;
	annual_saving /= 100;
	
	annual_roi = 0.05;
	
	// saved the terminal outputs to a text file
	// freopen("output.txt", "w", stdout);
	
	// Print the user inputs
	cout << endl << "Retirement Calculator" << endl;
	cout << "----------------------------------" << endl;
	cout << "Current Age: " << current_age << endl;
	cout << "Retirement Age: " << retirement_age << endl;
	cout << "Starting Money: US$ " << starting_money << "k" << endl;
	cout << "Retirement Age: US$ " << retirement_age << "k" << endl;
	cout << "Annual Saving Percentage: " << annual_saving*100 << "%" << endl;
	cout << "Annual Return on Investment: " << annual_roi*100 << "%" << endl;
	cout << "----------------------------------" << endl;
	
	
	// declare variables for the table columns
	int arr_len = retirement_age - current_age + 1;
	vector<int> ages(arr_len);
	vector<double> contributions(arr_len);
	vector<double> prev_savings(arr_len);
	vector<double> interests(arr_len);
	vector<double> total(arr_len);
	
	// initially the contibution is the starting money 
	// and previous saving is 0
	ages[0] = current_age;
	contributions[0] = starting_money;
	prev_savings[0] = 0;
	interests[0] = 0;
	total[0] = starting_money;
	
	// iterate through the rest of the year
	for (int i=1; i < arr_len; i++){
		ages[i] = current_age + i;
		contributions[i] = current_salary * annual_saving;
		prev_savings[i] = total[i-1];
		interests[i] = prev_savings[i] * annual_roi;
		total[i] = contributions[i] + prev_savings[i] + interests[i];
	};
	
	// print the annual savings table
	cout << "Age \t Contribution \t Prev_Saving \t Interest \t Total" << endl;
	cout << "   \t (1000 US$) \t (1000 US$) \t (1000 US$) \t (1000 US$)" << endl;
	for (int i=0; i < arr_len; i++){
		cout << fixed << setprecision(2) << ages[i] << " \t " << contributions[i] << " \t \t " << prev_savings[i] << "\t\t" << interests[i] << " \t \t" << total[i] << endl;
	};
	cout << endl;
	
	
	return 0;
};
