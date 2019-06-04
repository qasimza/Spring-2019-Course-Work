#include <iostream>

using namespace std;

const double M_PI = 3.14159265358979323846;

class Cylinder {
public:
	Cylinder() {
		setR(0);
		setH(0);
	}

	Cylinder(double in_r, double in_h) {
		setR(in_r);
		setH(in_h);
	}

	double getR() {
		return r;
	}

	double getH() {
		return h;
	}

	void setR(double in_r) {
		r = in_r;
	}

	void setH(double in_H) {
		h = in_H;
	}

	void display() {
		cout << "Cylinder Parameters: " << endl;
		cout << "Radius: " << getR() << endl;
		cout << "Height: " << getH() << endl;
		cout << "Area of Cross Surface: " << getAreaCross() << endl;
		cout << "Area of Curved Surface: " << getAreaCurved() << endl;
		cout << "Total Area: " << getArea() << endl;
		cout << "Volume: " << getVolume() << endl << endl;
	}

private:
	double getAreaCross() {
		return (M_PI*r*r);
	}

	double getAreaCurved() {
		return (2*M_PI*r*h);
	}

	double getArea() {
		return (2*getAreaCross() + getAreaCurved());
	}

	double getVolume() {
		return (getAreaCross())*h;
	}

	double r;
	double h;

};

int main13456() {

	Cylinder c1;
	c1.display();

	Cylinder c2(2, 4);
	c2.display();

	c2.setR(3);
	c2.display();

	return 0;
}