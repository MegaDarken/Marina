#ifndef MARNIA_H
#include "List.h"
#include "Booking.h"
#include "Watercraft.h"
#endif // !MARNIA_H

BookingList::BookingList()
{
	rootEntry = new BookingListEntry();//Start of the list's sequence
	
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

void BookingList::InsertEntry(Booking* currentBooking)
{
	//New Entry
	//BookingListEntry* newEntry = new BookingListEntry;
	//newEntry->value = currentBooking;//Insert Value

	//Insert value
	endEntry->value = currentBooking;

	endEntry->nextEntry = new BookingListEntry;//Hold Next entry

	endEntry = endEntry->nextEntry;

	//Increment Count
	entryCount++;
}

void BookingList::InsertEntry(Booking currentBooking)
{
	InsertEntry(new Booking(currentBooking));
}

void BookingList::InsertEntry(Booking* currentCraft, const int index)
{
	//check index is within bounds
	if (index < 0 || index > entryCount)
	{
		return;
	}

	BookingListEntry* currentEntry = rootEntry;//From the start

	for (int i = 0; i < index; i++)
	{
		currentEntry = currentEntry->nextEntry;//Move to next entry
	}

	//New Entry
	BookingListEntry* newEntry = new BookingListEntry;
	newEntry->value = currentCraft;//Insert Value

	newEntry->nextEntry = currentEntry->nextEntry;//Hold Next entry

	//Insert Entry
	currentEntry->nextEntry = newEntry;

	//Increment Count
	entryCount++;
}

void BookingList::RemoveEntry(Booking currentBooking)
{
	BookingListEntry* currentEntry = rootEntry;//From the start

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Booking* checkingBooking = nullptr;// = currentEntry->value;

	checkingBooking = currentEntry->value;

	//for root node
	if (*checkingBooking == currentBooking)//*(currentEntry->value) == currentBooking
	{
		//Move rootEntry to next
		rootEntry = rootEntry->nextEntry;

		//De-increment Count
		entryCount--;
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

void BookingList::RemoveEntry(int Index)
{
	//check index is within bounds
	if (Index < 0 || Index > entryCount)
	{
		return;
	}

	//If root entry
	if (Index == 0)
	{
		//skip over the entry
		rootEntry = rootEntry->nextEntry;
	}
	else
	{
		BookingListEntry* currentEntry = rootEntry;//From the start

		for (int i = 0; i < Index; i++)
		{
			currentEntry = currentEntry->nextEntry;//Move to next entry
		}

		BookingListEntry* chosenEntry = currentEntry;

		//skip over the entry
		currentEntry = currentEntry->nextEntry;

		//Remove entry
		delete chosenEntry;
	}

	//De-increment Count
	entryCount--;



	return;
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

	while (currentEntry != nullptr)
	{
		if (*(currentEntry->value) == currentBooking)
		{
			return true;
		}

		currentEntry = currentEntry->nextEntry;
	}

	return false;
}

int BookingList::GetIndex(Booking currentBooking)
{
	BookingListEntry* currentEntry = rootEntry;//From the start

	//Track the index we are currently on.
	int currentIndex = 0;

	//Check each entry
	while (currentEntry != nullptr)
	{
		//Does match exist?
		if (*(currentEntry->value) == currentBooking)
		{
			//Match found
			return currentIndex;
		}

		currentEntry = currentEntry->nextEntry;

		//Increment index counter
		currentIndex++;
	}

	//No match found
	return -1;
}

bool BookingList::VerifyIntegrity()
{
	BookingListEntry* currentEntry = rootEntry;//From the start

	while (currentEntry != nullptr)
	{
		if ((currentEntry->value) == nullptr)
		{
			return false;
		}

		currentEntry = currentEntry->nextEntry;
	}

	return true;
}