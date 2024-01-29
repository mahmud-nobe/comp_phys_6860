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

  const double analyticalSolution=1/3.;

  cout<<endl;
  cout<<" Calculate the lower sum of f(x)=x^2 [a,b]=["
      <<a<<","<<b<<"] with fixed stepsize = "<<stepsize<<endl;

  cout<<endl;
  cout<<" Analytical Solution = "<<analyticalSolution<<endl;

  double numericalSolutionLower=lowerSum(pol2,a,b,stepsize);
  cout<<" Numerical Solution (lower sum) = "<<numericalSolutionLower<<endl;

  double numericalSolutionUpper=upperSum(pol2,a,b,stepsize);
  cout<<" Numerical Solution (upper sum) = "<<numericalSolutionUpper<<endl;
  

  cout<<endl;
  cout<<" Use a pol3 --> pol2 to demonstrate template functions:"<<endl; 

  double numericalSolutionLower3=lowerSum(pol3,a,b,stepsize);
  cout<<" Numerical Solution (lower sum) = "<<numericalSolutionLower3<<endl;
  
  double numericalSolutionUpper3=upperSum(pol3,a,b,stepsize);
  cout<<" Numerical Solution (upper sum) = "<<numericalSolutionUpper3<<endl;

  cout<<endl;
return 0;
}




