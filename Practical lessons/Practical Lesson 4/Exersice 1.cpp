
#include <iostream>


using namespace std;

int main()
{
	constexpr int MAX = 90;
	constexpr int N_COLS = 5;

	long long int a = 1;
	long long int b = 0;


	for (int i = 1; i < MAX; i++)
	{

		long long int tmp = b;
		b = a + b;
		a = tmp;
		cout << b << " ";

		
		if ((i + 1) % N_COLS == 0)
			{

				cout << endl;
			}
			
	}



	return 0;
}



