//--------------------------------------------------------------------------
//					data.h - Declaration of the Data class
//							Author: Miguel Tarazona
//--------------------------------------------------------------------------

#pragma once

// Data class represents a data point in 3D space with an associated label.
class Data
{
// Private member variables to store the x, y, z coordinates and the label of the data point.
private:
	double x;
	double y;
	double z;
	int label;

// Public member functions to access and manipulate the data point.
public:
	Data();
	Data(double x, double y, double z, int label = 0);

	double getX() const;
	double getY() const;
	double getZ() const;
	int getLabel() const;
};