#include "SailingBoat.h"


//Constructors
SailingBoat::SailingBoat()
{
}

SailingBoat::SailingBoat(std::string ownerName, std::string boatName, int length, int draft) :Watercraft(ownerName, boatName, length, draft)
{

}

SailingBoat::~SailingBoat()
{
}
