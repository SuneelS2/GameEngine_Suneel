#include "Engine.h"

void Engine::Start(sf::RenderWindow* win)
{
	this->window = win;
	mainCamera = new MainCamera(sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y / 2));

	pauseMenu = new PauseMenu(win);
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

		this->pauseMenu->Update(event, 10.0f, this->window);
	}
	world->tick(10.0f);

	mainCamera->Update(world, 10.0f, window);

	if (States::getPausedState())
	{
		this->onGameInactiveState();
	}
}

void Engine::onGameInactiveState()
{
	pauseMenu->Render(this->window, 10.0f, this->mainCamera->cameraView.getCenter());
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
