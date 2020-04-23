#pragma once

#include "Booking.h"
#include "Watercraft.h"

//This header file contains the structure of a Linked List of watercraft 
struct WatercraftListEntry
{
	Watercraft* value;
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

	void InsertEntry(Watercraft*);
	void InsertEntry(Watercraft);
	void InsertEntry(Watercraft*,const int index);

	void RemoveEntry(Watercraft);
	void RemoveEntry(int Index);

	Watercraft* GetEntry(int);
	int GetCount();

	bool Contains(Watercraft);
	int GetIndex(Watercraft);

	bool VerifyIntegrity();//Checks no values are null or invalid.
};

//This header file contains the structure of a Linked List of bookings
struct BookingListEntry
{
	Booking* value;
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

	void InsertEntry(Booking*);
	void InsertEntry(Booking);
	void InsertEntry(Booking*,const int index);

	void RemoveEntry(Booking);
	void RemoveEntry(int Index);

	Booking* GetEntry(int);
	int GetCount();

	bool Contains(Booking);
	int GetIndex(Booking);

	bool VerifyIntegrity();//Checks no values are null or invalid.
};