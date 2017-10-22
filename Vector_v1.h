//first attempt at making a vector class
/* 
funcitons needed to be implemented:
-will need to use templating

*/
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])     

<template DataType>
Class Vector 
{
private:
	int size;
	DataType array[size];

public:
	Vector(int = 1);
	//void resize(int s);
	//int size(); //returns the size of the array
}