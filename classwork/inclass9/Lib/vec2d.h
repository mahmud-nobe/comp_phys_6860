// This is the header file
// of our vec2d class for ROOT

#ifndef ROOT_vec2d
#define ROOT_vec2d

#include "TObject.h"
#include "TBuffer.h"

//definition of our vec2d class
class vec2d : public TObject
{
  protected:

  double x;
  double y;

  public:

  // constructor
  vec2d(); //default
  vec2d(double mx, double my);

  // destructor
  virtual ~vec2d();

  //operators
  vec2d operator += (vec2d &);
  vec2d operator + (vec2d &);

  // Setter functions
  void SetX(double mx) {x=mx;}
  void SetY(double my) {y=my;}

  // Getter functions
  double GetX() {return x;}
  double GetY() {return y;}

  //our member functions
  void Print();
  double Length();

  //new feature from ROOT to allow
  // the generationg of a dictonary
  // so that you can use the class
  // in the ROOT propmt and provide I/O

  ClassDef(vec2d,1); 
  //the version number has to be > 1
  // in order to create the streamer
  // needed to saye to disk!
};
 
#endif //ROOT_vec2d
