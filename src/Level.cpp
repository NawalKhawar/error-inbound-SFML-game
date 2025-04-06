#include<iostream>
#include "Level.h"

//default constructor
Level::Level()
{
	isComplete = false;
	isSolved = false;
	isPuzzleInProgress = false;
	isPaused = false;
	pauseKeyReleased = true;
	isReset = false;
}

void Level::pause()
{
	isPaused = true;
}

void Level::resume()
{
	isPaused = false;
}

bool Level:: checkIfSolved()
{
	if (isSolved)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Level::checkIfComplete()
{
	if (isComplete)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Level::checkIfPaused() 
{
	if (isPaused)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Level::checkIfReset()
{
	if (isReset)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Level::checkIfPuzzleInProgress()
{
	if (isPuzzleInProgress)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//VIRTUAL FUNCTION - WILL BE OVERWRITTEN
void Level::initLevel()
{	
	//virtual

}

void Level::handleInput(sf::Event event)
{
	//(owl hooting)
}

Level::~Level()
{

}

