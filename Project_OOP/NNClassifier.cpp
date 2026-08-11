// Nearest neighbor classification method
// Miguel
#include "NNClassifier.h"
#include <cmath>


NNClassifier::NNClassifier() {
	// Default constructor
}


NNClassifier::NNClassifier(const vector<Data>& trainingData) {
	// Constructor that initializes the classifier with training data
	this->trainingData = trainingData;
}

int NNClassifier::classify(const Data& data) {

	double mini_distance = 9999999; // Initialize to a large value
	int nearest_label = -1; // Initialize to an invalid label


	// For loop to find the nearest neighbor
	for (auto item : trainingData) {
		double distance = sqrt(
			pow(item.x - data.x, 2) +
			pow(item.y - data.y, 2) +
			pow(item.z - data.z, 2)
		);

		// Update the nearest label if a closer neighbor is found
		if (distance < mini_distance) {
			mini_distance = distance;
			nearest_label = item.label;
		}
	}

	return nearest_label;
}