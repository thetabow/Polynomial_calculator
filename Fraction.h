#ifndef __FRACTION_H__
#define __FRACTION_H__

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


#define MIN(x,y) ((x) < (y) ? (x) : (y))

class Fraction {
	
	friend ostream& operator << (ostream& lhs, const Fraction& frac);
	friend istream& operator >> (istream& lhs, Fraction& frac);

private:
	int numerator;
	int denominator;
	Fraction& operator -- (int);
public:

	operator double();
	Fraction(int num = 1, int denom = 1);
	Fraction& operator = (const Fraction& f);
	Fraction& operator = (const int number);
	Fraction operator + (const Fraction& f) const;
	Fraction operator + (int) const;
	Fraction& operator += (const Fraction& f);
	Fraction operator - (const Fraction& f) const;
	Fraction operator - (int) const;
	Fraction& operator -= (const Fraction& f);
	Fraction operator * (const Fraction& f) const;
	Fraction operator * (int) const;
	Fraction& operator *= (const Fraction& f);
	Fraction operator / (const Fraction& f) const;
	Fraction operator / (int) const;
	Fraction& operator /= (const Fraction& f);
	int get_sign() const;

};

#endif //__FRACTION_H__