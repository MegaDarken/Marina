#include "userInput.h"

void userInput::userRecordBooking()
{
	//

}

void userInput::userRecordDelete()
{
	//

}

void userInput::viewRecords(std::vector<Booking> &bookingRecords)
{
	//Instantiate output char array
	char* outputArray;

	//for each of the vector's elements
	for (size_t index = 0; index < bookingRecords.size(); index++)
	{
		//get record as string
		bookingRecords[index].getAsString(outputArray);

		//print record as string
		std::cout << outputArray << std::endl;
	}

	//Remove the single char array from memory
}