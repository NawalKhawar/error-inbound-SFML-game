#pragma once

#include <SFML/Graphics.hpp>
#include "Level2.h"
#include"PCRender.h"
#include"DoorRender.h"
#include"PlayerRender.h"
#include"LEDRender.h"
#include"SpriteRender.h"
#include "Render.h"

class Level2Render : public Render
{
	//various renderers (for different objects)
	DoorRender doorRender; //for door
	PCRender pcRender; //for PC
	LEDRender ledRender; //for LED
	PlayerRender playerRender; //for Player
	SpriteRender spriteRender; //for backgrounds

public:

	//constructor
	Level2Render();

	//draw the level according to game state
	void draw(Level2& level, sf::Texture& forSprite, sf::Texture& forDoor, sf::Texture& forPC, sf::Texture& forLED, sf::Texture& forPlayer, sf::RenderWindow& window);
	
	//destructor
	~Level2Render();
};

