#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	//variables
	int radius = 0;
	int length = 0;

	bool Invalid_input = false;

	//set the max number of digits to 2
	cout << fixed << setprecision(2);

	//variables for arrays
	constexpr int SIZE = 150; //if to low, change.

	int seqX[SIZE] = { 0 };
	int valueX = 0;
	int seqY[SIZE] = { 0 };
	int valueY = 0;

	double distance[SIZE] = { 0 };

	int howMany = 0;

	// STEP 1
	do
	{
		cout << "Enter radius: ";
		cin >> radius;

		cout << "Enter length: ";
		cin >> length;

		Invalid_input = (radius < 5 || length < 5);

		if (Invalid_input)
		{
			cout << "Invalid input, try again!" << endl;
		}
	} while (Invalid_input);

	// STEP 2
	cout << "Enter the points: ";

	// test if value have already been used, some coded borrowed from lecture 6, "random numbers generator"
	while (howMany < SIZE && (cin >> valueX) && (cin >> valueY)) {

		seqX[howMany] = valueX;
		seqY[howMany] = valueY;

		bool found = false;

		// linear search
		for (int i = 0; i < howMany; ++i) {
			if (seqX[i] == valueX && seqY[i] == valueY || valueX > length && valueX < -length || valueY > length && valueY < -length)
			{
				found = true;
				break;
			}
		}

		if (!found && valueX <= length && valueY <= length && valueY >= -length && valueX >= -length)  // not repeated  value or too big/small value
		{
			seqX[howMany] = valueX;  // add new value to seqX and seqY
			seqX[howMany] = valueX;
			++howMany;
		}
	}

	// STEP 3
	for (int i = 0; i < howMany; i++)
	{
		valueX = seqX[i];
		valueY = seqY[i];

		double valueXY = sqrt(valueX * valueX + valueY * valueY);

		distance[i] = valueXY; // code used to calculate median distance in STEP 4

		if (valueXY < radius)
		{
			cout << valueX << "," << valueY << " in the circle." << endl;
		}
		if (valueXY >= radius)
		{
			cout << valueX << "," << valueY << " NOT in the circle." << endl;
		}

	}

	// code borrowed from lecture 5, bubble sort. Sorting the distances
	for (int pass = 1; pass <= howMany - 1; pass++)  // passes
	{
		for (int i = 0; i < howMany - 1; i++)  // one pass
		{
			if (distance[i] > distance[i + 1])  // compare a pair of adjacent values
			{
				// swap
				double temp = distance[i];
				distance[i] = distance[i + 1];
				distance[i + 1] = temp;
			}
		}
	}

	// spacing between
	cout << endl;

	//STEP 4
	// when number is even
	if (howMany % 2 == 0)
	{
		double outcome1 = distance[(howMany - 1) / 2];
		double outcome2 = distance[(howMany + 1) / 2];

		double total = (outcome1 + outcome2) / 2;

		cout << "Median distance to point (0,0): " << total;
	}

	//when number is odd
	else
		cout << "Median distance to point (0,0): " << distance[howMany / 2] << endl;

	return 0;
}