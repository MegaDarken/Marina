//Data.cpp	 Stores and Handles the program's data.
#pragma once

#include "Data.h"

using namespace std;

//namespace marina
//{
    //Constants

//Default values
    const char* defaultRecordsFileName = "bookingRecords.txt";

    const int defaultLoadCost = 0;
    //char* ownerName = new char;
    //char* craftName = new char;
    const int defaultLoadLength = 0;
    const int defaultLoadDraft = 0;

    //List of Records
    BookingList* Data::bookingRecords = new BookingList();

    //Marina Area
     //First List
    WatercraftList* Data::MarinaCraftList = new WatercraftList();

    //Holding Bay
     //Second List
    WatercraftList* Data::HoldingBayCraftList = new WatercraftList();

    //Timer(s)



    //Accessor(s)
    BookingList* Data::getBookingRecords()
    {
        return bookingRecords;
    }

    //Display
    void Data::showBookingRecords()
    {
        Booking* currentBooking = nullptr;//pointer setup
        std::string* outputString = new std::string;

        //for each index in the length of the records.
        for (int index = 0; index < bookingRecords->GetCount(); index++)
        {
            currentBooking = bookingRecords->GetEntry(index);//Get next booking

            //Show current entry
            cout << index << ':';

            //Print Out Booking
            currentBooking->getAsString(outputString);

            cout << (outputString) << endl;
        }

        //Cleanup data
        delete currentBooking;
        delete outputString;
    }

    //External File Storage (I/O)


    //Save To Files
    void Data::saveBookingRecords(const char* fileName)
    {
        //output char array
        char* outputArray = new char;

        //Open file
        ofstream currentFile;
        currentFile.open(fileName, ios::out);

        //ensure file is open
        if (currentFile.is_open() == false)
            cout << "Error opening file\n" << endl;
        else
        {
            //Input data
            for (size_t index = 0; index < bookingRecords->GetCount(); index++)
            {
                ////Get Next object


                //cast object into file
                //currentFile.write((char*)&bookingRecords[index], sizeof(bookingRecords[index]));

                bookingRecords->GetEntry(index);//->GetEntry(index).getAsString(outputArray);

                currentFile.write(outputArray, sizeof(outputArray));

            }
        }

        //Close file
        currentFile.close();
    }

    void Data::saveBookingRecords()
    {
        saveBookingRecords(defaultRecordsFileName);
    }

    //Load From Files
    void Data::loadBookingRecords(const char* fileName)
    {
        //Temp Variables
        int cost = defaultLoadCost;
        char* ownerName = new char;
        char* craftName = new char;
        int length = defaultLoadLength;
        int draft = defaultLoadDraft;

        Booking* currentBooking = new Booking();

        //Open file
        ifstream currentFile;
        currentFile.open(fileName);

        //check to see if file exists
        if (currentFile.good())
        {
            //file exists, continue

            //Clear existing records
            bookingRecords = new BookingList();

            //Ensure file is open
            if (currentFile.is_open() == false)
                cout << "Error opening file\n" << endl;
            else
            {
                //Input data
                while (!currentFile.eof())
                {
                    ////Get next line/object
                    //currentFile.read();

                    //currentFile.read((char*)& bookingRecords.push_back, sizeof(bookingRecords.begin));//Casting
                    currentFile.read((char*)cost, sizeof(int));

                    currentFile.read((char*)ownerName, sizeof(char*));
                    currentFile.read((char*)craftName, sizeof(char*));

                    currentFile.read((char*)length, sizeof(int));
                    currentFile.read((char*)draft, sizeof(int));

                    currentBooking = new Booking(cost, ownerName, craftName, length, draft);

                    bookingRecords->InsertEntry(*currentBooking);

                }
            }
        }

        //Close file
        currentFile.close();

        //Delete Vars
        //delete cost;
        delete ownerName;
        delete craftName;
        //delete length;
        //delete draft;
        delete currentBooking;
    }

    void Data::loadBookingRecords()
    {
        loadBookingRecords(defaultRecordsFileName);
    }

    //--Data (Boat) Deletion--




