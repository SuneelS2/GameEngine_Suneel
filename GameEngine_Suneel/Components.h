#pragma once
#include "Engine.h"

struct Transform 
{
public: 
	ECS_DECLARE_TYPE;
	float xPos;
	float yPos;

	Transform(float newX, float newY) {
		this -> xPos = newX;
		this->yPos = newY;
	}

};
ECS_DEFINE_TYPE(Tranform);

struct Sprite2D
{
public:
	ECS_DECLARE_TYPE;

	sf::Sprite picture;
	std::string texture;
	int width, height;

	Sprite2D(std::string filepath) : texture(filepath) {

	}
};
ECS_DEFINE_TYPE(Sprite2D);