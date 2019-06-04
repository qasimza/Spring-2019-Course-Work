// Add your information here

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

// Please replace this Point class with your version from Part B
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
		x = in_x;
	}

	void setY(int in_y) {
		y = in_y;
	}


private:
	int x, y;
};


class Line {
	// implement cout for Line classes objects
	friend ostream & operator<<(ostream &output, const Line &L) {
		output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
		return output;
	}

	// implement cin for Line classes objects
	friend istream & operator>>(istream &input, Line &L) {
		input >> L.P1 >> L.P2;
		return input;
	}

public:
	// Add your functions/methods here //
	Line() {
	}

	Line(Point in_p1, Point in_p2) {
		P1 = in_p1;
		P2 = in_p2;
	}

	Line(int in_x1, int in_y1, int in_x2, int in_y2) {
		Point in_p1(in_x1, in_y1);
		Point in_p2(in_x2, in_y2);
		P1 = in_p1;
		P2 = in_p2;
	}

	double slope() {
		return double (P2.getY()- P1.getY()) / (P2.getX() - P1.getX());
	}

	void isHorizontal() {
		if (slope() == 0) {
			cout << "Line is Horizontal" << endl;
		}
		else
		{
			cout << "Line is not Horizontal" << endl;
		}
	}

	void isVertical() {
		if (isinf(slope())) {
			cout << "Line is Vertical" << endl;
		}
		else
		{
			cout << "Line is not Vertical" << endl;
		}
	}

	double y_intercept() {
		return -1*slope()*P1.getX() + P1.getY();
	}

	double length_line() {
		return sqrt((P2.getX() - P1.getX())*(P2.getX() - P1.getX()) + (P2.getY() - P1.getY())*(P2.getY() - P1.getY()));
	}

	void isParallel(Line in_L2) {
		if (slope() == in_L2.slope())
			cout << "The Lines are Parallel" << endl;
		else
			cout << "The Lines are not Parallel" << endl;
	}

private:
	Point P1, P2;
};

int main12() {
	Line L1;
	Line L2(5,6,7,8);

	cout << "L1: should have all zeros for values" << endl;
	cout << L1 << endl;
	
	cout << "Enter Two Points For Line: ";
	cin >> L1;
	cout << L1 << endl;
	cout << "Slope of L1: " << L1.slope() << endl;
	L1.isHorizontal();
	L1.isVertical();
	cout << "y-intercept: " << L1.y_intercept() << endl;
	cout << "Length of Line 1: " << L1.length_line() << endl;

	cout << endl;
	cout << L2 << endl;
	cout << "Slope of L2: " << L2.slope() << endl;
	L2.isHorizontal();
	L2.isVertical();
	cout << "y-intercept: " << L2.y_intercept() << endl;
	cout << "Length of Line 1: " << L2.length_line() << endl;
	cout << "Length of Line 1: " << L2.length_line() << endl;

	L1.isParallel(L2);

	return 0;
}
