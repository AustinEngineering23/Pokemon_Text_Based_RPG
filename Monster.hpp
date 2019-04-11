/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the header file for the Monster class. It is the parent to all Pokemon classes.
*/
#include <string>
using std::string;

#ifndef MONSTER_HPP
#define MONSTER_HPP
class Monster
{
protected:
	int defense;
	int strength;
	int health;
	int initialHealth;
	int level;
	string name;
public:
	Monster(int, int, int, int, string);
	void levelUp();
	virtual int attack() = 0;
	void defend(int);
	bool isDead();
	string getName();
	int getDefense();
	int getStrength();
	int getHealth();
	void healMonster();
	void rest();
	int getInitialHealth();
	int getLevel();
	void rareCandy();
};

#endif


