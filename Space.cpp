/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the implementation file for the Space class.
*/
#include "Space.hpp"
#include "Trainer.hpp"


//Default sets east and west to nullptr
Space::Space()
{
	east = nullptr;
	west = nullptr; 
}

//Sets Pointers for space
void Space::setPointer(Space* northPtr, Space* southPtr)
{
	north = northPtr;
	south = southPtr;
}

//Returns name of the area
string Space::getAreaName()
{
	return areaName;
}

//Return the north Pointer
Space* Space::getNorth()
{
	return north;
}

//Return the south Pointer
Space* Space::getSouth()
{
	return south;
}
