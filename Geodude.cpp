/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the implementation file for the Geodude class. It is the child of Monster class.
*/
#include "Geodude.hpp"
#include "Monster.hpp"
#include <iostream>

using std::cout;
using std::endl;

//Constructor inherited from monster
Geodude::Geodude(int inputDef, int inputStrength, int inputHealth, int inputLevel, string inputName) : Monster(inputDef, inputStrength, inputHealth, inputLevel, inputName)
{

}

//Attack for Geodude
int Geodude::attack()
{
	cout << "Geodude used Rock Throw!" << endl; //Output text for Geodude's attack

	return strength; //Returns strength
}
