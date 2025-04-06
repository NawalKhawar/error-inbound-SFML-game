#include "PlayerRender.h"

PlayerRender::PlayerRender()
{
	//(owl hooting)
}

//draw player according to player state 
void PlayerRender::draw(Player& player, sf::Texture& texture, sf::RenderWindow& window)
{
	sf::RectangleShape newPlayer(sf::Vector2f(player.getWidth(), player.getHeight()));
	newPlayer.setPosition(player.getX(), player.getY());
	newPlayer.setTexture(&texture);

	window.draw(newPlayer);
}

PlayerRender::~PlayerRender()
{
	//(owl hooting)
}