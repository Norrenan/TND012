#include <iostream>
#include <iomanip>


using namespace std;

int main()
{

	int dept_hrs = 0;
	int dept_min = 0;
	int dur_hrs = 0;
	int dur_min = 0;
	int arr_hrs = 0;
	int arr_min = 0;

	cout << "Enter departure time of flight: " << endl;
	cout << "Hours: ";
	cin >> dept_hrs;

	if (dept_hrs < 0 || dept_hrs > 24)
	{
		cout << "ERROR!";
		return 0;
	}


	cout << "Minutes: ";
	cin >> dept_min;


	if (dept_min > 60 || dept_min < 0)
	{
		cout << "ERROR!";
		return 0;
	}

	// User prompted to enter hour for flight duration
	cout << "Enter flight duration: " << endl;
	cout << "Hours: ";


	if (dur_hrs > 24 || dur_hrs < 0)
	{
		cout << "ERROR!";
		return 0;
	}

	// User prompted to enter minutes for flight duration
	cin >> dur_hrs;
	cout << "Minutes: ";
	cin >> dur_min;

	if (dur_min < 0 || dur_min > 60)
	{
		cout << "ERROR!";
		return 0;
	}


	// Calculation of hours and minutes
	arr_min = (dept_min + dur_min) % 60;
	arr_hrs = dept_hrs + dur_hrs + (dept_min + dur_min) / 60;


	// krav på vad som händer om timmar och/eller minuter går över 24 eller 60.

	if ((arr_hrs >= 24) && (arr_min >= 60))
	{
		arr_hrs += 1;
	}

	else if (arr_hrs >= 24)
	{
		arr_hrs -=24 ;
	}

	else if (arr_min >= 60)
	{
		arr_hrs =+ 1;
	}

	
	if ((arr_min < 10) && (arr_hrs < 10))
	{
		cout << "Arrival time: 0" << arr_hrs << ":0" << arr_min << endl;
	}

	else if (arr_hrs < 10)
	{
		cout << "Arrival time: 0" << arr_hrs << ":" << arr_min << endl;
	}

	else if (arr_min < 10)
	{
		cout << "Arrival time: " << arr_hrs << ":0" << arr_min << endl;
	}

	else
	{
		cout << "Arrival time: " << arr_hrs << ":" << arr_min << endl;
	}

	return 0;
}
