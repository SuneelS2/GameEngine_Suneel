#include "AnimationSystem.h"

void AnimationSystem::tick(ECS::World* world, float deltaTime)
{
	world->each<Animator, Sprite2D>(
		[&](ECS::Entity* entity,
			ECS::ComponentHandle<Animator> animator,
			ECS::ComponentHandle<Sprite2D> sprite2D
			) -> void
		{
			animator->currentTime += deltaTime;
			if (animator->currentTime >= animator->nextFrameTime)
			{
				animator->currentTime = 0;
				animator->currentColumn = (animator->currentColumn + 1) % animator->totalColumns;
			}
			sprite2D->picture.setTextureRect(sf::IntRect(
				animator->currentColumn * animator->spriteWidth,
				animator->currentRow * animator->spriteHeight,
				animator->spriteWidth,
				animator->spriteHeight
				));
		});
}
