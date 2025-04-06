#pragma once
#include <SFML/Graphics.hpp>
#include "Render.h"

class SpriteRender : public Render
{
	sf::Sprite sprite;

public:
	SpriteRender();
	void draw(sf::Texture& texture, sf::RenderWindow& window);
	~SpriteRender();
};

