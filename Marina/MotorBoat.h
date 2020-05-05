#pragma once
#include "Watercraft.h"
class MotorBoat :
	public Watercraft
{

public:

	MotorBoat();
	MotorBoat(std::string ownerName, std::string boatName, int length, int draft);
	~MotorBoat();

	static std::string getCraftType();
};

