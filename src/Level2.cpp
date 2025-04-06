#include "Level2.h"

Level2::Level2()
{
	//LED 
	doorLED.setDimensions(35, 35);
	doorLED.setPosition(1472.0f, 245.0f);

	//Door
	door.setDimensions(85, 130);
	door.setPosition(1450.0f, 295.0f);

	//PC
	pc.setDimensions(82, 90);
	pc.setPosition(600.0f, 340.0f);

	//Player
	player.initPlayer();


	isPaused = false;
	pauseKeyReleased = true;
	isPuzzleInProgress = false;
	isSolved = false;
	isComplete = false;
	isReset = false;
}
void Level2::initLevel()
{
	//LED 
	doorLED.setDimensions(35, 35);
	doorLED.setPosition(1472.0f, 245.0f);

	//Door
	door.setDimensions(85, 130);
	door.setPosition(1450.0f, 295.0f);

	//PC
	pc.setDimensions(82, 90);
	pc.setPosition(600.0f, 340.0f);

	//Player
	player.initPlayer();


	isPaused = false;
	pauseKeyReleased = true;
	isPuzzleInProgress = false;
	isSolved = false;
	isComplete = false;
	isReset = false;
}
LED& Level2::getDoorLED()
{
	return doorLED;
}
Door& Level2::getDoor()
{
	return door;
}
PC& Level2::getPC()
{
	return pc;
}
Player& Level2::getPlayer()
{
	return player;
}

void Level2::handleInput(sf::Event event)
{
	player.handleInput(event);

	if (event.type == sf::Event::KeyPressed)
	{
		// Check for P key press
		if (event.key.code == sf::Keyboard::P && pauseKeyReleased)
		{
			isPaused = !isPaused; // Toggle pause state
			pauseKeyReleased = false; // Mark the key as not released
		}

		if (event.key.code == sf::Keyboard::R && isPaused) //player decides to reset level
		{
			isReset = true;
		}
	}

	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::P)
		{
			pauseKeyReleased = true; // Mark the key as released
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		//if level is solved and player has reached the door
		if (player.checkCollision(door) && isSolved)
		{
			isComplete = true;
		}

		//if level is NOT solved and player reaches the pc
		if (player.checkCollision(pc) && !isSolved)
		{
			isPuzzleInProgress = true;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isPuzzleInProgress)
	{
		//player has correctly solved the puzzle
		isSolved = true;
		isPuzzleInProgress = false;
	}


	player.update();

}

Level2::~Level2()
{

}

