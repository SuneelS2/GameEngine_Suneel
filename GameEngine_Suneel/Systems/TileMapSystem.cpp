#include "TileMapSystem.h"

void TileMapSystem::tick(ECS::World* world, float deltaTime)
{
	world->each<TileMap>(
		[&](ECS::Entity* entity, ECS::ComponentHandle<TileMap> TileMap)->void
		{
			if (States::getPausedState() == false)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					this->AddTileOnClick(true, TileMap);
					std::cout << entity->getEntityId() << " is the entity id(with collision)" << "\n";
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
				{
					this->AddTileOnClick(false, TileMap);
					std::cout << entity->getEntityId() << " is the entity id(without collision)" << "\n";
				}
			}

			if (ButtonMap::GetMap()["SAVE"] -> bClicked)
			{
				std::cout << "Saved" << std::endl;
				TileMap->SaveTileMap("tiletest.txt");
				ButtonMap::GetMap()["SAVE"]->bClicked = false;
			}

			if (ButtonMap::GetMap()["LOAD"]->bClicked)
			{
				std::cout << "Loaded" << std::endl;
				TileMap->LoadTileMap("tiletest.txt");
				ButtonMap::GetMap()["LOAD"]->bClicked = false;
			}
		});
}

void TileMapSystem::AddTileOnClick(bool bHasCollision, ECS::ComponentHandle<TileMap> tileMap)
{
	sf::RenderWindow* winRef = Engine::GetInstance().window;
	sf::Vector2f mousePosView = winRef->mapPixelToCoords(sf::Mouse::getPosition(*winRef));
	sf::Vector2f mousePosGrid(static_cast<int>(mousePosView.x / tileMap->gridSizeF), static_cast<int>(mousePosView.y / tileMap->gridSizeF));
	tileMap->AddTile(mousePosGrid.x, mousePosGrid.y, 0, bHasCollision);
}
