#include <iostream>
#include <vector>

using namespace std;

#define MAX(x,y) ((x) > (y) ? (x) : (y))
//#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])     maybe make this size of a vector 

typedef float coeffT;

class Polynomial
{
	friend ostream& operator << (ostream& lhs, Polynomial& rhs);
private:
	vector<coeffT> coeff;
	bool integral_only;
public:
	Polynomial(int deg = 0);
	void set_poly(vector<coeffT>& coefficients); //takes care of setting degree and coefficients
	int get_degree() const;
	Polynomial& operator -- (int);
	Polynomial& operator ++ (int);
	Polynomial operator = (const Polynomial& p);
	Polynomial operator + (const Polynomial& rhs) const;
	Polynomial operator - (const Polynomial& rhs) const;
	Polynomial operator * (const Polynomial& rhs) const; 
	Polynomial operator * (int scalar) const; 
	Polynomial operator / (const Polynomial& rhs) const;
	coeffT operator [](int degree) const;
	//~Polynomial();
};

int exp(int a, int b);