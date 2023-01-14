#include "RenderingSystem.h"

RenderingSystem::RenderingSystem() = default;

RenderingSystem::~RenderingSystem() = default;

void RenderingSystem::tick(ECS::World* world, float deltaTime)
{
	if (States::getPausedState() == false)
	{
		// Clear before drawing all texture
		Engine::GetInstance().window->clear();

		world->each<Transform, Sprite2D>([&](ECS::Entity* entity,
			ECS::ComponentHandle<Transform> transform,
			ECS::ComponentHandle<Sprite2D> sprite2D
			) -> void
			{
				//check if an entity had their texture already loaded
				if (textureMap.count(sprite2D->texture) < 1) {
					textureMap[sprite2D->texture] = LoadTexture(sprite2D->texture);
				}
				// If no texture is found, then add a texture to the map
				if (sprite2D->picture.getTexture() == nullptr) {
					sprite2D->picture.setTexture(*textureMap[sprite2D->texture]);
					sprite2D->width = sprite2D->picture.getGlobalBounds().width;
					sprite2D->height = sprite2D->picture.getGlobalBounds().height;
				}

				// Update anbd draw to the screen 
				sprite2D->picture.setPosition(transform->xPos, transform->yPos);
				Engine::GetInstance().window->draw(sprite2D->picture);

			});

		world->each <TileMap>(
			[&](
				ECS::Entity* entity,
				ECS::ComponentHandle<TileMap> tileMap
				) -> void 
			{
				// Loop through each tile and render onto the engines window instance
				// Note that this is looping through a vector which stores a vector which stores the tile value
				for (auto& x:tileMap->map)
				{
					for (auto& y:x)
					{
						for (auto& z:y)
						{
							if (z != nullptr)
							{
								sf::RenderWindow* winRef = Engine::GetInstance().window;
								winRef->draw(z->shape);
								if (z->getCollision() == true)
								{
									tileMap->collisionBox.setPosition(z->GetPosition());
									winRef->draw(tileMap->collisionBox);
								}
							}
						}
					}
				}
			});;
	

		// Display update
		Engine::GetInstance().window->display();
	}
}

sf::Texture* RenderingSystem::LoadTexture(std::string texturePath)
{
	sf::Texture* _texture = new sf::Texture();
	// If texture is not found
	if (_texture->loadFromFile(texturePath) == false) {
		std::cerr << "error: Unable to load image  " << texturePath << ".\nIs this image in the correct directory?" << std::endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	return _texture;
}