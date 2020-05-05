#pragma once
#include "Watercraft.h"
class NarrowBoat :
	public Watercraft
{

public:
	const std::string CraftType = "NarrowBoat";//For type identification

	NarrowBoat();
	NarrowBoat(std::string ownerName, std::string boatName, int length, int draft);
	~NarrowBoat();

	
};

