#include "SailingBoat.h"

static const std::string CraftType = "SailingBoat";//For type identification

//Constructors
SailingBoat::SailingBoat()
{
}

SailingBoat::SailingBoat(std::string ownerName, std::string boatName, int length, int draft) :Watercraft(ownerName, boatName, length, draft)
{

}

SailingBoat::SailingBoat(Watercraft& obj) : Watercraft(obj)
{

}

SailingBoat::SailingBoat(SailingBoat& obj) :Watercraft(obj)
{

}

SailingBoat::~SailingBoat()
{
}

//Type Getter
std::string SailingBoat::getCraftType()
{
	return CraftType;
}