#include "MotorBoat.h"

static const std::string MotorBoatCraftType = "MotorBoat";//For type identification
std::string MotorBoat::CraftType = MotorBoatCraftType;

//Constructors
MotorBoat::MotorBoat() :Watercraft()
{
}

MotorBoat::MotorBoat(std::string ownerName, std::string boatName, int length, int draft) :Watercraft(ownerName, boatName, length, draft)
{

}

MotorBoat::MotorBoat(Watercraft& obj) : Watercraft(obj)
{

}

MotorBoat::MotorBoat(MotorBoat& obj) : Watercraft(obj)
{

}


MotorBoat::~MotorBoat()
{
}

//Type Getter
std::string MotorBoat::getCraftType()
{
	return MotorBoat::CraftType;
}