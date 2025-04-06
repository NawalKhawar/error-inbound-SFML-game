#pragma once
#include<iostream>
#include"Player.h"


//acts as base class for all other Level classes in the game

class Level
{
protected:

	//flags to check game state
	bool isComplete; //player has reached open door
	bool isSolved; //player has solved puzzle but hasn't reached door
	bool isPaused; //user paused the game
	bool isPuzzleInProgress; //puzzle is currently being displayed
	bool pauseKeyReleased; //for displaying pause prompt
	bool isReset; //to check if user has reset level

public:

	//constructor
	Level();

	//initialize level (WILL BE OVERWRITTEN IN THE DERIVED CLASSES)
	virtual void initLevel();

	void pause();
	void resume();

	//checks flag
	bool checkIfSolved();
	bool checkIfComplete();
	bool checkIfPaused();
	bool checkIfReset();
	bool checkIfPuzzleInProgress();

	virtual void handleInput(sf::Event event);
	virtual ~Level();

};
