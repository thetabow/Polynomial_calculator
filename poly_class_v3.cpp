#include "poly_class_v3.h"

int main(int argc, char*argv[])
{
	Polynomial poly[3];

	user_poly(poly[0]);
	cout << poly[0];
	user_poly(poly[1]);	
	cout << poly[1];

	poly[2] = (poly[0] + poly[1]);
	cout << "The sum of the 2 polynomials is: " ;
	cout << poly[2];

	poly[2] = (poly[0] - poly[1]);
	cout << "Polynomial 1 minus polynomial 2  is: ";
	cout << poly[2];

	poly[2] = (poly[1] - poly[0]);
	cout << "Polynomial 2 minus polynomial 1 is: ";
	cout << poly[2]; 

	poly[2] = (poly[1] * poly[0]);
	cout << "The product of the 2 polynomials is: ";
	cout << poly[2];

	poly[2] = poly[0] * 5;
	cout << "The scalar product of the first polynomial and 5 is: ";
	cout << poly[2];

	poly[2] = poly[0] / poly[1];
	cout << "The quotient of polynomial 1 divided by polynomial 2 is: ";
	cout << poly[2];

	poly[2] = poly[0];
	cout << "The derivative of the first polynomial is: ";
	cout << poly[2]--;

	poly[2] = poly[1];
	cout << "The derivative of the second polynomial is: ";
	cout << poly[2]--; 

	poly[2] = poly[0];
	cout << "The indefinite integral of the first polynomial is: ";
	cout << poly[2]++;

	poly[2] = poly[1];
	cout << "The indefinite integral of the second polynomial is: ";
	cout << poly[2]++;

	cout << endl << "Thanks bye" << endl;
	return 0;	
}


//returns the vector of coefficients
void user_poly(Polynomial& p)
{
	vector<coeffT> c;
	int deg;
	coeffT coeff;
	cout << "Enter degree of polynomial: " << endl;
	cin >> deg;
	cout << "Enter " << deg + 1 << " coefficients..." << endl << endl;
	c.resize(deg + 1);
	
	for(int i = deg; i >= 0; i--)
	{
		cin >> coeff;
		c[i] = coeff;
	}
	p.set_poly(c);
}



/*prints a polynomial to screen
void cout << Polynomial& p, bool integral_only)
{
	cout << "\n\n\t";

	for (int i = p.get_degree(); i >= 0 ; i--)
	{
		if (i < p.get_degree())
		{
			if(p[i] >=0) 
				cout << " +";
			else 
				cout << " ";
		}
		cout << p[i];
		if (i>1) 
			cout << "x^" << i;
		if(i==1)
			cout << "x";
	}
	if(integral_only)
		cout << " +C";
	cout << "\n\n";
}

*/