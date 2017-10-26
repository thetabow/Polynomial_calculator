#include "Fraction.h"

Fraction::Fraction(int num, int denom)
{
	positive = true;
	if(num < 0)
		numerator = num*-1;
	else
		numerator = num;
	if(denom != 0)
	{
		if(denom < 0)
			denominator = denom*-1;
		else
			denominator = denom;
	}
	else 
		denominator = 1;
	if(num*denom < 0)
		positive = false;
}


Fraction& Fraction::operator = (const Fraction& f)
{
	numerator = f.numerator;
	denominator = f.denominator;
	positive = f.positive;
	return *this;
}

Fraction& Fraction::operator = (const int number)
{
	if(number < 0)
	{
		positive = false;
		numerator = number*-1;
	}
	else
	{
		positive = true;
		numerator = number;
	}
	denominator = 1;
	return *this;
}

//reduces fraction, private member
Fraction& Fraction::operator -- (int)	//postfix operator
{
	if(MIN(numerator, denominator) < 2)
		return *this;

	for(int i = MIN(numerator, denominator); i > 1 ; i--)
	{
		if(numerator % i == 0 && denominator%i == 0)
		{
			numerator /= i;
			denominator /= i;
			return *this;
		}
	}
	return *this;
}

//multiplication
Fraction Fraction::operator * (const Fraction& f) const
{
	Fraction product(numerator * f.numerator, denominator * f.denominator);
	if( (positive && f.positive) || (!positive && !f.positive) )
		product.positive = true;
	else
		product.positive = false;
	return product--;
}
Fraction Fraction::operator * (int scalar) const
{
	if(scalar > 0)
	{
		Fraction product(numerator * scalar, denominator);
		product.positive = true;
			return product--;
	}
	else if(scalar < 0)
	{
		scalar *= -1;
		Fraction product(numerator * scalar, denominator);
		product.positive = false;
			return product--;
	}
	else
	{
		Fraction product(0);
		product.positive = true;
			return product--;
	}
}

Fraction& Fraction::operator *= (const Fraction& f) 
{
	if(!f.positive)
		positive = !positive;
	*this = *this * f;
	return *this;
}


//division
Fraction Fraction::operator / (const Fraction& f) const
{
	Fraction quotient(numerator * f.denominator, denominator * f.numerator);

	if( (positive && f.positive) || (!positive && !f.positive) )
		quotient.positive = true;
	else
		quotient.positive = false;

	return quotient--;
}


Fraction Fraction::operator / (int dividend) const
{
	bool sign = true;
	if(dividend < 0)
	{
		sign = false;
		dividend *= -1;
	}
	Fraction quotient(numerator, denominator * dividend);
	quotient.positive = sign;
	return quotient--;
}

Fraction& Fraction::operator /= (const Fraction& f)
{
	if( (positive&&f.positive) || (!positive && !f.positive) )
		positive = true;
	else 
		positive = false;
	*this = *this / f;
	return *this;
}

//addition
Fraction Fraction::operator + (const Fraction& frac) const
{
	Fraction sum;
	Fraction f = frac;

if( (positive&&f.positive) || (!positive && !f.positive) )
{
	do{
		if(denominator == f.denominator)
		{
			sum.numerator = numerator + f.numerator;
			return sum--;
		}
		sum.denominator *= f.denominator;
		sum.numerator *= f.denominator;

		f.denominator *= denominator;
		f.numerator *= denominator;

	}while(1);
}
else if(positive && !f.positive)
{
	Fraction abs_f = f;
	abs_f.positive = true;
	sum = *this - abs_f;
	return sum--;
}
else if(f.positive && !positive)
{
	Fraction abs_f = *this;
	abs_f.positive = true;
	sum = f - abs_f;
	return sum--;
}

}
Fraction Fraction::operator + (int numb) const
{
	Fraction frac(numb);
	return *this + frac;
}
Fraction& Fraction::operator +=(const Fraction& f)
{
	*this = *this + f;
	return *this;
}

//subtraction
Fraction Fraction::operator - (const Fraction& frac) const
{
	Fraction difference;
	Fraction f = frac;

	do{
		if(denominator == f.denominator)
		{
			difference.numerator = numerator - f.numerator;
			return difference--;
		}
		difference.denominator *= f.denominator;
		difference.numerator *= f.denominator;
		
		f.denominator *= denominator;
		f.numerator *= denominator;

	}while(1);
}

Fraction Fraction::operator - (int numb) const
{
	Fraction frac(numb);
	return *this - frac;
}

Fraction& Fraction::operator -= (const Fraction& f)
{
	*this = *this - f;
	return *this;
}

Fraction::operator double()   //  double(frac)
{
	if(positive)
		return double(numerator)/denominator;
	else 
		return -1*double(numerator)/denominator;
}

int Fraction::get_sign() const
{
	if(positive)
		return 1;
	else
		return -1;
}


//only a friend
istream& operator >> (istream& lhs, Fraction& frac)
{
	lhs >> frac.numerator;
	frac.denominator = 1;
	return lhs;
}

//only a friend
ostream& operator << (ostream& lhs, const Fraction& frac)
{
	const char* super[10] = {
				"\u2070", "\u00B9", "\u00B2", "\u00B3", "\u2074", 
				"\u2075", "\u2076", "\u2077", "\u2078", "\u2079"};
	const char* sub[10] = {
				"\u2080", "\u2081", "\u2082", "\u2083", "\u2084", 
				"\u2085", "\u2086", "\u2087", "\u2088", "\u2089"};

	if(frac.denominator == 1)
	{
		lhs << frac.numerator;
		return lhs;
	}



	if(frac.get_sign() < 0)
		lhs << "-";
	//int index;
	//cout << "numerator is: " << frac.numerator << endl;
	for(int i = log(frac.numerator); i >= 0; i--)
	{
		//index = frac.numerator/int(pow(10, i));
		//cout << " the index is \n" << index << endl;
		lhs << super[frac.numerator/int(pow(10, i))];
	}

	lhs << "/";

	for(int i = log(frac.denominator) + 1; i > 0; i--)
	{
		lhs << sub[frac.denominator/int(pow(10, i))];
	}

	return lhs;


}