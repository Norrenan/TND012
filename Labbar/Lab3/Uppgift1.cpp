#include <iostream> 

using namespace std;

int main()
{
	int age = 0;
	constexpr int AGE_BABY = 0;
	constexpr int AGE_KID = 8;
	constexpr int AGE_TEEN = 15;
	constexpr int PRIS0 = 0;
	constexpr int PRIS1 = 30;
	constexpr int PRIS2 = 80;



	int Number_tickets = 0;
	int Total = 0;
	int Number_people = 1;

	
	cout << "Welcome to our fotball arena." << endl;
	cout << "............................." << endl;

	do
	{
		cout << "Number of Tickets: ";
		cin >> Number_tickets;

		if (Number_tickets < 1)
		{
			cout << "Invalid number of Tickets!!" << endl;
		}

	} while (Number_tickets < 1);

	// användaren anger åldern för alla som vill köpa biljetter (loop)
	while (Number_tickets > 0)
	{
		cout << "Enter age of person " << Number_people << ": ";
		cin >> age;

		Number_tickets -= 1;
		Number_people += 1;

		if (age >= AGE_BABY && age <= AGE_KID)        //ålder från baby till kíd
			Total += PRIS0;

		else if (age > AGE_KID && age <= AGE_TEEN)    //ålder mellan barn och tonåring 
			Total += PRIS1;

		else if (age > AGE_TEEN)                    //ålder över tonåring 
			Total += PRIS2;
	}

	cout << "Total price = " << Total << " SEK" << endl;


	return 0;
	}


	/*

	// datorn räknar ut summan av alla biljetter






	//if-else-sats (eller case) med ålder pris 30 sek för 8-15, 80 sek för 15 och äldre, gratis för barn under 8 år. 



	if (age < AGE_BABY)

	{

		cout << "Inte född än ;)";                        //ålder under baby (     

	}



	else if ((age >= AGE_BABY) && (age <= AGE_KID))        //ålder från baby till kíd 

	{

		cout << "Ticket is free!";

	}



	else if ((age > AGE_KID) && (age <= AGE_TEEN))    //ålder mellan barn och tonåring 

	{

		cout << "Price = " << PRIS1 << " SEK";        //cout << "Price = 30 SEK"; 

	}



	else if (age > AGE_TEEN)                    //ålder över tonåring 

	{

		cout << "Price = " << PRIS2 << " SEK";        //cout << "Price = 80 SEK";     

	}





	return 0;

}
*/
