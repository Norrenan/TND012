#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	constexpr int SIZE = 20;
	double products[SIZE] = { 0.0 };
	double tax_percentage = 0.0;

	cout << "Enter products price: ";
	
	for (int i = 0; i < SIZE; ++i)
	{
		cin >> products[i];
	}

	cout << "Enter tax: ";
	cin >> tax_percentage;

	cout << setfill(' ') << endl;
	cout << setw(20) << left << "Price tax free";
	cout << setw(9) << left << "Tax";
	cout << "Price with tax" << endl;

	cout << setw(43) << setfill('=') << "=" << endl;
	cout << setfill(' ');
	for (int i = 0; i < SIZE; i++)
	{
		double tax = products[i] * (tax_percentage / 100);
	
		cout << setw(8) << right <<fixed << setprecision(2) << products[i];
		cout << setw(15) << tax;
		cout << setw(20) << products[i] + tax << endl;
	}

	return 0;
}