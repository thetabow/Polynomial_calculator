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
	cout << numerator;
	cout << "/" << denominator << endl;
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
	Fraction f = frac;
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
		f2.denominator *= f1.denominator;
		f2.numerator *= f1.denominator;

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


	//int index;
	//cout << "numerator is: " << frac.numerator << endl;
	for(int i = int(log(abs(frac.numerator))); i >= 0; i--)
	{

		cout << "i for numerator is: " << i << "  " << endl;
		/*if(frac.numerator < 0)
			lhs << " ";
		else
			lhs << " +";*/
		//index = frac.numerator/int(pow(10, i));
		//cout << " the index is \n" << index << endl;
		//lhs << "numerator number: " << frac.numerator/*/int(pow(10, i))*/;
	}

	lhs << endl << endl << "/" << endl << endl;

	for(int i = int(log(frac.denominator)) + 1; i > 0; i--)
	{

		cout << "i for denominator is: " << i << "  " << endl;
		//lhs << "denominator number: " << frac.denominator/*/int(pow(10, i))*/;
	}

	return lhs;
}


int main()
{
	Fraction basic(5, 3);
	Fraction multi_digit(20, 44);
	Fraction negatives(-2, -5);
	//Fraction multi_negatives(-33, 999);
	//Fraction test(4235, 0);
	//Fraction trial(-1);
	cout << basic << endl;

	//cout << "basic: " << basic << endl << "multi_digit: " << multi_digit << endl << "try negatives: " << negatives << endl;
	return 0;

}