#include "Level1Render.h"


Level1Render::Level1Render()
{

	//(owl hooting)
}

void Level1Render::draw(Level1& level, sf::Texture& forSprite, sf::Texture& forDoor, sf::Texture& forPC, sf::Texture& forLED, sf::Texture& forPlayer,sf::RenderWindow& window)
{ 
	spriteRender.draw(forSprite, window);
	doorRender.draw(level.getDoor(), forDoor, window);
	pcRender.draw(level.getPC(), forPC, window);
	ledRender.draw(level.getDoorLED(), forLED, window);
	playerRender.draw(level.getPlayer(), forPlayer, window);
}

Level1Render::~Level1Render()
{

}