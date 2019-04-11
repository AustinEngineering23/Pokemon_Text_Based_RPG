/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the header file for the PewterCity class. It is the child of Space.
*/
#include "Space.hpp"
#include "Trainer.hpp"

#ifndef PEWTERCITY_HPP
#define PEWTERCITY_HPP
class PewterCity : public Space
{
public:
	PewterCity();
	void print();
	int menuDisplay(Trainer*);
};
#endif

