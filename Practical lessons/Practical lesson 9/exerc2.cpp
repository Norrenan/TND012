// ===============================================================
// TND012: practical lesson 9
// Exercise 2
// ===============================================================

#include <iostream>
#include <fstream>
#include "Point.h"

using namespace std;


int get_actual_points(ifstream& f, Point points[], int n);

void display(int howMany, Point points[], int radius);

int main()
{
	ifstream inFile("X:\\TND012\\Practical lesson\\Practical lesson 9\\Files9\\points.txt");

	if (!inFile) //write
	{
		cout << "Couldn't write file!" << endl;
		return 0;
	}

	ofstream OutFile("X:\\TND012\\Practical lesson\\Practical lesson 9\\Files9\\in_circle.txt");
	if (!OutFile)
	{
		cout << "Couldn't read file!" << endl;
		return 0;
	}
	constexpr int NUM_POINTS = 50;
	Point points[NUM_POINTS] = { 0 };
	int howMany = get_actual_points(inFile, points, NUM_POINTS);
	if (howMany == 0)
	{
		cout << "textfile is empty" << endl;
		return 0;
	}

	int radius;
	cout << "Enter radius: ";
	cin >> radius;



	display(howMany, points, radius);
	// if point is inside circle, display.

	return 0;
}


int get_actual_points(ifstream& f, Point points[], int n)
{
	int counter = 0;
	Point p = get(f);
	while (f)
	{
		bool should_insert = true;
		for (int i = 0; i < counter; i++)
		{
			if (equal(p, points[i]))
				should_insert = false;
		}
		if (should_insert)
		{
			points[counter] = p;
			counter++;
		}

		if (counter == n)
			break;

		p = get(f);
	}


	return counter;
}

void swap(Point& a, Point& b)
{
	Point temp = a;
	a = b;
	b = temp;
}

void display(int howMany, Point points[], int radius)
{
	for (int i = 0; i < howman; i++)
	{
		int min = i;
		for (int j = 0; j < Howman; j++)
		{
			if(less_than)
		}
	}




	for (int pass = 1; pass <= howMany - 1; pass++)  // passes
	{
		for (int i = 0; i < howMany - 1; i++)  // one pass
		{
			if (less_than(points[i], (points[i + 1])))  // compare a pair of adjacent values
			{
				swap(points[i], points[i + 1]);
			}
		}
	}

	cout << radius;
}

