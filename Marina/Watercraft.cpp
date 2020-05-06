#include "Watercraft.h"

// Constants
const std::string WatercraftCraftType = "Watercraft";//For type identification
std::string Watercraft::CraftType = WatercraftCraftType;

//Default Values


const int defaultLength = 0;
const int defaultDraft = 0;

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

	this->ownerName = new std::string;
	this->boatName = new std::string;

	this->length = defaultLength;
	this->draft = defaultDraft;
}

Watercraft::Watercraft(std::string ownerName, std::string boatName, int lengthValue, int draftValue)
{
	this->uniqueID = generateNextId();

	this->ownerName = new std::string (ownerName);
	this->boatName = new std::string (boatName);
	
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
	delete ownerName;
	delete boatName;
}

//Getters
std::string Watercraft::getCraftType()
{
	return CraftType;
}

unsigned Watercraft::getUniqueID()
{
	return this->uniqueID;
}

void Watercraft::setUniqueID(unsigned newValue)
{
	this->uniqueID = newValue;
}

std::string* Watercraft::getOwnerName()
{
	return this->ownerName;
}

void Watercraft::setOwnerName(std::string newValue)
{
	*this->ownerName = newValue;
}

std::string* Watercraft::getBoatName()
{
	return this->boatName;
}

void Watercraft::setBoatName(std::string newValue)
{
	*this->boatName = newValue;
}

int Watercraft::getLength()
{
	return this->length;
}

void Watercraft::setLength(int newValue)
{
	this->length = newValue;
}

int Watercraft::getDraft()
{
	return this->draft;
}

void Watercraft::setDraft(int newValue)
{
	this->draft = newValue;
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

void Watercraft::printAsString()
{
	std::cout << this->getUniqueID() << ": " << this->getCraftType() << ", " << *this->getBoatName() << ", " << *this->getOwnerName() << ", Length:" << this->getLength() << ", Draft:" << this->getDraft() << std::endl;
}