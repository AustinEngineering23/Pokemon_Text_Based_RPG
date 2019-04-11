/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the implementation file for PewterCity. It is the child of Shape
*/

#include "PewterCity.hpp"
#include <iostream>
#include "menu.hpp"

using std::cout;
using std::endl;

//Default constructor for Pewter City
PewterCity::PewterCity()
{
	east = nullptr;
	west = nullptr;

	areaName = "Pewter City";
}

//Print function to print the map of PewterCity
void PewterCity::print()
{

}

//Menu Display while in Route
int PewterCity::menuDisplay(Trainer* player)
{
	cout << "\nYou are currently in " << areaName << endl;
	cout << "What would you like to do?" << endl;
	cout << "[1]. Move North\n[2]. Move South\n[3]. Check your Pokemon\n[4]. Visit Pokemon Center\n[5]. Challenge Brock at Pewter Gym\n[6]. Use Rare Candy\n[7]. Exit" << endl;

	int choice = menu(1, 7); //Takes menu input

	if (choice == 1)
	{
		return 1; //Player will be moving North
	}
	else if (choice == 2)
	{
		return 2; //Player will be moving South
	}
	else if (choice == 3)
	{
		player->checkPokemon(); //Checks the Player's Pokemon Status
	}
	else if (choice == 4)
	{
		player->healPokemon();  //3 is the number that will cause a wild battle to execute in pokemonMain
	}
	else if (choice == 5)
	{
		return 4; //4 is the number that will cause a battle with Brock the gym leader to execute in pokemonMain
	}
	else if (choice == 6)
	{
		player->useCandy(); //The player uses a rare candy
	}
	else if (choice == 7)
	{
		return 9;  //9 is the special number used to exit the program
	}

}

