#pragma once
#include "Booking.h"

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

	int entryCount;

public:
	WatercraftList();
	~WatercraftList();

	void InsertEntry(Watercraft);
	void RemoveEntry(Watercraft);

	Watercraft* GetEntry(int);
};

//This header file contains the structure of a Linked List of bookings
struct BookingListEntry
{
	Booking value;
	BookingListEntry* nextEntry = NULL;
};

class BookingList
{
private:
	BookingListEntry* rootEntry; //All other entries are based upon this. List Removed if changed.
	BookingListEntry* endEntry;
	//BookingListEntry* currentEntry; //Pointer for current node

	int entryCount;

public:
	BookingList();
	~BookingList();

	void InsertEntry(Booking);
	void RemoveEntry(Booking);

	Booking* GetEntry(int);
	int GetCount();
};