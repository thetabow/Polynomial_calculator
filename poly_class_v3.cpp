#include "poly_class_v3.h"

int main(int argc, char*argv[])
{
	Polynomial poly[3];
	coeffT num1, num2;

	user_poly(poly[0]);
	//cin >> poly[0];
	cout << poly[0];
	cout << endl;

//	user_poly(poly[1]);
	//cin >> poly[1];	
//	cout << poly[1];
//	cout << endl;

//	if(poly[0] == poly[1])
//		cout << "Polynomials are the equivalent!" << endl;
//	else
//		cout << "Polynomials are not equivalent!" << endl;





	poly[2] = (poly[0] + poly[1]);
	cout << "The sum of the 2 polynomials is: \n\t" ;
	cout << poly[2] << endl << endl;

	poly[2] = (poly[0] - poly[1]);
	cout << "Polynomial 1 minus polynomial 2  is: \n\t";
	cout << poly[2] << endl << endl;

	poly[2] = (poly[1] - poly[0]);
	cout << "Polynomial 2 minus polynomial 1 is: \n\t";
	cout << poly[2] << endl << endl; 

	poly[2] = (poly[1] * poly[0]);
	cout << "The product of the 2 polynomials is: \n\t";
	cout << poly[2] << endl << endl;

	poly[2] = poly[0] * 5;
	cout << "The scalar product of the first polynomial and 5 is: \n\t";
	cout << poly[2] << endl << endl;

	cout << "Where to evaluate polynomial 1? " ;
	cin >> num1;
	cout << endl;
	cout << poly[0](num1);

	cout << "Where to evaluate polynomial 2? " ;
	cin >> num2;
	cout << endl;
	cout << poly[1](num2);

	poly[2] = poly[0] / poly[1];
	cout << "The quotient of polynomial 1 divided by polynomial 2 is: \n\t";
	cout << poly[2] << endl << endl;

	poly[2] = poly[0] % poly[1];
	cout << "With remainder: \n\t";
	cout << poly[2] << endl << endl;

	poly[2] = poly[0];
	cout << "The derivative of " << poly[2] << " is: \n\t";
	cout << poly[2]-- << endl << endl;

	poly[2] = poly[1];
	cout << "The derivative of " << poly[2] << " is: \n\t";
	cout << poly[2]-- << endl << endl; 

	poly[2] = poly[0];
	cout << "Integrating " << poly[2] << endl;
	cout << "The indefinite integral of the first polynomial is: \n\t";
	cout << poly[2]++ << endl << endl;
	cout << "Enter lower bound for integral : ";
	cin >> num2;
	cout << "Enter upper bound for integral: ";
	cin >> num1;
	poly[2] = poly[0];
	++poly[2];
	cout << (poly[2](num1) - (poly[2])(num2) );
	cout << endl << endl;


	poly[2] = poly[1];
	cout << "Integrating " << poly[2] << endl;
	cout << "The indefinite integral of the second polynomial is: \n\t";
	cout << poly[2]++ << endl << endl;
	cout << "Enter lower bound for integral : ";
	cin >> num2;
	cout << "Enter upper bound for integral: ";
	cin >> num1;
	poly[2] = poly[1];
	++poly[2];
	cout << (poly[2](num1) - (poly[2])(num2) );
	cout << endl << endl;

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
