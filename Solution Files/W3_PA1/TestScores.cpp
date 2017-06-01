#include "TestScores.h"

//###############################################################################################
//Calculates the average of the test scores stored in an array.									#
//###############################################################################################

int TestScores::getAverages()
{
	int accumulator = 0;		//Temporary accumulator variable
	int average = 0;			//Holder variable for the average

	//Step through the array, adding each value in it to the accumulator variable
	for (int count = 0; count < ARRAY_SIZE; count++)
	{
		accumulator += array[count];
	}

	//Divide the accumulator by the number of test scores to get the average.
	//If the average is negative, throw the NegativeScore exception class.
	//If the average is over 100, throw the TooLargeScore exception class.
	//The catch blocks in main() should catch the exceptions that are thrown here.
	average = accumulator / ARRAY_SIZE;

	if (average < 0)
		throw NegativeScore(average);
	if (average > 100)
		throw TooLargeScore(average);

	return average;
}

//###############################################################################################
//Returns the value stored in an array at the location passed as a parameter to the function.	#
//###############################################################################################
int TestScores::getScore(int val)
{
	return array[val];
}