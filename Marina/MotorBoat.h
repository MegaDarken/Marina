#pragma once
#include "Watercraft.h"
class MotorBoat :
	public Watercraft
{
	const std::string CraftType = "MotorBoat";//For type identification

public:
	MotorBoat();
	MotorBoat(std::string ownerName, std::string boatName, int length, int draft);
	~MotorBoat();
};

