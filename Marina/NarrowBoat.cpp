#include "NarrowBoat.h"

const std::string CraftType = "NarrowBoat";//For type identification

//Constructors
NarrowBoat::NarrowBoat()
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
	return CraftType;
}