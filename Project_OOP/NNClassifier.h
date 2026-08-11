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

// Public member functions to initialize the classifier and classify new data points
public:
	NNClassifier(const vector<Data>& trainingData);
	int classify(const Data& data) const override;
};

