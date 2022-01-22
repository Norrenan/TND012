/**************************************************************************
 Course: TND012, lab6
************************************************************************* */
#include "movies.h"

// Read a movie (name, number of copies, type) from file
// Return the movie read
Movie get(ifstream& file) {
    Movie m;

	file >> ws;             // skip any white spaces before the name
	getline(file, m.name);
	file >> m.genre;
	file >> m.number_of_movies;

    return m;
}

// Write a movie m to file
void put(ofstream& file, const Movie& m) {
	file << "Movie: " << m.name << endl;
	file << "Number of copies: " << m.number_of_movies << endl;
	file << "Genre" << m.genre << endl;
}

// Write movie m to cout
void put(const Movie& m) {
	cout << "Movie: " << m.name << endl;
	cout << "Number of copies: " << m.number_of_movies << endl;
	cout << "Genre: " << m.genre;
}

// Return true, if m1's name is alphabetically larger than m2's name
// Otherwise, returns false
bool larger_than(const Movie& m1, const Movie& m2) {
	
	if (m1.name > m2.name)
		return true;
	else
		return false;
}