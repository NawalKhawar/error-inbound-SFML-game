#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

// check if user has closed the screen
void checkIfWindowClosed(sf::Event& event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::Closed) //'x' clicked on the header
    {
        window.close();
    }
    if (event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //'Esc' pressed
    {
        window.close();
    }
}

// display when the game window closes
void displayFarewellMessage()
{
    std::cout << "\n\n-------------------------------------\n";
    std::cout << "Hope you had fun! See you next time!!\n";
    std::cout << "-------------------------------------\n\n\n\n";
}
