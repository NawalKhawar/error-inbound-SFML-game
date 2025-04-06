#pragma once
#include <SFML/Graphics.hpp>
#include "Render.h"
#include "PC.h"

class PCRender : public Render
{

public:
	PCRender();
	void draw(PC& pc, sf::Texture& texture, sf::RenderWindow& window);
	~PCRender();
};

