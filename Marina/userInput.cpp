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

//Handle booking
void userInput::userRecordBooking(BookingList& bookingRecords)
{
	//Show user records
	viewRecords(bookingRecords);

	//Initalise Variables
	char* ownerName = new char();

	//Promt user for booking details
	takeInput("", ownerName);//Collect inputs
	std::cout << ownerName;

	//Construct Object


	//Push to vector


	//Remove Variables

}

void userInput::userRecordDelete(BookingList& bookingRecords)
{
	//Show user records
	viewRecords(bookingRecords);

	//Select Entry

	

	//Remove from vector


	//Remove Boat from marina?


	//Remove from memory

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