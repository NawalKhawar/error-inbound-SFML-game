#include "PCRender.h"

PCRender::PCRender()
{
	//(owl hooting)
}
void PCRender::draw(PC& pc, sf::Texture& texture, sf::RenderWindow& window)
{
	sf::RectangleShape newPC(sf::Vector2f(pc.getWidth(), pc.getHeight()));
	newPC.setPosition(pc.getX(), pc.getY());
	newPC.setTexture(&texture);

	window.draw(newPC);
}
PCRender::~PCRender()
{
	//(owl hooting)
}