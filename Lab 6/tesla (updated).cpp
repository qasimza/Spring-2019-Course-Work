#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

//Generator Postion (ob = item to be moved)
vector <int> generate_position(vector <vector <char>>& a, int boardsize, char ob) {
	int row, column;
	do {
		row = rand() % boardsize;
		column = rand() % boardsize;
	} while (a[row][column] != 'x');
	a[row][column] = ob;
	return { row, column };
}

//Generate a game board with each intitialzed to 'x'
vector <vector<char>> generate_boardgame(int boardsize) {
	vector <char> a(boardsize, 'x');
	vector <vector <char>> gb(boardsize, a);
	return gb;
}

//Wake up Musk (Musk wakes up randomly when the player has made between 15 to 30 turns)
int wake_musk_after_turns() {
	return rand() % 16 + 15;
}

//Move Player
bool move_player(vector <vector <char>>& gb, vector <int>& p_pos) {
	int flag = 0;
	char p_move;
	while (flag == 0) {
		cout << "Next move (w-up/a-left/s-down/d-right/q-quit):  ";
		cin >> p_move;
		if (p_move == 'q' || p_move == 'Q') {
			flag = 2;
		}
		else if (p_move == 'w' || p_move == 'W') {
			p_pos.at(0)--;
			if (p_pos.at(0) == -1) {
				p_pos.at(0)++;
				cout << "End of Building: Cannot Move Up" << endl;
			}
			else {
				gb[p_pos.at(0) + 1][p_pos.at(1)] = 'x';
				gb[p_pos.at(0)][p_pos.at(1)] = 'p';
				flag = 1;
			}
		}
		else if (p_move == 'a' || p_move == 'A') {
			p_pos.at(1)--;
			if (p_pos.at(1) == -1) {
				p_pos.at(1)++;
				cout << "End of Building: Cannot Move Left" << endl;
			}
			else {
				gb[p_pos.at(0)][p_pos.at(1) + 1] = 'x';
				gb[p_pos.at(0)][p_pos.at(1)] = 'p';
				flag = 1;
			}
		}
		else if (p_move == 's' || p_move == 'S') {
			p_pos.at(0)++;
			if (p_pos.at(0) == 15) {
				p_pos.at(0)--;
				cout << "End of Building: Cannot Move Down" << endl;
			}
			else {
				gb[p_pos.at(0) - 1][p_pos.at(1)] = 'x';
				gb[p_pos.at(0)][p_pos.at(1)] = 'p';
				flag = 1;
			}
		}
		else if (p_move == 'd' || p_move == 'D') {
			p_pos.at(1)++;
			if (p_pos.at(1) == 15) {
				p_pos.at(1)--;
				cout << "End of Building: Cannot Move Right" << endl;
			}
			else {
				gb[p_pos.at(0)][p_pos.at(1) - 1] = 'x';
				gb[p_pos.at(0)][p_pos.at(1)] = 'p';
				flag = 1;
			}
		}
		else {
			cout << "ERROR: Move does not exist." << endl;
		}
	}
	if (flag == 0 || flag == 1) {
		return true; //continue game
	}
	else
		return false; //end game
}

//Move Musk
bool move_musk(vector <vector <char>>& gb, vector <int>& m_pos, int boardsize) {
	int row, column;
	bool flag = true;
	do {
		row = rand() % boardsize;
		column = rand() % boardsize;
		if (gb[row][column] == 'p'){
			flag = false;
			break;
		}
	} while (gb[row][column] != 'x');
	gb[m_pos.at(0)][m_pos.at(1)] = 'x';
	m_pos.at(0) = row;
	m_pos.at(1) = column;
	gb[row][column] = 'm';
	return flag;
}

//Calculate Distance
double distance(vector <int> player, vector <int> item) {
	double dist = sqrt((player.at(0)-item.at(0))*(player.at(0) - item.at(0)) + (player.at(1) - item.at(1)) * (player.at(1) - item.at(1)));
	return dist;
}

//Generate Hint
void generate_hint(char choice) {
	switch (choice) {
	case 'r':
		cout << "Getting closer to Roadster." << endl;
		break;
	case 'R':
		cout << "Getting away from Roadster." << endl;
		break;
	case 'W':
		cout << "Congratulations! You found the Roadster!" 
			 << " *** YOU WIN *** " 
			 << endl;
		break;
	case 'M':
		cout << "Danger: Musk Approaching." << endl;
		break;
	case 'm':
		cout << "You accidently bumped into Musk." << endl
			<< "You ran in a hurry and ended up in a random position." << endl
			<< "WARNING: BE CAREFUL. MUSK WILL BLAST YOU INTO SPACE THE NEXT TIME YOU ARE CAUGHT." << endl;
		break;
	case 'L':
		cout << "Musk found you!" << endl
			<< "You were tied to Roadster and then blasted into space." << endl
			<< "*** GAME OVER! YOU LOSE! ***" << endl;
		break;
	case 'I':
		cout << "Object Sensed." << endl;
		break;
	case 'f':
		cout << "You got into the Ford Pinto." << endl
			<< "The alarms went off..." << endl
			<< "Musk found you!" << endl
			<< "You were tied to Roadster and then blasted into space." << endl
			<< "*** GAME OVER! YOU LOSE! ***" << endl;
		break;
	case 'y':
		cout << "You got into the Yugo." << endl
			<< "The alarms went off..." << endl
			<< "Musk found you!" << endl
			<< "You were tied to Roadster and then blasted into space." << endl
			<< "*** GAME OVER! YOU LOSE! ***" << endl;
		break;
	default:
		cout << "None" << endl;
	}
};

//Displays Game Instructions
void display_game_instructions() {
	cout << "Welcome to SpaceX" << endl;
	cout << endl << "It is the night before the Roadster is mounted atop the rocket which is to send it into space" << endl;
	cout << "Elon musk is sleeping somewhere in this room" << endl;
	cout << "Items in the room: Roadster, Yugo, Ford Pinto" << endl;
	cout << endl << "OBJECTIVES:" << endl << "Find Musk's prized Roadster before he wakes up and finds you." << endl;
	cout << endl << "CONTROLS:" << endl
		<< "w - Move one step upward" << endl
		<< "a - Move one step left" << endl
		<< "s - Move one step down" << endl
		<< "d - Move one step right" << endl;
}

//Displays Current Game Stats
void display_current_stats(int total_games, int wins, int starman, int turns) {
	cout << endl << "CURRENT GAME STATS: " << endl;
	cout << "Total Games: " << total_games << endl;
	cout << "Total Wins: " << wins << '\t' << "Starman Count: " << starman << endl;
	cout << "Turns this game: " << turns << endl;
}

//Displays Final Stats
void display_final_stats(int total_games, int wins, int starman) {
	cout << "GAME STATS:" << endl;
	cout << "Total Games: " << total_games << endl;
	cout << "Total Wins: " << wins << '\t' << "Starman Count: " << starman << endl;
		
}

//Play one game
void play_one_game(int& total_games, int& wins, int& losses) {
	
	total_games++;
	
	int boardsize = 15, moves = 0, caught=0;
	vector <vector <char>> gameboard = generate_boardgame(boardsize); //Generate Game Board
	display_game_instructions(); // Display game Instructions
	vector <int> player_position = generate_position(gameboard, boardsize, 'p'); //Place player randomly on game board
	vector <int> musk_position = generate_position(gameboard, boardsize, 'm'); //Place Musk randomly on game board
	vector <int> roadster_position = generate_position(gameboard, boardsize, 'r'); //random roadster position
	vector <int> yugo_position = generate_position(gameboard, boardsize, 'y'); //random yugo position
	vector <int> ford_position = generate_position(gameboard, boardsize, 'f'); //random ford position
	
	int flag = 0;
	bool game_over = true;

	vector <int> temp = player_position;

	int wake_musk = wake_musk_after_turns();

	while (flag == 0) {
		
		display_current_stats(total_games, wins, losses, moves);

		if (moves >= wake_musk) {
			cout << "WARNING: MUSK IS AWAKE AND IS ACTIVELY SEARCHING FOR YOU!" << endl;
			move_musk(gameboard, musk_position, boardsize);
		}

		if (distance(player_position, musk_position) == 0 && caught==0) {
			generate_hint('m');
			caught++;
			player_position = generate_position(gameboard, boardsize, 'p');
			temp = player_position;
		}

		else if (distance(player_position, musk_position) == 0 && caught == 1) {
			generate_hint('L');
			flag = 1;
			losses++;
			break;
		}

		else if (distance(player_position, yugo_position) == 0) {
			generate_hint('y');
			flag = 1;
			losses++;
			break;
		}

		else if (distance(player_position, ford_position) == 0) {
			generate_hint('f');
			flag = 1;
			losses++;
			break;
		}
		
		else if (distance(player_position, roadster_position) == 0) {
			generate_hint('W');
			flag = 1;
			wins++;
			break;
		}

		else if (distance(player_position, yugo_position) <= sqrt(2) || distance(player_position, ford_position) <= sqrt(2)) {
			generate_hint('I');
		}

		else if (distance(player_position, musk_position) <= sqrt(2)) {
			generate_hint('M');
		}

		if (move_player(gameboard, player_position)==true) {

			cout << endl << "HINT: " << endl;
			if (distance(temp, roadster_position) < distance(player_position, roadster_position)) {
				generate_hint('R');
			}

			else {
				generate_hint('r');
			}
			temp = player_position;
			moves++;
		}
		else {
			losses++;
			flag = 1;
		}
	}	
}

//Main Method 
int main() {
	srand(unsigned int(time(NULL)));
	int number_of_games = 0, wins = 0, starman = 0;
	char flag = 'y';
	do {
		play_one_game(number_of_games, wins, starman);
		display_final_stats(number_of_games, wins, starman);
		cout << "Hit 'y' to play new game (Press any other key to end game): ";
		cin >> flag;
	} while (flag == 'y');
	cout << endl << "*** THE END ***" << endl;
	cout << endl;
	display_final_stats(number_of_games, wins, starman);
	return 0;

}

