/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the header file for the Charmander class. It is the child of Monster class.
*/
#include "Monster.hpp"

#ifndef CHARMANDER_HPP
#define CHARMANDER_HPP
class Charmander : public Monster
{
public: 
	Charmander(int, int, int, int, string);
	int attack();
};
#endif
