#pragma once
//Include(s) 
#ifndef MARNIA_L
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#endif // !MARNIA_L

class Watercraft
{
	const std::string CraftType = "Watercraft";//For type identification

protected:
	unsigned uniqueID;//Unique Identifier (For integrity)

	//Names
	std::string ownerName;
	std::string boatName;

	int length;
	int draft;

	static int craftIdCounter;
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

	//std::string GetCraftType();
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
