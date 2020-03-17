#pragma once
//Include(s) 
#ifndef MARNIA_H
#include <iostream>
#include <cstdlib>
#include <vector>

#include "List.h"
#include "Booking.h"
#include "Watercraft.h"
#endif // !MARNIA_H

class Watercraft
{
protected:
	unsigned uniqueID;//Unique Identifier (For integrity)

	//Names
	std::string ownerName;
	std::string boatName;

	int length;
	int draft;

	static int IdCounter;
	int generateNextId();
public:
	Watercraft();
	Watercraft(std::string ownerName, std::string boatName, int length, int draft);
	Watercraft(Watercraft &obj);//Copy Constructor
	~Watercraft();//Descructor

	//Getters and Setters
	unsigned getUniqueID();

	std::string getOwnerName();
	std::string getBoatName();

	int getLength();
	int getDraft();

	//Equality Operators
	bool operator==(const Watercraft &t);
	bool operator!=(const Watercraft &t);

	
};
//Polymorphism is able to be used to Inherit to Specific types of Craft/Boat (narrow, sailing, or motor)

//bool Watercraft::operator==()
//{
//
//}
//
//bool Watercraft::operator!=()
//{
//
//}
