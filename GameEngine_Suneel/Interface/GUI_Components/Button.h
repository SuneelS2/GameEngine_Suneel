#pragma once
#include "SFML/Graphics.hpp"
class Button
{
private:
	sf::Color defaultColor, highLightedColor;

public:
	sf::RectangleShape buttonBG;
	sf::Text buttonText;
	bool bPressed, bClicked, bReleased, bHighLighted;

	Button() = default;
	Button(sf::Vector2f size, sf::Color color, std::string text);
	~Button() = default;

	bool isHighLighted();
	void highLightButton(sf::RenderWindow* window);
	void update(sf::Event event, float deltaTime);
	void render(sf::RenderWindow* window, float deltaTime);
	void checkPressed(sf::Event event);
};

