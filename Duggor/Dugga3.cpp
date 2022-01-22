/*test values
-3.5 -6.5 6  1 1 -1 -1 1 -1 -1 1 0 6.6 0 -6.6
3 -3 5 2.3 4 3 10 12 8.8 0 12 3 2.8
8 19 1 8 -2.2
*/

#include <iostream>
#include <iomanip>
#include <tuple>

using namespace std;

constexpr int SIZE = 100; // max number size of array

struct Line
{
	double m;
	double b;
};

Line read_one_line(); // reads and stores the first line

void read_lines(int max_lines, Line DB[]); // reads and stores all the other lines

int checkIfValidNumberOfLines(); //does what functions name is

void display_line(Line M); //mandatory function

void display_parallel(Line M[], Line L1, int i); //used to display the parallel lines

bool is_parallel(Line M[], Line L1, int counter); //mandatory function

bool find_intersection_point(Line M[], Line L1, int i); //mandatory function

void display_intersection(Line m[], Line L1, int counter); //used to display intersecting lines

void calculate_intersetion(Line m[], Line L1, int i); //calculates the where intersections are, function is inside above function

int main()
{
	cout << fixed << setprecision(2); //sets number of decimals to 2
	Line DB[SIZE]; //stores lines in array

	cout << "Enter a line L(m followed by b): ";
	Line line_one = read_one_line();

	int numb_lines = checkIfValidNumberOfLines();

	read_lines(numb_lines, DB);

	cout << "Lines parallel with Line ";
	display_line(line_one);
	cout << endl;

	display_parallel(DB, line_one, numb_lines);
	cout << endl;
	cout << "Lines that intersect with line ";
	display_line(line_one);
	cout << endl;

	display_intersection(DB, line_one, numb_lines);
	cout << endl;

}

Line read_one_line()
{
	Line line;
	cin >> line.m >> line.b;
	return line;
}

void read_lines(int max_lines, Line DB[])
{
	cout << "Enter " << max_lines << " line(s): ";
	int counter = 0;
	while (counter < max_lines)
	{
		cin >> DB[counter].m >>
			DB[counter].b;
		counter++;
	}
}

int checkIfValidNumberOfLines()
{
	int numb_lines;
	bool Invalid_input = false;
	do
	{
		cout << "Enter number of lines: ";
		cin >> numb_lines;

		Invalid_input = numb_lines < 0 || numb_lines > 100;

		if (Invalid_input)
		{
			cout << "Invalid input, try again!" << endl << endl;
		}
	} while (Invalid_input);

	return numb_lines;
}

void display_line(const Line M)
{
	double m = M.b;
	double b = M.m;

	if (m >= 0)
		cout << "Y = " << b << "X + " << m;
	else
		cout << "Y = " << b << "X " << m;
}

void display_parallel(Line M[], const Line L1, int i)
{
	int number_of_parallels = 0;
	for (int counter = 0; counter < i; counter++)
	{

		if (is_parallel(M, L1, counter))
		{
			display_line(M[counter]);
			cout << endl;
			number_of_parallels++;
		}
	}

	if (number_of_parallels == 0)
	{
		cout << "No parallel lines found!!" << endl;
	}
}

bool is_parallel(Line M[], Line L1, int i)
{
	if (M[i].m == L1.m)	// if the the slope is the same, parallel lines is found.
		return true;
	else
		return false;
}

void display_intersection(Line m[], const Line L1, int counter)
{
	int number_of_intersections = 0;
	for (int i = 0; i < counter; i++)
	{

		if (find_intersection_point(m, L1, i))
		{
			display_line(m[i]);
			cout << right << setw(25);
			calculate_intersetion(m, L1, i);
			number_of_intersections++;
		}
	}

	if (number_of_intersections == 0)
	{
		cout << "No intersection lines found!!";
	}

}

bool find_intersection_point(Line M[], const Line L1, int i)
{
	if (L1.m != M[i].m) // if the the slope isn't the same, intersection is found.
		return true;
	else
		return false;
}

void calculate_intersetion(Line m[], Line L1, int i)
{
	double X = (m[i].b - L1.b) / (L1.m - m[i].m);
	double Y = L1.m * X + L1.b;

	//intersectionX = (b2 - b1) / (m1 - m2)
	//intersectionY = m1 * X + b1

	cout << "Intersection point: (" << X << ", " << Y << ")" << endl;
}