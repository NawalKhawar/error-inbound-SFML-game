#pragma once

#include <SFML/Graphics.hpp>
#include "Render.h"
#include"Door.h"
#include<vector>

class DoorRender : public Render
{

public:
	DoorRender();
	void draw(Door& door, sf::Texture& texture, sf::RenderWindow& window);
	~DoorRender();
};

