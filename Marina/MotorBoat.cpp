#include "MotorBoat.h"


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
