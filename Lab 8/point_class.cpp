// Add your information here

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Please complete this Point class.
// The cin/cout operators have been overloaded for you
class Point {

	// cout implementation for Point class
	friend ostream & operator<<(ostream &output, const Point &P) {
		output << "x: " << P.x << " y: " << P.y;
		return output;
	}

	// cin implementation for Point class
	friend istream & operator>>(istream &input, Point &P) {
		input >> P.x >> P.y;
		return input;
	}

public:
	Point() {
		x = 0;
		y = 0;
	}

	Point(int in_x, int in_y) {
		x = in_x;
		y = in_y;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	void setX(int in_x) {
		x=in_x;
	}

	void setY(int in_y) {
		y = in_y;
	}


private:
	int x, y;
};

int main123() {
	Point P1;
	Point P2(7, 6);
	cout << "Point P1 should have 0,0 as values" << endl;
	cout << P1 << endl;
	cout << "Point P2 should have 7,6 as values" << endl;
	cout << P2 << endl;
	cout << "y co-ordinate of Point P1= " << P1.getY() << endl;
	cout << "x co-ordinate of Point P2= " << P2.getX() << endl;
	cout << "Enter x and y points: ie 3 4 ";
	cin >> P1;
	cout << P1 << endl;
	cout << "New x co-ordinate of Point P1= " << P1.getX() << endl;
	cout << P2 << endl;
	P2.setX(-3);
	cout << "After changing x-xoordinate of P2 to -3, P2 is given by: " << endl << P2 << endl;
	return 0;
}