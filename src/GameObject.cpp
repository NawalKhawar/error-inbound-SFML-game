#include "GameObject.h"

//constructor
GameObject::GameObject()
{
	//will be overidden
}

//set dimensions of game object
void GameObject::setDimensions(int setW, int setH)
{
	width = setW;
	height = setH;
}

//set position (coordinates) of game object
void GameObject::setPosition(float setX,  float setY)
{
	x = setX;
	y = setY;
}

//getters
int GameObject::getWidth()
{
	return width;
}
int GameObject::getHeight()
{
	return height;
}
float GameObject::getX()
{
	return x;
}
float GameObject::getY()
{
	return y;
}

//destructor
GameObject::~GameObject()
{

}