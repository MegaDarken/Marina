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

//Copy
Watercraft::Watercraft(Watercraft &object)
{
	this->uniqueID = object.uniqueID;
	this->length = object.length;
	this->berth = object.berth;
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

bool Watercraft::operator==(const Watercraft &current)
{
	bool result = true;

	if (this->uniqueID != current.uniqueID) { result = false; }
	if (this->length != current.length) { result = false; }
	if (this->berth != current.berth) { result = false; }

	return result;
}

bool Watercraft::operator!=(const Watercraft &current)
{
	bool result = true;

	if (this->uniqueID == current.uniqueID &&
		this->length == current.length &&
		this->berth == current.berth) {
		result = false;
	}

	return result;
}

