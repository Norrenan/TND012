// ============================================================
// TND012: Practical lesson 5
// Exercise 1
// ============================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{
	cout << fixed << setprecision(2);
	//Define constants and variables
	//ADD CODE
	
	srand((time)(0));

	constexpr int SIZE = 100;
	int k = 0;
	constexpr int N_COLS = 5;

	constexpr int MAX = 100;
	constexpr int MIN = 20;

	int seq[SIZE] = { 0 };

	int counter = 0;

	constexpr int SIZE2 = 10;
	int numbers[SIZE2] = { 0 };


	/**********************************************************
	 * 1. Read number of values in the sequence and validate  *
	 **********************************************************/

	 //Read k

	 //ADD CODE
	do
	{
		cout << "How big is the sequence? ";
		cin >> k;

		if (k > MAX)
			cout << "Sequence too long!!" << endl;
		else if (k < MIN)
			cout << "Sequence too short!!" << endl;


	} while (k > MAX || k < MIN);


	/**********************************************************
	 * 2. Generate a random sequence of values                *
	 **********************************************************/
	while (counter < k)
	{
		int value = (rand() % 10);

		seq[counter] = value;

		++counter;
	}
	/**********************************************************
	 * 3. Display the random sequence, 5 values per line      *
	 **********************************************************/

	for (int i = 0; i < k; i++)
	{
		cout << setw(6) << seq[i];

		if ((i + 1) % N_COLS == 0)

			cout << endl;
	}

	/**************************************************************************
	 * 4. Count the number of occurrences of each value in the sequence seq   *
	 **************************************************************************/

	 //array för alla värden, plussa in för alla värde
	for (int i = 0; i < k; i++)
	{
		int value = seq[i];
		numbers[value]++;


		//cout << "Value: " << value  << " numbers is currently: "<< numbers[value] << endl;
	}
	/*for (int i = 0; i < 10; i++)
	{
		cout << "numbers[" <<i << "] is: " << numbers[i] << endl;


	}


	 /**********************************************************
	  * 5. Find the most/less frequent value                    *
	  ***********************************************************/
	
	//most frequent = highest number
	int frequent2 = 0;
	int frequent = 0;
	for (int i = 0; i < 10; i++)
	{
		if (numbers[i] > numbers[frequent])
		{
		frequent = i;
		}
	}
	
	//less frequent = lowest number
	for (int i = 0; i < 10; i++)
	{
		if (numbers[i] < numbers[frequent2])
		{
			frequent2 = i;
		}
	}

	  // Display most and less frequent digit
	cout << "Most frequent number: " << frequent << endl;

	cout << "Less frequent number: " << frequent2 << endl;

	/**********************************************************
	 * 6. Display table of probabilities                       *
	 ***********************************************************/

	cout << setw(5) << "d" << setw(15) << "P(d)" << endl;
	cout << setw(33) << setfill('=') << "=" << endl;
	cout << setfill(' ');

	 //ADD CODE

	for (int i = 0; i < 10; i++)
	{
		double probability = 0;
		double value = 0;
		value = numbers[i];
		
		probability = value / k;

		cout << i << setw(10) << probability << endl;



	}




	return 0;
}
