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
	~Booking();

	//Getters and Setters
	int getTotalCost();
	Watercraft* getBookedCraft();


	//Methods
	bool validLength();
	bool validDraft();
};

