#pragma once

#include <SFML/Graphics.hpp>
#include "Render.h"
#include"Player.h"
class PlayerRender : public Render
{

public:
	PlayerRender();
	void draw(Player& player, sf::Texture& texture, sf::RenderWindow & window);
	~PlayerRender();
};

