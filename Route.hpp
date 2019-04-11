/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the header file for the Route class. It is the child of Space.
*/
#include "Space.hpp"
#include "Trainer.hpp"

#ifndef ROUTE_HPP
#define ROUTE_HPP
class Route : public Space
{
public:
	Route(int);
	void print();
	int menuDisplay(Trainer*);
};
#endif


