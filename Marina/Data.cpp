//Data.cpp	 Stores and Handles the program's data.
#pragma once

#include "Data.h"

using namespace std;

//namespace marina
//{
    //Constants
    const char AttributeSplitChar = ';';


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

        //Vars
        Booking* currentBooking = new Booking();
        //char* outputArray = new char;//output char array
        std::string* tempString = new std::string();

        //Open file
        ofstream currentFile;
        currentFile.open(fileName, ios::out);

        //ensure file is open
        if (currentFile.is_open() == false)
            cout << "Error opening file\n" << endl;
        else if (currentFile.is_open())
        {
            //Input data
            for (size_t index = 0; index < bookingRecords->GetCount(); index++)
            {
                ////Get Next object
                currentBooking = bookingRecords->GetEntry(index);//->GetEntry(index).getAsString(outputArray);

                //cast object into file
                //currentFile.write((char*)&bookingRecords[index], sizeof(bookingRecords[index]));

                //currentFile.write(outputArray, sizeof(outputArray));

                //currentBooking->getAsFileString(tempString);

                //Write 
                //currentFile << ((char*)currentBooking->getTotalCost());
                ////currentFile << AttributeSplitChar;

                //Watercraft currentCraft = *currentBooking->getBookedCraft();
                //currentFile << currentBooking->getBookedCraft()->getOwnerName();// << AttributeSplitChar;
                ////currentFile << AttributeSplitChar;
                //currentFile << currentBooking->getBookedCraft()->getBoatName();// << AttributeSplitChar;
                ////currentFile << AttributeSplitChar;

                //currentFile << ((char*)currentBooking->getBookedCraft()->getLength());// << AttributeSplitChar;
                ////currentFile << AttributeSplitChar;
                //currentFile << ((char*)currentBooking->getBookedCraft()->getDraft());
                currentFile.write((char*)&currentBooking, sizeof(*currentBooking));
            }
        }

        //Close file
        currentFile.close();

        //Delete
        delete currentBooking;
        delete tempString;
    }

    void Data::saveBookingRecords()
    {
        saveBookingRecords(defaultRecordsFileName);
    }

    //Load From Files
    void Data::loadBookingRecords(const char* fileName)
    {
        //Temp Variables
        /*int cost = defaultLoadCost;
        char* ownerName = new char;
        char* craftName = new char;
        int length = defaultLoadLength;
        int draft = defaultLoadDraft;*/

        Booking* currentBooking = new Booking();

        char tempChar[50];
        
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
            else if (currentFile.is_open())
            {
                //Input data
                while (!currentFile.eof())
                {
                    ////Get next line/object
                    currentFile.get((char*) & currentBooking, sizeof(*currentBooking));

                    //currentFile.read((char*)& bookingRecords.push_back, sizeof(bookingRecords.begin));//Casting
                    /*currentFile.read((char*)cost, sizeof(int));

                    currentFile.read((char*)ownerName, sizeof(char*));
                    currentFile.read((char*)craftName, sizeof(char*));

                    currentFile.read((char*)length, sizeof(int));
                    currentFile.read((char*)draft, sizeof(int));

                    //currentBooking = new Booking(cost, ownerName, craftName, length, draft);*/
                    currentBooking->setFromFileString(&string(tempChar));

                    bookingRecords->InsertEntry(currentBooking);

                }
            }
        }
        else
        {
            //file does not exist
            //Warn user
            cout << "File chosen does not exist." << endl;
        }

        //Close file
        currentFile.close();

        //Delete Vars
        //delete cost;
        //delete ownerName;
        //delete craftName;
        //delete length;
        //delete draft;
        delete currentBooking;

        delete tempChar;
    }

    void Data::loadBookingRecords()
    {
        loadBookingRecords(defaultRecordsFileName);
    }

    //--Data (Boat) Deletion--




