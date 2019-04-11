/*
Author: Austin Henry
Date: 8/14/2018
Assignment: Final Project

This is the header file for the Space class. It is abstract.
*/
#include <string>
using std::string;

#ifndef SPACE_HPP
#define SPACE_HPP

class Trainer; //Forward Declaration so that Space knows Trainer will exist

class Space
{
protected:
	Space* north;
	Space* south;
	Space* east;
	Space* west;
	string areaName;

public:
	Space();
	virtual void print() = 0;
	virtual int menuDisplay(Trainer*) =0;
	virtual void setPointer(Space*, Space*);
	string getAreaName();
	Space* getNorth();
	Space* getSouth();

};
#endif
