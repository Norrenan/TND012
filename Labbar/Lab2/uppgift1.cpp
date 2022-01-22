#include <iostream>

using namespace std;

int main()
{
	
	int age = 0;
	constexpr int AGE_BABY = 0;
	constexpr int AGE_KID = 8;
	constexpr int AGE_TEEN = 15;


	cout << "Welcome to our fotball arena." << endl;
	cout << "............................." << endl;
	cout << "Enter age: ";
	cin >> age;


	
	if (age < AGE_BABY)
	{
		cout << "Inte född än ;)";						
	}

	else if	( (age >= AGE_BABY) && (age <= AGE_KID) )	
	{
		cout << "Ticket is free!";
	}
	
	else if ((age > AGE_KID) && (age <= AGE_TEEN))
	{
		cout << "Price = 30 SEK";
	}
	else if (age > AGE_TEEN)			
	{
		cout << "Price = 80 SEK";
	}
	

	return 0;
}
