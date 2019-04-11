/*
Author: Austin Henry
Class : CS 162 Summer 2018
Date : 8/ 15 / 2018
Assignment : Final Project

Menu Class (is reused for other projects)
*/
#include <iostream>
#include <string>
#include <sstream>
#include "menu.hpp"

using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;




int menu(int min, int max)
{
	int answer;
	string check;

	while (true) {

		getline(cin, check); //gets input as string check
		stringstream convert(check); //turns the string into a stream

									 //Makes sure it was converted to integer. Also checks to see if it is within the boundaries min and max
		if (convert >> answer && !(convert >> check) && answer >= min && answer <= max)
		{
			return answer;
		}

		cin.clear();

		//Prompting again for the correct input between boundaries
		cout << "Please enter a valid number between " << min << " and " << max << endl;

	}
}


