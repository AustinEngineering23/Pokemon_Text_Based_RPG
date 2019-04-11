/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the header file for the Onix class. It is the child of Monster class.
*/
#include "Monster.hpp"

#ifndef ONIX_HPP
#define ONIX_HPP
class Onix : public Monster
{
public:
	Onix(int, int, int, int, string);
	int attack();
};
#endif
