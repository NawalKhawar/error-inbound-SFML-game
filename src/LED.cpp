
#include "LED.h"

//default constructor
LED::LED()
{
	colour = "grey";
}

//overloaded constructor
LED::LED(std::string c)
{
	colour = c;
}

//set colour of LED
void LED::setColour(std::string newColour)
{
	colour = newColour;
}

//get colour of LED
std::string LED::getColour()
{
	return colour;
}

//destructor
LED::~LED()
{

}