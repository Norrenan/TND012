#include <iostream>
using namespace std;

int main()
{

	int then = 0;
	int now = 0;
	int summa = 0;
	double pris = 0.0;
	double total = 0.0;
	double pris90 = 0.0;
	double pris10 = 0.0;
	constexpr double procent90 = 0.9;
	constexpr double procent105 = 0.105;


	cout << "Enter the electricity meter reading a year ago: ";
	cin >> then;

	cout << "Enter the electricity meter reading now: ";
	cin >> now;
	cout << endl;

	cout << "Enter regular price of 1kWh: ";
	cin >> pris;

	
	summa = now - then;
	pris90 = pris * summa * procent90;

	pris10 = summa * pris * procent105;

	total = pris90 + pris10;

	cout << "You have used " << summa << " kWh during the last year" << endl;

	cout << "Total cost = " << total << " SEK." << endl;

	cout << "10% of the used energy costs " << pris10 << " SEK." << endl;

	return 0;
}