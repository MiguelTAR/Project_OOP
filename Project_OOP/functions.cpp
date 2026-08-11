//--------------------------------------------------------------------------
//			functions.cpp - Implementation of the utility functions
//						Author: Ivan Immanuel Shaji
//--------------------------------------------------------------------------

#include <iomanip>
#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

// Function to read labeled data from a CSV file and return a vector of Data objects
vector<Data> readLabeledData(const string& filename)
{
	vector<Data> data;														// Vector to store the loaded data
	ifstream file(filename);												// Opens the file for reading

	if (!file.is_open())													// Checks if the file was opened successfully
	{
		cout << "Error opening file: " << filename << endl;
		return data;
	}

	double x;																// Variables to store the x, y, z coordinates and label read from the file
	double y;
	double z;
	int label;

	char comma1;															// Variables to read the commas in the CSV file
	char comma2;
	char comma3;

	while (file >> x >> comma1 >> y >> comma2 >> z >> comma3 >> label)		// Reads a line from the file and extracts the values
	{
		if (comma1 != ',' || comma2 != ',' || comma3 != ',')				// Checks if the commas are in the expected positions
		{
			cout << "Error reading line: " << x << comma1 << y << comma2 << z << comma3 << label << endl;
			continue;														// Skips this line and continues with the next
		}
		data.push_back(Data(x, y, z, label));								// Adds the read data to the vector
	}
	return data;															// Returns the vector of Data objects
}

// Function to read unknown data from a CSV file and return a vector of Data objects
vector<Data> readUnknownData(const string& filename)
{
	vector<Data> data;														// Vector to store the loaded data
	ifstream file(filename);												// Opens the file for reading

	if (!file.is_open())													// Checks if the file was opened successfully
	{
		cout << "Error opening file: " << filename << endl;
		return data;
	}

	double x;																// Variables to store the x, y, z coordinates read from the file
	double y;
	double z;

	char comma1;															// Variables to read the commas in the CSV file
	char comma2;

	while (file >> x >> comma1 >> y >> comma2 >> z)							// Reads a line from the file and extracts the values
	{
		if (comma1 != ',' || comma2 != ',')									// Checks if the commas are in the expected positions
		{
			cout << "Error reading line: " << x << comma1 << y << comma2 << z << endl;
			continue;														// Skips this line and continues with the next
		}
		data.push_back(Data(x, y, z));
	}
	return data;															// Returns the vector of Data objects
}

// Function to get the orientation string corresponding to a label
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

// Function to classify a vector of Data objects using a given classifier and save the results to a CSV file
bool classifyFile(const vector<Data>& data, const Classifier& classifier, const string& outputFilename)
{
	ofstream outputFile(outputFilename);									// Opens the output file for writing

	if (!outputFile)														// Checks if the file was opened successfully
	{
		cout << "Could not create "<< outputFilename << endl;
		return false;
	}

	outputFile << setprecision(8);											// Sets the precision for floating-point output

	for (const Data& item : data)											// Iterates through each Data object in the input vector
	{
		int label = classifier.classify(item);								// Classifies the Data object using the provided classifier

		outputFile << item.getX() << ',' << item.getY() << ',' << item.getZ() << ',' << label << ',' << getOrientation(label) << '\n';	// Writes the x, y, z coordinates, label, and orientation to the output file
	}

	return true;															// Returns true to indicate successful classification and file writing
}

// Function to test the accuracy of a classifier on a set of testing data
double testClassifier(const vector<Data>& testingData, const Classifier& classifier)
{
	if (testingData.empty())												// Checks if the testing data is empty
	{
		return 0;
	}

	int correctPredictions = 0;												// Counter for correct predictions

	for (const Data& item : testingData)									// Iterates through each Data object in the testing data
	{
		int predictedLabel = classifier.classify(item);						// Classifies the Data object using the provided classifier

		if (predictedLabel == item.getLabel())								// Checks if the predicted label matches the actual label
		{
			correctPredictions++;											// Increments the counter for correct predictions
		}
	}

	return 100.0 * correctPredictions / testingData.size();					// Returns the accuracy as a percentage of correct predictions
}