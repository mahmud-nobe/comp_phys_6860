// vecNd class definition
// header file for vecNd class

#ifndef VECND_H
#define VECND_H

class matrixNN; // forward declaration

class vecNd
{
  private:

  int ndim; // number of dimension
  double *x; // array 

  public:

  // constructor
  vecNd(); //default
  vecNd(int n); //constructor with n dimension
  vecNd(double mx, double my); //2d constructor
  vecNd(double mx, double my, double mz); //3d constructor
  
  // copy constructor for pointer
  vecNd(vecNd& v);

  // destructor
  ~vecNd();

  //operators
  vecNd operator = (vecNd &v);
  vecNd operator = (vecNd *v);
  
  vecNd& operator += (vecNd &v); // scaler addition (in place)
  vecNd& operator + (vecNd &v);  // scaler addition
  vecNd& operator -= (vecNd &v); // scaler subtraction (in place)
  vecNd& operator - (vecNd &v);  // scaler subtraction
  
  vecNd& operator /= (double a); // scaler division (in place)
  vecNd& operator / (double a);  // scaler division
  vecNd& operator *= (double a); // scaler multiplication (in place)
  vecNd& operator * (double a);  // scaler multiplication
  
  vecNd& operator * (vecNd &v);  // vector product
  vecNd& operator * (matrixNN &m); // vector-matrix multiplication

  // Setter functions
  void SetN(int n) {ndim=n;}
  void SetComponent(int i, double mx) {x[i]=mx;}

  // Getter functions
  int GetDimension() {return ndim;}
  double GetComponent(int i) {return (double) x[i];}

  //our member functions
  void Print();
  double Length();
  double scaler_prod(vecNd &v);
};

#endif // VECND_H
 

