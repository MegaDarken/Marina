#pragma once
#include "Watercraft.h"
class MotorBoat :
	public Watercraft
{
protected:
	static std::string CraftType;

public:

	MotorBoat();
	MotorBoat(std::string ownerName, std::string boatName, int length, int draft);
	MotorBoat(Watercraft& obj);
	MotorBoat(MotorBoat& obj);//Copy Constructor
	~MotorBoat();

	static std::string getCraftType();
};

