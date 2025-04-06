#include "Player.h"

//constructor
Player::Player()
{
    width = CHARACTER_WIDTH;
    height = CHARACTER_HEIGHT;
    speed = RUN_SPEED;
    x = INIT_X;
    y = INIT_Y;

    isRunningLeft = false;
    isRunningRight = false;
}

//initialize player position
void Player::initPlayer()
{
    x = INIT_X;
    y = INIT_Y;
}


//getters
int Player::getWidth()
{
    return width;
}

int Player::getHeight()
{
    return height;
}

float Player::getX()
{
    return x;
}

float Player::getY()
{
    return y;
}

//setters
void Player::setPosition(float setX, float setY)
{
    x = setX;
    y = setY;
}

//handle user inputs (key presses)
void Player::handleInput(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)  //if a key is pressed
    {
        if (event.key.code == sf::Keyboard::Left) //LEFT KEY 
        {
            isRunningLeft = true;
        }
        if (event.key.code == sf::Keyboard::Right) //RIGHT KEY
        {
            isRunningRight = true;
        }
    }

    // Handle key release
    if (event.type == sf::Event::KeyReleased) 
    {
        if (event.key.code == sf::Keyboard::Left)
        {
            isRunningLeft = false;
        }
        if (event.key.code == sf::Keyboard::Right)
        {
            isRunningRight = false;
        }
    }
}

//update player position
void Player::update()
{
    this->checkWindowBounds();

    if (isRunningLeft)
    {
        x -= speed;
    }
    if (isRunningRight)
    {
        x += speed;
    }
}

bool Player::checkCollision(GameObject& obj)
{
    bool hOverlap = false;  //horizontal overlap
    bool vOverlap = false;  //vertical overlap

    float playerLeftEdge = x;
    float playerRightEdge = x + width;

    float objLeftEdge = obj.getX();
    float objRightEdge = obj.getX() + obj.getWidth();

    for (float i = playerLeftEdge; i <= playerRightEdge; i++) //check each pixel for overlap
    {
        if (i >= objLeftEdge && i <= objRightEdge)
        {
            hOverlap = true;
            break;
        }
    }

    float playerTopEdge = y;
    float playerBottomEdge = y + height;

    float objTopEdge = obj.getY();
    float objBottomEdge = obj.getY() + obj.getHeight();

    for (float i = playerTopEdge; i <= playerBottomEdge; i++)  //check each pixel for overlap
    {
        if (i >= objTopEdge && i <= objBottomEdge)
        {
            vOverlap = true;
            break;
        }
    }

    return hOverlap && vOverlap; //only return true if BOTH overlaps are true
}

bool Player::checkifRunningLeft() 
{
    if (isRunningLeft)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Player::checkifRunningRight()
{
    if (isRunningRight)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Player::checkWindowBounds()
{
    if (x < 0.f) //if player reaches the left side of the screen
    {
        x = 50.f;
    }

    if (x + width > 1600.f) //if player reaches the right side of the screen
    {
        x = 1600.f;
    } 
}

//destructor
Player::~Player()
{

}