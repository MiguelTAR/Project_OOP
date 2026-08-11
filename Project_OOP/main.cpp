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
	vector<Data> trainingData = readLabeledData("trainingData.txt");            // Loads training data from file

	if (trainingData.empty())                                                   // Checks if training data was loaded successfully
    {
        cout << "Training data could not be loaded." << endl;
        return 1;
    }

	NNClassifier nnClassifier(trainingData);                                    // Initializes the nearest neighbor classifier with training data
	AnotherClassifier anotherClassifier;                                        // Initializes another classifier
	KNNClassifier knnClassifier;                                                // Initializes the KNN classifier

	int classifierChoice;                                                       // Variable to store the user's choice of classifier

    cout << "PHONE ORIENTATION CLASSIFIER" << endl;
    cout << "1. Nearest Neighbour" << endl;
    cout << "2. Another Classifier" << endl;
    cout << "3. KNN Classifier" << endl;
    cout << "Choose a classifier: ";
	if (!(cin >> classifierChoice))                                             // Checks if the user input is valid
    {
        cout << "Invalid classifier choice." << endl;
        return 1;
    }

	if (classifierChoice == 1)                                                  // If the user chooses the nearest neighbor classifier
    {
		vector<Data> testingData = readLabeledData("testingData.txt");          // Loads testing data from file

		if (!testingData.empty())                                               // Checks if testing data was loaded successfully
        {
			double accuracy = testClassifier(testingData, nnClassifier);        // Tests the classifier with the testing data and calculates accuracy
			cout << "\nTesting Accuracy: " << accuracy << "%" << endl;          // Outputs the accuracy of the classifier
        }

        int inputChoice;                                                        // Variable to store the user's choice of input method

        cout << "\n1. Enter x, y and z" << endl;
        cout << "2. Enter a data filename" << endl;
        cout << "Choose an option: ";
		if (!(cin >> inputChoice))                                              // Checks if the user input is valid
        {
            cout << "Invalid option." << endl;
            return 1;
        }

		if (inputChoice == 1)                                                   // If the user chooses to enter x, y, and z directly
        {
            double x;
            double y;
            double z;

            cout << "\nEnter x y z:\n";
			if (!(cin >> x >> y >> z))                                          // Checks if the user input is valid
            {
                cout << "Invalid input. Please enter three numbers." << endl;
                return 1;
            }

			Data sample(x, y, z);                                               // Creates a Data object with the user's input

			int label = nnClassifier.classify(sample);                          // Classifies the sample using the nearest neighbor classifier

			cout << "\nLabel: " << label << endl;                               // Outputs the label of the classified sample
			cout << "Orientation: " << getOrientation(label) << endl;           // Outputs the orientation corresponding to the label
        }

		else if (inputChoice == 2)                                              // If the user chooses to enter a data filename
        {
			string filename;                                                    // Variable to store the filename

            cout << "\nEnter filename: ";
			if (!(cin >> filename))                                             // Checks if the user input is valid
            {
                cout << "Invalid filename." << endl;
                return 1;
            }

			vector<Data> unknownData = readUnknownData(filename);               // Loads unknown data from the specified file

			if (unknownData.empty())                                            // Checks if unknown data was loaded successfully
            {
                cout << "No unknown data was loaded." << endl;
                return 1;
            }

			if (classifyFile(unknownData, nnClassifier, "result.txt"))          // Classifies the unknown data and saves the results to result.txt
            {
                cout << "\nResults saved to result.txt." << endl;
            }
        }

		else                                                                    // If the user input is invalid
        {
            cout << "Invalid option." << endl;
        }
    }

	else if (classifierChoice == 2)                                             // If the user chooses another classifier
    {
		anotherClassifier.classify(Data());                                     // Classifies a sample using another classifier (currently not implemented)
    }

	else if (classifierChoice == 3)                                             // If the user chooses the KNN classifier
    {
		knnClassifier.classify(Data());                                         // Classifies a sample using the KNN classifier (currently not implemented)
    }

	else                                                                        // If the user input is invalid
    {
        cout << "Invalid classifier." << endl;
    }

	return 0;                                                                   // Returns 0 to indicate successful execution
}