#pragma once
#include "Watercraft.h"

//This header file contains the structure of a Linked List of watercraft 
struct WatercraftListEntry
{
	Watercraft value;
	WatercraftListEntry* nextEntry = NULL;
};

class WatercraftList
{
private:
	WatercraftListEntry* rootEntry; //All other entries are based upon this. List Removed if changed.

	WatercraftListEntry* currentEntry; //Pointer for current node

public:
	WatercraftList();
	~WatercraftList();

	void InsertEntry(Watercraft);
	void RemoveEntry(Watercraft);
};
