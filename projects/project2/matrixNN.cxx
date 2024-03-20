// Implementation of our matrixNN class

#include "matrixNN.h"

#include <iostream>  
#include <cmath>

using namespace std;

matrixNN::matrixNN():vecNd()
{
  //default constructor
  //DEBUG:
  cout<<" matrixNN: default constructor called"<<endl;
  ndim=0;
}

matrixNN::~matrixNN() 
{
  cout<<" matrixNN: default destructor called"<<endl;
}; 

void matrixNN::Print()
{
  cout<<"matrixNN Clas:"<<endl;
  cout<<" dimension = "<<ndim<<endl;
}
