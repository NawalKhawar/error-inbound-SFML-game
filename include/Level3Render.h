#pragma once
#include <SFML/Graphics.hpp>
#include "Level3.h"
#include"PCRender.h"
#include"PlayerRender.h"
#include"SpriteRender.h"
#include "Render.h"

class Level3Render : public Render
{
	//renderers for various objects
	PCRender pcRender; //for PC
	PlayerRender playerRender; //for Player
	SpriteRender spriteRender; //for background

public:

	//constructor
	Level3Render();

	//draw level according to game state
	void draw(Level3& level, sf::Texture& forSprite, sf::Texture& forPC, sf::Texture& forPlayer, sf::RenderWindow& window);
	~Level3Render();
};

