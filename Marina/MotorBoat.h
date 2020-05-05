#pragma once
#include "Watercraft.h"
class MotorBoat :
	public Watercraft
{

public:
	const std::string CraftType = "MotorBoat";//For type identification

	MotorBoat();
	MotorBoat(std::string ownerName, std::string boatName, int length, int draft);
	~MotorBoat();
};

