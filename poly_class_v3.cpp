#include "poly_class_v3.h"

int main(int argc, char*argv[])
{
	Polynomial poly[3];
	coeffT num1, num2;

	//user_poly(poly[0]);
	cin >> poly[0];
	cout << poly[0] << endl;

//	user_poly(poly[1]);
	cin >> poly[1];	
	cout << poly[1] << endl;

	if(poly[0] == poly[1])
		cout << "The polynomials are the equivalent!" << endl;
	else
		cout << "The polynomials are not equivalent!" << endl;


	cout << "(" << poly[0] << ") + (" << poly[1] << ") \n\t=  " << poly[0] + poly[1] << endl << endl;
	cout << "(" << poly[0] << ") - (" << poly[1] << ") \n\t=  " << poly[0] - poly[1] << endl << endl;
	cout << "(" << poly[0] << ") * (" << poly[1] << ") \n\t=  " << poly[0] * poly[1] << endl << endl;
	cout << "(" << poly[0] << ") / (" << poly[1] << ") \n\t=  " << poly[0] / poly[1] << "\t Remainder: " << poly[0] % poly[1] << endl << endl;

	cout << "f(x) = " << poly[0] << endl << "x = ";
	cin >> num1;
	cout << "f(" << num1 << ") = " << poly[0](num1) << endl << endl;

	cout << "g(x) = " << poly[1] << endl << "x = ";
	cin >> num2;
	cout << "g(" << num2 << ") = " << poly[1](num2) << endl << endl;


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
