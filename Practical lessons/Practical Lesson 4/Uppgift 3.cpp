
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	constexpr int NUMBERS = 20;
	int line = 10;
	int positive[NUMBERS] = { 0 };

	cout << "Enter sequence: " << endl;

	for (int i = 0; i < NUMBERS; ++i)
	{
		cin >> positive[i];
	}


	/*
	for (int i = 0; i < NUMBERS; ++i)
	{
		cout << setw(6) << positive[i];

		for (int j = 0; j < NUMBERS; ++j)
		{
			for (int k = 0; k < NUMBERS; ++k)
			{
				//control if sum of a[i]+a[j] == a[k]
			}
		}

		if ((i + 1) % line == 0)
		{
			cout << endl;
		}
	}
	*/

return 0;
}








