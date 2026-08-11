#pragma once
#include "Classifier.h"

class KNNClassifier : public Classifier
{
public:
    int classify(const Data& data) const override;
};