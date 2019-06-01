#include <iostream>

using namespace std;

int main()
{
	int sum = 0, terms = 0;
	double avg;
	for (int i = 2; i <= 35; i += 3) {
		sum = sum + i;
		terms++;
	}
	avg = static_cast<double>(sum) / terms;
	cout << "SUM: " << sum << endl;
	cout << "AVERAGE: " << avg << endl;
	return 0;
}
