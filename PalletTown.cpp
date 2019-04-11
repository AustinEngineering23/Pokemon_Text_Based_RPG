/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the implementation file for the Pallet Town class. It is the child of Shape
*/

#include "PalletTown.hpp"
#include <iostream>
#include "menu.hpp"

using std::cout;
using std::endl;

//Default constructor for Pallet Town
PalletTown::PalletTown() : Space()
{
	areaName = "PalletTown";
}

//Print function to print the map of Pallet Town
void PalletTown::print()
{

}

//Menu Display while in Pallet Town
int PalletTown::menuDisplay(Trainer* player)
{
	cout << "\nYou are currently in " << areaName << endl;
	cout << "What would you like to do?" << endl;
	cout << "[1]. Move North\n[2]. Move South\n[3]. Talk to Professor Oak\n[4]. Check your Pokemon\n[5]. Use Rare Candy\n[6]. Exit" << endl;

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
		return talkToOak(player); //Talks to Professor Oak. Returns 0 if doesn't have the badge. If has the badge, returns 9 to exit game
	}
	else if (choice == 4)
	{
		player->checkPokemon(); //Checks the Player's Pokemon Status
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

//Talking to Professor Oak, checking for win condition
int PalletTown::talkToOak(Trainer* player)
{
	if (player->checkBadge())
	{
		cout << "\nCongratulations!! I see you have the boulder badge.\nYou have clearly demonstrated you are ready to become a trainer." << endl;
		cout << "I wish you the best of luck on your future journies!\n" << endl;
		return 9;
	}
	else 
	{
		cout << "\nIt seems like your journey is coming along fine! Make sure to level up your Pokemon." << endl;
		cout << "And don't forget to get the boulder badge from Brock in Pewter City!!\n" << endl;
		return 0;
	}
	
}
