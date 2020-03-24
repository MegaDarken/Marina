#ifndef MARNIA_H
#include "List.h"
#include "Booking.h"
#include "Watercraft.h"
#endif // !MARNIA_H

BookingList::BookingList()
{
	rootEntry = new BookingListEntry;//Start of the list's sequence

	endEntry = rootEntry;
	currentEntry = rootEntry;

	entryCount = 0;
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
	endEntry->value = new Booking(currentBooking);//Insert Value
	endEntry->nextEntry = new BookingListEntry;//Make Next Entry

	//move end to next
	endEntry = endEntry->nextEntry;

	//Increment Count
	entryCount++;
}

void BookingList::RemoveEntry(Booking currentBooking)
{
	currentEntry = rootEntry;//From the start



	//for root node
	if (currentEntry->value.getBookedCraft() == currentBooking.getBookedCraft())
	{
		//Move rootEntry to next
		rootEntry = rootEntry->nextEntry;
	}

	//{
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

	//}

	//Clean up memory
	//delete currentEntry;
}

Booking* BookingList::GetEntry(int entryIndex)
{
	//check index is within bounds
	if (entryIndex < 0 || entryIndex > entryCount)
	{
		return NULL;
	}

	BookingListEntry* currentEntry = rootEntry;//From the start

	for (int i = 0; i < entryIndex; i++)
	{
		currentEntry = currentEntry->nextEntry;//Move to next entry
	}

	return (currentEntry->value);//return entry's value

	delete currentEntry;//Used after return
}

int BookingList::GetCount()
{
	return entryCount;
}