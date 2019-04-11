/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the implementation file for the Charmander class. It is the child of Monster class.
*/
#include "Charmander.hpp"
#include "Monster.hpp"
#include <iostream>

using std::cout;
using std::endl;

//Constructor inherited from monster
Charmander::Charmander(int inputDef, int inputStrength, int inputHealth, int inputLevel, string inputName) : Monster(inputDef, inputStrength, inputHealth, inputLevel, inputName)
{

}

//Attack for Charmander
int Charmander::attack()
{
	cout << "Charmander used Ember!" << endl; //Output text for Charmander's attack

	return strength; //Returns strength
}
