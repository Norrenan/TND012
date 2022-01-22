/**************************************************************************
 Course: TND012, lab6
***************************************************************************/
#include <iostream>
#include <fstream>

#include "movies.h"

using namespace std;

/****************************************/
// Function declarations (prototypes)
/****************************************/

// NO CHANGES TO FUNCTION DECLARATIONS ALLOWED HERE!

// Sort alphabetically array V with n movies
// movies name is used for sorting
void sort_movies(Movie V[], int n);

// Read a text file f of movies and
// Load the movies into array V
// Function returns the number of movies read
// Array V has n movie slots
int read_From_File(ifstream& f, Movie V[], int n);

// Write all movies in array V to file f
// Array V stores n movies
void write_to_File(ofstream& f, const Movie V[], int n);

// Display all movies in array V to cout
// Array V stores n movies
void display_db(const Movie V[], int n);

// ADD ADDITIONAL FUNCTIONS BELOW IF NEEDED

void swap(Movie a, Movie b);

/****************************************/
// Main program
/****************************************/

// DO NOT CHANGE THE main() function, with exception for the paths to the files
int main() {
	// Change the paths to files
	ifstream in_file("C:\\Filestmp\\movies.txt");          // file to read
	ofstream out_file("C:\\Filestmp\\movies_sorted.txt");  // file to write

	// Test if opening the files succeeded
	if (!in_file || !out_file) {
		cout << "Error in file opening" << endl;
		return 1;  // end the program
	}

	constexpr int SIZE = 100;
	Movie db[SIZE];  // A database of movies

	// Load a file of movies into array db
	int howMany = read_From_File(in_file, db, SIZE);

	if (!howMany) {
		cout << "File is empty!!" << endl;
		return 2;
	}

	// Sort array db by movies name
	sort_movies(db, howMany);

	// Display the sorted movies in array db to the screen
	display_db(db, howMany);

	// Save the sorted movies stored in db to a text file
	write_to_File(out_file, db, howMany);

	// close the files
	in_file.close();
	out_file.close();

	return 0;
}

/****************************************/
// Function definitions
/****************************************/
void swap(Movie a, Movie b)
{
	Movie tmp = a;
	a.name = b.name;
	b.name = tmp.name;
}

// Sort alphabetically array V with n movies
// movies name is used for sorting
void sort_movies(Movie V[], int n) {

	for (int pass = 1; pass <= (n - 1); pass++)
		for (int i = 0; i < (n - 1); i++)
			if (larger_than(V[i], V[i + 1])) {
				// Swap
				Movie temp = V[i];
				V[i] = V[i + 1];
				V[i + 1] = temp;
			}
}

// Read a text file f of movies and
// Load the movies into array V
// Function returns the number of movies read
// Array V has n movie slots
int read_From_File(ifstream& f, Movie V[], int n) {
	Movie m;
	int counter = 0;

	m = get(f);  // read first employee

	while (f)  // test if stream is in good state
	{
		V[counter] = m;  // store employee in V
		counter++;       // increment the counter

		// for debugging purposes
		// put(E);

		// all n slots of array V are occupied
		if (counter == n)
			break;

		m = get(f);  // read next employee
	}

	return counter;
}

// Write all movies in array V to file f
// Array V stores n movies
void write_to_File(ofstream& f, const Movie V[], int n)
{
	for (int i = 0; i < n; ++i) {
		put(f, V[i]);  // write an employee to the file out
		f << endl;
	}
}

// Display all movies in array V to cout
// Array V stores n movies
void display_db(const Movie V[], int n)
{
	for (int i = 0; i < n; i++)
	{
		put(V[i]);
		cout << endl << endl;
	}
}
