/* 
This program solves the E. Lorenz Equations
 using the GSL
*/
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>
#include <TROOT.h>
#include <TFile.h>
#include <TH2.h> 
  
// parameters for diff eq
double g = 9.1;  // gravitational const
double l = 1; // length of the rope
  
/* dfunct - defines the first order differencial equations to solve */
int dfunc (double t, const double y[], double f[], void *params_ptr)
{ 
   /* parameters are declared as globals */
   // theta" + g/l theta = 0
   // Let phi = theta'
   f[0] = y[1]; // theta' = phi
   f[1] = sin(y[0]) * (-g/l); // phi' = -g/l theta
   return GSL_SUCCESS;	
} // end of dfunct


// Main function
int main (void) {

  const int dimension = 2;  /* number of differential equations */

  int status;               /* status of driver function */

  const double eps_abs = 1.e-8;  /* absolute error requested */
  const double eps_rel = 1.e-10; /* relative error requested */

  double myparams[2];
  double y[dimension];    /* current solution vector */
  double t, t_next;       /* current and next independent variable */
  double tmin, tmax, delta_t; /* range of t and step size for output */
  double h = 1.0e-6;      /* starting step size for ode solver */

  gsl_odeiv2_system ode_system;	/* structure with the dfunc function, etc. */

  printf("\nThis program numerically solves the Pendulum Equations\n\n");

  /* load values into the ode_system structure */
  ode_system.function = dfunc;	/* the right-hand-side functions dy[i]/dt */
  ode_system.dimension = dimension;	/* number of diffeq's */

  myparams[0] = g; /* Diff equations parameters */
  myparams[1] = l;
  
  TFile *f=new TFile("pendulum.root","RECREATE");
  TH2D *hlorenz2d=new TH2D("hpendulum2d","",100,-25,25,100,-25,25);
   
  ode_system.params = myparams;	/* parameters for GSL functions */
  tmin = 0.0;     /* starting t value */
  tmax = 40.0;    /* final t value */
  delta_t = 0.010; /* increment data points */

  /* initial values of theta, y, and z */
  y[0] = 2.1473670;  // theta = angle
  y[1] = 0;  // phi = angular velocity

  gsl_odeiv2_driver * drv =
      gsl_odeiv2_driver_alloc_y_new (&ode_system, gsl_odeiv2_step_rkf45, 
	     h, eps_abs, eps_rel);

  // Runge–Kutta–Fehlberg (4, 5) method: gsl_odeiv2_step_rkf45
  // 4th order Runge–Kutta : gsl odeiv2 step rk4

  printf("Input data: \n");
  printf("Initial values theta = %g phi = %g \n", y[0], y[1]); 
  printf(" Parameters: g= %g l= %g \n", g, l);
  printf(" Starting step size (h): %0.5e\n", h);
  printf(" Time parameters: %f %f %f \n", tmin, tmax, delta_t); 
  printf(" Absolute  and relative error requested: %0.6e %0.6e \n", 
         eps_abs, eps_rel);
  printf(" Number of equations (dimension): %d \n\n", dimension);
  printf("    Time           theta             phi   \n");
  t = tmin;             /* initialize t */
  printf ("%.5e  %.5e  %.5e \n", t, y[0], y[1]);	/* initial values */
  /* step to tmax from tmin */

  for (t_next = tmin + delta_t; t_next <= tmax; t_next += delta_t)
  {
     status = gsl_odeiv2_driver_apply (drv, &t, t_next, y);
     if (status != GSL_SUCCESS) {
          printf("Error: status = %d \n", status);
          break;
     }
	 /* print at t=t_next */
     // printf ("%.5e  %.5e  %.5e \n", t, y[0], y[1]); 
     hlorenz2d->Fill(y[0],y[1]);
  } // end for

  gsl_odeiv2_driver_free (drv);
  
  f->Write();
  f->Close();

  return 0;

} // end of main


