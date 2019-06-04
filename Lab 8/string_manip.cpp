// Please place your information here
//
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// This prototype is complete
class stringManip {
public:
	stringManip();
	stringManip(string input);
	string retrieve();
	void setString(string input);
	void chop();
	void padString(int n);
	void center(int length);
	void truncate(int n);
	void removeNonAlpha();
	void convertToUpperCase();
	void convertToLowerCase();

private:
	string tobeEdited;
};

// Not all functions are defined here

// Default Constructor
stringManip::stringManip() {
	tobeEdited = "";
}

// Overloaded Constructor
stringManip::stringManip(string in_string) {
	tobeEdited = in_string;
}

// retrieve function
string stringManip::retrieve() {
	return tobeEdited;
}

// padString() function
void stringManip::padString(int length) {
	 while (tobeEdited.length() < length) {
		tobeEdited += " ";
	}
}

// setString() function
void stringManip::setString(string input) {
	tobeEdited = input;
}

// chop() function
void stringManip::chop() {
	int i = 0;

	if (tobeEdited.size() > 0) {

		while (tobeEdited.size() > 0 && isspace(tobeEdited.at(0))) {
			tobeEdited = tobeEdited.substr(1, tobeEdited.size() - 1);
		}

		while (tobeEdited.size() > 0 && isspace(tobeEdited.at(tobeEdited.size() - 1))) {
			tobeEdited = tobeEdited.substr(0, tobeEdited.size() - 1);
		}
	}
}

//center() function
void stringManip::center(int length) {
	chop();
	int num_spaces = length - tobeEdited.size();
	for (int i = 0; i < num_spaces; i++) {
		if (i % 2 != 0) {
			tobeEdited = " " + tobeEdited;
		}
		else
			tobeEdited = tobeEdited + " ";
	}
}

//truncate() function
void stringManip::truncate(int length) {
	if (tobeEdited.size() > length) {
		tobeEdited = tobeEdited.substr(0,length);
	}

}

//removeNonAlpha() function
void stringManip::removeNonAlpha() {
	string temp;
	for (int i = 0; i < tobeEdited.size(); i++) {
		if (isalpha(char(tobeEdited[i])))
			temp = temp+ tobeEdited[i];
	}
	tobeEdited = temp;
}

//convertToUpperCase() function
void stringManip::convertToUpperCase() {
	char ch;
	for (int i = 0; i < tobeEdited.size(); i++) {
		ch = char(tobeEdited[i]);
		if (islower(ch)) {
			ch = toupper(ch);
			tobeEdited[i] = ch;
		}
	}
}

//convertToLowerCase() function
void stringManip::convertToLowerCase() {
	char ch;
	for (int i = 0; i < tobeEdited.size(); i++) {
		ch = char(tobeEdited[i]);
		if (isupper(ch)) {
			ch = tolower(ch);
			tobeEdited[i] = ch;
		}
	}
}


// Add test cases to main()
int main1() {
	stringManip S1;
	stringManip S2("testing 123");

	// Test case for padString() You should correct some of your own.
	cout << "S2 before padString(20): <" << S2.retrieve() << ">" << endl;
	S2.padString(20);
	cout << "S2 after padString(20): <" << S2.retrieve() << ">" << endl;
	cout << "Should be: <testing 123       >" << endl;
	
	//Test case for chop()
	S2.chop();
	cout << "S2 after chop(): <" << S2.retrieve() << ">" << endl;
	
	
	//Test case for chop()
	S2.padString(25);
	S2.center(19);
	cout << "S2 after center(): <" << S2.retrieve() << ">" << endl;

	//Test case for truncate()
	S2.chop();
	S2.truncate(8);
	cout << "S2 after truncate(): <" << S2.retrieve() << ">" << endl;

	//Test case for convertToUpperCase()
	S2.convertToUpperCase();
	cout << "S2 after convertToUpperCase(): <" << S2.retrieve() << ">" << endl;

	//Test case for convertToLowerCase()
	S2.convertToLowerCase();
	cout << "S2 after convertToLowerCase(): <" << S2.retrieve() << ">" << endl;

	//Test case for  
	S2.setString("testing 123 ab");
	S2.removeNonAlpha();
	cout << "testing 123 ab after convertToLowerCase(): <" << S2.retrieve() << ">" << endl;
	return 0;
}