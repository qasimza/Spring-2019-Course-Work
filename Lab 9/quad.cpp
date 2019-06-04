#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <math.h>

using namespace std;

const double pi = 3.141592653589793238462643383279;

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

	double getX() {
		return x;
	}

	double getY() {
		return y;
	}

	void setX(double in_x) {
		x = in_x;
	}

	void setY(double in_y) {
		y = in_y;
	}

	bool operator==(Point &rhs) {
		return (rhs.x == x && rhs.y == y);
	}

private:
	double x, y;
};

class Quad {
	Point P1, P2, P3, P4;

	// implement cout for Quadrilateral classes objects
	friend ostream & operator<<(ostream &output, const Quad &T) {
		output << "Point 1: " << T.P1 << endl << "Point 2: " << T.P2 << endl << "Point 3: " << T.P3 << endl << "Point 4: " << T.P4;
		return output;
	}

	// implement cin for Quadrilateral classes objects
	friend istream & operator>>(istream &input, Quad &T) {
		input >> T.P1 >> T.P2 >> T.P3 >> T.P4;
		return input;
	}


public:
	Quad() {
	}

	Quad(Point in_p1, Point in_p2, Point in_p3, Point in_p4) {
		P1 = in_p1;
		P2 = in_p2;
		P3 = in_p3;
		P4 = in_p4;
	}

	Quad(int in_x1, int in_y1, int in_x2, int in_y2, int in_x3, int in_y3, int in_x4, int in_y4) {
		Point in_p1(in_x1, in_y1);
		Point in_p2(in_x2, in_y2);
		Point in_p3(in_x3, in_y3);
		Point in_p4(in_x4, in_y4);
		P1 = in_p1;
		P2 = in_p2;
		P3 = in_p3;
		P3 = in_p4;
	}

	void set_P1(double a, double b) {
		P1.setX(a);
		P1.setY(b);
	}

	void set_P2(double a, double b) {
		P2.setX(a);
		P2.setY(b);
	}

	void set_P3(double a, double b) {
		P3.setX(a);
		P3.setY(b);
	}

	void set_P4(double a, double b) {
		P4.setX(a);
		P4.setY(b);
	}

	// Determines if the object is a quadrilateral
	bool is_quadrilateral() {
		if (P1 == P2 || P1 == P3 || P1 == P4 || P2 == P3 || P3 == P4 || P2 == P4) {
			return false;
		}
		else {
			double p1p2p3 = P1.getX()*(P2.getY() - P3.getY()) + P2.getX()*(P3.getY() - P1.getY()) + P3.getX()*(P1.getY() - P2.getY());
			if (p1p2p3 == 0)
				return false;
			double p2p3p4 = P2.getX()*(P3.getY() - P4.getY()) + P3.getX()*(P4.getY() - P2.getY()) + P4.getX()*(P2.getY() - P3.getY());
			if (p2p3p4 == 0)
				return false;
			double p1p3p4 = P1.getX()*(P3.getY() - P4.getY()) + P3.getX()*(P4.getY() - P1.getY()) + P4.getX()*(P3.getY() - P1.getY());
			if (p1p3p4 == 0)
				return false;
			double p1p2p4 = P1.getX()*(P2.getY() - P4.getY()) + P2.getX()*(P4.getY() - P1.getY()) + P4.getX()*(P1.getY() - P2.getY());
			if (p1p2p4 == 0)
				return false;
		}
		return true;
	}

	//Returns area
	double area() {
		double ar = 0.5 *(P1.getX()*P2.getY() + P2.getX()*P3.getY() + P3.getX()*P4.getY() + P4.getX()*P1.getY() - P2.getX()*P1.getY() - P3.getX()*P2.getY() - P4.getX()*P3.getY() - P1.getX()*P4.getY());
		return ar;
	}


};

int main() {

	cout << "Creating Quadrilateral object C1 with center and edge point both initialized to (0,0)" << endl;

	Quad C1;
	cout << C1 << endl;
	cout << "Result of is_quadrilateral() on C1: 0-False(Not a quad), 1-True(Is a quad): " << C1.is_quadrilateral() << endl;
	cout << "Area: " << C1.area() << endl;


	cout << endl << "Enter coordinates for the Quadrilateral, C1: " << endl;
	cin >> C1;
	cout << "After input, C1 has the following coordinates: " << endl;
	cout << C1 << endl;
	cout << "Result of is_quadrilateral() on C1: 0-False(Not a quad), 1-True(Is a quad): " << C1.is_quadrilateral() << endl;
	cout << "Area: " << C1.area() << endl;

	return 0;
}