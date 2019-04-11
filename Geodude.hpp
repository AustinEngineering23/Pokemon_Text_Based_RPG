/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the header file for the Geodude class. It is the child of Monster class.
*/
#include "Monster.hpp"

#ifndef GEODUDE_HPP
#define GEODUDE_HPP
class Geodude : public Monster
{
public:
	Geodude(int, int, int, int, string);
	int attack();
};
#endif
