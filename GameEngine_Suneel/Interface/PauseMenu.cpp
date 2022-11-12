#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow* window)
{
	States::setPausedState(false);
	this->InitButtons();
}

void PauseMenu::Update(sf::Event event, float deltatime, sf::RenderWindow* window)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			States::setPausedState(!States::getPausedState());
		}
	}

	if (States::getPausedState())
	{
		ButtonMap::GetMap()["RESUME"]->update(event, deltatime);
		ButtonMap::GetMap()["SAVE"]->update(event, deltatime);
		ButtonMap::GetMap()["QUIT"]->update(event, deltatime);
		ButtonMap::GetMap()["LOAD"]->update(event, deltatime);

		if (ButtonMap::GetMap()["RESUME"]->bClicked)
		{
			States::setPausedState(false);
			ButtonMap::GetMap()["RESUME"]->bClicked = false;
		}
		if (ButtonMap::GetMap()["QUIT"]->bClicked)
		{
			this->Quit(window);
			ButtonMap::GetMap()["RESUME"]->bClicked = false;
		}
	}
}

void PauseMenu::Render(sf::RenderWindow* window, float deltatime, sf::Vector2f resumePosition)
{
	sf::Font BAUHS;
	BAUHS.loadFromFile("../Debug/Fonts/BAUHS93.TTF");
	sf::Vector2f sizeOffset = sf::Vector2f(
		ButtonMap::GetMap()["RESUME"]->buttonBG.getSize().x / 2,
		ButtonMap::GetMap()["RESUME"]->buttonBG.getSize().y / 2
	);

	ButtonMap::GetMap()["RESUME"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, -80) - sizeOffset);
	ButtonMap::GetMap()["RESUME"]->buttonText.setFont(BAUHS);
	ButtonMap::GetMap()["RESUME"]->buttonText.setPosition(ButtonMap::GetMap()["RESUME"]->buttonBG.getPosition());
	ButtonMap::GetMap()["RESUME"]->highLightButton(window);
	ButtonMap::GetMap()["RESUME"]->render(window, deltatime);

	ButtonMap::GetMap()["LOAD"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, -40) - sizeOffset);
	ButtonMap::GetMap()["LOAD"]->buttonText.setFont(BAUHS);
	ButtonMap::GetMap()["LOAD"]->buttonText.setPosition(ButtonMap::GetMap()["LOAD"]->buttonBG.getPosition());
	ButtonMap::GetMap()["LOAD"]->highLightButton(window);
	ButtonMap::GetMap()["LOAD"]->render(window, deltatime);

	ButtonMap::GetMap()["SAVE"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, 0) - sizeOffset);
	ButtonMap::GetMap()["SAVE"]->buttonText.setFont(BAUHS);
	ButtonMap::GetMap()["SAVE"]->buttonText.setPosition(ButtonMap::GetMap()["SAVE"]->buttonBG.getPosition());
	ButtonMap::GetMap()["SAVE"]->highLightButton(window);
	ButtonMap::GetMap()["SAVE"]->render(window, deltatime);

	ButtonMap::GetMap()["QUIT"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, 40) - sizeOffset);
	ButtonMap::GetMap()["QUIT"]->buttonText.setFont(BAUHS);
	ButtonMap::GetMap()["QUIT"]->buttonText.setPosition(ButtonMap::GetMap()["QUIT"]->buttonBG.getPosition());
	ButtonMap::GetMap()["QUIT"]->highLightButton(window);
	ButtonMap::GetMap()["QUIT"]->render(window, deltatime);

	window->display();
}						 

void PauseMenu::InitButtons()
{
	sf::Vector2f size(125, 35);
	ButtonMap::GetMap().insert(
		{
			"RESUME", new Button(size, sf::Color(100, 100, 100, 255), "RESUME GAME")
		}
	);
	ButtonMap::GetMap().insert(
		{
			"LOAD", new Button(size, sf::Color(100, 100, 100, 255), "SAVE TILE MAP")
		}
	);
	ButtonMap::GetMap().insert(
		{
			"SAVE", new Button(size, sf::Color(100, 100, 100, 255), "LOAD TILE MAP")
		}
	);
	ButtonMap::GetMap().insert(
		{
			"QUIT", new Button(size, sf::Color(100, 100, 100, 255), "QUIT GAME")
		}
	);
}

void PauseMenu::Quit(sf::RenderWindow* window)
{
	window->close();
}

//ButtonMap::GetMap()["RESUME"]
