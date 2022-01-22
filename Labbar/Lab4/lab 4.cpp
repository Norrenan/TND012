/**************************************************************************
 Course: tnd012, lab4
 Program to find prime numbers
************************************************************************* */

#include <iostream>
#include <iomanip>
using namespace std;

// Start with i = 2 bc not interested in divison by 0 or 1
// Largest possible divisor we're looking for is n/2			DOES NOT WORK!!!
bool isPrime(int n) {
	for (int i = 2; i <= (n / 2); i++)
		if (n % i == 0)
			return false;
	return true;
}

void test_prime(int number) 
{
	if (number < 0)
		cout << endl << "Invalid input!" << endl << endl;
	else if (isPrime(number))
		cout << endl << number << " is a prime." << endl;
	else
		cout << endl << number << " is not a prime." << endl;
}
int nextPrime(int n) {
	do {
		n++; // Iterate upwards until prime is found
	} while (!isPrime(n));
	return n;
}

void next_prime(int number) 
{
	if (number < 0)
		cout << endl << "Invalid input!" << endl << endl;
	else
		cout << endl << "Next prime of " << number << " is " << nextPrime(number) << endl;
}

int previousPrime(int n) {
	do {
		n--; // Iterate downward until prime is found
	} while (!isPrime(n));
	return n;
}
void previous_Prime(int number)	
{
	if (number < 2)
		cout << endl << "Invalid input!" << endl << endl;
	else
		cout << endl << "Previous prime of " << number << " is " << previousPrime(number) << endl;
}

void displayPrimes(int n) 
{
	// Check from 2 to n and add primes to output
	for (int i = 2; i <= n; i++) // 1 is not a prime number 
		if (isPrime(i))
			cout << i << " ";
	cout << endl;
}

void display_primes(int number)
{
if (number < 0)
	cout << endl << "Invalid input!" << endl << endl;
else {
	cout << endl << "Primes in [1, " << number << "]" << endl;
	displayPrimes(number);
}
}

int main() {

	constexpr int EXIT = 5;
	int option = EXIT;	
	int number = 0;


	do {
		cout << setw(18) << setfill('=') << "=" << endl;
		cout << "1. Test Prime" << endl;
		cout << "2. Next Prime" << endl;
		cout << "3. Previous Prime" << endl;
		cout << "4. Display Primes" << endl;
		cout << "5. Exit" << endl;
		cout << setw(18) << setfill('=') << "=" << endl;

		cout << "Your Choice: ";
		cin >> option;

		switch (option) {
		case 1:
			cout << "Test Prime? ";
			cin >> number;
			test_prime(number); 
			break;

		case 2:
			cout << "Next Prime? ";
			cin >> number;
			next_prime(number);
			break;

		case 3:
			cout << "Previous Prime? ";
			cin >> number;
			previous_Prime(number);
			break;

		case 4:
			cout << "N? ";
			cin >> number;
			display_primes(number);
			break;

		case 5:
			option = EXIT;
			cout << endl << "Exiting..." << endl << endl;
			break;

		default:
			cout << endl << "Wrong Choice!" << endl << endl;
		}
		cout << endl;
	} while (option != EXIT);

	return 0;
}