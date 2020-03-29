#pragma once


class Data
{
public:
	//Data();
	//~Data();

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