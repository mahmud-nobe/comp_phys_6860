/* 
This program solves the E. Lorenz Equations
 using the GSL
*/

#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>
  
double sigma = 10.0;  /* parameters for the diffeq */
double beta = 8.0/3.0;
double rho = 28.0;
  
/* dfunct - defines the first order differencial equations to solve */
int dfunc (double t, const double y[], double f[], void *params_ptr);

int main (void) {

  const int dimension = 3;  /* number of differential equations */

  int status;               /* status of driver function */

  const double eps_abs = 1.e-8;  /* absolute error requested */
  const double eps_rel = 1.e-10; /* relative error requested */

  double myparams[3];
  double y[dimension];    /* current solution vector */
  double t, t_next;       /* current and next independent variable */
  double tmin, tmax, delta_t; /* range of t and step size for output */
  double h = 1.0e-6;      /* starting step size for ode solver */

  gsl_odeiv2_system ode_system;	/* structure with the dfunc function, etc. */

  printf("\nThis program numerically solves the Lorenz Equations\n\n");

  /* load values into the ode_system structure */
  ode_system.function = dfunc;	/* the right-hand-side functions dy[i]/dt */
  ode_system.dimension = dimension;	/* number of diffeq's */

  myparams[0] = sigma; /* Lorenz equations parameters */
  myparams[1] = beta;
  myparams[2] = rho;
   
  ode_system.params = myparams;	/* parameters for GSL functions */
  tmin = 0.0;     /* starting t value */
  tmax = 40.0;    /* final t value */
  delta_t = 0.010; /* increment data points */

  /* initial values of x, y, and z */
  y[0] = 2.1473670;  // 4.250440
  y[1] = -2.078048;  // 1.008479
  y[2] = 27.0; 

  gsl_odeiv2_driver * drv =
      gsl_odeiv2_driver_alloc_y_new (&ode_system, gsl_odeiv2_step_rkf45, 
	     h, eps_abs, eps_rel);

  // Runge–Kutta–Fehlberg (4, 5) method: gsl_odeiv2_step_rkf45
  // 4th order Runge–Kutta : gsl odeiv2 step rk4

  printf("Input data: \n");
  printf("Initial values x = %g y = %g z = %g \n", y[0], y[1], y[2]); 
  printf(" Parameters: sigma= %g beta= %g rho= %g \n", sigma, beta, rho);
  printf(" Starting step size (h): %0.5e\n", h);
  printf(" Time parameters: %f %f %f \n", tmin, tmax, delta_t); 
  printf(" Absolute  and relative error requested: %0.6e %0.6e \n", 
         eps_abs, eps_rel);
  printf(" Number of equations (dimension): %d \n\n", dimension);
  printf("    Time           x             y            z \n");
  t = tmin;             /* initialize t */
  printf ("%.5e  %.5e  %.5e   %.5e \n", t, y[0], y[1], y[2]);	/* initial values */
  /* step to tmax from tmin */

  for (t_next = tmin + delta_t; t_next <= tmax; t_next += delta_t)
  {
     status = gsl_odeiv2_driver_apply (drv, &t, t_next, y);
     if (status != GSL_SUCCESS) {
          printf("Error: status = %d \n", status);
          break;
     }
	 /* print at t=t_next */
     printf ("%.5e  %.5e  %.5e   %.5e \n", t, y[0], y[1], y[2]); 
  } // end for

  gsl_odeiv2_driver_free (drv);

  return 0;

} // end of main

int dfunc (double t, const double y[], double f[], void *params_ptr)
{ 
   /* parameters are declared as globals */
   /* evaluate the right-hand-side of Lorenz equations at t */
   f[0] = sigma * (y[1] - y[0]);
   f[1] = y[0] * (rho - y[2]);
   f[2] = y[0] * y[1] - beta * y[2];
   return GSL_SUCCESS;	
} // end of dfunct
