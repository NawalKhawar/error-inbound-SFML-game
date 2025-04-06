#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include"GameObject.h"
#include"Game_Constants.h"

class Player
{
	//dimensions
	float x;
	float y;

	//position
	int width;
	int height;

	float speed; //movement speed/offset

	//flags to check player state
	bool isRunningRight;
	bool isRunningLeft;

public:

	Player(); //constructor
	void initPlayer(); //initialize player (same for each level)

	//getters
	int getWidth();
	int getHeight();
	float getX();
	float getY();

	//setter
	void setPosition(float setX, float setY);

	//handles game events and updates flags accordingly
	void handleInput(sf::Event event);

	//update player position (when right/left keys pressed)
	void update();

	//check collision with various game objects
	bool checkCollision(GameObject& obj);

	//check flags
	bool checkifRunningLeft();
	bool checkifRunningRight();

	//to make sure player stays inside game window
	void checkWindowBounds();

	//destructor
	~Player();

};

