#include "Engine.h"

void Engine::Start(sf::RenderWindow* win)
{
	this->window = win;
	while (window->isOpen())
	{
		this->Update();
	}
}

Engine::Engine()
{
	bQuit = false;
}

Engine::~Engine() = default;

void Engine::Update()
{
	sf::Event event;
	while (window->pollEvent(event) == true)
	{
		//CLose requested event
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}
}

Engine& Engine::GetInstance()
{
	static Engine instance;
	return instance;
}

void Engine::addSystem(ECS::EntitySystem* newSys)
{
	world->registerSystem(newSys);
	world->enableSystem(newSys);
}
