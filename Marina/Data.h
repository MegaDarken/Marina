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

	//Accessor
	static BookingList* getBookingRecords();

	//Display
	static void showBookingRecords();

	//File I/O
	static void saveBookingRecords();
	static void saveBookingRecords(const char*);

	static void loadBookingRecords();
	static void loadBookingRecords(const char*);


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
};

//Data::Data()
//{
//}
//
//Data::~Data()
//{
//}