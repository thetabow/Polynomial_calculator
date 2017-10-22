#include <iostream>
#include <vector>

using namespace std;

#define MAX(x,y) ((x) > (y) ? (x) : (y))
//#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])     maybe make this size of a vector 

class Polynomial
{
private:
	vector<float> coeff;
public:
	Polynomial(int deg = 0);
	void set_poly(vector<float>& coefficients); //takes care of setting degree and coefficients
	int get_degree() const;
	int get_coeff(int index) const;
	Polynomial operator -- (int);
	Polynomial operator ++ (int);
	Polynomial operator = (const Polynomial& p);
	Polynomial operator + (const Polynomial& rhs);
	Polynomial operator - (const Polynomial& rhs);
	Polynomial operator * (const Polynomial& rhs);  
	int operator [](int degree) const;
	//~Polynomial();
};