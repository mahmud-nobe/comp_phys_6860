// include necessary libraries for basic functions.
# include <iostream>
# include <iomanip>
# include <cmath>
# include <ctime>

using namespace std;

// declare global constants
const double pi = M_PI;

void swap(double n1, double n2){
	double temp = n1;
	n1 = n2;
	n2 = temp;
}

void bubble_sort(int arr[], int arr_len){
	for(int i=0; i<arr_len; i++){
		arr[i] += 1;
	}
}

int main(){
	// declare fixed array
	int arr[20];
	
	srand(time(NULL)); // first seed value
	
	for (int i = 0; i<20; i++){
		arr[i] = 1 + rand()%100; // create random number between 1-100
	}
	
	// print the unsorted array
	cout << "The random unsorted array: " << endl;
	for(int i=0; i<20; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	bubble_sort(arr, 20);
	
	
	// print the sorted array
	cout << endl <<  "The sorted array: " << endl;
	for(int i=0; i<20; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
};
