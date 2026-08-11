//--------------------------------------------------------------------------
//			NNClassifier.h - Declaration of the NNClassifier class
//						Author: Miguel Tarazona
//--------------------------------------------------------------------------

#pragma once

#include "Classifier.h"
#include <vector>

using namespace std;

// NNClassifier class implements the nearest neighbor classification algorithm
class NNClassifier : public Classifier
{
// Private member variable to store the training data
private:
	vector<Data> trainingData; 

// Private member function to calculate the Euclidean distance between two Data points
public:
	NNClassifier(const vector<Data>& trainingData);
	int classify(const Data& data) const override;
};

