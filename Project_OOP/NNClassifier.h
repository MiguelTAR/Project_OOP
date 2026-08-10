#pragma once

#include "Classifier.h"
#include "Data.h"
#include <vector>


using namespace std;

class NNClassifier : public Classifier
{
private:
	// Store the training data
	vector<Data> trainingData; 

public:
	// Default constructor
	NNClassifier();
	NNClassifier(const vector<Data>& trainingData);// loads training data into the classifier
	int classify(const Data& data) override;//nearest neighbor classification method
};

