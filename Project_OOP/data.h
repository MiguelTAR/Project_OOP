#pragma once

// Data class represents a data point in 3D space with an label.
class Data
{
public:
	double x;
	double y;
	double z;
	int label;

	Data();
	Data(double x, double y, double z, int label = 0);


};