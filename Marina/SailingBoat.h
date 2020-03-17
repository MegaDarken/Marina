#pragma once
#include "Watercraft.h"
class SailingBoat :
	public Watercraft
{
	const std::string CraftType = "SailingBoat";//For type identification

public:
	SailingBoat();
	SailingBoat(std::string ownerName, std::string boatName, int length, int draft);
	~SailingBoat();
};

