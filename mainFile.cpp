
//Libraries
#include <SFML/Graphics.hpp>
#include<iostream>

//Classes
#include"Level1.h"
#include"Level2.h"
#include"Level3.h"
#include"Level1Render.h"
#include"Level2Render.h"
#include"Level3Render.h"

//Header files
#include"Game_Constants.h"
#include"Utility_Functions.h"


int main()
{
    Level1 level1;
    Level2 level2;
    Level3 level3;

    Level1Render level1render;
    Level2Render level2render;
    Level3Render level3render;
    SpriteRender spriteRender;

    // ------------------------------------ TEXTURES ------------------------------------
    sf::Texture playerTexture;
    playerTexture.loadFromFile("Graphics/Character/idle.png"); 


    sf::Texture pcTexture;
    pcTexture.loadFromFile("Graphics/Objects/pc.png");


    sf::Texture titleTexture;
    titleTexture.loadFromFile("Graphics/Screens/titleScreen.png");


    sf::Texture finalTexture;
    finalTexture.loadFromFile("Graphics/Screens/finalScreen.png");

    sf::Texture pausePromptTexture;
    pausePromptTexture.loadFromFile("Graphics/Screens/pause.png");
    
    sf::Texture level1Texture;
    level1Texture.loadFromFile("Graphics/Screens/Levels/level1.png");

    sf::Texture level2Texture;
    level2Texture.loadFromFile("Graphics/Screens/Levels/level2.png");

    sf::Texture level3Texture;
    level3Texture.loadFromFile("Graphics/Screens/Levels/level3.png");

    sf::Texture puzzle1Texture;
    puzzle1Texture.loadFromFile("Graphics/Screens/puzzle1.png");
   
    sf::Texture puzzle2Texture;
    puzzle2Texture.loadFromFile("Graphics/Screens/puzzle2.png");

    sf::Texture puzzle3Texture;
    puzzle3Texture.loadFromFile("Graphics/Screens/puzzle3.png");

    //will load their graphics in the game loop
    sf::Texture LEDTexture;
    sf::Texture doorTexture;


    //GAME WINDOW
    sf::RenderWindow window(sf::VideoMode(SCREEN_LENGTH, SCREEN_WIDTH), "Error Inbound", sf::Style::Close | sf::Style::Titlebar);
    

    // --------------- PROMPTS ---------------
    sf::RectangleShape pausePrompt(sf::Vector2f(480.0f, 480.0f));
    pausePrompt.setPosition(550.0f, 130.0f);
    pausePrompt.setTexture(&pausePromptTexture);



    // ------------- PUZZLES -------------
    sf::RectangleShape puzzle1(sf::Vector2f(1450.0f, 570.0f));
    puzzle1.setPosition(100.0f, 100.0f);
    puzzle1.setTexture(&puzzle1Texture);


    sf::RectangleShape puzzle2(sf::Vector2f(1460.0f, 590.0f));
    puzzle2.setPosition(50.0f, 50.0f);
    puzzle2.setTexture(&puzzle2Texture);


    sf::RectangleShape puzzle3(sf::Vector2f(1450.0f, 540.0f));
    puzzle3.setPosition(100.0f, 100.0f);
    puzzle3.setTexture(&puzzle3Texture);





    // --------------- VARIABLES ---------------
    bool isGamePaused = false;
    bool isGameQuit = false;
    int currentLevel = 0; //this keeps track of the current level
    









    // ---------------------------------------- game loop --------------------------------------
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) // ------ events -------
        {
            checkIfWindowClosed(event, window); //checkc if user closed the window

          
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && isGamePaused)
            {
                isGameQuit = true;
            }

            if (isGameQuit)
            {
                level1.initLevel();
                level2.initLevel();
                level3.initLevel();

                currentLevel = 0;
                isGameQuit = false;
            }

           
            if (currentLevel == 0)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    currentLevel++;
                }
            }
            else if (currentLevel == 1)
            {
                level1.handleInput(event); //update level flags

                if (level1.checkIfPaused()) //check if game is paused
                {
                    isGamePaused = true;
                }
                else
                {
                    isGamePaused = false;
                }

                if (level1.checkIfReset())
                {
                    level1.initLevel();
                }

                if (level1.checkIfComplete())
                {
                    currentLevel++;
                }
            }
            else if (currentLevel == 2)
            {
                level2.handleInput(event); //update level flags

                if (level2.checkIfPaused()) //check if game is paused
                {
                    isGamePaused = true;
                }
                else
                {
                    isGamePaused = false;
                }

                if (level2.checkIfReset())
                {
                    level2.initLevel();
                }

                if (level2.checkIfComplete())
                {
                    currentLevel++;
                }
            }
            else if (currentLevel == 3)
            {
                level3.handleInput(event); //update level flags

                if (level3.checkIfPaused()) //check if game is paused
                {
                    isGamePaused = true;
                }
                else
                {
                    isGamePaused = false;
                }

                if (level3.checkIfReset())
                {
                    level3.initLevel();
                }

                if (level3.checkIfComplete())
                {
                    currentLevel++;
                }
            }
            else if (currentLevel == 4)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) //player decides to play again
                {
                    level1.initLevel();
                    level2.initLevel();
                    level3.initLevel();

                    currentLevel = 0;
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) //player decides to call it a day
                {
                    window.close();
                }
            }
           
        }

        window.clear();

        // ----------------------- RENDER LOOPS!! ----------------------- 

            if (currentLevel == 0)
            {
                spriteRender.draw(titleTexture, window);
            }
            else if (currentLevel == 1)
            {
                if (level1.checkIfSolved())
                {
                    LEDTexture.loadFromFile("Graphics/Objects/blueLED.png");
                    doorTexture.loadFromFile("Graphics/Objects/doorOpened.jpg");
                }
                else
                {
                    LEDTexture.loadFromFile("Graphics/Objects/greyLED.png");
                    doorTexture.loadFromFile("Graphics/Objects/doorClosed.jpg");
                }

                level1render.draw(level1, level1Texture, doorTexture, pcTexture, LEDTexture, playerTexture, window);

                if (level1.checkIfPuzzleInProgress())
                {
                    //print the console screen
                    window.draw(puzzle1);
                }
            }
            else if (currentLevel == 2)
            {
                if (level2.checkIfSolved())
                {
                    LEDTexture.loadFromFile("Graphics/Objects/blueLED.png");
                    doorTexture.loadFromFile("Graphics/Objects/doorOpened.jpg");
                }
                else
                {
                    LEDTexture.loadFromFile("Graphics/Objects/greyLED.png");
                    doorTexture.loadFromFile("Graphics/Objects/doorClosed.jpg");
                }

                level2render.draw(level2, level2Texture, doorTexture, pcTexture, LEDTexture, playerTexture, window);

                if (level2.checkIfPuzzleInProgress())
                {
                    //print the console screen
                    window.draw(puzzle2);
                }
            }
            else if (currentLevel == 3)
            {
                level3render.draw(level3, level3Texture, pcTexture, playerTexture, window);

                if (level3.checkIfPuzzleInProgress())
                {
                    //print the console screen
                    window.draw(puzzle3);
                }
            }
            else if (currentLevel == 4)
            {
                spriteRender.draw(finalTexture, window);
            }

            if (isGamePaused)
            {
                window.draw(pausePrompt);
            }


        //display everything onscreen
        window.display();
    }


    //player has now exited the window
    displayFarewellMessage();

    return 0;
}

