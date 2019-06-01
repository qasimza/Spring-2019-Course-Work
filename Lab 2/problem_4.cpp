//Programmer: Zaina Qasim
//Purpose: TO accept the coordinates of a point and output its quadrant

#include <iostream>
using namespace std;

int main()
{
    double x, y;
	cout << "Enter XY Pair: ";
	cin >> x;
	cin >> y;
	cout << endl;
	if (x > 0 && y > 0)
		cout << "Pair is Q1" << endl;
	else if (x < 0 && y > 0)
		cout << "Pair is Q2" << endl;
	else if (x < 0 && y < 0)
		cout << "Pair is Q3" << endl;
	else if (x > 0 && y < 0)
		cout << "Pair is Q4" << endl;
	else if (x == 0 && y == 0)
		cout << "Center Point" << endl;
	else if (x == 0)
		cout << "On Y-Axis" << endl;
	else 
		cout << "On X-Axis" << endl;
	return 0;
}
