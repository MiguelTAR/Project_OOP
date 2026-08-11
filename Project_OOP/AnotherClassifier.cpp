//--------------------------------------------------------------------------
//	AnotherClassifier.cpp - Implementation of the AnotherClassifier class
//			                Author: Zuwair Khilji
//--------------------------------------------------------------------------

#include "AnotherClassifier.h"
#include <iostream>

using namespace std;

// Function to classify a new data point using another classification algorithm
int AnotherClassifier::classify(const Data&) const
{
    cout << "\nAnotherClassifier::classify()" << endl;
	cout << "\nAnotherClassifier has not been implemented yet." << endl;
    return -1;       // Returns -1 to indicate that the classification is not implemented
}