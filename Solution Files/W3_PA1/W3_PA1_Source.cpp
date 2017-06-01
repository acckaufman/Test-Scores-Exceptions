//This program creates a class called TestScores, which includes exception classes named NegativeScore and TooLargeScore.
//It demonstrates the use of exception classes to throw and catch exceptions and display an error message in a program.
#include <iostream>
#include "TestScores.h"
using namespace std;

int main()
{
	cout << "This program creates arrays of 10 test scores each, and demonstrates" << endl
		<< "exceptions that are thrown when errors occur" << endl;
	cout << "No negative test scores, or scores over 100, are allowed." << endl << endl;
	
	cout << "##############################################################################" << endl;
	cout << "Part 1: Negative test score, valid average." << endl;
	cout << "##############################################################################" << endl << endl;

	cout << "Let's see what happens when we create an instance of our TestScores " << endl
		<< "class, passing it an array of 10 scores which includes a negative value." << endl << endl;

	int includesNegativeValue[ARRAY_SIZE] = { 100, 98, -88, 99, 85, 76, 92, 94, 89, 81 };		//Initialize the array of 10 test scores
	TestScores negativeValue(includesNegativeValue);		//Exception will be thrown as this instance of TestScores is constructed.

	cout << endl << "As expected, the constructor finds the negative value" << endl
		<< "and throws the NegativeScore exception." << endl << endl;

	system("pause");

	cout << endl << "Let's tell the program to try to calculate the average of the values" << endl
		<< "stored in this first instance of TestScores, using a try/catch statement." << endl << endl;

	try
	{
		cout << "The average of the test scores is " << negativeValue.getAverages() << "." << endl;

	}
	catch (TestScores::NegativeScore e)
	{
		cout << "Error: " << e.getValue() << " is an invalid value for a test score average." << endl;
	}
	catch (TestScores::TooLargeScore e)
	{
		cout << "Error: " << e.getValue() << " is an invalid value for a test score average." << endl;
	}

	cout << endl << "No exception is thrown, because although a negative value was" << endl
		<< "contained in the array, the average is still between 0 and 100." << endl << endl;

	system("pause");

	cout << endl;
	cout << "##############################################################################" << endl;
	cout << "Part 2: Too large test score, valid average." << endl;
	cout << "##############################################################################" << endl << endl;

	cout << "Now, let's create another instance of TestScores, passing it" << endl
		<< "an array containing a value over 100." << endl << endl;

	int includesValueOverMax[ARRAY_SIZE] = { 100, 54, 88, 99, 85, 76, 192, 94, 89, 81 };		//Initialize the array of 10 test scores
	TestScores overMax(includesValueOverMax);				//Exception will be thrown as this instance is constructed.

	cout << endl << "As expected, the constructor finds the value over 100" << endl
		<< "and throws the TooLargeScore exception." << endl << endl;

	system("pause");

	cout << endl << "Let's tell the program to try to calculate the average of the values" << endl
		<< "stored in this second instance of TestScores, using a try/catch statement." << endl << endl;

	try
	{
		cout << "The average of the test scores is " << overMax.getAverages() << "." << endl;

	}
	catch (TestScores::NegativeScore e)
	{
		cout << "Error: " << e.getValue() << " is an invalid value for a test score average." << endl;
	}
	catch (TestScores::TooLargeScore e)
	{
		cout << "Error: " << e.getValue() << " is an invalid value for a test score average." << endl;
	}

	cout << endl << "No exception is thrown, because although a value over 100 was" << endl
		<< "contained in the array, the average is still between 0 and 100." << endl << endl;

	system("pause");

	cout << endl;
	cout << "##############################################################################" << endl;
	cout << "Part 3: Valid test scores, valid average." << endl;
	cout << "##############################################################################" << endl << endl;

	cout << "Let's make sure the program doesn't throw any exceptions if" << endl
		<< "an array of valid scores between 0 and 100 is passed to a TestScores object." << endl << endl;
	cout << "Creating the third instance of TestScores now...";

	int validScores[ARRAY_SIZE] = { 100, 98, 88, 99, 85, 76, 92, 94, 89, 81 };			//Initialize the array of 10 test scores
	TestScores valid(validScores);				//This instance will be constructed with no errors.

	cout << endl << "Done." << endl << endl;

	system("pause");

	cout << endl << "We should also check that the average can be calculated successfully," << endl
		<< "again using the try/catch statement:" << endl << endl;

	try
	{
		cout << "The average of the test scores is " << valid.getAverages() << "." << endl;

	}
	catch (TestScores::NegativeScore e)
	{
		cout << "Error: " << e.getValue() << " is an invalid value for a test score average." << endl;
	}
	catch (TestScores::TooLargeScore e)
	{
		cout << "Error: " << e.getValue() << " is an invalid value for a test score average." << endl;
	}

	cout << endl << "As expected, there were no errors." << endl << endl;

	system("pause");

	cout << endl;
	cout << "##############################################################################" << endl;
	cout << "Part 4: Negative test score(s), negative average." << endl;
	cout << "##############################################################################" << endl << endl;

	cout << "Finally, we need to be sure that exceptions will be thrown by main()" << endl
		<< "if the average comes out negative or over 100." << endl << endl;

	cout << "Let's create a TestScores object, constructed based on an array of test" << endl
		<< "scores with a negative average." << endl;
	cout << "The first exception should be thrown while the TestScores object is created," << endl
		<< "due to the negative value in the array." << endl << endl;

	int negAverage[ARRAY_SIZE] = { -500, 45, 68, 34, 65, 43, 98, 14, 23, 11 };
	TestScores neg(negAverage);			//Exception should be thrown as this instance is created, because of the negative value in the array.

	cout << endl;
	system("pause");

	cout << endl << "An exception should also be thrown when we try to calculate the average of" << endl
		<< "these values, because it is negative:" << endl << endl;

	try
	{
		cout << "The average of the test scores is " << neg.getAverages() << "." << endl;

	}
	catch (TestScores::NegativeScore e)
	{
		cout << "Error: " << e.getValue() << " is an invalid value for a test score average." << endl;
	}
	catch (TestScores::TooLargeScore e)
	{
		cout << "Error: " << e.getValue() << " is an invalid value for a test score average." << endl;
	}

	cout << endl << "As we can see, the NegativeScore exception class was thrown." << endl << endl;

	system("pause");

	cout << endl;
	cout << "##############################################################################" << endl;
	cout << "Part 5: Too large test score, too large average." << endl;
	cout << "##############################################################################" << endl << endl;

	cout << "In this last case, we will check that an exception will be thrown by main()" << endl
		<< "if the average is over 100." << endl << endl;

	cout << "Let's create a TestScores object, constructed based on an array of test" << endl
		<< "scores with an average over 100." << endl;
	cout << "The first exception should be thrown while the TestScores object is created," << endl
		<< "due to the value over 100 in the array." << endl << endl;

	int bigAverage[ARRAY_SIZE] = { 500, 95, 88, 64, 65, 83, 98, 84, 73, 91 };
	TestScores big(bigAverage);			//Exception should be thrown as this instance is created, because of the value over 100 in the array.

	cout << endl;
	system("pause");

	cout << endl << "An exception should also be thrown when we try to calculate the average of" << endl
		<< "these values, because it is over 100:" << endl << endl;

	try
	{
		cout << "The average of the test scores is " << big.getAverages() << "." << endl;

	}
	catch (TestScores::NegativeScore e)
	{
		cout << "Error: " << e.getValue() << " is an invalid value for a test score average." << endl;
	}
	catch (TestScores::TooLargeScore e)
	{
		cout << "Error: " << e.getValue() << " is an invalid value for a test score average." << endl;
	}

	cout << endl << "The TooLargeScore exception class should have been thrown." << endl << endl;

	cout << "That's the end of the program!" << endl << endl;

	system("pause");
	return 0;
}