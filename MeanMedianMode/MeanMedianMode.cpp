// MeanMedianMode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

// Prototypes for my mean,median,mode functions--------
void getMean(int myArray[]);
void getMedian(int myArray[]);
void getMode(int myArray[]);


int main()
{
	int myArray[5];//Declaring an array with 5 elements
	

	for (int i = 0; i < 5; i++)// Loop that will allow the user to fill the array with their own numbers
	{
		int number;
		cout << "Enter a number: " << endl;
		cin >> number;
		myArray[i] = number;
	}
	
	getMean(myArray);
	getMedian(myArray);     // calling my functions and passing the array into them.
	getMode(myArray);

	system("pause");
    return 0;
}
void getMean(int myArray[])	
{
	int sum = 0;// declaring interger to hold sum of all numbers in an array
	for (int i = 0; i < 5; i++)// loop that goes through each element in the array 
	{
		sum = sum + myArray[i];// adding each element to the next
	}
	cout << "The mean for your numbers is " << sum / 5;

}
void getMedian(int myArray[])
{
	int temp = 0;// temp int to hold the elements we are swapping
	int i = 0;// counter for our loops 
	int median = 0;// int that holds the median
	int length = sizeof(myArray) / sizeof(int);// getting the number of elements in the array
	for (int i = 0; i < length; i++)
	{
		if (myArray[i] > myArray[i + 1]) 
		{
			temp = myArray[i];
			myArray[i] = myArray[i + 1];
			myArray[i + 1] = temp;
		}
	}
	if (length % 2 == 0)// if the number of elements is even (in our example elements will not be even)
	{
		median = (myArray[length / 2] + myArray[length / 2] - 1) / 2;
	}
	else
		median = myArray[length / 2];// when number of elements is not even we can just divide array and get mid number

	cout << "The median is: " << median << endl;

}
void getMode(int myArray[])
{
	int number = myArray[0];
	int length = sizeof(myArray) / sizeof(int);
	int mode = number;
	int count = 1;
	int countMode = 1;

	for (int i = 1; i<length; i++)
	{
		if (myArray[i] == number)
		{ // count occurrences of the current number
			++count;
		}
		else
		{ // now this is a different number
			if (count > countMode)
			{
				countMode = count; // mode is the biggest ocurrences
				mode = number;
			}
			count = 1; // reset count for the new number
			number = myArray[i];
		}
	}

	cout << "mode : " << mode << endl;

}
