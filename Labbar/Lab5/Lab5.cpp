/*Test data 1
 country X: 50 50 100 250 100 50 100 85 100 180 10 100 -1
 Sweden:    70 78 170 250 105 90 120 96 160 250 18 150 -1
 */

/*Test data 2
 country X: 50 50 100 250 100 50 100 85 100 180 10 100 50 50 120 120 50 77 -1
 Sweden:    70 78 170 250 105 90 120 96 160 250 18 150 65 60 190 147 90 90 -1
 */

/*Test data 3
 country X: 50 50 100 250 100 50 -1
 Sweden:    70 78 170 250 105 90 120 96 160 250 18 150 -1
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <tuple>

using namespace std;


/******************************
 * Function declarations      *
 ******************************/

int read_seq(int input[], int n);

void difference(int V1[], int V2[], int V3[]);

int count_stars(int n);

void display_graph_line(int n, char c);

tuple <int, int> find_min_max(int V3[], int n);

void display_data(int V3[], int n);



int main() {
    
    constexpr int SIZE = 240;
    int countryX[SIZE] = {0};
    int sweden[SIZE] = {0};
    int howMany = 0;
    int diff[SIZE] = {0};
    
    cout << "Enter data for country X: " << endl;
    
    howMany = read_seq(countryX, SIZE);
    
    cout << "\nEnter data for Sweden: " << endl;
    
    if (howMany != read_seq(sweden, SIZE)) // Number of data points for each country must match
        cout << "\nWrong input" << endl;
    else{
        difference(countryX, sweden, diff); // calculate difference between Sweden and X
        
        cout << "The Graph" << endl;
        display_data(diff, howMany);
    }
    
    cout << endl;
    return 0;
}


int read_seq(int input[], int n) { // Record monthly downloads to array and return number of months

	int howMany = 0;

	for (int i = 0; i < n; i++) {
		cin >> input[i];

		if (input[i] == -1) // Break when user enters -1
			break;
		else
			howMany++; // Increase howMany with every correct input
	}
	return howMany; // Return number of months for which data has been entered
}


void difference(int V1[], int V2[], int V3[]) {

	for (int i = 0; V1[i] != -1; i++)
		V3[i] = V2[i] - V1[i]; // Calculate difference in downloads between Sweden and X
}

int count_stars(int n) {

	return round(n * 0.1);
	// reference for dunction round(double x): http://cplusplus.com/reference/cmath/round
}

void display_graph_line(int n, char c) {

	// Monthly outputs of differences with first letter of each month and numerical difference
	// where each * = 10
	cout << setw(4) << c << ' ';
	for (int i = 1; i <= count_stars(n); i++) // Add * to ouput based on value from count_stars
		cout << '*';
	cout << endl;

}

tuple <int, int> find_min_max(int V3[], int n) {

	// Variables initialized to values we know exist in the data
	int min = V3[0];
	int max = V3[0];

	for (int i = 1; i < n; i++) // i=1 because values for index 0 are already registred
		if (V3[i] < min)
			min = V3[i]; // Update min when lower value is found
		else if (V3[i] > max)
			max = V3[i]; // Update max when higer value is found

	return { min, max };
}

void display_data(int V3[], int n) {

	auto[min, max] = find_min_max(V3, n);
	string min_deviation = "";
	string max_deviation = "";
	const string MONTHS[12] = { "January, ", "February, ", "March, ", "April, ", "May, ", "June, ",
		"July, ", "August, ", "September, ", "October, ", "November, ", "December, " };
	// Reference for using string arrays: http://cplusplus.com/forum/general/100586

	for (int i = 0; i < n; i++) {
		if (V3[i] == min)
			min_deviation.append(MONTHS[i % 12]); // Add month(s) to ouput string when min value is found
		if (V3[i] == max)
			max_deviation.append(MONTHS[i % 12]); // Add month(s) to ouput string when max value is found
		// Reference to string.append: http://cplusplus.com/reference/string/string/append
		if ((i % 6) == 0)
			cout << endl; // Blank line every 6 months
		display_graph_line(V3[i], MONTHS[i % 12].at(0));
		// Reference to string.at(int pos): http://www.cplusplus.com/reference/string/string/at/
	}

	cout << "Month(s) deviating least from country X:" << endl << min_deviation << min << endl;
	cout << "Month(s) deviating most from country X:" << endl << max_deviation << max << endl;
}

