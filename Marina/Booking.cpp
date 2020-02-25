#include "Booking.h"


//Constants
const int MaximumBoatLength = 15;//As defined in brief
const int MaximumBoatDraft = 5;
const int PoundsPerMeterPerMonth = 10;


Booking::Booking()
{
}


Booking::~Booking()
{
}


int Booking::getTotalCost()
{
	return totalCost;
}

Watercraft* Booking::getBookedCraft()
{
	return bookedCraft;
}

bool Booking::validLength()
{
	return (bookedCraft->getLength <= MaximumBoatLength);
}

bool Booking::validDraft()
{
	return (bookedCraft->getDraft <= MaximumBoatDraft);
}

