#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double first = 0.0;
	double last = 0.0;
	double step = 0.0;
	double percentage = 0.0;

	bool invalid_input = false;

	do {
		cout << "Enter first price: ";
		cin >> first;

		cout << "Enter last price: ";
		cin >> last;

		cout << "Enter price step: ";
		cin >> step;

		cout << "Enter tax percentage: ";
		cin >> percentage;

		invalid_input = (first < 0) || (last < 0) || (last <= first) || (step <= 0) || (percentage < 0);

		if (invalid_input) 
		{

			cout << "Invalid input!" << endl;
		}

	} while (invalid_input);


	cout << endl;
	cout << "Taxes Table" << endl;
	cout << "Tax = " << fixed << setprecision(2) << percentage << "%" << endl << endl;

	cout << setw(20) << left << "Price tax free"
		<< setw(9) << left << "Tax"
		<< "Price with tax" << endl;

	cout << setw(50) << setfill('=') << "=" << endl;

	cout << setfill(' ');

	for (double i = first; i <= last; i += step)
	{

		cout << setw(20) << fixed << setprecision(2) << i;
		double tax = i * percentage / 100;
		double totalprice = i + tax;

		cout << setw(9) << left << tax
			<< totalprice << endl;
	}

	return 0;

}


