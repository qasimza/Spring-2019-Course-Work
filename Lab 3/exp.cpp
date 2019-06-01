// Program: exp.cpp
// Description: Test and develop a version of the exp() function - main() has test
// code to check and see if this version of exp() function works properly.

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// double factorial(int N) - returns the factorial variable N
// Please add the code necessary to calculate the factorial of the number represented by N

double factorial(int N) {
	double return_val = N, fact = 1;
	for (int i = 2; i <= N; i++) {
		fact = i * fact;
	}
	return_val = fact;
	return return_val;
}

// A clone of the system exp() function.  
// Please do not use the system exp() function in the creation of your function.
double E_to_X(double X) {
	double sum = 0;
	for (int i = 0; i <= 30; i++) {
		double x = pow(X, i);
		sum += (x / factorial(i));
	}
	return sum; // Replace return statement with something more proper
}

// You can change main() in anyway you want
int main() {

	cout << fixed << "E_to_X(0) is " << E_to_X(0) << " should be 1" << endl;
	cout << fixed << "E_to_X(1) is " << E_to_X(1) << " should be 2.718" << endl;
	cout << fixed << "E_to_X(2) is " << E_to_X(2) << " should be 7.38" << endl;
	cout << fixed << "E_to_X(5) is " << E_to_X(5) << " should be 148.41" << endl;
	cout << fixed << "E_to_X(10) is " << E_to_X(10) << " should be 21991.5" << endl;

	return 0;
}