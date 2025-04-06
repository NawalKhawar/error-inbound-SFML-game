#include "DoorRender.h"

DoorRender::DoorRender()
{

}
void DoorRender::draw(Door& door, sf::Texture& texture, sf::RenderWindow& window)
{
	sf::RectangleShape newDoor(sf::Vector2f(door.getWidth(), door.getHeight()));
	newDoor.setPosition(door.getX(), door.getY());
	newDoor.setTexture(&texture);

	window.draw(newDoor);
}
DoorRender::~DoorRender()
{

}