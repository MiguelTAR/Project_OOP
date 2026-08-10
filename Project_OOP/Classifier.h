#pragma once


#include "Data.h"

// Abstract base class for classifiers
class Classifier
{
public:
	virtual int classify(const Data& data) = 0; // Pure virtual function for classification
	virtual ~Classifier() {} // Virtual destructor
};