//--------------------------------------------------------------------------
//	AnotherClassifier.h - Declaration of the AnotherClassifier class
//			                Author: Zuwair Khilji
//--------------------------------------------------------------------------

#pragma once
#include "Classifier.h"

// AnotherClassifier class implements another classification algorithm
class AnotherClassifier : public Classifier
{
public:
    int classify(const Data& data) const override;
};