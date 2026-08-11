//--------------------------------------------------------------------------
//	  Classifier.h - Declaration of the Classifier abstract base class
//                      Author: Ivan Immanuel Shaji
//--------------------------------------------------------------------------

#pragma once
#include "data.h"

// Classifier is an abstract base class that defines the interface for classification algorithms.
class Classifier
{
public:
	virtual int classify(const Data& data) const = 0;	// Pure virtual function for classification
	virtual ~Classifier() = default;					// Virtual destructor
};