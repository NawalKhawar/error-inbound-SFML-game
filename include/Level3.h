#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Player.h"
#include "PC.h"
class Level3 : public Level
{
	//game objects (last level only includes player and pc)
	PC pc; 
	Player player;

public:

	//constructor
	Level3();

	//initialize level
	void initLevel() override;

	//update 
	void handleInput(sf::Event event) override;

	//getters
	PC& getPC();
	Player& getPlayer();

	~Level3();

};

