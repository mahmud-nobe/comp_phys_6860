// This is the header file
// of our vecNd class


//definition of our vec2d class
class vecNd
{
  private:

  int ndim; // number of dimension
  double *x; // array 

  public:

  // constructor
  vecNd(); //default
  vecNd(double mx, double my); //2d constructor
  vecNd(double mx, double my, double mz); //3d constructor
  
  // copy constructor for pointer
  vecNd(vecNd& v);

  // destructor
  ~vecNd();

  //operators
  vecNd operator = (vecNd &v);
  vecNd operator = (vecNd *v);
  
  vecNd operator += (vecNd &); // scaler addition (in place)
  vecNd operator + (vecNd &);  // scaler addition
  
  vecNd operator *= (vecNd &); // scaler product (in place)
  vecNd operator * (vecNd &);  // scaler product

  // Setter functions
  void SetN(int n) {ndim=n;}
  void SetComponent(int i, double mx) {x[i]=mx;}

  // Getter functions
  int GetDimension() {return ndim;}
  double GetComponent(int i) {return (double) x[i];}

  //our member functions
  void Print();
  double Length();
};
 

