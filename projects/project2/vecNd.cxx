// Implementation of our vecNd class
// now we have to include our header
// file !!!

#include "vecNd.h"

#include <iostream>  
#include <cmath>

using namespace std;


vecNd vecNd::operator=(vecNd &v)
{
  cout<<" vecNd: user defined = operator:"<<endl;
  ndim=(int) v.GetDimension();
  x = new double[ndim];

  for (int i=0;i<(int) ndim;i++)
    x[i]=v.GetComponent(i);

  return *this;
}

vecNd vecNd::operator = (vecNd *v)
{
  cout<<" vecNd: user defined = operator *:"<<endl;
  ndim=(int) v->GetDimension();
  x=new double[ndim];

  for (int i=0;i<(int) ndim;i++)
    x[i]=v->GetComponent(i);

  return *this;
}

vecNd vecNd::operator += (vecNd &v)
{
	cout<<" vecNd: user defined += operator:"<<endl;
  //DEBUG:
  //cout<<x<<" "<<v.GetX()<<endl;
  //cout<<y<<" "<<v.GetY()<<endl;
  
  ndim = (int) v.GetDimension();
  for (int i = 0; i<ndim; i++){
  	x[i] += v.GetComponent(i);
  }
  
  //DEBUG:
  //cout<<"After Add : x = "<<x<<" "<<y<<endl;

  return *this;
}

vecNd vecNd::operator + (vecNd &v)
{
	cout<<" vecNd: user defined += operator:"<<endl;
  //DEBUG:
  //cout<<x<<" "<<v.GetX()<<endl;
  //cout<<y<<" "<<v.GetY()<<endl;
  
  ndim = (int) v.GetDimension();
  vecNd x_new(ndim);  
  
  for (int i = 0; i<ndim; i++){
  	x_new.SetComponent(i, x[i] + v.GetComponent(i) );
  }
  
  //DEBUG:
  //cout<<"After Add : x = "<<x<<" "<<y<<endl;

  return x_new; // need to figure out what to return
}


vecNd::vecNd()
{
  //default constructor
  //DEBUG:
  cout<<" vecNd: default constructor called"<<endl;
  ndim=0;
  // create an "array" so that we can use the
  // generic delete in the destructor
  x=new double[1];
}

vecNd::vecNd(double mx, double my)
{
  //user defined constructor for nd vector as a 2d vector
  cout<<" vecNd: user defined 2d constructor called"<<endl;
  ndim=2;
  x=new double[2];
  x[0]=mx; x[1]=my;
}

vecNd::vecNd(double mx, double my, double mz)
{
  //user defined constructor for nd vector as a 2d vector
  cout<<" vecNd: user defined 3d constructor called"<<endl;
  ndim=3;
  x=new double[3];
  x[0]=mx; x[1]=my, x[2]=mz;
}


vecNd::vecNd(vecNd& v)
{
  cout<<" vecNd: user defined copy constructor called!"<<endl;
  
  ndim=(int) v.GetDimension();
  x=new double[(int) v.GetDimension()];
  
  for (int i=0;i<(int) v.GetDimension();i++)
    x[i]=v.GetComponent(i);
}


vecNd::~vecNd() 
{
  cout<<" vecNd: default destructor called"<<endl;
  delete [] x;
}; 

void vecNd::Print()
{
  cout<<"VecNd Clas:"<<endl;
  cout<<" dimension = "<<ndim<<endl;
  for (int i=0;i<ndim;i++)    
    cout<<"x["<<i<<"] = "<<x[i]<<endl;
}


double vecNd::Length()
{
	double square_sum = 0;
	for (int i=0; i<ndim; i++){
		square_sum += x[i]*x[i];
	}
  return sqrt(square_sum);
}

