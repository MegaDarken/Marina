#include "userInput.h"

void userInput::takeInput(const char* prompt, char* returnedInput)
{
	//Prompt user
	std::cout << prompt;

	//Remove Prompt from input
	std::cin.clear();

	//Take input
	std::cin.getline(returnedInput,12); //returnedInput;
}

void userInput::takeInput(const char* prompt, std::string* returnedInput)
{
	takeInput(prompt, (char*)returnedInput);
}

void userInput::takeInput(const std::string* prompt, std::string* returnedInput)
{
	takeInput((char*)prompt, (char*)returnedInput);
}

//Handle booking
void userInput::userRecordBooking(BookingList& bookingRecords)
{
	//Show user records
	viewRecords(bookingRecords);

	//Initalise Object
	Booking* newBooking = new Booking(new Watercraft());

	//Promt user for booking details
	takeInput("Owner's Name:", newBooking->getBookedCraft()->getOwnerName());//Collect inputs
	takeInput("Boat Name:", newBooking->getBookedCraft()->getBoatName());
	//std::cout << ownerName;

	//Show 
	newBooking->getAsString();

	//Push to list


	//Remove Variables
	delete 
}

void userInput::userRecordDelete(BookingList& bookingRecords)
{
	//Data Inital
	Booking* selectedBooking = new Booking();
	bool matchFound;

	//Show user records
	viewRecords(bookingRecords);

	//Select Entry
	takeInput("Owner's Name:", selectedBooking->getBookedCraft()->getOwnerName());//Collect inputs
	takeInput("Boat Name:", selectedBooking->getBookedCraft()->getBoatName());

	//Get matching booking?
	matchFound = bookingRecords.Contains(*selectedBooking);

	//If a match is found
	if (matchFound)
	{
		//Remove Booking
		bookingRecords.RemoveEntry(*selectedBooking);

		//Remove Boat from marina?


	}

	//Remove from memory
	delete selectedBooking;
	//delete matchFound;
}

void userInput::viewRecords(BookingList& bookingRecords)
{
	//Instantiate output char array
	char* outputArray = new char;

	//for each of the vector's elements
	for (size_t index = 0; index < bookingRecords.GetCount(); index++)
	{
		//clear array
		outputArray = new char;

		//get record as string
		bookingRecords.GetEntry(index)->getAsString(outputArray);

		//print record as string
		std::cout << outputArray << std::endl;
	}

	//Remove the single char array from memory
	delete outputArray;

	return;
}