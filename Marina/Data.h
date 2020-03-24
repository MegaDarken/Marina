#pragma once


static class Data
{
public:
	//Data();
	//~Data();

	void saveBookingRecords();
	void saveBookingRecords(const char*);

	void loadBookingRecords();
	void loadBookingRecords(const char*);


private:
	//Constants
	const char* defaultRecordsFileName = "bookingRecords.txt";

	//List of Records
	BookingList* bookingRecords = new BookingList();

	//Boat Data Storage

	//Marina Area
	 //First List
	//WatercraftList* Data::MarinaCraftList = new WatercraftList();

	//Holding Bay
	 //Second List
	//WatercraftList* HoldingBayCraftList = new WatercraftList();
};

//Data::Data()
//{
//}
//
//Data::~Data()
//{
//}