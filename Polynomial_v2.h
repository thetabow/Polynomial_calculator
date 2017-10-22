#include <iostream>
#include <vector>

using namespace std;

#define MAX(x,y) ((x) > (y) ? (x) : (y))
//#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])     maybe make this size of a vector 

typedef float coeffT;

class Polynomial
{
private:
	vector<coeffT> coeff;
public:
	Polynomial(int deg = 0);
	void set_poly(vector<coeffT>& coefficients); //takes care of setting degree and coefficients
	int get_degree() const;
	Polynomial operator -- (int);
	Polynomial operator ++ (int);
	Polynomial operator = (const Polynomial& p);
	Polynomial operator + (const Polynomial& rhs);
	Polynomial operator - (const Polynomial& rhs);
	Polynomial operator * (const Polynomial& rhs);  
	coeffT operator [](int degree) const;
	//~Polynomial();
};