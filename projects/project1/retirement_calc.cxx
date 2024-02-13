// include necessary libraries for basic functions.
# include <iostream>
# include <iomanip>
# include <cmath>
# include <ctime>
# include <bits/stdc++.h>

using namespace std;

// finding mean of an array
double mean_arr(int arr[], int arr_len){
	// get the summation of all values
	double sum = 0;
	for (int i = 0; i<arr_len; i++){
		sum += arr[i];
	};
	// divide the sum by the number of values
	return sum/(double) arr_len;
};

// finding standard deviation of an array
double std_arr(int arr[], int arr_len){
	double mean = mean_arr(arr, arr_len);
	// get the sum of squared error
	double sum_sq_err = 0;
	for (int i = 0; i<arr_len; i++){
		// squared difference between mean and the current value
		sum_sq_err += (arr[i] - mean)*(arr[i] - mean);
	};
	// square root of the mean sum of squared error
	return pow(sum_sq_err/(double) arr_len, 0.5);
};

// save the value of mean and standar deviation using call by reference
void get_mean_std_arr(int arr[], int arr_len, double &mean, double &std){
	mean = mean_arr(arr, arr_len);
	std = std_arr(arr, arr_len);
};

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
	
	
	// Print the user inputs
	cout << endl << "Retirement Calculator" << endl;
	cout << "----------------------------------" << endl;
	cout << "Current Age: " << current_age << endl;
	cout << "Retirement Age: " << retirement_age << endl;
	cout << "Starting Money: US$" << starting_money << "k" << endl;
	cout << "Retirement Age: US$" << retirement_age << "k" << endl;
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
	cout << "Ages \t contribution \t prev_saving \t interest \t total" << endl;
	for (int i=0; i < arr_len; i++){
		cout << fixed << setprecision(2) << ages[i] << " \t " << contributions[i] << " \t \t " << prev_savings[i] << "\t\t" << interests[i] << " \t \t" << total[i] << endl;
	};
	cout << endl;
	
	
	return 0;
};
