#pragma once
#include "Watercraft.h"
class NarrowBoat :
	public Watercraft
{

public:

	NarrowBoat();
	NarrowBoat(std::string ownerName, std::string boatName, int length, int draft);
	~NarrowBoat();

	static std::string getCraftType();
};

