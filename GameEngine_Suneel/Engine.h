#pragma once
#include<iostream>
#include "sfml/graphics.hpp"
#include "ECS.h"
#include "Components.h"
#include "Systems/RenderingSystem.h"
#include "Systems/AnimationSystem.h"
#include "Systems/MovementSystem.h"
#include "Systems/InputSystem.h"
#include "Systems/PhysicsSystem.h"
#include "Interface/MainCamera.h"

class Engine
{
public:
	sf::RenderWindow* window = nullptr;
	ECS::World* world = nullptr;
	class MainCamera* mainCamera = nullptr;
private: 
	bool bQuit;

public:
	void Start(sf::RenderWindow* win);
	static Engine& GetInstance();
	void addSystem(ECS::EntitySystem* newSys);

private:
	Engine();
	// Required to prevent the referance from being copied moved or assigned
	Engine(Engine& copy); // Hide copy constructor
	Engine(Engine&& other); // Hide move constructor
	Engine& operator=(Engine& copy); // Hide assignment operator

	~Engine();
	void Update();
	
};

