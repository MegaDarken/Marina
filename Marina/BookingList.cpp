
#include "List.h"

BookingList::BookingList()
{
	rootEntry = new BookingListEntry;//Start of the list's sequence

	endEntry = rootEntry;
	//currentEntry = rootEntry;
}

BookingList::~BookingList()
{
	rootEntry = nullptr;
	delete rootEntry;
	delete endEntry;
}

void BookingList::InsertEntry(Booking currentBooking)
{
	//Once at an Empty Entry
	endEntry->value = Booking(currentBooking);//Insert Value
	endEntry->nextEntry = new BookingListEntry;//Make Next Entry

	//move end to next
	endEntry = endEntry->nextEntry;

	//Increment Count
	entryCount++;
}

void BookingList::RemoveEntry(Booking currentBooking)
{
	BookingListEntry* currentEntry = rootEntry;//From the start

	//for root node
	if (currentEntry->value.getBookedCraft() == currentBooking.getBookedCraft())
	{
		//Move rootEntry to next
		rootEntry = rootEntry->nextEntry;
	}

	{
		//While the next Entry does not contain the object; Continue
		while (currentEntry->nextEntry != nullptr)//currentEntry->nextEntry->value != currentCraft ||
		{
			currentEntry = currentEntry->nextEntry;//Move to next entry

			//If the next entry is the one to be removed
			if (currentEntry->nextEntry->value.getBookedCraft() == currentBooking.getBookedCraft())
			{
				BookingListEntry* chosenEntry = currentEntry->nextEntry;

				//skip over the entry
				currentEntry->nextEntry = chosenEntry->nextEntry;

				delete chosenEntry;

				//De-increment Count
				entryCount--;
			}
		}

	}
}

Booking* BookingList::GetEntry(int entryIndex)
{

}
