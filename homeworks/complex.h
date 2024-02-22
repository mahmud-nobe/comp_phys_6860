// header file for complex class

class complex
{
	private:
	double real; // real part
	double imaginary; // imaginary part
	
	public:
	
	// constructor
	complex(); // default
	// constructor using real and imaginary part
	complex(double real_n, double imag_n){
		real = real_n; 
		imaginary = imag_n;
	};
	
	// destructor
	~complex();
	
	// setter function
	void setReal(double real_n){real = real_n;};
	void setImaginary(double imag_n){imaginary = imag_n;};
	
	// getter function
	double getReal(){return real;};
	double getImaginary(){return imaginary;};
	
	// member function
	void Print();
	double abs_value();
};
