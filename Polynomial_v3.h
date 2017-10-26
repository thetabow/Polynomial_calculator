#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include "Fraction.h"

#include <iostream>
#include <vector>

using namespace std;

#define MAX(x,y) ((x) > (y) ? (x) : (y))
//#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])     maybe make this size of a vector 

typedef Fraction coeffT;

class Polynomial
{
	friend ostream& operator << (ostream& lhs, Polynomial& rhs);
private:
	vector<coeffT> coeff;
	bool integral_only;
public:
	Polynomial(int deg = 0);
	void set_poly(vector<coeffT>& coefficients); //takes care of setting coefficients
	int get_degree() const;
	Polynomial& operator -- (int);
	Polynomial& operator ++ (int);
	Polynomial operator = (const Polynomial& p);
	Polynomial operator = (int the_constant);
	Polynomial operator + (const Polynomial& rhs) const;
	Polynomial& operator += (const Polynomial& rhs);
	Polynomial operator - (const Polynomial& rhs) const;
	Polynomial& operator -= (const Polynomial& rhs);
	Polynomial operator * (const Polynomial& rhs) const; 
	Polynomial operator * (int scalar) const; 
	Polynomial operator / (const Polynomial& rhs) const;
	Polynomial operator % (const Polynomial& rhs) const;
	Polynomial& operator <<= (int shift);
	Polynomial& operator >>= (int shift);
	coeffT operator [](int degree) const;
	//~Polynomial();
};

int exp(int a, int b);


#endif //__POLYNOMIAL_H__