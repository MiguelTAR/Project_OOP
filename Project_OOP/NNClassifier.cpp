//--------------------------------------------------------------------------
//			NNClassifier.cpp - Implementation of the NNClassifier class
//						Author: Miguel Tarazona
//--------------------------------------------------------------------------

#include "NNClassifier.h"
#include <cmath>

using namespace std;

NNClassifier::NNClassifier(const vector<Data>& trainingData) 
{
	// Constructor that initializes the classifier with training data
	this->trainingData = trainingData;
}

int NNClassifier::classify(const Data& data) const
{
	double min_distance = INFINITY; // Initialize to a large value
	int nearest_label = -1;			// Initialize to an invalid label

	// For loop to find the nearest neighbor
	for (const Data& item : trainingData) 
	{
		double distance = sqrt(pow(item.getX() - data.getX(), 2) + pow(item.getY() - data.getY(), 2) + pow(item.getZ() - data.getZ(), 2));
		if (distance < min_distance) 
		{
			min_distance = distance;
			nearest_label = item.getLabel();
		}
	}
	return nearest_label;
}