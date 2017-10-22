/* -----------------------------------------------------------------------------------------------------------
FILE NAME: poly_class_v2.h

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
Z


------------------------------------------------------------------------------------------------------------*/

#include "Polynomial_v2.h"
#include <iostream>
#include <vector>

void display_poly(Polynomial& p, bool integral_only = false);
void user_poly(Polynomial& p);

//make exponent function
