#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

//Checks if upper limit is within the required range
bool check_lim(int upperlimit) {
	if (upperlimit > 100 || upperlimit < 0)
		return false;
	else
		return true;
}

//Checks if number of samples is greater than 0
bool check_val(int num_val) {
	if (num_val < 0)
		return false;
	else
		return true;
}

//Accepts user input, stores in variables
void input(int& u, int& num_values) {
	cout << "Enter the upper limit: ";
	cin >> u;
	while (!check_lim(u)) {
		cout << "INCORRECT INPUT: Enter a value between 0 and 100: ";
		cin >> u;
	}
	cout << "Enter the number samples: ";
	cin >> num_values;
	while (!check_val(num_values)) {
		cout << "INCORRECT INPUT: Number of samples should be greater than 0: ";
		cin >> num_values;
	}
}

//Generates random numbers and calculates frequency
void generate_random(int upperlimit, int num_values, vector <int>& a) {
	int random_number;
	for (int i = 0; i < num_values; i++) {
		random_number=rand() % (upperlimit+1);
		a.at(random_number)++;
	}
}

//Returns minimum value in the vector
int min_value(vector <int>a) {
	int min = a.at(0);
	for (int i = 1; i < a.size(); i++) {
		min = min < a.at(i) ? min : a.at(i);
	}
	return min;
}

//Returns maximum value in the vector
int max_value(vector <int>a) {
	int max = a.at(0);
	for (int i = 1; i < a.size(); i++) {
		max = max < a.at(i) ? a.at(i) : max;
	}
	return max;
}

//Returns scale used on the bar graph
int scale(vector <int> a) {
	return ceil(double(max_value(a))/60); 
}

//Outputs the barchart
void barchart(int upper_limit, vector <int> a) {
	cout << "Index" << '\t' << "Value" << '\t' << "Bar" << endl;
	for (int i = 0; i <= upper_limit; i++) {
		cout << i << '\t' << a.at(i) << '\t';
		for (int j = 0; j < ceil(double(a.at(i))/scale(a)); j++)
			cout << "*";
		cout << endl;
	}
}

//Displays the stats
void display_stats(int upper_limit, vector <int> a, int samples) {
	cout << "Scale: " << scale(a) << " per *" << endl;
	cout << "Range: 0 to " << upper_limit << endl;
	cout << "Min Value: " << min_value(a) << endl;
	cout << "Max Value: " << max_value(a) << endl;
	cout << "Sum Value: " << samples << endl;
	cout << "Mean Value: " << double(samples)/(upper_limit+1) << endl;
}

int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	int upper, num_samples;
	input(upper, num_samples);
	vector <int> values(upper+1,0);
	generate_random(upper, num_samples, values);
	for (int i = 0; i <= upper; i++)
		cout << values.at(i) << endl;
	barchart(upper, values);
	display_stats(upper, values, num_samples);
	return 0;
}
