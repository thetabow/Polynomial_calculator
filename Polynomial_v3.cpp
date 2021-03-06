#include "Polynomial_v3.h"

/*------------------------------------------------------------------------------------------------------------
								Polynomial class constructor
PURPOSE: declares a new instance of a polynomial and resizes the coefficient matrix to be one more than the 
		 the degree of the polynoial
ARGUMENTS: optional number of degree, defaults to zero
RETURNS: nothing because constructors cant return things
NOTES: 
------------------------------------------------------------------------------------------------------------*/
Polynomial::Polynomial()
{
	int deg = 0;
	coeff.resize(deg + 1);
	for(int i = 0; i < deg + 1; i++)
	coeff[i] = 0;
	integral_only = false;
}

/*------------------------------------------------------------------------------------------------------------
								Polynomial class constructor
PURPOSE: declares a new instance of a polynomial and resizes the coefficient matrix to be one more than the 
		 the degree of the polynoial
ARGUMENTS: optional number of degree, defaults to zero
RETURNS: nothing because constructors cant return things
NOTES: 
------------------------------------------------------------------------------------------------------------*/
Polynomial::Polynomial(int deg)
{
	coeff.resize(deg + 1);
	for(int i = 0; i < deg + 1; i++)
	coeff[i] = 0;
	integral_only = false;
}

/*-----------------------------------------------------------------------------------------------------------
								Polynomial copy constructor
PURPPOSE: declares a new polynomial and makes it equal to the argument polynomial
ARGUMENTS: polynomial passed by reference
RETURNS: nothing
NOTES:
-----------------------------------------------------------------------------------------------------------*/
Polynomial::Polynomial(const Polynomial& p)
{
	coeff.resize(p.coeff.size());
	for(int i = 0; i < coeff.size(); i ++)
	{
		coeff[i] = p[i];
	}
}

/*-----------------------------------------------------------------------------------------------------------
								= operator overload
PURPOSE: assign contents of one Polynomial class object to another
RETURNS: the Polynomial assigned (just like normal = operator)
NOTES: 
------------------------------------------------------------------------------------------------------------*/
Polynomial& Polynomial::operator = (const Polynomial& p)
{
	//cout << "using assignment operator..." << endl;
	integral_only = false;
	coeff.resize(p.coeff.size());
	for(int i = 0; i < p.coeff.size(); i++)
	{
		coeff[i] = p.coeff[i];
	}

	return *this;
}

/*-----------------------------------------------------------------------------------------------------------
								= operator overload
PURPOSE: assign contents of int object to a Polynomial as a constant
RETURNS: the constant assigned except now as a polynomial of degree 0
NOTES: 
------------------------------------------------------------------------------------------------------------*/
Polynomial& Polynomial::operator = (int the_constant)
{
	integral_only = false;
	coeff.resize(1);
	
	coeff[0] = the_constant;

	return *this;
}

/*-----------------------------------------------------------------------------------------------------------
								[] operator overload
PURPOSE: incase of trying to access an array element that doesnt exist, it will return 0
RETURNS: coefficient corresponding to the given degree
NOTES: the vector of coefficientsonly stores as far as the largest non-zero degree, this ensures that if trying
	   to access a higher degree than that, 0 is received instead of garbage out of the vector
------------------------------------------------------------------------------------------------------------*/
coeffT Polynomial::operator[] (int deg) const
{
	if(deg > get_degree())
	{
		return 0;
	}
	else
	{
		return coeff[deg];
	}
}

/*-----------------------------------------------------------------------------------------------------------
								+ overload operator
PURPOSE: adds 2 polynomials
RETURNS: the sum of the polynomials
NOTES: makes use of the []operator to ensure if the polynomials' degrees are different that it's not adding 
	   garbage
------------------------------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator + (const Polynomial& rhs) const
{
	int deg = MAX(get_degree(), rhs.get_degree());
	Polynomial sum(deg);

	for (int i = deg; i >= 0; i--)
	{
		sum.coeff[i] = operator[](i) + rhs[i];
    }
      return sum;
}

/*-----------------------------------------------------------------------------------------------------------
									+= overload operator
PURPOSE: adds the rhs polynomial to this and makes this = the sum
RETURNS this + rhs
NOTES:
-----------------------------------------------------------------------------------------------------------*/
Polynomial& Polynomial::operator += (const Polynomial& rhs) 
{
	*this = *this + rhs;
	return *this;
}

/*-----------------------------------------------------------------------------------------------------------
								- overload operator
PURPOSE: subtract 2 polynomials
RETURNS: the difference between the 2 polynomials
NOTES: makes use of the []operator to ensure if the polynomials' degrees are different that it's not 
	   subtracting garbage
------------------------------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator - (const Polynomial& rhs) const
{
	int deg = MAX(get_degree(), rhs.get_degree());
	Polynomial sum(deg);

	for (int i = deg; i >= 0; i--)
	{
		sum.coeff[i] = operator[](i) - rhs[i];
    }
      return sum;
}

/*-----------------------------------------------------------------------------------------------------------
									-= overload operator
PURPOSE: subtracts the rhs polynomial from this and makes this = the diference
RETURNS this - rhs
NOTES:
-----------------------------------------------------------------------------------------------------------*/
Polynomial& Polynomial::operator -= (const Polynomial& rhs) 
{
	*this = *this - rhs;
	return *this;
}

/*-----------------------------------------------------------------------------------------------------------
								* overload operator
PURPOSE:multiply 2 polynomials
RETURNS: the product of the 2 polynomials
NOTES: makes use of the []operator to ensure if the polynomials' degrees are different that it's not 
	   multiplying garbage garbage
------------------------------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator * (const Polynomial& rhs) const
{
	int deg = get_degree() + rhs.get_degree();
	Polynomial product(deg);
	int i = 0, j = 0;
	for (i = 0; i <= get_degree(); i++)
	{
		for(j = 0; j <= rhs.get_degree(); j++)
		{
			product.coeff[i + j] += (operator[](i) * rhs[j]);
		}
    }
      return product;
}

/*-----------------------------------------------------------------------------------------------------------
								* overload operator
PURPOSE: scalar multiplication of polynomial times a constant
RETURNS: the product of the polynomial and the constant
NOTES: polynomial must be on the left, int on right (later function will be able to do either)
------------------------------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator * (const int scalar) const
{
	Polynomial product(get_degree());
	for(int i = 0; i <= get_degree(); i++)
	{
		product.coeff[i] = operator[](i) * scalar;
	}
	return product;
}

/*-----------------------------------------------------------------------------------------------------------
								/overload operator
PURPOSE: divide polynomials
RETURNS: quotient
NOTES: works with floats, hates Fraction class
-----------------------------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator / (const Polynomial& rhs) const
{
	Polynomial quotient(get_degree() - rhs.get_degree());
	Polynomial working(get_degree());
	working = *this;
	coeffT lead_coeff_rhs = rhs[rhs.get_degree()];

	Polynomial new_coeff(0);
	for(int j = get_degree(); j - rhs.get_degree() >= 0; j--)
	{
		new_coeff.clear();
		new_coeff.coeff[0] = working[j]/lead_coeff_rhs;	
		new_coeff <<= j - rhs.get_degree();
		quotient += new_coeff;
		working -= (rhs * new_coeff);
	}
	Polynomial remainder;
	remainder = working;
	return quotient;
}

/*-----------------------------------------------------------------------------------------------------------
								%overload operator
PURPOSE: part of dividing polynomials
RETURNS: the remainder after division
NOTES: 
-----------------------------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator % (const Polynomial& rhs) const
{
	Polynomial quotient(get_degree() - rhs.get_degree());
	Polynomial working(get_degree());
	working = *this;
	coeffT lead_coeff_rhs = rhs[rhs.get_degree()];

	Polynomial new_coeff(0);
	for(int j = get_degree(); j - rhs.get_degree() >= 0; j--)
	{
		new_coeff.clear();
		new_coeff.coeff[0] = working[j]/lead_coeff_rhs;	
		new_coeff <<= j - rhs.get_degree();
		quotient += new_coeff;
		working -= (rhs * new_coeff);
	}
	Polynomial remainder;
	remainder = working;
	return remainder;
}

/*-----------------------------------------------------------------------------------------------------------
								-- overload operator
PURPOSE: takes a derivative of the polynomial
RETURNS: the derivative
NOTES: uses postfix
------------------------------------------------------------------------------------------------------------*/
Polynomial& Polynomial::operator -- (int) 
{
	for(int i = 0; i < get_degree(); i++)
	{
		coeff[i] = coeff[i + 1] * (i + 1);
	}
	coeff.resize(coeff.size() - 1);
	integral_only = false;
	return *this;
}

/*-----------------------------------------------------------------------------------------------------------
									++ overload operator
PURPOSE: takes a indefinite integral of the polynomial
RETURNS: the integral
NOTES: uses postfix
------------------------------------------------------------------------------------------------------------*/
Polynomial& Polynomial::operator ++ (int) 
{
	coeff.resize(coeff.size() + 1, 0);

	for(int i = get_degree(); i > 0; i--)
	{
		coeff[i] = coeff[i - 1]/i;
	}
	coeff[0] = 0;
	integral_only = true;
	return *this;
}

/*------------------------------------------------------------------------------------------------------------
									++ overload operator
PURPOSE: takes a definite integral so that it can be evaluated at limits using other function
RETURNS: polynomial reference
NOTES: same as indefinite except no +C at end uses prefix
------------------------------------------------------------------------------------------------------------*/
Polynomial& Polynomial::operator ++()
{
	coeff.resize(coeff.size() + 1, 0);

	for(int i = get_degree(); i > 0; i--)
	{
		coeff[i] = coeff[i - 1]/i;
	}
	coeff[0] = 0;
	return *this;
}

/*-----------------------------------------------------------------------------------------------------------
FUNCTION NAME: clear
PURPOSE: make the given polynomial  = to the constant 0
RETURNS: 0 as a polynomial
-----------------------------------------------------------------------------------------------------------*/
Polynomial Polynomial::clear()
{
	(*this).coeff.resize(1, 0);
	return *this;
}

/*-----------------------------------------------------------------------------------------------------------
									== overload operator
PUROSE: tests if 2 polynomials are equal
RETURNS: true/false
NOTES:
-----------------------------------------------------------------------------------------------------------*/
bool Polynomial::operator == (const Polynomial& rhs)
{
	if(get_degree() != rhs.get_degree())
		return false;
	for(int i = 0; i <= get_degree(); i++)
	{
		if(coeff[i] != rhs[i])
			return false;
	}
	return true;
}

/*-----------------------------------------------------------------------------------------------------------
									() overload operator
PURPOSE: evaluate a polynomial at a given x
RETURNS: value at that spot
NOTES:
-----------------------------------------------------------------------------------------------------------*/
coeffT Polynomial::operator () (coeffT eval)
{
	coeffT value;
	value = 0;
	for(int i = get_degree(); i >=0; i--)
		value += coeff[i]*exp(eval, i);
	return value;
}

/*-----------------------------------------------------------------------------------------------------------
									<<= overload operator
PURPOSE: shifts all coefficients to the next higher order the amount of times specified by the shift
RETURNS: result
NOTES:
-----------------------------------------------------------------------------------------------------------*/
Polynomial& Polynomial::operator <<= (int shift)
{

	coeff.insert(coeff.begin(), shift, 0.0);	
	return *this;
}

/*-----------------------------------------------------------------------------------------------------------
									>>= overload operator
PURPOSE: shifts all coefficients to the next lower order the amount of times specified by the shift
RETURNS: result
NOTES:
-----------------------------------------------------------------------------------------------------------*/
Polynomial& Polynomial::operator >>= (int shift)
{
	coeff.erase(coeff.begin(), coeff.begin()+shift);
	return *this;
}

/*-----------------------------------------------------------------------------------------------------------
FUNCTION NAME: get_degree
PURPOSE: returns degree of polynomial by checking size of coeff vector - 1
ARGUMENTS: none
RETURNS: degree of polynomial
NOTES: 
------------------------------------------------------------------------------------------------------------*/
int Polynomial::get_degree() const
{
	return coeff.size() - 1;
}

/*-----------------------------------------------------------------------------------------------------------
FUNCTION NAME: Polynomial::set_poly
PURPOSE: resizes the coefficient vector and sets the coefficients of the polynomial
ARGUMENTS: vector (of type int) reference
RETURNS: void
NOTES: sets the polynomial's coefficient vector
------------------------------------------------------------------------------------------------------------*/
void Polynomial::set_poly(vector<coeffT>& coefficients)
{
	coeff.resize(coefficients.size());
	for(int i = 0; i < coefficients.size(); i++)
	{
		coeff[i] = coefficients[i];
	}
}

/*------------------------------------------------------------------------------------------------------------
DESTRUCTOR
------------------------------------------------------------------------------------------------------------*/
Polynomial::~Polynomial()
{
	cout << " destructor \n";
}

/*------------------------------------------------------------------------------------------------------------
								>> overload operator 
PURPOSE: takes in user input for polynomial
RETURNS: ostream reference
NOTES: only a friend of the Polynomial class
------------------------------------------------------------------------------------------------------------*/
istream& operator >> (istream & lhs, Polynomial& p)
{
	vector<coeffT> c;
	int deg;
	coeffT coefficient;
	cout << "Enter degree of polynomial: " << endl;
	lhs >> deg;
	cout << "Enter " << deg + 1 << " coefficients..." << endl << endl;
	c.resize(deg + 1);
	
	for(int i = deg; i >= 0; i--)
	{
		lhs >> coefficient;
		c[i] = coefficient;
	}

	p.coeff.resize(c.size());
	for(int i = 0; i < c.size(); i++)
	{
		p.coeff[i] = c[i];
	}
	return lhs;
}


/*------------------------------------------------------------------------------------------------------------
								<< overload operator 
PURPOSE: be able to output a Polynomial object
RETURNS: ostream reference
NOTES: only a friend of the Polynomial class, only works for certain font in putty //ask alex which font to use
------------------------------------------------------------------------------------------------------------*/
ostream& operator << (ostream& lhs, const Polynomial& rhs)
{
	const char* super[10] = {
				"\u2070", "\u00B9", "\u00B2", "\u00B3", "\u2074", 
				"\u2075", "\u2076", "\u2077", "\u2078", "\u2079"};
	
	for (int i = rhs.get_degree(); i >= 0 ; i--)
	{
		if(double(rhs[i]) != 0) //if coefficient is 0 it skips the term
		{
			if (i < rhs.get_degree()) //stops it from having a + sign in front of the first term
			{
				if(double(rhs[i]) >= 0) //prints + for positive
					lhs << " +";
				else  //prints a space for - coefficients bc negative will print with value of coefficient automatically
					lhs << " ";
			}



			lhs << rhs[i]; //prints the value of the coeficient
			if (i>1) 
			{
				lhs << "x";
	
				int number = i;
				int digits = int(log10(number));
				int index;

				for(int j = digits; j >=0; j--)
				{
					index = number / pow(10, j);
					lhs << super[index];
					number-= index * pow(10, j);
				}
			}

			if(i==1)
				lhs << "x";
		}
	}
	if(rhs.integral_only)
		lhs << " +C";

	return lhs;
}

