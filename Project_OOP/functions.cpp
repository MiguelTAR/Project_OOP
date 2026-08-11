#include <iostream>
#include "functions.h"

using namespace std;

vector<Data> readLabeledData(const std::string& filename)
{
	vector<Data> data;
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "Error opening file: " << filename << endl;
		return data;
	}

	double x;
	double y;
	double z;
	int label;

	char comma1; // To read the first comma in the CSV file
	char comma2; // To read the second comma in the CSV file
	char comma3; // To read the third comma in the CSV file

	while (file >> x >> comma1 >> y >> comma2 >> z >> comma3 >> label)
	{
		if (comma1 != ',' || comma2 != ',' || comma3 != ',')
		{
			cout << "Error reading line: " << x << comma1 << y << comma2 << z << comma3 << label << endl;
			continue;						// Skip this line and continue with the next
		}
		data.push_back(Data(x, y, z, label));
	}
	return data;
}

vector<Data> readUnknownData(const std::string& filename)
{
	vector<Data> data;
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "Error opening file: " << filename << endl;
		return data;
	}

	double x;
	double y;
	double z;

	char comma1; // To read the first comma in the CSV file
	char comma2; // To read the second comma in the CSV file

	while (file >> x >> comma1 >> y >> comma2 >> z)
	{
		if (comma1 != ',' || comma2 != ',')
		{
			cout << "Error reading line: " << x << comma1 << y << comma2 << z << endl;
			continue;						// Skip this line and continue with the next
		}
		data.push_back(Data(x, y, z));
	}
	return data;
}

string getOrientation(int label)
{
	switch (label)
	{
	case 1:
		return "Face up";
	case 2:
		return "Face down";
	case 3:
		return "Portrait";
	case 4:
		return "Portrait upside down";
	case 5:
		return "Landscape left";
	case 6:
		return "Landscape right";
	default:
		return "Unknown";
	}
}