#pragma once
class Watercraft
{
private:
	unsigned uniqueID;//Unique Identifier (For integrity)

	//Names
	char* ownerName;
	char* boatName;

	int length;
	int draft;

public:
	Watercraft();
	Watercraft(char ownerName[], char boatName[], int length, int draft);
	Watercraft(Watercraft &obj);//Copy Constructor
	~Watercraft();//Descructor

	//Getters and Setters
	unsigned getUniqueID();

	char* getOwnerName();
	char* getBoatName();

	int getLength();
	int getDraft();

	//Equality Operators
	bool operator==(const Watercraft &t);
	bool operator!=(const Watercraft &t);

	
};
//Polymorphism is able to be used to Inherit to Specific types of Craft/Boat (narrow, sailing, or motor)

//bool Watercraft::operator==()
//{
//
//}
//
//bool Watercraft::operator!=()
//{
//
//}
