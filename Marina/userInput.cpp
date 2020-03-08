#include "userInput.h"

void userInput::userRecordBooking(std::vector<Booking>& bookingRecords)
{
	//Show user records
	viewRecords(bookingRecords);

	//Initalise Variables

	//Promt user for booking details

	//Collect inputs

	//Construct Object

	//Push to vector

}

void userInput::userRecordDelete(std::vector<Booking>& bookingRecords)
{
	//Show user records
	viewRecords(bookingRecords);

	//

}

void userInput::viewRecords(std::vector<Booking> &bookingRecords)
{
	//Instantiate output char array
	char* outputArray;

	//for each of the vector's elements
	for (size_t index = 0; index < bookingRecords.size(); index++)
	{
		//clear array
		outputArray = new char[];

		//get record as string
		bookingRecords[index].getAsString(outputArray);

		//print record as string
		std::cout << outputArray << std::endl;
	}

	//Remove the single char array from memory
	delete outputArray;

	return;
}