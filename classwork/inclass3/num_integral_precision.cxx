// numerical integration lower sum (JP)
// using function template and default
// function parameters

#include <iostream>  

using namespace std;

double pol2(double x)
{
  // simple f(x)=x^2
  const double p0=0;
  const double p1=0;
  const double p2=1;

  return p0+p1*x+p2*x*x;
}

double pol3(double x)
{
  // make also a simple f(x)=x^2
  const double p0=0;
  const double p1=0;
  const double p2=1;
  const double p3=0;

  return p0+p1*x+p2*x*x+p3*x*x*x;
}

// equivalent usage: template<class F> 
template<typename F_low> 
double lowerSum(F_low f,double a, double b, int stepsize)
{
  double lSum=0;				
  const double deltaX=(b-a)/(double) stepsize;

  for (int i=0;i<stepsize;i++)
    {
      double xi=a+deltaX*i;
      lSum += (f(xi)*deltaX);
    }

  return lSum;
}

template<typename F_up> 
double upperSum(F_up f,double a, double b, int stepsize)
{
  double uSum=0;				
  const double deltaX=(b-a)/(double) stepsize;

  for (int i=1;i<=stepsize;i++)
    {
      double xi=a+deltaX*i;
      uSum += (f(xi)*deltaX);
    }

  return uSum;
}


int main( )
{ 
  int stepsize=10000;

  // simple values to check and compare to
  // analytical solution = 1/3

  double a=0;
  double b=1;
  double precision = 0.00000001;
  double numericalSolutionLower, numericalSolutionUpper;
  double solnLower_before, solnLower_after;
  
  const double analyticalSolution=1/3.;

  cout<<endl;
  cout<<" Calculate the lower sum of f(x)=x^2 [a,b]=["
      <<a<<","<<b<<"] with fixed stepsize = "<<stepsize<<endl;

  cout<<endl;
  cout<<" Analytical Solution = "<<analyticalSolution<<endl;

  numericalSolutionLower=lowerSum(pol2,a,b,stepsize);
  cout<<" Numerical Solution (lower sum) = "<<numericalSolutionLower<<endl;

  numericalSolutionUpper=upperSum(pol2,a,b,stepsize);
  cout<<" Numerical Solution (upper sum) = "<<numericalSolutionUpper<<endl;

  cout << "Now using lower sum and the given precison = " << precision << endl;
  
  solnLower_before = lowerSum(pol2,a,b,stepsize);
  stepsize = stepsize + 100;
  solnLower_after = lowerSum(pol2,a,b,stepsize);
  int iteration = 0;
   
  while(solnLower_after - solnLower_before > precision){
      stepsize = stepsize + 100;
      iteration++;
      solnLower_before = solnLower_after;
      solnLower_after = lowerSum(pol2,a,b,stepsize);
  }

  cout << "Total  Iteration = " << iteration << endl;
  cout << "Final Solution = " << solnLower_after << endl;
  cout << "Total stepsize = " << stepsize << endl;
  
return 0;
}




