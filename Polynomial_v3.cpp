#include "Polynomial_v3.h"

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
	integral_only = false;
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

/*-----------------------------------------------------------------------------------------------------------
								= operator overload
PURPOSE: assign contents of one Polynomial class object to another
RETURNS: the Polynomial assigned (just like normal = operator)
NOTES: 
------------------------------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator = (const Polynomial& p)
{
	integral_only = false;
	coeff.resize(p.coeff.size());
	for(int i = 0; i < p.coeff.size(); i++)
	{
		coeff[i] = p.coeff[i];
	}

	return p;
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
NOTES: 
-----------------------------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator / (const Polynomial& rhs) const
{
	Polynomial quotient(get_degree() - rhs.get_degree());
	Polynomial remainder();
	Polynomial working(get_degree());
	working = *this;
	coeffT scalar;

	for(int j = get_degree(); j - rhs.get_degree() >= 0; j--)
	{
		quotient.coeff[j - rhs.get_degree()] = working[j]/rhs[rhs.get_degree()];
		working = working - (rhs * quotient);
		
	}
	Polynomial Remainder = working;
	return quotient;
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
	for(int i = get_degree(); i > 0; i--)
	{
		coeff[i] = coeff[i - 1]/i;
	}
	integral_only = true;
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

/*------------------------------------------------------------------------------------------------------------
FUNCTION NAME: exp
PURPOSE: exponent function
RETURNS: a to the power of b
NOTES:
------------------------------------------------------------------------------------------------------------*/
int exp(int a, int b)
{
	int result = 1;
	while(b)
	{
		if(b&1)
			result *=a;
		b>>=1;
		a *= a;
	}
	return result;
}


/*------------------------------------------------------------------------------------------------------------
								<< overload operator 
PURPOSE: 

------------------------------------------------------------------------------------------------------------*/
ostream& operator << (ostream& lhs, Polynomial& rhs)
{
	lhs << "\n\n\t";

	for (int i = rhs.get_degree(); i >= 0 ; i--)
	{
		if (i < rhs.get_degree())
		{
			if(rhs[i] >=0) 
				lhs << " +";
			else 
				lhs << " ";
		}
		lhs << rhs[i];
		if (i>1) 
			lhs << "x^" << i;
		if(i==1)
			lhs << "x";
	}
	if(rhs.integral_only)
		lhs << " +C";
	lhs << "\n\n";
	return lhs;
}