/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the implementation file for the Trainer Class
*/
#include<iostream>
#include "Trainer.hpp"


using std::cin;
using std::cout;
using std::endl;

//Default Constructor
Trainer::Trainer(Space* startSpace, Monster* startPokemon)
{
	currentSpace = startSpace;     //Assigns starting space
	currentPokemon = startPokemon; //Assigns starting pokemon

	items.push_back(0);    //0 rare candy at position 0
	items.push_back(0);    //0 boulder badge at position 1
}

//Initializes the pointer once a space has been created
void Trainer::initializePointer(Space* startSpace)
{
	currentSpace = startSpace;
}

//Gets Trainers current Space
Space* Trainer::getSpace()
{
	return currentSpace;
}

//Move the trainer North on the map
void Trainer::moveNorth()
{
	if (currentSpace->getNorth() != nullptr)
	{
		currentSpace = currentSpace->getNorth(); //Sets pointer to the north pointer
	}
	else
	{
		cout << "Your mother has not given you permission to go past Pewter City." << endl;
	}
}

//Move the trainer South on the map
void Trainer::moveSouth()
{
	if (currentSpace->getSouth() != nullptr)
	{
		currentSpace = currentSpace->getSouth(); //Sets pointer to the south pointer
	}
	else
	{
		cout << "A fence blocks your way from going South of PalletTown." << endl;
	}
}

//Checking the trainers Pokemon
void Trainer::checkPokemon()
{
	cout << currentPokemon->getName() << " Level " << currentPokemon->getLevel() << endl;
	cout << currentPokemon->getHealth() << "/" << currentPokemon->getInitialHealth() << " HP" << endl;
	cout << "Attack: " << currentPokemon->getStrength() << " Defense: " << currentPokemon->getDefense() << endl;

	cout << currentPokemon->getName() << " looks happy! You decide to take the day off and rest." << endl;
	cout << currentPokemon->getName() << "'s max health increased by 1!" << endl << endl;
	currentPokemon->rest();

}

//Heals the Pokemon when user uses the pokemon center
void Trainer::healPokemon()
{
	currentPokemon->healMonster();
}

//Checks to see if the player has the boulder badge
bool Trainer::checkBadge()
{
	//If the item vector at position 1 is at least 1, then the user has a badge
	if (items.at(1) >= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Gives the player the boulder badge
void Trainer::giveBadge()
{
	items.at(1) = 1;
}

//Gives the Player a rare candy
void Trainer::giveRareCandy()
{
	if (items.at(0) == 1)
	{
		cout << "Can only hold one rare candy. You must use it" << endl;
	}
	else
	{
		cout << "While traveling you randomly found a rare candy!" << endl;
		cout << "One rare candy has been added to your bag! You may only carry one at a time" << endl;
		items.at(0) += 1;
	}
}

void Trainer::useCandy()
{
	//If you do not have a rare candy, you lose a day!
	if (items.at(0) == 0)
	{
		cout << "You do not have a rare candy to use! You waste a day searching for one but do not find one." << endl;
	}
	else
	{
		cout << "\nUsed a rare candy. " << currentPokemon->getName() << " gained a huge stat increase!" << endl;
		currentPokemon->rareCandy(); //Has pokemon use the rare candy
		items.at(0) = 0; //Resets item count of rare candy to 0
	}
}
