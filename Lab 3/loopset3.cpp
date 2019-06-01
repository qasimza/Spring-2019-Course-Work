#include <iostream>

using namespace std;

int main()
{
	double start;
	cout << "Enter a number greater than 0: ";
	cin >> start;
	cout << start;
	while (start > 0) {
		start -= 0.5;
		cout << "," << start;
	}
	return 0;
}