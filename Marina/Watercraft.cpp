#include "Watercraft.h"

// Constants
//Default Values


const int defaultLength = 15;
const int defaultDraft = 5;

//Initalise Static 
int  Watercraft::craftIdCounter = 0;

int Watercraft::generateNextId()
{
	/*if (craftIdCounter == NULL)
	{
		craftIdCounter = 0;
	}*/
	//Increment
	craftIdCounter++;

	return craftIdCounter;
}

//Constructors
Watercraft::Watercraft()
{
	this->uniqueID = generateNextId();


	this->length = defaultLength;
	this->draft = defaultDraft;
}

Watercraft::Watercraft(std::string ownerName, std::string boatName, int lengthValue, int draftValue)
{
	this->uniqueID = generateNextId();

	this->ownerName = ownerName;
	this->boatName = boatName;
	
	this->length = lengthValue;
	this->draft = draftValue;
}

//Copy
Watercraft::Watercraft(Watercraft &object)
{
	this->uniqueID = object.uniqueID;
	this->ownerName = object.ownerName;
	this->boatName = object.boatName;
	this->length = object.length;
	this->draft = object.draft;
}

Watercraft::~Watercraft()
{
}

//Getters
unsigned Watercraft::getUniqueID()
{
	return uniqueID;
}

std::string Watercraft::getOwnerName()
{
	return this->ownerName;
}

std::string Watercraft::getBoatName()
{
	return this->boatName;
}

int Watercraft::getLength()
{
	return length;
}

int Watercraft::getDraft()
{
	return draft;
}

//Boolian Operators
bool Watercraft::operator==(const Watercraft &current)
{
	bool result = true;//Returned Value

	if (this->uniqueID != current.uniqueID) { result = false; }

	if (this->ownerName != current.ownerName) { result = false; }
	if (this->boatName != current.boatName) { result = false; }

	if (this->length != current.length) { result = false; }
	if (this->draft != current.draft) { result = false; }

	return result;
}

bool Watercraft::operator!=(const Watercraft &current)
{
	bool result = false;

	if (this->uniqueID != current.uniqueID) { result = true; }

	if (this->ownerName != current.ownerName) { result = true; }
	if (this->boatName != current.boatName) { result = true; }

	if (this->length != current.length) { result = true; }
    if (this->draft != current.draft) { result = true; }
	

	return result;
}

