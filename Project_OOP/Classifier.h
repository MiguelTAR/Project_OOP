#pragma once


#include "data.h"

// Abstract base class for classifiers
class Classifier
{
public:
	virtual int classify(const Data& data) const = 0;	// Pure virtual function for classification
	virtual ~Classifier() = default;					// Virtual destructor
};