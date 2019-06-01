#include <iostream>

using namespace std;

int main()
{
	double sum = 0, num = 1.0;
	double avg;
	while (num > 0) {
		cout << "Enter Positive Number to Add or Enter Zero or Negative Number to End: ";
		cin >> num;
		if (num <= 0) {
			break;
		}
		sum += num;
	}
	cout << "Sum of Entered Numbers: " << sum;
	return 0;
}
