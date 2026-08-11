//--------------------------------------------------------------------------
//  main.cpp - Entry point for the Phone Orientation Classifier program
//                      Author: Ivan Immanuel Shaji
//--------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>

#include "AnotherClassifier.h"
#include "KNNClassifier.h"
#include "NNClassifier.h"
#include "functions.h"

using namespace std;

int main()
{
    vector<Data> trainingData = readLabeledData("trainingData.txt");

    if (trainingData.empty())
    {
        cout << "Training data could not be loaded." << endl;
        return 1;
    }

    NNClassifier nnClassifier(trainingData);
    AnotherClassifier anotherClassifier;
    KNNClassifier knnClassifier;

    int classifierChoice;

    cout << "PHONE ORIENTATION CLASSIFIER" << endl;
    cout << "1. Nearest Neighbour" << endl;
    cout << "2. Another Classifier" << endl;
    cout << "3. KNN Classifier" << endl;
    cout << "Choose a classifier: ";
    cin >> classifierChoice;

    if (classifierChoice == 1)
    {
        vector<Data> testingData = readLabeledData("testingData.txt");

        if (!testingData.empty())
        {
            double accuracy = testClassifier(testingData, nnClassifier);

            cout << "\nTesting Accuracy: " << accuracy << "%" << endl;
        }

        int inputChoice;

        cout << "\n1. Enter x, y and z" << endl;
        cout << "2. Enter a data filename" << endl;
        cout << "Choose an option: ";
        cin >> inputChoice;

        if (inputChoice == 1)
        {
            double x;
            double y;
            double z;

            cout << "\nEnter x y z:\n";
            cin >> x >> y >> z;

            Data sample(x, y, z);

            int label = nnClassifier.classify(sample);

            cout << "\nLabel: " << label << endl;
            cout << "Orientation: " << getOrientation(label) << endl;
        }

        else if (inputChoice == 2)
        {
            string filename;

            cout << "\nEnter filename: ";
            cin >> filename;

            vector<Data> unknownData = readUnknownData(filename);

            if (unknownData.empty())
            {
                cout << "No unknown data was loaded." << endl;
                return 1;
            }

            if (classifyFile(unknownData, nnClassifier, "result.txt"))
            {
                cout << "\nResults saved to result.txt." << endl;
            }
        }

        else
        {
            cout << "Invalid option." << endl;
        }
    }

    else if (classifierChoice == 2)
    {
        anotherClassifier.classify(Data());
    }

    else if (classifierChoice == 3)
    {
        knnClassifier.classify(Data());
    }

    else
    {
        cout << "Invalid classifier." << endl;
    }

    return 0;
}