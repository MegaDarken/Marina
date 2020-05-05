#include "MotorBoat.h"

static const std::string CraftType = "MotorBoat";//For type identification

//Constructors
MotorBoat::MotorBoat()
{
}

MotorBoat::MotorBoat(std::string ownerName, std::string boatName, int length, int draft) :Watercraft(ownerName, boatName, length, draft)
{

}

MotorBoat::~MotorBoat()
{
}

//Type Getter
std::string MotorBoat::getCraftType()
{
	return CraftType;
}