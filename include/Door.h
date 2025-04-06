#pragma once
#include "GameObject.h"
class Door : public GameObject
{
	bool isOpen; //flag to check if door is open or closed

public:

	//constructor
	Door();
	
	//check door state
	bool checkIfOpen();

	//toggle door state
	void toggle();

	//destructor
	~Door();
};

