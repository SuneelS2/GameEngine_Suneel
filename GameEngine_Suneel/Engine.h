#pragma once
#include<iostream>
#include "sfml/graphics.hpp"
#include "ECS.h"
#include "Components.h"
#include "System/RenderingSystems.h"
class Engine
{
public:
	sf::RenderWindow* window;
	ECS::World* world = nullptr;

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

