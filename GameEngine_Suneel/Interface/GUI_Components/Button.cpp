#include "Button.h"

Button::Button(sf::Vector2f size, sf::Color color, std::string text) {
	
	//std::memset(this, false, sizeof(Button));
	bPressed = false;
	bClicked = false;
	bReleased = false;
	bHighLighted = false;

	this->defaultColor = color;
	this->highLightedColor = sf::Color(this->defaultColor.r + 50, this->defaultColor.g + 50, this->defaultColor.b + 50, this->defaultColor.a);

	this->buttonBG.setSize(size);
	this->buttonBG.setFillColor(defaultColor);
	this->buttonBG.setPosition(0, 0);

	this->buttonText.setCharacterSize(11);
	this->buttonText.setFillColor(sf::Color::White);
	this->buttonText.setPosition(0, 0);
	this->buttonText.setString(text);
}

bool Button::isHighLighted()
{
	return bHighLighted;
}

void Button::highLightButton(sf::RenderWindow* window)
{
	this->bHighLighted = this->buttonBG.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));

	if (bHighLighted == true)
	{
		this->buttonBG.setFillColor(this->highLightedColor);
	}
	else
	{
		this->buttonBG.setFillColor(this->defaultColor);
	}
}

void Button::update(sf::Event event, float deltaTime)
{
	this->checkPressed(event);
}

void Button::render(sf::RenderWindow* window, float deltaTime)
{
	window->draw(this->buttonBG);
	window->draw(this->buttonText);
	window->display();
}

void Button::checkPressed(sf::Event event)
{
	if (this->bHighLighted == false)
	{
		return;
	}
	if (event.type == sf::Event::MouseButtonPressed)
	{
		this->bPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left); 
		if (this->bPressed == false)
		{
			this->bClicked = false;
		}
	}

	if (this->bPressed == true)
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			this->bReleased = true;
			this->bClicked = true;
		}
		else
		{
			this->bReleased = false;
			this->bClicked = false;
		}
	}
}