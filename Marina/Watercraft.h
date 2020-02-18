#pragma once
class Watercraft
{
private:
	unsigned uniqueID;//Unique Identifier

	int length;
	int berth;

public:
	Watercraft();
	Watercraft(int, int);
	Watercraft(Watercraft &obj);//Copy Constructor
	~Watercraft();

	//Getters and Setters
	unsigned getUniqueID();
	int getLength();
	int getBerth();

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
