/**************************************************************************
 Course: TND012, lab6
************************************************************************* */
#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

// DO NOT CHANGE THE GIVEN FUNCTION DECLARATIONS
// DO NOT ADD NEW FUNCTIONS

using namespace std;

// ADD NEW DATA TYPE "Movie" HERE

struct Movie 
{
	string name;
	int number_of_movies;
	string genre;
};

// Read a movie (name, number of copies, type) from file
// Return the movie read
Movie get(ifstream& file);

// Write a movie m to file
void put(ofstream& file, const Movie& m);

// Write movie m to cout
void put(const Movie& m);

// Return true, if m1's name is alphabetically larger than m2's name
// Otherwise, returns false
bool larger_than(const Movie& m1, const Movie& m2);

//// Return true, if m1's name is alphabetically larger than m2's name
//// Otherwise, returns false
bool larger_than(const Movie& m1, const Movie& m2);		

#endif
// MOVIES_H_INCLUDED
