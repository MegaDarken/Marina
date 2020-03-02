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
	//for each of the vector's elements
	for (size_t index = 0; index < bookingRecords.size(); index++)
	{
		//print record as string
		std::cout << bookingRecords[index].getAsString() << std::endl;
	}
}