#include "Polynomial_v1.h"

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
}

/*-----------------------------------------------------------------------------------------------------------
FUNCTION NAME: Polynomial::set_poly
PURPOSE: resizes the coefficient vector and sets the coefficients of the polynomial
ARGUMENTS: vector (of type int) reference
RETURNS: void
NOTES: sets the polynomial's coefficient vector
------------------------------------------------------------------------------------------------------------*/
void Polynomial::set_poly(vector<int>& coefficients)
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
int Polynomial::operator[] (int deg) const
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
Polynomial Polynomial::operator + (const Polynomial& rhs)
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
Polynomial Polynomial::operator - (const Polynomial& rhs)
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
								-- overload operator
PURPOSE: takes a derivative of the polynomial
RETURNS: the derivative
NOTES: uses postfix
------------------------------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator -- (int) 
{
	Polynomial derivative(get_degree() - 1);

	for(int i = 0; i < get_degree(); i++)
	{
		derivative.coeff[i] = coeff[i + 1] * (i + 1);
	}
	return derivative;
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




 /*   dont need this anymore because of [] operator function
int Polynomial::get_coeff(int index) const
{
	return coeff[index];
}*/

