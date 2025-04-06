#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "LED.h"
#include "Door.h"
#include "Player.h"
#include "PC.h"

class Level2 : public Level
{
	LED doorLED;  //LED displayed on top of door (signals if door is open or closed)
	Door door; //door to next floor/level
	PC pc; //for puzzle
	Player player; //the player (duh)

public:

	//constructor
	Level2();

	//initialize level
	void initLevel() override;

	//updates flags according to user input
	void handleInput(sf::Event event) override;

	//getters
	LED& getDoorLED();
	Door& getDoor();
	PC& getPC();
	Player& getPlayer();

	//destructor
	~Level2();
};

