/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the header file for the Pallet Town class. It is the child of Space.
*/
#include "Space.hpp"
#include "Trainer.hpp"

#ifndef PALLETTOWN_HPP
#define PALLETTOWN_HPP
class PalletTown: public Space
{
public:
	PalletTown();
	void print();
	int menuDisplay(Trainer*);
	int talkToOak(Trainer*);
};
#endif

