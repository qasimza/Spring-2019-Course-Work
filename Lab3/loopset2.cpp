#include <iostream>

using namespace std;

int main()
{
	int begin, end, step;
	cout << "Starting Index: ";
	cin >> begin;
	cout << "Ending Index: ";
	cin >> end;
	cout << "Step Count: ";
	cin >> step;
	int sum = 0, terms = 0;
	double avg;
	for (int i = begin; i <= end; i += step) {
		sum = sum + i;
		terms++;
	}
	avg = static_cast<double>(sum) / terms;
	cout << "SUM: " << sum << endl;
	cout << "AVERAGE: " << avg << endl;
	return 0;
}