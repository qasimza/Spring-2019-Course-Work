#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "Enter Four numbers: ";
	double a, b, c, d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cout << endl;
	cout << "Formula 1: " << ((a + b + c) / (2 * a*c)) << endl;
	cout << "Formula 2: " << (a*a/b+(c/d)*(a+b)) << endl;
	cout << "Formula 3: " << (pow(a,(2+b+c))+a-c+4) << endl;
	return 0;
}
