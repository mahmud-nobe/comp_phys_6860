#include <stdio.h>
#include <gsl/gsl_matrix.h>

int main () {
	int i, j;
	gsl_matrix *m1 = gsl_matrix_alloc(3, 3);
	int mat_elements[] = {1, 3, 3, 1, 4, 3, 1,3, 4};
	
	int n = 0;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			gsl_matrix_set(m1, i, j, mat_elements[n]);
			n += 1;
		};
	};
	
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			printf("m(%d,%d) = %g\n", i, j, gsl_matrix_get(m1, i, j));
	
	gsl_matrix_free(m1);
	return 0;
}
