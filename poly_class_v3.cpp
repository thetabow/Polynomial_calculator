#include "poly_class_v3.h"

int main(int argc, char*argv[])
{

	//cout << "start of shenanigans: " << endl << endl;
	Polynomial poly[3];
	//cout << "post declaring i have 3 polynomials" << endl << endl;

	user_poly(poly[0]);
	//cin >> poly[0];
	cout << endl;
	cout << poly[0];
	user_poly(poly[1]);
	cout << endl;
	//cin >> poly[1];	
	cout << poly[1];

/*	poly[2] = (poly[0] + poly[1]);
	cout << "The sum of the 2 polynomials is: \n\t" ;
	cout << poly[2] << endl;

	poly[2] = (poly[0] - poly[1]);
	cout << "Polynomial 1 minus polynomial 2  is: \n\t";
	cout << poly[2] << endl;

	poly[2] = (poly[1] - poly[0]);
	cout << "Polynomial 2 minus polynomial 1 is: \n\t";
	cout << poly[2] << endl; 

	poly[2] = (poly[1] * poly[0]);
	cout << "The product of the 2 polynomials is: \n\t";
	cout << poly[2] << endl;

	poly[2] = poly[0] * 5;
	cout << "The scalar product of the first polynomial and 5 is: \n\t";
	cout << poly[2] << endl;

	poly[2] = poly[0] / poly[1];
	cout << "The quotient of polynomial 1 divided by polynomial 2 is: \n\t";
	cout << poly[2] << endl;

	poly[2] = poly[0] % poly[1];
	cout << "With remainder: \n\t";
	cout << poly[2] << endl;

	poly[2] = poly[0];
	cout << "The derivative of the first polynomial is: \n\t";
	cout << poly[2]-- << endl;

	poly[2] = poly[1];
	cout << "The derivative of the second polynomial is: \n\t";
	cout << poly[2]-- << endl; 

	poly[2] = poly[0];
	cout << "The indefinite integral of the first polynomial is: \n\t";
	cout << poly[2]++ << endl;
*/
	poly[2] = poly[0];
	cout << "The indefinite integral of the first polynomial is: \n\t";
	cout << poly[2]++ << endl;

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
