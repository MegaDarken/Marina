#pragma once
#include "Watercraft.h"
class NarrowBoat :
	public Watercraft
{
	const std::string CraftType = "NarrowBoat";//For type identification

public:
	NarrowBoat();
	NarrowBoat(std::string ownerName, std::string boatName, int length, int draft);
	~NarrowBoat();

	
};

