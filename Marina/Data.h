#pragma once
//Include(s) 
#ifndef MARNIA_L
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#endif // !MARNIA_L

#ifndef MARNIA_H
#include "List.h"
#include "Booking.h"
#include "Watercraft.h"
#endif // !MARNIA_H

class Data
{
public:
	//Data();
	//~Data();

	//Accessor(s)
	static BookingList* getBookingRecords();
	static WatercraftList* getMarinaCraftList();
	static WatercraftList* getHoldingCraftList();

	//Display
	static void showBookingRecords();

	//File I/O
	static void saveBookingRecords();
	static void saveBookingRecords(const char*);

	static void loadBookingRecords();
	static void loadBookingRecords(const char*);

	//Boat Movement
	static void moveFrontCraftToHolding();
	//static void moveCraftToHolding(const int);
	static void moveCraftsToHolding(const int);

	static void moveBackCraftFromHolding();
	static void moveCraftsFromHolding();

private:

	//List of Records
	static BookingList* bookingRecords;

	//Boat Data Storage

	//Marina Area
	 //First List
	static WatercraftList* MarinaCraftList;

	//Holding Bay
	 //Second List
	static WatercraftList* HoldingBayCraftList;

	//Timers

};

//Data::Data()
//{
//}
//
//Data::~Data()
//{
//}