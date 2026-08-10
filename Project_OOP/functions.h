#pragma once

#include "Classifier.h"
#include "data.h"

#include <string>
#include <vector>
#include <fstream>

using namespace std;
vector<Data> readLabeledData(const std::string& filename);
vector<Data> readUnknownData(const std::string& filename);

string getOrientation(int label);

bool classifyFile(const vector<Data>& samples, const Classifier& classifier, const string& outputFilename);

double testClassifier(const vector<Data>& testingData, const Classifier& classifier);