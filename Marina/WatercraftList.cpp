
#include "List.h"

const int defaultMaximumLengthMeters = 150;//Max allowed, As defined in brief
const int defaultMaximumDraftMeters = 5;

const int defaultMaximumIndividualLengthMeters = 15;

const int startingLengthMeters = 0;

WatercraftList::WatercraftList()
{
	rootEntry = new WatercraftListEntry;//Start of the list's sequence

	//Ensure not empty
	rootEntry->value = nullptr;//new Watercraft;
	rootEntry->nextEntry = nullptr;//new WatercraftListEntry;

	currentEntry = rootEntry;

	entryCount = 0;

	//Size related
	maximumLengthMeters = defaultMaximumLengthMeters;
	maximumDraft = defaultMaximumDraftMeters;

	maximumIndividualLengthMeters = defaultMaximumIndividualLengthMeters;

	currentTotalLength = startingLengthMeters;
}

WatercraftList::WatercraftList(int maximumLengthMeters, int maximumDraftMeters, int maximumIndividualLengthMeters)
{
	rootEntry = new WatercraftListEntry;//Start of the list's sequence

	//Ensure not null
	rootEntry->value = nullptr;//new Watercraft;
	rootEntry->nextEntry = nullptr;//new WatercraftListEntry;


	currentEntry = rootEntry;

	entryCount = 0;

	//Size related
	this->maximumLengthMeters = maximumLengthMeters;
	this->maximumDraft = maximumDraftMeters;

	this->maximumIndividualLengthMeters = maximumIndividualLengthMeters;

	currentTotalLength = startingLengthMeters;
}


WatercraftList::~WatercraftList()
{
}

void WatercraftList::InsertEntry(Watercraft* currentCraft)
{
	//Check that the new length isn't going to exceed the maximum length
	if (maximumLengthMeters < (currentTotalLength + currentCraft->getLength()))
	{
		//Unable to be added
		return;
	}

	if (maximumIndividualLengthMeters < currentCraft->getLength())
	{
		//Exceeds length
		return;
	}

	currentEntry = rootEntry;//From the start

	//While the next Entry does not already have a craft
	while (currentEntry->nextEntry != nullptr)
	{
		currentEntry = currentEntry->nextEntry;//Move to next entry
	}

	//currentEntry = new WatercraftListEntry;//Make Next Entry

	//Once at an Empty Entry
	currentEntry->value = currentCraft;//Insert Value
	currentEntry->nextEntry = new WatercraftListEntry;

	//currentEntry = currentEntry->nextEntry;//Move to next entry
	//currentEntry = new WatercraftListEntry;//Make Next Entry

	//Increment Count
	entryCount++;

	CalculateTotalLength();//Length update
}

void WatercraftList::InsertEntry(Watercraft currentCraft)
{
	InsertEntry(new Watercraft(currentCraft));
}

void WatercraftList::InsertEntry(Watercraft* currentCraft, const int index)
{
	//Check that the new length isn't going to exceed the maximum length
	if (maximumLengthMeters < (currentTotalLength + currentCraft->getLength()))
	{
		//Unable to be added
		return;
	}

	if (maximumIndividualLengthMeters < currentCraft->getLength())
	{
		//Exceeds length
		return;
	}

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
	/*WatercraftListEntry* newEntry = new WatercraftListEntry;
	newEntry->value = currentCraft;//Insert Value

	newEntry->nextEntry = currentEntry->nextEntry;//Hold Next entry*/
	
	//Insert Entry
	currentEntry->value = currentCraft;

	currentEntry = currentEntry->nextEntry;//Move to next entry
	currentEntry = new WatercraftListEntry;

	//Increment Count
	entryCount++;

	CalculateTotalLength();//Length update
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

	CalculateTotalLength();//Length update
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

		for (int i = 1; i < Index; i++)
		{
			currentEntry = currentEntry->nextEntry;//Move to next entry
		}

		WatercraftListEntry* chosenEntry = currentEntry->nextEntry;

		//skip over the entry
		currentEntry->nextEntry = currentEntry->nextEntry->nextEntry;

		//Remove entry
		delete chosenEntry;
	}

	//De-increment Count
	entryCount--;

	CalculateTotalLength();//Length update

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

int WatercraftList::GetMaximumLength()
{
	return maximumLengthMeters;
}

int WatercraftList::GetMaximumDraft()
{
	return maximumDraft;
}

int WatercraftList::GetMaximumIndividualLength()
{
	return maximumIndividualLengthMeters;
}

int WatercraftList::CalculateTotalLength()
{
	//Set the new length to Start
	int newLength = startingLengthMeters;

	//Set Pointer to Start
	this->currentEntry = rootEntry;

	//While not at the end
	while (currentEntry != nullptr)
	{
		//Ensure 
		if ((currentEntry->value) != NULL)
		{
			//Add current length to total
			newLength = newLength + this->currentEntry->value->getLength();
		}

		currentEntry = currentEntry->nextEntry;
	}

	//set total length to new value
	this->currentTotalLength = newLength;

	return newLength;//Return total
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

void WatercraftList::PrintList()
{
	currentEntry = rootEntry;//From the start

	//For each entry
	while (currentEntry != NULL)
	{
		//If the watercraft exists
		if ((currentEntry->value) != NULL)
		{
			//Print Watercraft
			currentEntry->value->printAsString();
		}

		//Move to next
		currentEntry = currentEntry->nextEntry;
	}

	return;
}