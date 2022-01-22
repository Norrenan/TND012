#include<iostream> 

using namespace std;

int main()
{
	//variables declaration
	double money_Euro = 0.0;
	double money_SEK = 0.0;
	constexpr double EURO_EXCHANGE_RATE = 10.73;

    //Read input data: how much money in euro
	cout << "Euro: ";
	cin >> money_Euro;

    //Convert from Euro to SEK
    money_SEK = EURO_EXCHANGE_RATE * money_Euro;

    //Display the result: euro -> SEK
    cout << money_Euro << " Euro is converted to "
         << money_SEK << " SEK." << endl;

	cout << "Enter SEK";
	cin >> money_SEK;

    money_Euro = money_SEK / EURO_EXCHANGE_RATE;

	cout << money_Euro;

    return 0;

}
