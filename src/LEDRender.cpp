#include "LEDRender.h"

LEDRender::LEDRender()
{
	//(owl hooting)
}

void LEDRender::draw(LED& led, sf::Texture texture, sf::RenderWindow& window)
{
	sf::RectangleShape newLED(sf::Vector2f(led.getWidth(), led.getHeight()));
	newLED.setPosition(led.getX(), led.getY());
	newLED.setTexture(&texture);

	window.draw(newLED);
}

LEDRender::~LEDRender()
{

}