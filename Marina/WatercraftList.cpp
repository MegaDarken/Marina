
#include "List.h"


WatercraftList::WatercraftList()
{
	rootEntry = new WatercraftListEntry;//Start of the list's sequence


	currentEntry = rootEntry;

	entryCount = 0;
}

WatercraftList::~WatercraftList()
{
}

void WatercraftList::InsertEntry(Watercraft currentCraft)
{
	currentEntry = rootEntry;//From the start

	//While the next Entry does not already have a craft
	while (currentEntry->nextEntry != nullptr)
	{
		currentEntry = currentEntry->nextEntry;//Move to next entry
	}

	//Once at an Empty Entry
	currentEntry = new WatercraftListEntry;//Make Next Entry
	currentEntry->value = Watercraft(currentCraft);//Insert Value

	//Increment Count
	entryCount++;
}

void WatercraftList::RemoveEntry(Watercraft currentCraft)
{
	currentEntry = rootEntry;//From the start

	//for root node
	if (currentEntry->value == currentCraft)
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
			if (currentEntry->nextEntry->value == currentCraft)
			{
				WatercraftListEntry* chosenEntry = currentEntry->nextEntry;

				//skip over the entry
				currentEntry->nextEntry = chosenEntry->nextEntry;

				delete chosenEntry;
			}
		}

	}

	//De-increment Count
	entryCount--;
}

