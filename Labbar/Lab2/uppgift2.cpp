#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	// variables
	double b = 0.0;
	double c = 0.0;
	double x1 = 0.0;
	double x2 = 0.0;
	double delta = 10e-8;


	//	user prompted to enter coefficients
	cout << "Solving a second degree equation of the form x ^ 2 + b * x + c" << endl << endl;	cout << "Enter coefficient b: ";
	cin >> b;
	cout << "Enter coefficient c: ";
	cin >> c;
	cout << endl;


	//  simplified expression under square root
	double d = (b / 2)*(b / 2) - c;

	//  checking for complex roots
	if (d < 0)
	{
		cout << "Complex root!" << endl;
	}
	//  checking for double roots
	else if (abs(d) < delta)
	{
		x1 = ((-b / 2) + sqrt(d));
		cout << "x1, x2 = " << fixed << setprecision(3) << x1 << "double root " << endl;
	}
	//  Return when equation has 2 unique roots
	else
	{
		x1 = ((-b / 2) + sqrt(d));
		x2 = ((-b / 2) - sqrt(d));
		cout << "x1= " << fixed << setprecision(3) << x1 << endl;
		cout << "x2= " << fixed << setprecision(3) << x2 << endl;
	}



	return 0;
}
