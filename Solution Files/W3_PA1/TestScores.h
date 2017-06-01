#pragma once
#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

//###############################################################################################
//This class has a private member array to hold a series of test scores.  It also contains		#
//the definitions of the NegativeScore and TooLargeScore exceptions, as public members.			#
//###############################################################################################
class TestScores
{
private:
	int array[ARRAY_SIZE];
public:
	//Exception class for a negative score
	class NegativeScore
	{
	private:
		int value;				//Holder for the negative value in the array
	public:
		NegativeScore(int val)	//Constructor to set the value passed to the NegativeScore class when the exception is thrown
		{
			value = val;
		}

		int getValue() const
		{
			return value;		//Return the invalid negative value
		}
	};

	//Exception class for a score that is over 100
	class TooLargeScore
	{
	private:
		int value;				//Holder for the value in the array that is too large
	public:
		TooLargeScore(int val)	//Constructor to set the value passed to the TooLargeScore class when the exception is thrown
		{
			value = val;
		}

		int getValue() const
		{
			return value;		//Return the score that is too large
		}
	};

	//###############################################################################################
	//Default constructor.  Initializes all of the member array's elements to 0.					#
	//###############################################################################################
	TestScores()
	{
		for (int count = 0; count < ARRAY_SIZE; count++)
			array[count] = 0;
	}

	//###############################################################################################
	//Constructor that accepts an array of ints as a parameter, and copies the values into the		#
	//class instance's member array.																#
	//This constructor throws an exception if any value found in the array is either negative		#
	//or over 100.																					#
	//###############################################################################################
	TestScores(int copy[])
	{
		//Copy all the values from the parameter array into the TestScores member variable array.
		//We want these values to be copied into the TestScores member array, regardless of what they are,
		//so that we can still calculate the average of the values later.
		for (int index = 0; index < ARRAY_SIZE; index++)
			array[index] = copy[index];

		//Now, step through the array, checking each value for a negative score or score over 100.
		//If a negative value is encountered, throw the NegativeScore exception class.
		//If a value over 100 is encountered, throw the TooLargeScore exception class.
		try
		{
			for (int count = 0; count < ARRAY_SIZE; count++)
			{
				if (copy[count] < 0)
					throw NegativeScore(copy[count]);			//However, if the value was negative, send the user an error message.
				if (copy[count] > 100)
					throw TooLargeScore(copy[count]);			//In the same way, if the value was too large, send the user an error message.
			}
		}
		catch (NegativeScore f)
		{
			cout << "Error: A negative value of " << f.getValue() << " was encountered." << endl;
		}
		catch (TooLargeScore f)
		{
			cout << "Error: A value of " << f.getValue() << ", which is over the max of 100, was encountered." << endl;
		}
	}

	//###############################################################################################
	//Returns the average of the test scores in an array - see TestScores.cpp for definition.		#
	//###############################################################################################
	int getAverages();

	//###############################################################################################
	//Returns the value stored in the array at location specified in the parameter passed to		#
	//the function - see TestScores.cpp for definition.												#
	//###############################################################################################
	int getScore(int);

	//###############################################################################################
	//Destructor.																					#
	//###############################################################################################
	~TestScores()
	{

	}
};

