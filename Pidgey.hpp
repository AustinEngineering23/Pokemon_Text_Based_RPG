/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the header file for the Pidgey class. It is the child of Monster class.
*/
#include "Monster.hpp"

#ifndef PIDGEY_HPP
#define PIDGEY_HPP
class Pidgey : public Monster
{
public:
	Pidgey(int, int, int, int, string);
	int attack();
};
#endif
