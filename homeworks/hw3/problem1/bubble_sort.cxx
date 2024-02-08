// include necessary libraries for basic functions.
# include <iostream>
# include <iomanip>
# include <cmath>
# include <ctime>

using namespace std;

// declare global constants
const double pi = M_PI;

void swap(double &n1, double &n2){
	double temp = n1;
	n1 = n2;
	n2 = temp;
}

void bubble_sort(int arr[], int arr_len){
	// every iteration the largest number will move to the rightmost position,
	// so the length of unsorted array reduced by 1
	for (int j=arr_len; j>0; j--){
		// check all the adjacent pairs upto the unsorted part
		for(int i=1; i<j; i++){
			// right adjacent should be larger, otherwise swap the pair
			if (arr[i] < arr[i-1]){
				swap(arr[i], arr[i-1]);
			};
		};
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
