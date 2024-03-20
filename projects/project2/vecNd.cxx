// vecNd Class Implementation
// Implementation of member function

#include "vecNd.h"
#include "matrixNN.h"

#include <iostream>  
#include <cmath>

using namespace std;

// member function Print
void vecNd::Print()
{
  cout<<"VecNd Clas:"<<endl;
  cout<<" Dimension = "<<ndim<<endl;
  for (int i=0;i<ndim;i++)    
    cout<<" x["<<i<<"] = "<<x[i]<<endl;
}

// member function to get the magnitude
double vecNd::Length()
{
	double square_sum = 0;
	for (int i=0; i<ndim; i++){
		square_sum += x[i]*x[i];
	}
  return sqrt(square_sum);
}

// member function scaler product
double vecNd::scaler_prod(vecNd &v)
{
  double prod = 0;
	for (int i=0; i<ndim; i++){
		prod += x[i] * v.GetComponent(i);
	}
  return prod;
}

// Constructors //

// default constructor
vecNd::vecNd()
{
  cout<<" vecNd: default constructor called"<<endl;
  ndim=0;
  // create an "array" so that we can use the
  // generic delete in the destructor
  x=new double[1];
}

// constructor for nd vector as a 2d vector
vecNd::vecNd(double mx, double my)
{
  cout<<" vecNd: user defined 2d constructor called"<<endl;
  ndim=2;
  x=new double[2];
  x[0]=mx; x[1]=my;
}

// constructor for nd vector as a 3d vector
vecNd::vecNd(double mx, double my, double mz)
{
  cout<<" vecNd: user defined 3d constructor called"<<endl;
  ndim=3;
  x=new double[3];
  x[0]=mx; x[1]=my, x[2]=mz;
}

// copy constructor for pointer
vecNd::vecNd(vecNd &v)
{
  cout<<" vecNd: user defined copy constructor called!"<<endl;
  
  ndim=(int) v.GetDimension();
  x=new double[ndim];
  
  for (int i=0;i<ndim;i++)
    x[i]=v.GetComponent(i);
}

// destructor
vecNd::~vecNd() 
{
  cout<<" vecNd: default destructor called"<<endl;
  delete [] x;
}; 


// operators //

// Equal operator for for reference
vecNd vecNd::operator=(vecNd &v)
{
  cout<<" vecNd: user defined = operator:"<<endl;
  ndim=(int) v.GetDimension();
  x = new double[ndim];

  for (int i=0;i<(int) ndim;i++)
    x[i]=v.GetComponent(i);

  return *this;
}

// Equal operator for for pointer
vecNd vecNd::operator = (vecNd *v)
{
  cout<<" vecNd: user defined = operator *:"<<endl;
  ndim=(int) v->GetDimension();
  x=new double[ndim];

  for (int i=0;i<(int) ndim;i++)
    x[i]=v->GetComponent(i);

  return *this;
}

// operator: addition in place
vecNd vecNd::operator += (vecNd &v)
{
  cout<<" vecNd: user defined += operator:"<<endl;
  
  ndim = (int) v.GetDimension();
  for (int i = 0; i<ndim; i++){
  	x[i] += v.GetComponent(i);
  }

  return *this;
}

// operator: addition 
vecNd vecNd::operator + (vecNd &v)
{
	cout<<" vecNd: user defined + operator:"<<endl;
  vecNd v_new(v);
  for (int i = 0; i<ndim; i++){
  	v_new.SetComponent(i, x[i] + v.GetComponent(i) );
  }
 
  return v_new;
}


// operator: vector product 
vecNd vecNd::operator * (vecNd &v)
{
	if (ndim != (int) v.GetDimension()){
		cout << "The dimensions are not equal!" << endl;
	}
	else if (ndim == 3){
		// vector product for 3D:
		vecNd v_new(v);
		
		v_new.SetComponent(0, x[1]*v.GetComponent(2) - x[2]*v.GetComponent(1) );
		v_new.SetComponent(1, x[2]*v.GetComponent(0) - x[0]*v.GetComponent(2) );
		v_new.SetComponent(2, x[0]*v.GetComponent(1) - x[1]*v.GetComponent(0) );
		
		return v_new;
	};
	
	return vecNd();
  
}


// vector-matrix multiplication 
vecNd vecNd::operator * (matrixNN &m)
{
	if (ndim == m.GetDimension()){
			vecNd v_new;
			v_new.SetN(ndim);
			
			for (int i=0; i<ndim; i++){
					double elem = 0;
					for (int n=0; n < ndim; n++){
						elem += x[n] * m.GetElement(n, i);
					};
					v_new.SetComponent(i, elem);
			};
			cout << "Multiplication Done" << endl;
			return v_new;
	}
	
	else{
		cout << "Dimensions are not equal!" << endl;
		vecNd v_new; // return empty matrix
		return v_new;
	};
	
}


