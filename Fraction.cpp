#include "Fraction.h"

Fraction::Fraction(int num, int denom)
{
	numerator = num;
	denominator = denom;

	if(denom != 0)
	{
		if(denom < 0)
		{
			numerator *=-1;
			denominator = denom*-1;
		}
		else
			denominator = denom;
	}
	else 
		denominator = 1;
	
}

		
Fraction& Fraction::operator = (const Fraction& f)
{
	numerator = f.numerator;
	denominator = f.denominator;
	return *this;
}

Fraction& Fraction::operator = (const int number)
{
	numerator = number;
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
	return product--;
}
Fraction Fraction::operator * (int scalar) const
{
	Fraction product(numerator * scalar, denominator);
	return product--;
}

Fraction& Fraction::operator *= (const Fraction& f) 
{
	*this = *this * f;
	return *this;
}


//division
Fraction Fraction::operator / (const Fraction& f) const
{
	Fraction quotient(numerator * f.denominator, denominator * f.numerator);
	return quotient--;
}


Fraction Fraction::operator / (int dividend) const
{
	Fraction quotient(numerator, denominator * dividend);
	return quotient--;
}

Fraction& Fraction::operator /= (const Fraction& f)
{
	*this = *this / f;
	return *this;
}

//addition
Fraction Fraction::operator + (const Fraction& frac) const
{
	Fraction sum;
	Fraction f1 = frac;
	Fraction f2 = *this;

	do{
		if(f2.denominator == f1.denominator)
		{
			sum.numerator = f2.numerator + f1.numerator;
			sum.denominator = f1.denominator;
			return sum--;
		}

		f1.denominator *= f2.denominator;
		f1.numerator *= f2.denominator;
		f2.denominator *= frac.denominator;
		f2.numerator *= frac.denominator;

	}while(1);

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
	Fraction f1 = frac;
	Fraction f2 = *this;

	do{
		if(f2.denominator == f1.denominator)
		{
			difference.numerator = f2.numerator - f1.numerator;
			difference.denominator = f1.denominator;
			return difference--;
		}

		f1.denominator *= f2.denominator;
		f1.numerator *= f2.denominator;
		f2.denominator *= frac.denominator;
		f2.numerator *= frac.denominator;

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
	return double(numerator)/denominator;
}



Fraction exp(const Fraction& base, int exponent)
{
	if(exponent == 1)
		return base;
	if(exponent == 0)
		return 1;
	Fraction value;
	value = 1;
	Fraction base_cpy;
	base_cpy = base;
	if(exponent < 0)
	{
		base_cpy.numerator = base.denominator;
		base_cpy.denominator = base.numerator;
		exponent *= -1;
	}
	while(exponent)
	{
		if(exponent&1)
			value *= base_cpy;
		exponent>>=1;
		base_cpy *= base_cpy;
	}
	return value;
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
	if(frac.numerator == 0)
	{
		lhs << frac.numerator;
		return lhs;
	}
	if(frac.numerator < 0)
		lhs << "-";


	int number = abs(frac.numerator);
	int digits = int(log10(number));
	int index;

	for(int i = digits; i >=0; i--)
	{
		index = number / pow(10, i);
		lhs << super[index];
		number-= index * pow(10, i);
	}

	lhs << "/";

	number = abs(frac.denominator);
	digits = int(log10(number));

	for(int i = digits; i >=0; i--)
	{
		index = number / pow(10, i);
		lhs << sub[index];
		number-= index * pow(10, i);
	}

	return lhs;
}

/*
int main()
{
	Fraction basic(3, 4);
	Fraction multi_digit(5, 8);
	//Fraction negatives(-2, -5);
	//Fraction multi_negatives(-33, 999);
	//Fraction test(4235, 0);
	//Fraction trial(-1);
	cout << basic << " + " << multi_digit << " = " << basic+multi_digit << endl;
	//cout << basic << endl;

	//cout << "basic: " << basic << endl << "multi_digit: " << multi_digit << endl << "try negatives: " << negatives << endl;
	return 0;

}*/