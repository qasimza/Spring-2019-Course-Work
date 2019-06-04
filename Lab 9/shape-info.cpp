#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <sstream>
#include <fstream>


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
		return 2 * length_radius();
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

class Triangle {
	Point P1, P2, P3;

	// implement cout for Triangle classes objects
	friend ostream & operator<<(ostream &output, const Triangle &T) {
		output << "Point 1: " << T.P1 << endl << "Point 2: " << T.P2 << endl << "Point 3: " << T.P3;
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

class Quad {
	Point P1, P2, P3, P4;

	// implement cout for Quadrilateral classes objects
	friend ostream & operator<<(ostream &output, const Quad &Q) {
		output << "Point 1: " << Q.P1 << endl << "Point 2: " << Q.P2 << endl << "Point 3: " << Q.P3 << endl << "Point 4: " << Q.P4 <<endl;
		return output;
	}

	// implement cin for Quadrilateral classes objects
	friend istream & operator>>(istream &input, Quad &Q) {
		input >> Q.P1 >> Q.P2 >> Q.P3 >> Q.P4;
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
		P4 = in_p4;
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

vector<double> breakupstring(string str) {
	vector<double> numdata;
	stringstream ss;     //requires sstream library included
	ss << str;

	while (!ss.eof()) {
		double temp;
		ss >> temp;
		numdata.push_back(temp);
	}

	return numdata;
}

int main() {
	ifstream in_file;
	ofstream out_file;
	in_file.open("C:\\temp\\shapes.txt");
	out_file.open("C:\\temp\\shape-info.txt");
	vector <double> val;
	string str;
	int ch;
	while (!(in_file.eof())) {
		getline(in_file, str);
		val = breakupstring(str);
		ch = val.size();
		if (ch == 4) {

			out_file << "Sufficient cordinates input." << endl;
			Circle C1(val.at(0), val.at(1), val.at(2), val.at(3));
			if (C1.is_circle()) {
				out_file << "The object is a circle." << endl;
				out_file << "Radius of the Circle: " << C1.length_radius() << " unit" << endl;
				out_file << "Diameter of the Circle: " << C1.diameter() << " units" << endl;
				out_file << "Area of the Circle: " << C1.area() << " sq units" << endl;
				out_file << "Circumference of the Circle: " << C1.circumference() << " units" << endl;
			}
			else {
				out_file << "The object is not a circle." << endl;
			}
			
			
		}
		else if (ch == 6) {

			out_file << "Sufficient cordinates input." << endl;
			Triangle T1(val.at(0), val.at(1), val.at(2), val.at(3), val.at(4), val.at(5));
			if (T1.is_triangle()) {
				out_file << "The object is a triangle." << endl;
				out_file << "Area of the triangle: " << T1.area() << " sq units" << endl;
				out_file << "Perimeter of the triangle: " << T1.perimeter() << " units" << endl;
				if (T1.is_equilateral()) {
					out_file << "The triangle is an equilateral triangle." << endl;
				}
				else {
					out_file << "The triangle is not an equilateral triangle." << endl;
				}
			}
			else {
				out_file << "The object is not a triangle." << endl;
			}
		}
		else if (ch == 8) {

			out_file << "Sufficient cordinates input." << endl;
			Quad Q1;
			Q1.set_P1(val.at(0), val.at(1));
			Q1.set_P2(val.at(2), val.at(3));
			Q1.set_P3(val.at(4), val.at(5));
			Q1.set_P4(val.at(6), val.at(7));
			

			if (Q1.is_quadrilateral()) {
				out_file << "The object is a Quadrilateral." << endl;
				out_file << "Area of the Quadrilateral: " << Q1.area() << " sq units" << endl;
			}
			else {
				out_file << "The object is not a Quadrilateral." << endl;
			}
		}
		else{
			out_file << "Sufficient cordinates NOT input." << endl;
		}
		out_file << endl;
	}
	return 0;
}
