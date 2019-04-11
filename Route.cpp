/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the implementation file for the Route. It is the child of Space.

On a route space you may battle wild pokemon. You also have a 1/3 chance of getting a rare candy when moving north or South from a route
*/

#include "Route.hpp"
#include <iostream>
#include "menu.hpp"

using std::cout;
using std::endl;

//Default constructor for Route
Route::Route(int number)
{
	east = nullptr;
	west = nullptr;
	
	//Sets the name of the Route that the user is on
	if (number == 1)
	{
		areaName = "Route 1";
	}
	else if (number ==2)
	{
		areaName = "Route 2";
	}
	else
	{
		areaName = "Route 3";
	}
}

//Print function to print the map of Route
void Route::print()
{

}

//Menu Display while in Route
int Route::menuDisplay(Trainer* player)
{
	cout << "\nYou are currently in " << areaName << endl;
	cout << "What would you like to do?" << endl;
	cout << "[1]. Move North\n[2]. Move South\n[3]. Check your Pokemon\n[4]. Battle Wild Pokemon\n[5]. Use Rare candy\n[6]. Exit" << endl;

	int choice = menu(1, 6); //Takes menu input

	if (choice == 1)
	{
		//A random opportunity to gain a rare candy when moving North on a Route Space
		int randomCandy = rand() % 3 + 1;
		if (randomCandy == 1)
		{
			player->giveRareCandy();
		}

		return 1; //Player will be moving North
	}
	else if (choice == 2)
	{
		//A random opportunity to gain a rare candy when moving North on a Route Space
		int randomCandy = rand() % 3 + 1;
		if (randomCandy == 1)
		{
			player->giveRareCandy();
		}

		return 2; //Player will be moving South
	}
	else if (choice == 3)
	{
		player->checkPokemon(); //Checks the Player's Pokemon Status
	}
	else if (choice == 4)
	{
		return 3;  //3 is the number that will cause a wild battle to execute in pokemonMain
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


