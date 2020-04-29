
#include "List.h"

const int defaultMaximumLengthMeters = 150;//Max allowed, As defined in brief
const int defaultMaximumDraftMeters = 5;

const int startingLengthMeters = 0;

WatercraftList::WatercraftList()
{
	rootEntry = new WatercraftListEntry;//Start of the list's sequence


	currentEntry = rootEntry;

	entryCount = 0;

	//Size related
	maximumLengthMeters = defaultMaximumLengthMeters;
	maximumDraft = defaultMaximumDraftMeters;

	currentTotalLength = startingLengthMeters;
}

WatercraftList::~WatercraftList()
{
}

void WatercraftList::InsertEntry(Watercraft* currentCraft)
{
	currentEntry = rootEntry;//From the start

	//While the next Entry does not already have a craft
	while (currentEntry->nextEntry != nullptr)
	{
		currentEntry = currentEntry->nextEntry;//Move to next entry
	}

	//Once at an Empty Entry
	currentEntry = new WatercraftListEntry;//Make Next Entry
	currentEntry->value = currentCraft;//Insert Value

	//Increment Count
	entryCount++;
}

void WatercraftList::InsertEntry(Watercraft currentCraft)
{
	InsertEntry(new Watercraft(currentCraft));
}

void WatercraftList::InsertEntry(Watercraft* currentCraft, const int index)
{
	//check index is within bounds
	if (index < 0 || index > entryCount)
	{
		return;
	}

	currentEntry = rootEntry;//From the start

	for (int i = 0; i < index; i++)
	{
		currentEntry = currentEntry->nextEntry;//Move to next entry
	}

	//New Entry
	WatercraftListEntry* newEntry = new WatercraftListEntry;
	newEntry->value = currentCraft;//Insert Value

	newEntry->nextEntry = currentEntry->nextEntry;//Hold Next entry
	
	//Insert Entry
	currentEntry->nextEntry = newEntry;

	//Increment Count
	entryCount++;
}

void WatercraftList::RemoveEntry(Watercraft currentCraft)
{
	currentEntry = rootEntry;//From the start

	//for root node
	if (currentEntry->value == &currentCraft)
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
			if (currentEntry->nextEntry->value == &currentCraft)
			{
				WatercraftListEntry* chosenEntry = currentEntry->nextEntry;

				//skip over the entry
				currentEntry->nextEntry = chosenEntry->nextEntry;

				delete chosenEntry;

				//De-increment Count
				entryCount--;
			}
		}

	}
}

void WatercraftList::RemoveEntry(int Index)
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
		currentEntry = rootEntry;//From the start

		for (int i = 0; i < Index; i++)
		{
			currentEntry = currentEntry->nextEntry;//Move to next entry
		}

		WatercraftListEntry* chosenEntry = currentEntry;

		//skip over the entry
		currentEntry = currentEntry->nextEntry;

		//Remove entry
		delete chosenEntry;
	}

	//De-increment Count
	entryCount--;

	return;
}

Watercraft* WatercraftList::GetEntry(int entryIndex)
{
	//check index is within bounds
	if (entryIndex < 0 || entryIndex > entryCount)
	{
		return NULL;
	}

	currentEntry = rootEntry;//From the start

	for (int i = 0; i < entryIndex; i++)
	{
		currentEntry = currentEntry->nextEntry;//Move to next entry
	}

	return (currentEntry->value);//return entry's value
}

int WatercraftList::GetCount()
{
	return entryCount;
}

int WatercraftList::GetCurrentTotalLength()
{
	return currentTotalLength;
}

bool WatercraftList::Contains(Watercraft currentWatercraft)
{
	currentEntry = rootEntry;//From the start

	//Check each entry
	while (currentEntry != nullptr)
	{
		//Does match exist?
		if (*(currentEntry->value) == currentWatercraft)
		{
			//Match found
			return true;
		}

		currentEntry = currentEntry->nextEntry;
	}

	//No match found
	return false;
}

int WatercraftList::GetIndex(Watercraft currentWatercraft)
{
	currentEntry = rootEntry;//From the start

	//Track the index we are currently on.
	int currentIndex = 0;

	//Check each entry
	while (currentEntry != nullptr)
	{
		//Does match exist?
		if (*(currentEntry->value) == currentWatercraft)
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

bool WatercraftList::VerifyIntegrity()
{
	currentEntry = rootEntry;//From the start

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