/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the implementation file for the Pidgey class. It is the child of Monster class.
*/
#include "Pidgey.hpp"
#include "Monster.hpp"
#include <iostream>

using std::cout;
using std::endl;

//Constructor inherited from monster
Pidgey::Pidgey(int inputDef, int inputStrength, int inputHealth, int inputLevel, string inputName) : Monster(inputDef, inputStrength, inputHealth, inputLevel, inputName)
{

}

//Attack for Pidgey
int Pidgey::attack()
{
	cout << "Pidgey used Gust!" << endl; //Output text for Pidgey's attack

	return strength; //Returns strength
}
