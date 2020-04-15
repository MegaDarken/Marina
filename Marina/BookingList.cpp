#ifndef MARNIA_H
#include "List.h"
#include "Booking.h"
#include "Watercraft.h"
#endif // !MARNIA_H

BookingList::BookingList()
{
	rootEntry = new BookingListEntry;//Start of the list's sequence
	
	rootEntry->value = new Booking;
	rootEntry->nextEntry = new BookingListEntry;

	endEntry = rootEntry;
	//currentEntry = rootEntry;

	entryCount = 0;

	std::cout << "BookingList instantiated..." << std::endl;
}

BookingList::~BookingList()
{
	//rootEntry = nullptr;
	delete rootEntry;
	delete endEntry;
}

void BookingList::InsertEntry(Booking currentBooking)
{
	endEntry = new BookingListEntry;//Make Next Entry

	//Once at an Empty Entry
	endEntry->value = new Booking(currentBooking);//Insert Value
	

	//move end to next
	endEntry = endEntry->nextEntry;

	//Increment Count
	entryCount++;
}

void BookingList::RemoveEntry(Booking currentBooking)
{
	BookingListEntry* currentEntry = rootEntry;//From the start

	Booking* checkingBooking = currentEntry->value;

	//for root node
	if (checkingBooking->getBookedCraft() == currentBooking.getBookedCraft())
	{
		//Move rootEntry to next
		rootEntry = rootEntry->nextEntry;
	}

	//{
		//While the next Entry does not contain the object; Continue
		while (currentEntry->nextEntry != nullptr)//currentEntry->nextEntry->value != currentCraft ||
		{
			currentEntry = currentEntry->nextEntry;//Move to next entry

			//Does the Booking exist?
			if (currentEntry->value != nullptr)
			{
				checkingBooking = currentEntry->value;

				//If the next entry is the one to be removed
				if (checkingBooking->getBookedCraft() == currentBooking.getBookedCraft())
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

	//}

	//Clean up memory
	//delete currentEntry;
}

Booking* BookingList::GetEntry(int entryIndex)
{
	//check index is within bounds
	if (entryIndex < 0 || entryIndex >= entryCount)
	{
		return NULL;
	}

	BookingListEntry* currentEntry = rootEntry;//From the start

	for (int i = 0; i < entryIndex; i++)
	{
		currentEntry = currentEntry->nextEntry;//Move to next entry
	}

	return (currentEntry->value);//return entry's value

	currentEntry = nullptr;
	delete currentEntry;//Used after return(?)
}

int BookingList::GetCount()
{
	return entryCount;
}

bool BookingList::Contains(Booking currentBooking)
{
	//bool matchFound = false;
	BookingListEntry* currentEntry = rootEntry;//From the start

	while (currentEntry->nextEntry != nullptr)
	{
		if (*(currentEntry->value) == currentBooking)
		{
			return true;
		}
	}

	return false;
}