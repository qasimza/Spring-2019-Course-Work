
#include <iostream>
using namespace std;

int main()
{
    double r;
	cout << "Enter RIchter Scale Number: ";
	cin >> r;
	cout << endl;
	if (r < 5.0)
		cout << "Little Damage" << endl;
	else if (r < 5.5)
		cout << "Some Damage" << endl;
	else if (r < 6.5)
		cout << "Serious Damage" << endl;
	else if (r < 7.5)
		cout << "Disastrous Damage" << endl;
	else
		cout << "Catastrophic Damage" << endl;
	return 0;
}