#include "NarrowBoat.h"

const std::string NarrowBoatCraftType = "NarrowBoat";//For type identification
std::string NarrowBoat::CraftType = NarrowBoatCraftType;

//Constructors
NarrowBoat::NarrowBoat() :Watercraft()
{
}

NarrowBoat::NarrowBoat(std::string ownerName, std::string boatName, int length, int draft) :Watercraft(ownerName, boatName, length, draft)
{

}

NarrowBoat::NarrowBoat(Watercraft& obj) : Watercraft(obj)
{

}

NarrowBoat::NarrowBoat(NarrowBoat& obj) : Watercraft(obj)
{

}

NarrowBoat::~NarrowBoat()
{
}

//Type Getter
std::string NarrowBoat::getCraftType()
{
	return NarrowBoat::CraftType;
}