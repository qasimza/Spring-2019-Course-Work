#include <iostream>
#include <cmath>

using namespace std;

const double M_PI = 3.14159265358979323846;

class TriangularPrism {
public:
	TriangularPrism() {
		setA(0);
		setB(0);
		setC(0);
		setH(0);
	}

	TriangularPrism(double in_a, double in_b, double in_c, double in_h) {
		setA(in_a);
		setB(in_b);
		setC(in_c);
		setH(in_h);
	}

	double getA() {
		return a;
	}

	double getB() {
		return b;
	}

	double getC() {
		return c;
	}

	double getH() {
		return h;
	}

	void setA(double in_a) {
		a = in_a;
	}

	void setB(double in_b) {
		b = in_b;
	}

	void setC(double in_c) {
		c = in_c;
	}

	void setH(double in_H) {
		h = in_H;
	}

	void display() {
		cout << "Prism Parameters: " << endl;
		cout << "Side 1: " << getA() << endl;
		cout << "Side 2: " << getB() << endl;
		cout << "Side 3: " << getC() << endl;
		cout << "Height: " << getH() << endl;
		cout << "Area of Cross Surface: " << getAreaCross() << endl;
		cout << "Area of Surface along side of length " << getA() << " :" << getAreaFace1() << endl;
		cout << "Area of Surface along side of length " << getB() << " :" << getAreaFace2() << endl;
		cout << "Area of Surface along side of length " << getC() << " :" << getAreaFace3() << endl;
		cout << "Total Area: " << getArea() << endl;
		cout << "Volume: " << getVolume() << endl << endl;
	}

private:
	double getAreaCross() {
		double ar,s;
		s = (a + b + c) / 2;
		ar = sqrt(s*(s - a)*(s - b)*(s - c));
		return ar;
	}

	double getAreaFace1() {
		return (a*h);
	}

	double getAreaFace2() {
		return (b*h);
	}

	double getAreaFace3() {
		return (c*h);
	}

	double getArea() {
		return 2 * (getAreaFace1() + getAreaFace2() + getAreaFace3() + getAreaCross());
	}

	double getVolume() {
		return (getAreaCross()*h);
	}

	double a, b, c;
	double h;

};

int main3() {

	TriangularPrism tp1;
	tp1.display();

	TriangularPrism tp2(3, 4, 5, 12);
	tp2.display();

	tp2.setB(3);
	tp2.display();

	return 0;
}