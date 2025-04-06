#pragma once

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include<string>

class LED : public GameObject
{
	std::string colour; //colour of LED

public:

	LED(); //default constructor
	LED(std::string c); //overloaded constructor
	void setColour(std::string newColour); //set colour of LED
	std::string getColour(); //get colour of LED
	~LED(); //destructor
};

