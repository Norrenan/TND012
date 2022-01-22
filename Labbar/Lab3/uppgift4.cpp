//
//  4.2 Generera alla möjliga kombinationer där fyra variabler kan vara 0-9
//  4.3 Generera kombinationer, likt 4.2, men att en siffra inte får tillskrivas två variabler (två variabler får ej ha samma siffra)

/*
#include <iostream>
using namespace std;

int main()
{
	constexpr int SIZE = 10;  // 0-9 is 10 digits (possibilties)


	// In nested loops inner most loop finishes first
	for (int d = 0; d < SIZE; d++) {
		for (int g = 0; g < SIZE; g++) {
			for (int o = 0; o < SIZE; o++) {
				for (int t = 0; t < SIZE; t++) {
					cout << "D = " << d << " ";
					cout << "G = " << g << " ";
					cout << "O = " << o << " ";
					cout << "T = " << t << endl;
				}
				cout << endl;  // Block spacing
			}
		}
	}


	return 0;
}


#include <iostream>
using namespace std;

int main()
{
	constexpr int SIZE = 10;  // 0-9 is 10 digits (possibilties)


	//
	for (int d = 0; d < SIZE; d++) {
		for (int g = 0; g < SIZE; g++) {
			if (g != d) {   // Check for used digits

				for (int o = 0; o < SIZE; o++) {
					if (o != g && o != d) {   // Check for used digits

						for (int t = 0; t < SIZE; t++) {
							if (t != o && t != g && t != d) { // Check for used digits

								cout << "D = " << d << " ";
								cout << "G = " << g << " ";
								cout << "O = " << o << " ";
								cout << "T = " << t << endl;
							}
						}
						cout << endl;  // Block spacing
					}
				}
			}
		}
	}


	return 0;
}
*/

#include <iostream>
using namespace std;

int main()
{
	constexpr int SIZE = 10;  // 0-9 is 10 digits (possibilties)
	int TOO = 0;
	int GOOD = 0;

	//
	for (int d = 0; d < SIZE; d++) {
		for (int g = 0; g < SIZE; g++) {
			if (g != d) {   // Check for used digits

				for (int o = 0; o < SIZE; o++) {
					if (o != g && o != d) {   // Check for used digits

						for (int t = 0; t < SIZE; t++) {
							if (t != o && t != g && t != d) { // Check for used digits

								TOO = (t * 100) + (o * 10) + o;
								GOOD = (g * 1000) + (o * 100) + (o * 10) + d;

								if (4 * TOO == GOOD) {
									cout << "TOO = " << TOO << " and GOOD = " << GOOD << endl;
								}

							}
						}
					}
				}
			}
		}
	}


	return 0;
}