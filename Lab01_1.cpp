// Lab01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<fstream>
#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;

string promptUser(void);

int main() {
	string inBuf = promptUser();
	ifstream file;
	double number, first, penult, finalnum = 0;
	int count = 1, i = 1;

	file.open(inBuf);
	if (!file) {
		cout << "Unable to find or open input: " << inBuf << endl;
		file.close();
		return 0;
	}
	file >> number;
	first = number;
	
	while (file >> number) {
		count++;
		penult = finalnum;
		finalnum = number;
	}
	file.close();

	cout << "The total quantity of numbers is: " << count << endl;
	cout << "The first number is: " << first << endl;
	cout << "The penultimate number is: " << penult << endl;
	cout << "The final number is: " << finalnum << endl;

	return 0;
}

string promptUser(void) {
	string input;

	cout << "Please enter a filename: ";
	cin >> input;
	return input;
}