#include "pch.h"
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
