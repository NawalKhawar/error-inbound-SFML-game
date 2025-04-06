#include "SpriteRender.h"

SpriteRender::SpriteRender()
{
	//(owl hooting)
}

void SpriteRender::draw(sf::Texture& texture, sf::RenderWindow& window)
{
	sprite.setTexture(texture);
	window.draw(sprite);
}


SpriteRender::~SpriteRender()
{
	//(owl hooting)
}