/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the implementation file for the Onix class. It is the child of Monster class.
*/
#include "Onix.hpp"
#include "Monster.hpp"
#include <iostream>

using std::cout;
using std::endl;

//Constructor inherited from monster
Onix::Onix(int inputDef, int inputStrength, int inputHealth, int inputLevel, string inputName) : Monster(inputDef, inputStrength, inputHealth, inputLevel, inputName)
{

}

//Attack for Onix
int Onix::attack()
{
	cout << "Onix used Bind!" << endl; //Output text for Onix's attack

	return strength; //Returns strength
}
