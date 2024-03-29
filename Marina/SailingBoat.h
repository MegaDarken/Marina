#pragma once
#include "Watercraft.h"
class SailingBoat :
	public Watercraft
{
protected:
	static std::string CraftType;

public:
	
	SailingBoat();
	SailingBoat(std::string ownerName, std::string boatName, int length, int draft);
	SailingBoat(Watercraft& obj);
	SailingBoat(SailingBoat& obj);//Copy Constructor
	~SailingBoat();

	static std::string getCraftType();
};

