#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function to return one roll of a die
int rollDie() {
	int r = rand() % 6 + 1;
	return r;
}

//Retruns results of one game
bool playOneGame(int pt) {
	int wins = 0, roll;
	for (int i = 1; i < 4; i++) {
		roll = rollDie();
		cout << "Roll #" << i << " is " << roll << endl;
		if (pt == roll) {
			cout << "** You win! **" << endl;
			return true;
		}
	}
	cout << "** You lose! **" << endl;
	return false;
}

//Validates user input
bool validation(int val) {
	if (val > 0 && val < 7)
		return true;
	else {
		cout << "Error: Enter your point value, must be between 1 and 6 :";
		return false;
	}
}

//returns win percentage
double win_percentage(int total_wins, int total_plays) {
	double p = static_cast<double>(total_wins) * 100 / total_plays;
	return p;
}

//Checking if there is enough balance
bool balance_check(double bal){
	if (bal > 0)
		return true;
	else {
		cout << "Game over, you are out of money!" << endl;
		return false;
	}
}

//validates wager input by the user
int wager_check(double bal, double w) {
	if (w < 0 || w > bal) {
		cout << "Error: You must wager between $1 and $" << bal << "(type 0 to exit): ";
		return 0;
	}
	else if (w == 0)
		return 1;

	else{
		return 2;
	}
}

//Display stats
void disp_stats(double bal, int wins, int plays) {
	cout << "Your final account balance is $" << bal << endl;
	cout << "You won " << wins << " times out of " << plays << " for a winning percentage of " << win_percentage(wins, plays) << "%" << endl;
}


int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	int point, losses=0, wins=0, plays=0;
	double acc = 100, wager; //default values
	while (balance_check(acc)){
		cout << "Account balance $" << acc << endl; 
		cout << "Enter wager (0 to exit) $";
		cin >> wager;
	label1:;
		switch (wager_check(acc, wager)) {
		case 0:
			cin >> wager;
			goto label1;
		case 1:
			goto label2;
		case 2:
			cout << "Enter your point value (1 - 6): ";
			cin >> point;
			acc = acc - wager;
			plays++;
			while (!validation(point)) {
				cin >> point;
			}
			if (playOneGame(point)) {
				wins++;
				acc += 2 * wager;
			}
		}
	}
	
label2:;
	disp_stats(acc, wins, plays);
	return 0;
}
