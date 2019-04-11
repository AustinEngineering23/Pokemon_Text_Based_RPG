/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the main implementation file for the final project.
It is a pokemon themed game where the user must earn a gym badge
in order to win.
*/

#include <iostream>
#include <string>
#include <vector>
#include "menu.hpp"
#include "PalletTown.hpp"
#include "PewterCity.hpp"
#include "ViridianForest.hpp"
#include "Route.hpp"
#include "Monster.hpp"
#include "Charmander.hpp"
#include "Geodude.hpp"
#include "Pidgey.hpp"
#include "Caterpie.hpp"
#include "Onix.hpp"
#include "Trainer.hpp"
#include <time.h>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

int main()
{

	//Allocates the Spaces on the game Map
	Space* room1 = new PalletTown();
	Space* room2 = new Route(1);
	Space* room3 = new ViridianForest();
	Space* room4 = new Route(2);
	Space* room5 = new Route(3);
	Space* room6 = new PewterCity();

	//Links all spaces together in a linear fashion
	room1->setPointer(room2, nullptr);
	room2->setPointer(room3, room1);
	room3->setPointer(room4, room2);
	room4->setPointer(room5, room3);
	room5->setPointer(room6, room4);
	room6->setPointer(nullptr, room5);

	Monster* m1 = new Charmander(5, 7, 20, 5, "Charmander");
	Trainer player1(room1, m1);
	Trainer* playerPointer = &player1;


	srand(time(NULL)); //For random event in Route


	/***********************GAME STARTS HERE*************************/

	/*Uses Player Pointer's getSpace function to find the current Space. Then uses the current space's
	menu display function to have the user input a choice. The menu display also takes the player as a parameter,
	in case the player is needed to determine special events

	Here is the response for all the possible integer returns:
	
	menuDecision = 0 ->  No response, or a message was outputted. Game will print the same menu again
	menuDecision = 1 -> Player will attempt to move North. Next areas menu will be printed if player was moved
	menuDecision = 2 -> Player will attempt to move South. Next areas menu will be printed if player was moved
	menuDecision = 3 -> A wild Battle will begin with a Pidgey
	menuDecision = 4 -> The user will battle with Brock the gym leader
	menuDecision = 5 -> A wild Battle will begin with a Caterpie

	menuDecision = 9 -> The game will Exit if it ever returns 9.

	*/
	string name; //Player's name

	cout << "Hello there! Welcome to the world of Pokémon!" <<endl;
	cout << "My name is Oak! People call me the Pokemon Prof!" << endl;
	cout << "This world is inhabited by creatures called Pokemon! " << endl;
	cout << "For some people, Pokemon are pets. Other use them for fights. " << endl;
	cout << "Myself... I study Pokemon as a profession. " << endl;
	cout << "First, what is your name?" << endl;
	getline(cin, name);
	cout <<"Right! So your name is " << name << endl;
	cout << "Your very own Pokemon legend is about to unfold! " << endl;
	cout << "A world of dreams and adventures with Pokémon awaits! Let's go." << endl;
	cout << "\n\nBut first... Your mother asked that you be tested before" << endl;
	cout << "beginning your journey. I want you take this Charmander and" << endl;
	cout << "go challenge Brock, the Pewter City gym leader. You will find " << endl;
	cout << "him due North of here. Once you get the Boulder badge from Brock," << endl;
	cout <<"show it to me here in Pallet Town and then I will approve of your pokemon journey! " << endl;
	cout << "I must warn you though.. he is strong! If you cannot complete this " << endl;
	cout << "task within 30 days, then I'm afraid you may not be ready to begin your journey." << endl;


	int days = 0; //The time limit for the game

	//First menu Prompt
	int	menuDecision = playerPointer->getSpace()->menuDisplay(playerPointer);

	//The Program will only return a 9 if the user selected to EXIT the program in menuDisplay
	while (menuDecision != 9 && days !=30)
	{



		if (menuDecision == 1)
		{


			playerPointer->moveNorth(); //Moves Player North


		}

		else if (menuDecision == 2)
		{


			playerPointer->moveSouth(); //Moves Player South


		}

		else if (menuDecision == 3) //Will cause a wild battle with a Pidgey
		{


			if (m1->isDead())
			{
				cout << "\nYou cannot battle while Charmander is fainted!\nIt must be healed at a Pokemon Center\n" << endl;
			}
			else //Commence battle
			{

				Monster* m2 = new Pidgey(3, 4, 15, 3, "Pidgey"); //Creates the new pidgey

				cout << "\n\nWild Pidgey appeared!\n" << endl;
				int battleChoice = 0;

				//While both Pokemon are alive, fight continues
				while (!m2->isDead() && !m1->isDead() && battleChoice != 2)
				{
					//Printing Status of fighters
					cout << "\n" << m1->getName() << " Level " << m1->getLevel() << "  HP: " << m1->getHealth() << "/" << m1->getInitialHealth() << endl;
					cout << m2->getName() << " Level " << m2->getLevel() << "  HP: " << m2->getHealth() << "/" << m2->getInitialHealth();

					//Prompting for a decision
					cout << "\nChoose an action\n[1]. Attack\n[2]. Run away" << endl;
					battleChoice = menu(1, 2);

					//If choose to attack
					if (battleChoice == 1)
					{
						int attack1 = m1->attack();
						m2->defend(attack1);


						//Second phase of battle if the opponent did not die
						if (!m2->isDead())
						{
							int attack2 = m2->attack();
							m1->defend(attack2);
						}

					}
					else
					{
						cout << "\nYou fled the battle!!\n" << endl;
					}


				}


				if (m2->isDead())
				{
					cout <<"\nPidgey has fainted!" << endl;
					cout << "\nCharmander has leveled up!\n" << endl;
					m1->levelUp();
				}

				delete m2; //Deletes the Pidgey at end of random battle
			}
		}

		else if (menuDecision == 4) //This will be the gym challenge with Brock
		{
			if (playerPointer->checkBadge())
			{
				cout << "You already have the Boulder Badge, you cannot earn it again!" << endl;
			}
			else
			{



				if (m1->isDead())
				{
					cout << "\nYou cannot battle while Charmander is fainted!\nIt must be healed at a Pokemon Center\n" << endl;
				}
				else //Commence battle
				{

					cout << "\nBrock:\nI'm Brock! I'm Pewter's Gym Leader! I believe in rock hard defense and determination!" << endl;
					cout << "That's why my Pokémon are all the Rock-type! Do you still want to challenge me? Fine then! Show me your best.\n" << endl;

					Monster* m3 = new Geodude(10, 10, 22, 12, "Geodude"); //Creates the new Geodude

					cout << "\nBrock sent out Geodude!\n" << endl;
					int battleChoice = 0;

					//While both Pokemon are alive, fight continues
					while (!m3->isDead() && !m1->isDead())
					{
						//Printing Status of fighters
						cout << "\n" << m1->getName() << " Level " << m1->getLevel() << "  HP: " << m1->getHealth() << "/" << m1->getInitialHealth() << endl;
						cout << m3->getName() << " Level " << m3->getLevel() << "  HP: " << m3->getHealth() << "/" << m3->getInitialHealth();

						//Prompting for a decision
						cout << "\nChoose an action\n[1]. Attack\n[2]. Run away" << endl;
						battleChoice = menu(1, 2);

						//Does not allow for battleChoice to be 2
						if (battleChoice == 2)
						{
							cout << "\nThere is no running from a trainer battle!\n" << endl;
							battleChoice = 1;
						}

						//If choose to attack
						if (battleChoice == 1)
						{
							int attack1 = m1->attack();
							m3->defend(attack1);


							//Second phase of battle if the opponent did not die
							if (!m3->isDead())
							{
								int attack2 = m3->attack();
								m1->defend(attack2);
							}

						}

					}


					delete m3; //deletes the geodude
				}

				/***********Battling Brock's Second Pokemon**********/

				if (m1->isDead())
				{
					cout << "\nYou lose!\n" << endl;
				}
				else //Commence battle
				{
					Monster* m4 = new Onix(13, 13, 25, 14, "Onix"); //Creates the new Onix

					cout << "\nBrock sent out Onix!\n" << endl;
					int battleChoice = 0;

					//While both Pokemon are alive, fight continues
					while (!m4->isDead() && !m1->isDead())
					{
						//Printing Status of fighters
						cout << "\n" << m1->getName() << " Level " << m1->getLevel() << "  HP: " << m1->getHealth() << "/" << m1->getInitialHealth() << endl;
						cout << m4->getName() << " Level " << m4->getLevel() << "  HP: " << m4->getHealth() << "/" << m4->getInitialHealth();

						//Prompting for a decision
						cout << "\nChoose an action\n[1]. Attack\n[2]. Run away" << endl;
						battleChoice = menu(1, 2);

						//Does not allow for battleChoice to be 2
						if (battleChoice == 2)
						{
							cout << "\nThere is no running from a trainer battle!\n" << endl;
							battleChoice = 1;
						}

						//If choose to attack
						if (battleChoice == 1)
						{
							int attack1 = m1->attack();
							m4->defend(attack1);


							//Second phase of battle if the opponent did not die
							if (!m4->isDead())
							{
								int attack2 = m4->attack();
								m1->defend(attack2);
							}

						}

					}

					//If onix is defeated, then the player will get the boulder badge!
					if (m4->isDead())
					{
						cout << "\n\nBrock: I took you for granted. As proof of your victory, here's the BoulderBadge!" << endl;
						cout << "That's an official Pokemon League Badge! Its bearer's Pokemon become more powerful!\n" << endl;
						playerPointer->giveBadge(); //Gives the player the boulder badge
					}


					delete m4; //Deletes the Onix at the end of battle

				}



			}
		}
		else if (menuDecision == 5) //Battling a wild Caterpie
		{


			if (m1->isDead())
			{
				cout << "\nYou cannot battle while Charmander is fainted!\nIt must be healed at a Pokemon Center\n" << endl;
			}
			else //Commence battle
			{

				Monster* m5 = new Caterpie(3, 4, 15, 3, "Caterpie"); //Creates the new Caterpie

				cout << "\n\nWild Caterpie appeared!\n" << endl;
				int battleChoice = 0;

				//While both Pokemon are alive, fight continues
				while (!m5->isDead() && !m1->isDead() && battleChoice != 2)
				{
					//Printing Status of fighters
					cout << "\n" << m1->getName() << " Level " << m1->getLevel() << "  HP: " << m1->getHealth() << "/" << m1->getInitialHealth() << endl;
					cout << m5->getName() << " Level " << m5->getLevel() << "  HP: " << m5->getHealth() << "/" << m5->getInitialHealth();

					//Prompting for a decision
					cout << "\nChoose an action\n[1]. Attack\n[2]. Run away" << endl;
					battleChoice = menu(1, 2);

					//If choose to attack
					if (battleChoice == 1)
					{
						int attack1 = m1->attack();
						m5->defend(attack1);


						//Second phase of battle if the opponent did not die
						if (!m5->isDead())
						{
							int attack2 = m5->attack();
							m1->defend(attack2);
						}

					}
					else
					{
						cout << "\nYou fled the battle!!\n" << endl;
					}


				}


				if (m5->isDead())
				{
					cout << "\nCaterpie has fainted!" << endl;
					cout << "\nCharmander has leveled up!\n" << endl;
					m1->levelUp();
				}

				delete m5; //Deletes the Caterpie at end of random battle
			}
		}



		if (days == 25)
		{
			cout << "\nYou only have 5 days left to finish your task!!" << endl;
		}

		//Printing out the menu of the space again to allow the user to choose their next action
		cout << "Day: " << days;
		menuDecision = playerPointer->getSpace()->menuDisplay(playerPointer);
		
		days++; //Increments the counter of days
	}


	if (days == 30)
	{
		cout << "\n\nYou ran out of time! Professor Oak came to pick you up." << endl;
		cout << "You go home with broken dreams, dreaming of what might have been." << endl;
	}


	cout << "\n\nThank you for playing!!" << endl;



	delete m1;    //deallocating memory of Charmander as well as other rooms
	delete room1;
	delete room2;
	delete room3;
	delete room4;
	delete room5;
	delete room6;
	cin.get();


    return 0;
}
