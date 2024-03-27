#include <iostream>
#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_linalg.h>
using namespace std;

void print_matrix(gsl_matrix &m){
	cout << "nrow: " << m.size1 << ", ncol: " << m.size2 << endl;
	for (int i = 0; i < m.size1; i++){
		for (int j = 0; j < m.size2; j++){
			cout << " " << gsl_matrix_get(&m, i, j);
		};
		cout << endl;
	}; 
}


int main () {
	cout << "Program Start" << endl;
	int i, j;
	gsl_matrix *m1 = gsl_matrix_alloc(3, 3);
	int mat_elements1[] = {1, 3, 3, 1, 4, 3, 1,3, 4};
	int s;
	
	int n = 0;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			gsl_matrix_set(m1, i, j, mat_elements1[n]);
			n += 1;
		};
	};
	
	cout << "Matrix 1:" << endl;
	print_matrix(*m1);
	cout << endl;
	
	gsl_matrix *m2 = gsl_matrix_alloc(3, 3);
	int mat_elements2[] = {1, 2, 7, 4, 6, 8, 5, 6, 1};
	n = 0;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			gsl_matrix_set(m2, i, j, mat_elements2[n]);
			n += 1;
		};
	};
	
	cout << "Matrix 2:" << endl;
	print_matrix(*m2);
	cout << endl;
	
	
	gsl_matrix *m2_inv = gsl_matrix_alloc(3, 3); // for storing inverse matrix
	gsl_permutation *p = gsl_permutation_alloc(3);
	
	// LU decomposition
	gsl_linalg_LU_decomp(m2, p, &s); 
	gsl_linalg_LU_invert(m2, p, m2_inv);
	
	
	cout << "Inverse of Matrix 2:" << endl;
	print_matrix(*m2_inv);
	cout << endl;
		
	cout << "Program End" << endl;
	
	return 0;
}
