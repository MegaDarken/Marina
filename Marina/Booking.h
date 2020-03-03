#pragma once

#include "Watercraft.h"




class Booking
{
private:

	//Duration

	int totalCost;//Cost

	Watercraft* bookedCraft;//Watercraft pointer

public:
	Booking();
	Booking(Watercraft* bookedCraft);//Where cost is calculated from the craft
	Booking(int cost, Watercraft*);
	Booking(char ownerName[], char boatName[], int length, int draft);//New craft is created
	Booking(int cost, char ownerName[], char boatName[], int length, int draft);
	~Booking();

	//Getters and Setters
	int getTotalCost();
	Watercraft* getBookedCraft();

	char* getAsString();
	void getAsString(char* outputString);

	//Methods
	bool validLength();
	bool validDraft();
};

