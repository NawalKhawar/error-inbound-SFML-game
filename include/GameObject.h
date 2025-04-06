#pragma once


#include<vector>
#include<string>

//base class for all other objects in the game
class GameObject
{
protected:

	//dimensions
	int width;
	int height;

	//positions
	float x;
	float y;

public:

	GameObject();

	//setters
	void setDimensions(int setW, int setH);
	void setPosition(float setX, float setY);

	//getters
	int getWidth();
	int getHeight();
	float getX();
	float getY();

	~GameObject();
};

