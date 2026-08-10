#pragma once

// Data class represents a data point in 3D space with an associated label.
class Data
{
private:
	double x;
	double y;
	double z;
	int label;

public:
	Data();
	Data(double x, double y, double z, int label = 0);

	double getX() const;
	double getY() const;
	double getZ() const;
	int getLabel() const;
};