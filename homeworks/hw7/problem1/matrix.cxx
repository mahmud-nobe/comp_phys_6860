
#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_linalg.h>


int main () {
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
	
	gsl_matrix *m2 = gsl_matrix_alloc(3, 3);
	int mat_elements2[] = {1, 2, 7, 4, 6, 8, 5, 6, 1};
	n = 0;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			gsl_matrix_set(m2, i, j, mat_elements2[n]);
			n += 1;
		};
	};
	
	printf ("Matrix A = \n");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			printf("m1(%d,%d) = %g\n", i, j, gsl_matrix_get(m1, i, j));
	
	printf ("Matrix B = \n");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			printf("m2(%d,%d) = %g\n", i, j, gsl_matrix_get(m2, i, j));
	
	gsl_matrix *m2_inv = gsl_matrix_alloc(3, 3);
	gsl_permutation *p = gsl_permutation_alloc(3);
	gsl_linalg_LU_decomp(m2, p, &s);
	gsl_linalg_LU_invert(m2, p, m2_inv);
	printf("M2 Inverse vector x = \n");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			printf("m2(%d,%d) = %g\n", i, j, gsl_matrix_get(m2_inv, i, j));
		
	//gsl_vector_fprintf (stdout, x, "%g");
	//gsl_permutation_free(p);
	//gsl_matrix_free(m1);
	//gsl_vector_free (x);
	//gsl_vector_free (b);
	
	return 0;
}
