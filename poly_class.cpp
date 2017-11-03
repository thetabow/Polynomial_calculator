#include "poly_class.h"
#include "Vector.h"

int main(int argc, char*argv[])
{
	Polynomial poly[3];
	coeffT upper, lower;

	cin >> poly[0];
	cout << "\t" << poly[0] << endl;

	cin >> poly[1];	
	cout << "\t" << poly[1] << endl;

	if(poly[0] == poly[1])
		cout << "The polynomials are the equivalent!" << endl << endl;
	else
		cout << "The polynomials are not equivalent!" << endl << endl;


	cout << "(" << poly[0] << ") + (" << poly[1] << ") \n\t=  " << poly[0] + poly[1] << endl << endl;
	cout << "(" << poly[0] << ") - (" << poly[1] << ") \n\t=  " << poly[0] - poly[1] << endl << endl;
	cout << "(" << poly[0] << ") * (" << poly[1] << ") \n\t=  " << poly[0] * poly[1] << endl << endl;

	if(poly[0].get_degree() >= poly[1].get_degree())
		cout << "(" << poly[0] << ") / (" << poly[1] << ") \n\t=  " << poly[0] / poly[1] << "\t Remainder: " << poly[0] % poly[1] << endl << endl;
	else
		cout << "(" << poly[1] << ") / (" << poly[0] << ") \n\t=  " << poly[1] / poly[0] << "\t Remainder: " << poly[1] % poly[0] << endl << endl;

	cout << "f(x) = " << poly[0] << endl << "x = ";
	cin >> upper;
	cout << "f(" << upper << ") = " << poly[0](upper) << endl << endl;

	cout << "g(x) = " << poly[1] << endl << "x = ";
	cin >> lower;
	cout << "g(" << lower << ") = " << poly[1](lower) << endl << endl;


	poly[2] = poly[0];
	cout << "The derivative of " << poly[2] << " is: \n\t";
	cout << poly[2]-- << endl << endl;

	poly[2] = poly[1];
	cout << "The derivative of " << poly[2] << " is: \n\t";
	cout << poly[2]-- << endl << endl; 
	

	poly[2] = poly[0];
	cout << "Integrating " << poly[2] << endl;
	cout << "The indefinite integral is: \n\t";
	cout << poly[2]++ << endl << endl;
	cout << "Enter lower bound for definite integral : ";
	cin >> lower;
	cout << "Enter upper bound for definite integral: ";
	cin >> upper;
	poly[2] = poly[0];
	++poly[2];
	if(lower <= upper)
		cout << (poly[2](upper) - (poly[2])(lower) );
	else
		cout << (poly[2](lower) - (poly[2])(upper) );
	cout << endl << endl;

	poly[2] = poly[1];
	cout << "Integrating " << poly[2] << endl;
	cout << "The indefinite integral is: \n\t";
	cout << poly[2]++ << endl << endl;
	cout << "Enter lower bound for definite integral : ";
	cin >> lower;
	cout << "Enter upper bound for definite integral: ";
	cin >> upper;
	poly[2] = poly[1];
	++poly[2];
	if(lower <= upper)
		cout << (poly[2](upper) - poly[2](lower) );
	else
		cout << (poly[2](lower) - (poly[2])(upper) );
	cout << endl << endl;



	cout << endl << "Thanks bye" << endl;
	return 0;	
}
