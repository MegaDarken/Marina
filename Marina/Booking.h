#pragma once

#include "Watercraft.h"




class Booking
{
private:

	//Duration

	int totalCost;//Cost

	Watercraft* bookedCraft = nullptr;//Watercraft pointer

public:
	Booking();
	Booking(Watercraft* bookedCraft);//Where cost is calculated from the craft
	Booking(int cost, Watercraft* bookedCraft);
	Booking(char ownerName[], char boatName[], int length, int draft);//New craft is created
	Booking(int cost, std::string ownerName, std::string boatName, int length, int draft);
	~Booking();

	//Getters and Setters
	int getTotalCost();
	Watercraft* getBookedCraft();

	std::string getAsString();
	void getAsString(std::string *outputString);
	void getAsPrintString(std::string* outputString);

	//Methods
	bool validLength();
	bool validDraft();

	//Equality Operators
	bool operator==(const Booking& t);
	bool operator!=(const Booking& t);
};

