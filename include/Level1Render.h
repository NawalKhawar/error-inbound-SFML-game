#pragma once

#include <SFML/Graphics.hpp>
#include "Render.h"
#include "Level1.h"
#include"PCRender.h"
#include"DoorRender.h"
#include"PlayerRender.h"
#include"LEDRender.h"
#include"SpriteRender.h"

class Level1Render : public Render
{
	//renderers for various objects in the level
	DoorRender doorRender; //for door
	PCRender pcRender; //for PC
	LEDRender ledRender; //for LED above door
	PlayerRender playerRender; //for player
	SpriteRender spriteRender; //for background

public:
	Level1Render();
	void draw(Level1& level, sf::Texture& forSprite, sf::Texture& forDoor, sf::Texture& forPC, sf::Texture& forLED, sf::Texture& forPlayer, sf::RenderWindow& window);
	~Level1Render();
};

