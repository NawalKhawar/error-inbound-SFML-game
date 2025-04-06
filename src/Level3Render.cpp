#include "Level3Render.h"

Level3Render::Level3Render()
{

	//(owl hooting)
}

void Level3Render::draw(Level3& level, sf::Texture& forSprite, sf::Texture& forPC, sf::Texture& forPlayer, sf::RenderWindow& window)
{
	spriteRender.draw(forSprite, window);
	pcRender.draw(level.getPC(), forPC, window);
	playerRender.draw(level.getPlayer(), forPlayer, window);
}

Level3Render::~Level3Render()
{

}