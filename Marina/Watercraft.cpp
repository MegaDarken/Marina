#include "Watercraft.h"

// Constants
//Default Values

Watercraft::Watercraft()
{
}

Watercraft::Watercraft(int lengthValue, int berthValue)
{
	this->length = lengthValue;
	this->berth = berthValue;
}


Watercraft::~Watercraft()
{
}

//Getters
unsigned Watercraft::getUniqueID()
{
	return uniqueID;
}

int Watercraft::getLength()
{
	return length;
}

int Watercraft::getBerth()
{
	return berth;
}

