
#include "Point.h"

// Read a point from cin
Point get() {
	Point p;

	cin >> p.x >> p.y;

	return p;
}

// Read a point from file f
Point get(ifstream& f) {
	Point p;

	f >> p.x >> p.y;

	return p;
}

// Write point p to cout
void put(const Point& p) {

	cout << p.x << ", " << p.y;

}

// Write point p to file f
void put(ofstream& f, const Point& p) {

	f << p.x << ", " << p.y;
}

// Return the distance between points p1 and p2
double distance(const Point& p1, const Point& p2) {

	double distance = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));

	return distance;
}

// Return true, if distance of p1 to (0,0) is smaller than the distance of p2 to (0,0)
// Otherwise, return false
bool less_than(const Point& p1, const Point& p2) {

	double dis1 = sqrt(p1.x*p1.x + p1.y*p1.y);
	double dis2 = sqrt(p2.x*p2.x + p2.y*p2.y);

	if (dis1 < dis2)
		return true;
	else
		return false;
}

// Return true, if points p1 and p2 have same coordinates
// Otherwise, return false
bool equal(const Point& p1, const Point& p2) {
	
	if (p1.x == p2.x && p1.y == p2.y)
		return true;
	else
		return false;
}
