#pragma once
#include "Watercraft.h"
class SailingBoat :
	public Watercraft
{

public:
	const std::string CraftType = "SailingBoat";//For type identification

	SailingBoat();
	SailingBoat(std::string ownerName, std::string boatName, int length, int draft);
	~SailingBoat();
};

