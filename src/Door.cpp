
#include "Door.h"

Door::Door()
{
	isOpen = false;
}

//return door state
bool Door::checkIfOpen()
{
	if (isOpen) //door is open
	{
		return true;
	}
	else //door is closed
	{
		return false;
	}
}

//open/close the door
void Door::toggle()
{
	isOpen = !isOpen;
}

Door::~Door()
{

}
