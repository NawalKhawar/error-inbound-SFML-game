#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "LED.h"
#include "Door.h"
#include "Player.h"
#include "PC.h"

class Level1 : public Level
{
	LED doorLED;
	Door door;
	PC pc;
	Player player;

public:

	Level1();
	void initLevel() override;
	void handleInput(sf::Event event) override;
	LED& getDoorLED();
	Door& getDoor();
	PC& getPC();
	Player& getPlayer();
	~Level1();

};
