
/* -----------------------------------------------------------------------------------------------------------
FILE NAME: poly_class_v3.h

DESCRITION: header file for Polynomial project

PURPOSE: includes Polynomial class header file into poly_class_v2.cpp

USAGE: no parameters needed

EXAMPLES: ./Polynomial

PARAMETERS: none

EXIT CODES: 0 for success, otherwise means it failed

COMPILATION: use command 'make' to compile most updated version

NOTES: 

MODIFICATION HISTORY:

Author:				Date: 			Version:
--------------------------------------------------------------------------------------------------------------
Zuriah Quinton		10-16-17		slow start to setting up the class and various files
Zuriah Quinton		10-20-17		finalize work on v1: input output, add and subtract works, derivative
									functional, display works, still using vector class 
Zuriah Quinton		10-21-17		long division, scalar multiplication, integration, polynomial 
									multiplication all implemented
Zuriah Quinton		10-22-17		replaced display_poly with << operator
Zuriah Quinton		10-23-17		realized long division is broken, added +=, -=, <<=, >>= to facilitate
									long division process...fixed long division


------------------------------------------------------------------------------------------------------------*/

#include "Polynomial_v3.h"
#include <iostream>
#include <vector>

void user_poly(Polynomial& p);


//make exponent function
