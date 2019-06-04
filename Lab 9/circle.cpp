#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

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

class Circle {

	Point P1, P2;

	// implement cout for Circle classes objects
	friend ostream & operator<<(ostream &output, const Circle &C) {
		output << "Center: " << C.P1 << endl << "Point on the Circumference: " << C.P2;
		return output;
	}

	// implement cin for Circle classes objects
	friend istream & operator>>(istream &input, Circle &C) {
		input >> C.P1 >> C.P2;
		return input;
	}

public:
	// Add your functions/methods here //
	
	Circle() {
	}

	Circle(Point in_p1, Point in_p2) {
		P1 = in_p1;
		P2 = in_p2;
	}

	Circle(int in_x1, int in_y1, int in_x2, int in_y2) {
		Point in_p1(in_x1, in_y1);
		Point in_p2(in_x2, in_y2);
		P1 = in_p1;
		P2 = in_p2;
	}

	// Determines if the object is a circle
	bool is_circle() {
		return (!(P1 == P2));
	}

	// Calculates the radius of the circle
	double length_radius() {
		return sqrt((P2.getX() - P1.getX())*(P2.getX() - P1.getX()) + (P2.getY() - P1.getY())*(P2.getY() - P1.getY()));
	}

	// Calculates the diameter circle
	double diameter() {
		return 2* length_radius();
	}

	// Calculates the area of the circle
	double area() {
		return (pi * length_radius() * length_radius());
	}

	// Calculates the circumference circle
	double circumference() {
		return (pi* diameter());
	}

	// Overloading ==
	bool operator==(Circle rhs) {
		return (P1 == rhs.P1 && P2 == rhs.P2);
	}

	void set_P1(double a, double b) {
		P1.setX(a);
		P1.setY(b);
	}

	void set_P2(double a, double b) {
		P2.setX(a);
		P2.setY(b);
	}
};

int main() {
	
	cout << "Creating Cirlce object C1 with center and edge point both initialized to (0,0)" << endl;
	
	Circle C1;
	cout << C1 << endl;
	cout << "Result of is_circle () on C1: 0-False(Not a circle), 1-True(Is a circle): " << C1.is_circle() << endl;
	cout << "Radius: " << C1.length_radius() << endl;
	cout << "Diameter: " << C1.diameter() << endl;
	cout << "Area: " << C1.area() << endl;
	cout << "Circumference: " << C1.circumference() << endl;
	
	cout << "Enter coordinates for First Circle, C1: " << endl;
	cin >> C1;
	cout << "After input, C1 has the following coordinates: " << endl;
	cout << C1 <<endl;
	cout << "Result of is_circle () on C1: 0-False(Not a circle), 1-True(Is a circle): " << C1.is_circle() << endl;
	cout << "Radius: " << C1.length_radius() << endl;
	cout << "Diameter: " << C1.diameter() << endl;
	cout << "Area: " << C1.area() << endl;
	cout << "Circumference: " << C1.circumference() << endl;

	cout << "Setting C1 parameters to (0, 0, 2, 4)" << endl;
	C1.set_P1(0, 0);
	C1.set_P2(2, 4);
	cout << "Coordinates of C1: " << endl << C1 << endl;

	cout << "Creating another circle object C2 with construnctor parameters (4, 3, 7, 9)" << endl;
	Circle C2(4, 3, 7, 9);
	cout << "Coordinates of C2: " << endl << C2 << endl;

	cout << "Result of C1 == C2: " << (C1 == C2) << endl;

	cout << "Putting C1 = C2" << endl;
	C1 = C2;
	cout << "Coordinates of C1: " << endl << C1 << endl;

	cout << "Result of C1 == C2: " << (C1 == C2) << endl;

	return 0;
}