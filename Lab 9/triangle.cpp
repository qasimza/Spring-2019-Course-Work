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

class Triangle {
	Point P1, P2, P3;

	// implement cout for Triangle classes objects
	friend ostream & operator<<(ostream &output, const Triangle &T) {
		output << "Point 1: " << T.P1 << endl << "Point 2: " << T.P2 <<endl <<  "Point 3: " << T.P3;
		return output;
	}

	// implement cin for Triangle classes objects
	friend istream & operator>>(istream &input, Triangle &T) {
		input >> T.P1 >> T.P2 >> T.P3;
		return input;
	}


public:
	Triangle() {
	}

	Triangle(Point in_p1, Point in_p2, Point in_p3) {
		P1 = in_p1;
		P2 = in_p2;
		P3 = in_p3;
	}

	Triangle(int in_x1, int in_y1, int in_x2, int in_y2, int in_x3, int in_y3) {
		Point in_p1(in_x1, in_y1);
		Point in_p2(in_x2, in_y2);
		Point in_p3(in_x3, in_y3);
		P1 = in_p1;
		P2 = in_p2;
		P3 = in_p3;
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

	//Length of side
	double length_side(Point a, Point b) {
		return sqrt((a.getX() - b.getX())*(a.getX() - b.getX()) + (a.getY() - b.getY())*(a.getY() - b.getY()));
	}
	
	// Determines if the object is a triangle
	bool is_triangle() {
		if (P1 == P2 || P2 == P3) {
			return false;
		}
		else {
			double slope_p1p2 = (P2.getY() - P1.getY()) / (P2.getX() - P1.getX());
			double slope_p2p3 = (P3.getY() - P2.getY()) / (P3.getX() - P2.getX());
			return (!(slope_p1p2 == slope_p2p3));
		}
	}

	//Returns area
	double area() {
		double a = length_side(P1, P2);
		double b = length_side(P1, P3);
		double c = length_side(P2, P3);
		double ar, s;
		s = (a + b + c) / 2;
		ar = sqrt(s*(s - a)*(s - b)*(s - c));
		return ar;
	}

	//Returns perimeter 
	double perimeter() {
		double a = length_side(P1, P2);
		double b = length_side(P1, P3);
		double c = length_side(P2, P3);
		return (a + b + c);
	}

	//checks if the triangle is equilateral
	bool is_equilateral() {
		double a = length_side(P1, P2);
		double b = length_side(P1, P3);
		double c = length_side(P2, P3);
		return (a == b && b == c);
	}

	// Overloading ==
	bool operator==(Triangle rhs) {
		return (P1 == rhs.P1 && P2 == rhs.P2 && P3 == rhs.P3);
	}

};

int main() {

	cout << "Creating Triangle object C1 with center and edge point both initialized to (0,0)" << endl;

	Triangle C1;
	cout << C1 << endl;
	cout << "Result of is_triangle () on C1: 0-False(Not a trinagle), 1-True(Is a traingle): " << C1.is_triangle() << endl;
	cout << "Perimeter: " << C1.perimeter() << endl;
	cout << "Area: " << C1.area() << endl;


	cout << endl << "Enter coordinates for First Trinagle, C1: " << endl;
	cin >> C1;
	cout << "After input, C1 has the following coordinates: " << endl;
	cout << C1 << endl;
	cout << "Result of is_triangle () on C1: 0-False(Not a trinagle), 1-True(Is a traingle): " << C1.is_triangle() << endl;
	cout << "Perimeter: " << C1.perimeter() << endl;
	cout << "Area: " << C1.area() << endl;
	cout << "Is it equilateral? (0=No/1=Yes): " << C1.is_equilateral() << endl;
	
	/*cout << endl << "Setting C1 parameters to (0, 0, 6, 0, 3, 3tan(pi/3))" << endl;
	C1.set_P1(0, 0);
	C1.set_P2(6, 0);
	C1.set_P2(3, 3*tan(pi/3));
	cout << "Coordinates of C1: " << endl << C1 << endl;
	cout << "Is it equilateral? (0=No/1=Yes): " << C1.is_equilateral() << endl;*/

	cout << "Creating another trinagle object C2 with construnctor parameters (4, 3, 7, 9, 10, 11)" << endl;
	Triangle C2(4, 3, 7, 9, 10, 11);
	
	cout << "Coordinates of C2: " << endl << C2 << endl;

	cout << "Result of C1 == C2: " << (C1 == C2) << endl;

	cout << "Putting C1 = C2" << endl;
	C1 = C2;
	cout << "Coordinates of C1: " << endl << C1 << endl;

	cout << "Result of C1 == C2: " << (C1 == C2) << endl;

	return 0;
}