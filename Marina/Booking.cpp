#ifndef MARNIA_H
#include <iostream>
#include <cstdlib>
#include <vector>

#include "List.h"
#include "Booking.h"
#include "Watercraft.h"
#endif // !MARNIA_H

//Constants
const int MaximumBoatLength = 15;//As defined in brief
const int MaximumBoatDraft = 5;
const int PoundsPerMeterPerMonth = 10;

const char splitChar = ';';

Booking::Booking()
{
}

Booking::Booking(Watercraft* bookedCraft)
{
	this->bookedCraft = bookedCraft;

	//Calculate Cost
}

Booking::Booking(int cost, Watercraft*)
{
	this->totalCost = cost;
	this->bookedCraft = bookedCraft;
}

Booking::Booking(char ownerName[], char boatName[], int length, int draft)
{
	//Create watercraft
	this->bookedCraft = new Watercraft(ownerName, boatName, length, draft);

	//Calculate cost
}

Booking::Booking(int cost, char ownerName[], char boatName[], int length, int draft)
{
	this->totalCost = cost;

	//Create watercraft
	this->bookedCraft = new Watercraft(ownerName, boatName, length, draft);

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

char* Booking::getAsString()
{
	char* outputString;

	//Add parts to string
	strcat(outputString, bookedCraft->getOwnerName);
	strcat(outputString, bookedCraft->getBoatName);

	return outputString;
}

 void Booking::getAsString(char* outputString)
{
	//char* outputString;

	//Add parts to string
	strcat(outputString, (char*)totalCost);

	strcat(outputString, bookedCraft->getOwnerName);
	strcat(outputString, bookedCraft->getBoatName);

	strcat(outputString, (char*)bookedCraft->getLength);
	strcat(outputString, (char*)bookedCraft->getDraft);

	//return outputString;
}

bool Booking::validLength()
{
	return (bookedCraft->getLength <= MaximumBoatLength);
}

bool Booking::validDraft()
{
	return (bookedCraft->getDraft <= MaximumBoatDraft);
}

