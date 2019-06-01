#include <iostream>
#include <iomanip> 
#include <cmath>

using namespace std;

int main()
{
	double w, t, x;
	cout << "Width: ";
	cin >> w;
	cout << "Tolerance: ";
	cin >> t;

	cout << "Width: " << w << endl;
	cout << "Tolerance: " << t << endl;

	cout << "Temperature" << '\t' << "Width" << '\t' << "Within Tolerance" << endl;
	for (int i = 60; i < 86; i++) {
		x = w + (i - 70)*(0.0001);
		cout << i << '\t';
		cout << fixed << setw(11) << setprecision(7) << x;
		if (abs(w - x) < t) {
			cout << '\t' << "*";
		}
		cout << endl;
	}

	return 0;
}