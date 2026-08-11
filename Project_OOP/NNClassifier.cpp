//--------------------------------------------------------------------------
//			NNClassifier.cpp - Implementation of the NNClassifier class
//						Author: Miguel Tarazona
//--------------------------------------------------------------------------

#include "NNClassifier.h"
#include <cmath>

using namespace std;

// Constructor that initializes the classifier with training data
NNClassifier::NNClassifier(const vector<Data>& trainingData)
{
	this->trainingData = trainingData;						// Stores the training data in the classifier
}

// Function to classify a new data point using the nearest neighbor algorithm
int NNClassifier::classify(const Data& data) const
{
	double min_distance = INFINITY;							// Initializes to a large value
	int nearest_label = -1;									// Initializes to an invalid label

	// For loop to find the nearest neighbor
	for (const Data& item : trainingData)
	{
		double distance = sqrt(pow(item.getX() - data.getX(), 2) + pow(item.getY() - data.getY(), 2) + pow(item.getZ() - data.getZ(), 2));	// Calculates the Euclidean distance between the new data point and the training data point

		if (distance < min_distance)						// If the calculated distance is less than the current minimum distance, update the minimum distance and nearest label
		{
			min_distance = distance;
			nearest_label = item.getLabel();
		}
	}
	return nearest_label;									// Returns the label of the nearest neighbor
}