//Data.cpp	 Stores and Handles the program's data.
#pragma once

#ifndef MARNIA_L
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#endif // !MARNIA_L

#ifndef MARNIA_H
#include "List.h"
#include "Booking.h"
#include "Watercraft.h"
#endif // !MARNIA_H



using namespace std;

const char* defaultRecordsFileName = "bookingRecords.txt";


//List of Records
vector<Booking> bookingRecords;

//Boat Data Storage

//Marina Area
 //First List
WatercraftList* MarinaCraftList = new WatercraftList();

//Holding Bay
 //Second List
WatercraftList* HoldingBayCraftList = new WatercraftList();

//Timer(s)



//External File Storage (I/O)


//Save To Files
void saveBookingRecords(const char* fileName)
{
    //output char array
    char* outputArray;

    //Open file
    ofstream currentFile;
    currentFile.open(fileName, ios::out);

    //ensure file is open
    if (currentFile.is_open() == false)
        cout << "Error opening file\n" << endl;
    else
    {
        //Input data
        for (size_t index = 0; index < bookingRecords.size(); index++)
        {
            //cast object into file
            //currentFile.write((char*)&bookingRecords[index], sizeof(bookingRecords[index]));

            bookingRecords[index].getAsString(outputArray);

            currentFile.write(outputArray, sizeof(outputArray));
        }
    }

    //Close file
    currentFile.close();
}

void saveBookingRecords()
{
    saveBookingRecords(defaultRecordsFileName);
}

//Load From Files
void loadBookingRecords(const char* fileName)
{
    //Temp Variables
    int cost;
    char* ownerName;
    char* craftName;
    int length;
    int draft;

    //Open file
    ifstream currentFile;
    currentFile.open(fileName);

    //Ensure file is open
    if (currentFile.is_open() == false)
        cout << "Error opening file\n" << endl;
    else
    {
        //Input data
        while (!currentFile.eof())
        {
            //currentFile.read((char*)& bookingRecords.push_back, sizeof(bookingRecords.begin));//Casting
            currentFile.read((char*)cost, sizeof(int));

            currentFile.read((char*)ownerName, sizeof(char*));
            currentFile.read((char*)craftName, sizeof(char*));

            currentFile.read((char*)length, sizeof(int));
            currentFile.read((char*)draft, sizeof(int));

            bookingRecords.push_back(new Booking(cost, ownerName, craftName, length, draft));
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
}

void loadBookingRecords()
{
    loadBookingRecords(defaultRecordsFileName);
}

//--Data (Boat) Deletion--