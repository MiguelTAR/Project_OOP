//--------------------------------------------------------------------------
//			KNNClassifier.h - Declaration of the KNNClassifier class
//						    Author: Zuwair Khilji
//--------------------------------------------------------------------------

#pragma once
#include "Classifier.h"

// KNNClassifier class implements the K-Nearest Neighbors classification algorithm
class KNNClassifier : public Classifier
{
public:
    int classify(const Data& data) const override;
};