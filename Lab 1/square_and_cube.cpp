
// Programmer: Zaina Qasim

// Program to accept a number from the user and output is square and cube

#include <iostream>

using namespace std;

int main() {
	int userNum = 0, num2;
	int square, cube;
	cout << "Enter integer:" << endl;
	cin >> userNum;
	cout << "You entered: " << userNum << endl;
	square = userNum * userNum;
	cube = userNum * userNum* userNum;
	cout << userNum << " squared is " << square << endl << "And " << userNum << " cubed is " << cube << "!!" << endl << "Enter another integer:" << endl;
	cin >> num2;
	cout << userNum << " + " << num2 << " is " << userNum + num2 << endl;
	cout << userNum << " * " << num2 << " is " << userNum * num2 << endl;
	return 0;
}
