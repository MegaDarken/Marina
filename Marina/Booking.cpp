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


//Conversion
void intToChar(int input, char* output)
{
	int iterations = log10(input);
	int charIndex = 0;

	for (int i = iterations; i > 0; i--)
	{
		int currentDigit = input;
		int currentPower = pow(10, iterations);

		currentDigit = currentDigit % (currentPower * 10);
		currentDigit = currentDigit / currentPower;

		output[charIndex] = ('0' + currentDigit);
		charIndex++;
	}
}

//Constructor
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
	strcat(outputString, this->bookedCraft->getOwnerName());
	strcat(outputString, this->bookedCraft->getBoatName());

	return outputString;
}

 void Booking::getAsString(char* outputString)
{
	char* tempString;

	//Add parts to string
	intToChar(this->totalCost, tempString);
	strcat(outputString, tempString);

	strcat(outputString, this->bookedCraft->getOwnerName);
	strcat(outputString, this->bookedCraft->getBoatName);

	intToChar(this->bookedCraft->getLength, tempString);
	strcat(outputString, tempString);
	intToChar(bookedCraft->getDraft, tempString);
	strcat(outputString, tempString);
	//strcat(outputString, (char*)this->bookedCraft->getLength);
	//strcat(outputString, (char*)this->bookedCraft->getDraft);

	delete tempString;
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

