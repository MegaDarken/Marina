#pragma once
#include "Watercraft.h"
class NarrowBoat :
	public Watercraft
{

public:

	NarrowBoat();
	NarrowBoat(std::string ownerName, std::string boatName, int length, int draft);
	NarrowBoat(Watercraft& obj);
	NarrowBoat(NarrowBoat& obj);//Copy Constructor
	~NarrowBoat();

	static std::string getCraftType();
};

