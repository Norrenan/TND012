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

	// anv�ndaren anger �ldern f�r alla som vill k�pa biljetter (loop)
	while (Number_tickets > 0)
	{
		cout << "Enter age of person " << Number_people << ": ";
		cin >> age;

		Number_tickets -= 1;
		Number_people += 1;

		if (age >= AGE_BABY && age <= AGE_KID)        //�lder fr�n baby till k�d
			Total += PRIS0;

		else if (age > AGE_KID && age <= AGE_TEEN)    //�lder mellan barn och ton�ring 
			Total += PRIS1;

		else if (age > AGE_TEEN)                    //�lder �ver ton�ring 
			Total += PRIS2;
	}

	cout << "Total price = " << Total << " SEK" << endl;


	return 0;
	}


	/*

	// datorn r�knar ut summan av alla biljetter






	//if-else-sats (eller case) med �lder pris 30 sek f�r 8-15, 80 sek f�r 15 och �ldre, gratis f�r barn under 8 �r. 



	if (age < AGE_BABY)

	{

		cout << "Inte f�dd �n ;)";                        //�lder under baby (     

	}



	else if ((age >= AGE_BABY) && (age <= AGE_KID))        //�lder fr�n baby till k�d 

	{

		cout << "Ticket is free!";

	}



	else if ((age > AGE_KID) && (age <= AGE_TEEN))    //�lder mellan barn och ton�ring 

	{

		cout << "Price = " << PRIS1 << " SEK";        //cout << "Price = 30 SEK"; 

	}



	else if (age > AGE_TEEN)                    //�lder �ver ton�ring 

	{

		cout << "Price = " << PRIS2 << " SEK";        //cout << "Price = 80 SEK";     

	}





	return 0;

}
*/
