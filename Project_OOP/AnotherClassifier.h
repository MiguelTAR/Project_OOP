#pragma once
#include "Classifier.h"

class AnotherClassifier : public Classifier
{
public:
    int classify(const Data& data) const override;
};