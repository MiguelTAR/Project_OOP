//--------------------------------------------------------------------------
//	AnotherClassifier.h - Declaration of the AnotherClassifier class
//			                Author: Zuwair Khilji
//--------------------------------------------------------------------------

#pragma once
#include "Classifier.h"

// AnotherClassifier class implements the placeholder for another classification algorithm
class AnotherClassifier : public Classifier
{
public:
    int classify(const Data& data) const override;
};