#pragma once

#include "Render.h"
#include"LED.h"

class LEDRender : public Render
{

public:

	LEDRender();
	void draw(LED& led, sf::Texture texture, sf::RenderWindow& window);
	~LEDRender();
};

