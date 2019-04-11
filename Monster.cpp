/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the implementation file for the Monster class. It is the parent to all Pokemon classes.
*/

#include "Monster.hpp"
#include <iostream>

using std::cout;
using std::endl;


//Constructor
Monster::Monster(int inputDef, int inputStrength, int inputHealth, int inputLevel, string inputName)
{
	defense = inputDef;
	strength = inputStrength;
	health = inputHealth;
	initialHealth = inputHealth;
	level = inputLevel;
	name = inputName;
}

//Levels up the monster adding some bonus stats
void Monster::levelUp()
{
	defense += 1;
	strength += 1;
	health += 1;
	initialHealth += 1;
	level += 1;
}

//Defending
void Monster::defend(int inputAttack)
{
	int damage = (inputAttack/defense) +1;  //Calculating damage

	//If damage is less than 0, it must be set to 0 to prevent healing the opponent
	if (damage < 0)
	{
		damage = 0;
	}

	if (damage > health) //If damage is greater than remaining health, health = 0
	{
		cout << name << " has fainted!" << endl;
		health = 0;
	}
	else
	{
		cout << name << " takes " << damage << " damage" << endl;
		health -= damage;  //Else subtract the damage
	}
}

//Determining if a monster is dead
bool Monster::isDead()
{
	if (health == 0)
	{
		return true; //True if dead
	}
	else
	{
		return false; //False if alive
	}
}

//Returns the name of the Monster
string Monster::getName()
{
	return name;
}

//Returns the defense of the Monster
int Monster::getDefense()
{
	return defense;
}

//Returns the strength
int Monster::getStrength()
{
	return strength;
}

//Returns health
int Monster::getHealth()
{
	return health;
}

//Sets the health
void Monster::healMonster()
{
	cout << "\n" << name << " has been restored to full health!\n" << endl; 
	health = initialHealth;  //This will be used to represent healing the pokemon to full health
}

//Increases health and maxhealth by 1
void Monster::rest()
{
	health++;
	initialHealth++;
}

//Returns initial health
int Monster::getInitialHealth()
{
	return initialHealth;
}

//Returns the level
int Monster::getLevel()
{
	return level;
}

//Rare candy use means it gains huge stat increases
void Monster::rareCandy()
{
	defense += 3;
	strength += 3;
	health += 3;
	initialHealth += 3;
	level += 1;
}

