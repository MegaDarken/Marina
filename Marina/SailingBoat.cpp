#include "SailingBoat.h"

static const std::string SailingBoatCraftType = "SailingBoat";//For type identification
std::string SailingBoat::CraftType = SailingBoatCraftType;

//Constructors
SailingBoat::SailingBoat() : Watercraft()
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
	return SailingBoat::CraftType;
}