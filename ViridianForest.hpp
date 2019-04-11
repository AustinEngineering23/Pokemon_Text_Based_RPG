/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the header file for the Viridian Forest class. It is the child of Space.
*/
#include "Space.hpp"
#include "Trainer.hpp"

#ifndef VIRIDIANFOREST_HPP
#define VIRIDIANFOREST_HPP
class ViridianForest : public Space
{
public:
	ViridianForest();
	void print();
	int menuDisplay(Trainer*);
};
#endif
