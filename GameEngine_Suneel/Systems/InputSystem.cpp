#include "InputSystem.h"

InputSystem::InputSystem(sf::RenderWindow* window)
{
	this->window = window;
}

void InputSystem::tick(ECS::World* world, float deltaTime)
{
	this->GetKeyEvents(world);
}

void InputSystem::GetKeyEvents(ECS::World* world)
{
	if (States::getPausedState() == false)
	{
		world->each<InputController>(
			[&](ECS::Entity* entity,
				ECS::ComponentHandle<InputController> Input
				) -> void
			{
				Input->w = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
				Input->a = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
				Input->s = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
				Input->d = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
				Input->left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
				Input->right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
				Input->up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
				Input->down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
				Input->space = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
			});
	}
}
