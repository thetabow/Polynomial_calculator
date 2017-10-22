#include "poly_class_v2.h"

int main(int argc, char*argv[])
{
	Polynomial poly[3];

	user_poly(poly[0]);
	display_poly(poly[0]);
	user_poly(poly[1]);	
	display_poly(poly[1]);

	poly[2] = (poly[0] + poly[1]);
	cout << "The sum of the 2 polynomials is: " ;
	display_poly(poly[2]);

	poly[2] = (poly[0] - poly[1]);
	cout << "Polynomial 1 minus polynomial 2  is: ";
	display_poly(poly[2]);

	poly[2] = (poly[1] - poly[0]);
	cout << "Polynomial 2 minus polynomial 1 is: ";
	display_poly(poly[2]); 

	poly[2] = (poly[1] * poly[0]);
	cout << "The product of the 2 polynomials is: ";
	display_poly(poly[2]);

	poly[2] = poly[0]--;
	cout << "The derivative of the first polynomial is: ";
	display_poly(poly[2]);

	poly[2] = poly[1]--;
	cout << "The derivative of the second polynomial is: ";
	display_poly(poly[2]); 

	poly[2] = poly[0]++;
	cout << "The indefinite integral of the first polynomial is: ";
	display_poly(poly[2], true);

	cout << endl << "Thanks bye" << endl;

//	poly[0] + poly[1];

	return 0;	
}


//returns the vector of coefficients
void user_poly(Polynomial& p)
{
	vector<float> c;
	int deg;
	float coeff;
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



//prints a polynomial to screen
void display_poly(Polynomial& p, bool integral_only)
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