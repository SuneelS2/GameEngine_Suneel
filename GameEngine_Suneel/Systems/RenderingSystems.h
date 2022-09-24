#pragma once
#include "../Engine.h"
class RenderingSystems: public ECS::EntitySystem
{
	RenderingSystems();
	~RenderingSystems();
	void tick(ECS::World* world, float deltaTime) override;
};

