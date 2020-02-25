#pragma once
#include "Watercraft.h"

//This header file contains the structure of a Linked List of watercraft 
struct ListEntry
{
	Watercraft value;
	ListEntry* nextEntry;
};

class List
{
private:
	ListEntry* rootEntry; //All other entries are based upon this. List Removed if changed.

	ListEntry* currentEntry; //Pointer for current node

public:
	List();
	~List();

	void InsertEntry(Watercraft);
	void RemoveEntry(Watercraft);
};

List::List()
{
	rootEntry = new ListEntry;//Start of the list's sequence


	currentEntry = rootEntry;
}

List::~List()
{
}

void List::InsertEntry(Watercraft currentCraft)
{
	currentEntry = rootEntry;//From the start

	//While the current Entry does not already have a craft
	while (currentEntry != NULL)
	{
		currentEntry = currentEntry->nextEntry;//Move to next entry
	}

	//Once at an Empty Entry
	currentEntry = new ListEntry;//Make Next Entry
	currentEntry->value = currentCraft;//Insert Value
	


}

void List::RemoveEntry(Watercraft currentCraft)
{
	currentEntry = rootEntry;//From the start

	if (currentEntry->value == currentCraft)
	{
		//Move rootEntry to next
		rootEntry = rootEntry->nextEntry;
	}
	else
	{
	//While the next Entry does not contain the object; Continue
	while (currentEntry->nextEntry->value != currentCraft || currentEntry != NULL)
	{
		currentEntry = currentEntry->nextEntry;//Move to next entry
	}

	if (currentEntry->nextEntry->nextEntry != NULL)
	{
		currentEntry->nextEntry == NULL;
	}

	delete currentEntry->nextEntry;
	}
}
