#include <iostream>
#include <cmath>

using namespace std;

const double TOLERANCE = .0001;

double f(double x) {		// f(x)
	return (pow(x, 4) + 2 * pow(x, 3) - 31 * pow(x, 2) - 32 * x + 60);
}
double fprime(double x) { 	// f’(x)
	return (4 * pow(x, 3) + 6 * pow(x, 2) - 62 * x - 32);
}

double newtonRoot(double x0) { 	// root finder 
	double fx = f(x0);
	double fpr = fprime(x0);
	double x1 = x0 - fx / fpr;
	if (fabs(fx / fpr) >= TOLERANCE)
	{
		x1 = newtonRoot(x1);
	}
	else return x1;
}

int main() {

	char choice = 'y';
	double g;
	while (choice == 'y')
	{
		cout << "Enter Guess: ";
		cin >> g;
		if (g < -10 || g > 10) {
			cout << "Root out of Range" << endl;
		}
		else {
			double r = newtonRoot(g);
			cout << "Root: " << r << endl;
		}
		cout << "Enter Another Guess:y/n? ";
		cin >> choice;
	}

	return 0;
}

