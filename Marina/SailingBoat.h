#pragma once
#include "Watercraft.h"
class SailingBoat :
	public Watercraft
{
public:
	SailingBoat();
	SailingBoat(std::string ownerName, std::string boatName, int length, int draft);
	~SailingBoat();
};

