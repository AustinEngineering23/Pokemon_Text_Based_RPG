/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the implementation file for the ViridianForest. It is the child of Shape
*/

#include "ViridianForest.hpp"
#include <iostream>
#include "menu.hpp"

using std::cout;
using std::endl;

//Default constructor for Route
ViridianForest::ViridianForest()
{
	east = nullptr;
	west = nullptr;

	areaName = "Viridian Forest";

}

//Print function to print the map of Viridian Forest
void ViridianForest::print()
{

}

//Menu Display while in ViridianForest
int ViridianForest::menuDisplay(Trainer* player)
{
	cout << "\nYou are currently in " << areaName << endl;
	cout << "What would you like to do?" << endl;
	cout << "[1]. Move North\n[2]. Move South\n[3]. Check your Pokemon\n[4]. Battle Wild Pokemon\n[5]. Use Rare Candy\n[6]. Exit" << endl;

	int choice = menu(1, 6); //Takes menu input

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
		return 5;  //5 is the number that will cause a wild battle to execute in pokemonMain with a bug pokemon
	}
	else if (choice == 5)
	{
		player->useCandy(); //The player uses a rare candy
	}
	else if (choice == 6)
	{
		return 9;  //9 is the special number used to exit the program
	}

}
