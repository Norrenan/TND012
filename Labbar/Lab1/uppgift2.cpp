#include <iostream>
using namespace std;

int main()
{

	int then = 0;
	int now = 0;
	int summa = 0;		

	
	cout << "Enter the electricity meter reading a year ago:"; 

	cin >> then;

	cout << "Enter the electricity meter reading now:";

	cin >> now;
	cout << endl;

	summa = now - then;

	cout << "You have used " << summa << " kWh during the last year" <<endl;


	return 0;
}