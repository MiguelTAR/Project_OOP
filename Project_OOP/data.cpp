//Data class implementation
//Miguel
#include "data.h"

// Constructor that initializes the data point with default values
Data::Data() 
{
	x = 0;
	y = 0;
	z = 0;
	label = 0;
}

// Constructor that initializes the data point with given values
Data::Data(double x, double y, double z, int label) 
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->label = label;
}

// Getter for x coordinate
double Data::getX() const
{
	return x;
}

// Getter for y coordinate
double Data::getY() const
{
	return y;
}

// Getter for z coordinate
double Data::getZ() const
{
	return z;
}

// Getter for label
int Data::getLabel() const
{
	return label;
}