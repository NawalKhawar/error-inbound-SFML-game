#include "Level3.h"

Level3::Level3()
{
	//PC
	pc.setDimensions(82, 90);
	pc.setPosition(1000.0f, 340.0f);

	//Player
	player.initPlayer();

	//initialize flags
	isPaused = false;
	pauseKeyReleased = true;
	isPuzzleInProgress = false;
	isSolved = false;
	isComplete = false;
	isReset = false;
}
void Level3::initLevel()
{
	//PC
	pc.setDimensions(82, 90);
	pc.setPosition(1000.0f, 340.0f);

	//Player
	player.initPlayer();

	//initialize flags
	isPaused = false;
	pauseKeyReleased = true;
	isPuzzleInProgress = false;
	isSolved = false;
	isComplete = false;
	isReset = false;
}

//getters
PC& Level3::getPC()
{
	return pc;
}
Player& Level3::getPlayer()
{
	return player;
}

//update flags based on user input
void Level3::handleInput(sf::Event event)
{
	player.handleInput(event);

	if (event.type == sf::Event::KeyPressed) //a key is pressed
	{
		// Check for P key press
		if (event.key.code == sf::Keyboard::P && pauseKeyReleased) //P for pause
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
		//if level is NOT solved and player reaches the pc
		if (player.checkCollision(pc) && !isSolved)
		{
			isPuzzleInProgress = true;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && isPuzzleInProgress) //player pressed E - correct answer
	{
		//player has correctly solved the puzzle
		isSolved = true;
		isComplete = true;
		isPuzzleInProgress = false;
	}


	player.update();

}

//destructor
Level3::~Level3()
{

}