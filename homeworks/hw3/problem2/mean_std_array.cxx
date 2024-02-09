// include necessary libraries for basic functions.
# include <iostream>
# include <iomanip>
# include <cmath>
# include <ctime>

using namespace std;

// finding mean of an array
double mean_arr(int arr[], int arr_len){
	double sum = 0;
	for (int i = 0; i<arr_len; i++){
		sum += arr[i];
	};
	return sum/(double) arr_len;
};

// finding standard deviation of an array
double std_arr(int arr[], int arr_len){
	double mean = mean_arr(arr, arr_len);
	double sum_sq_err = 0;
	for (int i = 0; i<arr_len; i++){
		sum_sq_err += (arr[i] - mean)*(arr[i] - mean);
	};
	return pow(sum_sq_err/(double) arr_len, 0.5);
};

// save the value of mean and standar deviation using call by reference
void get_mean_std_arr(int arr[], int arr_len, double &mean, double &std){
	mean = mean_arr(arr, arr_len);
	std = std_arr(arr, arr_len);
};

int main(){
	// declare variables
	int arr_len;
	double mean, std;
	
	cout << "What is the length of your array: ";
	cin >> arr_len;
	
	int arr[arr_len]; // declare the array
	
	srand(time(NULL)); // first seed value
	
	for (int i = 0; i<arr_len; i++){
		// create random number between 1-50
		arr[i] = 1 + rand()%50; 
	}
	
	// print the array
	cout << "The random unsorted array: " << endl;
	for(int i=0; i<arr_len; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	// print the mean and std of the array
	cout << "Mean: " << mean_arr(arr, arr_len) << endl;
	cout << "Standard Deviation: " << std_arr(arr, arr_len) << endl;
	
	// print the mean and std of the array using call by reference
	get_mean_std_arr(arr, arr_len, mean, std);
	cout << "Mean: " << mean << endl;
	cout << "Standard Deviation: " << std << endl;
	
	return 0;
};
