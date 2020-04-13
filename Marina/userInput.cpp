#include "userInput.h"

void userInput::takeInputChar(const char* prompt, char* returnedInput)
{
	//Prompt user
	std::cout << prompt;

	//Remove Prompt from input
	std::cin.clear();

	//Take input
	std::cin.getline(returnedInput,12); //returnedInput;
}

void userInput::takeInputCharString(const char* prompt, std::string* returnedInput)
{
	//Clear non-digits from input buffer
	if (std::cin.peek() == '\n')
	{
		std::cin.ignore();
	}

	//Prompt user
	std::cout << prompt;

	//Remove Prompt from input
	std::cin.clear();

	//Take input
	std::getline(std::cin, *returnedInput);

	return;
}

void userInput::takeInputString(const std::string* prompt, std::string* returnedInput)
{
	takeInputCharString((char*)prompt, returnedInput);
}

//Handle booking
void userInput::userRecordBooking(BookingList& bookingRecords)
{
	std::string* outputString = new std::string;

	//Show user records
	viewRecords(bookingRecords);

	//Initalise Object
	Booking* newBooking = new Booking(new Watercraft());

	//Promt user for booking details

	takeInputCharString("Owner's Name:", outputString);//Collect inputs
	newBooking->getBookedCraft()->setOwnerName(*outputString);

	takeInputCharString("Boat Name:", outputString);
	newBooking->getBookedCraft()->setBoatName(*outputString);
	//std::cout << ownerName;

	//Show 
	
	newBooking->printAsString();
	std::cout << std::endl;

	//Push to list
	bookingRecords.InsertEntry(*newBooking);

	//Remove Variables
	delete newBooking;
	delete outputString;
}

void userInput::userRecordDelete(BookingList& bookingRecords)
{
	//Data Inital
	Booking* selectedBooking = new Booking();
	bool matchFound;

	//Show user records
	viewRecords(bookingRecords);

	//Select Entry
	takeInputCharString("Owner's Name:", selectedBooking->getBookedCraft()->getOwnerName());//Collect inputs
	takeInputCharString("Boat Name:", selectedBooking->getBookedCraft()->getBoatName());

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
	std::string *outputString = new std::string;

	//for each of the vector's elements
	for (int index = 0; index < bookingRecords.GetCount(); index++)
	{
		//clear array
		outputString = new std::string;


		//Display index
		std::cout << index << ':';

		//print record as string
		bookingRecords.GetEntry(index)->printAsString();
		std::cout << std::endl;
	}

	//Remove the single char array from memory
	delete outputString;

	return;
}