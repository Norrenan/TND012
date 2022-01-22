#include <iostream>
#include <fstream>

using namespace std;

//Do not modify

struct Point {
    int x = 0;
    int y = 0;
};

//Read a point from cin
Point get();

//Read a point from file f
Point get(ifstream& f);

//Write point p to cout
void put(const Point& p);

// Write point p to file f
void put(ofstream& f, const Point& p);

//Return the distance between points p1 and p2
double distance(const Point& p1, const Point& p2);

//Return true, if distance of p1 to (0,0) is smaller than the distance of p2 to (0,0)
//Otherwise, return false
bool less_than(const Point& p1, const Point& p2);

// Return true, if points p1 and p2 have same coordinates
// Otherwise, return false
bool equal(const Point& p1, const Point& p2);
