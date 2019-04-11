/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the header file for the Caterpie class. It is the child of Monster class.
*/
#include "Monster.hpp"

#ifndef CATERPIE_HPP
#define CATERPIE_HPP
class Caterpie : public Monster
{
public:
	Caterpie(int, int, int, int, string);
	int attack();
};
#endif
