/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the header file for the Trainer Class
*/
#include "Space.hpp"
#include "Monster.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

#ifndef TRAINER_HPP
#define TRAINER_HPP
class Trainer 
{
private:
	Space * currentSpace;
	Monster* currentPokemon;
	vector <int> items;

public:
	Trainer(Space*, Monster*);
	void initializePointer(Space*);
	Space* getSpace();
	void moveNorth();
	void moveSouth();
	void checkPokemon();
	void healPokemon();
	bool checkBadge();
	void giveBadge();
	void giveRareCandy();
	void useCandy();

};

#endif
