/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the implementation file for the Caterpie class. It is the child of Monster class.
*/
#include "Caterpie.hpp"
#include "Monster.hpp"
#include <iostream>

using std::cout;
using std::endl;

//Constructor inherited from monster
Caterpie::Caterpie(int inputDef, int inputStrength, int inputHealth, int inputLevel, string inputName) : Monster(inputDef, inputStrength, inputHealth, inputLevel, inputName)
{

}

//Attack for Pidgey
int Caterpie::attack()
{
	cout << "Caterpie used Tackle!" << endl; //Output text for Caterpie's attack

	return strength; //Returns strength
}
