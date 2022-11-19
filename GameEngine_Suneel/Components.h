#pragma once
#include "Engine.h"


struct Transform 
{
public: 
	ECS_DECLARE_TYPE;
	float xPos;
	float yPos;
	float rotation;
	float xSpeed;
	float ySpeed;
	float xSpeedMod;
	float ySpeedMod;

	Transform(float newX, float newY, float xSpeed = 0.0f, float ySpeed = 0.0f, float rotation = 0.0f) {
		this -> xPos = newX;
		this->yPos = newY;
		this->xSpeed = 0.0f;
		this->ySpeed = 0.0f;
		this->xSpeedMod = xSpeed;
		this->ySpeedMod = ySpeed;
		this->rotation = rotation;
	}

	void Move() {
		this->xPos += this->xSpeed;
		this->yPos += this->ySpeed;
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

struct Animator {
public:
	ECS_DECLARE_TYPE;

	int spriteWidth;
	int spriteHeight;
	int currentColumn;
	int currentRow;
	int totalColumns;
	int totalRows;
	float currentTime;
	float nextFrameTime;
	bool bFacingRight;

	Animator(int newWidth, int newHeight, float timeBetweenFrames, int columns, int rows) 
	{
		this->spriteWidth = newWidth;
		this->spriteHeight = newHeight;
		this->currentColumn = 0;
		this->currentRow = 0;
		this->totalColumns = columns;
		this->totalRows = rows;
		this->nextFrameTime = timeBetweenFrames;
		this->currentTime = 0;
		this->bFacingRight = true;
	}
};
ECS_DEFINE_TYPE(Animator);

struct InputController {
public:

	ECS_DECLARE_TYPE;

	bool bInputActive;
	bool w, a, s, d, left, right, up, down, space;

	InputController() 
	{
		std::memset(this, false, sizeof(InputController));
		bInputActive = true;
	}
};
ECS_DEFINE_TYPE(InputController);

struct BoxCollider {
public:
	ECS_DECLARE_TYPE;
	int leftEdge, rightEdge, topEdge, bottomEdge;

	BoxCollider() {
	std:memset(this, 0, sizeof(BoxCollider));
	}

	void Update(int x, int y, int width, int height) {
		this->leftEdge = x;
		this->rightEdge = x + width;
		this->topEdge = y;
		this->bottomEdge = y + height;
	}
}
ECS_DEFINE_TYPE(BoxCollider);

struct Tag {
	ECS_DECLARE_TYPE;
public:
	std::vector<std::string> tagNames;
	Tag() = default;
	void addTag(std::string tag)
	{
		this->tagNames.push_back(tag);
	}

};
ECS_DEFINE_TYPE(Tag);

struct TileMap {
	ECS_DECLARE_TYPE;
public:
	float gridSizeF;
	uint32_t gridSizeU;
	uint32_t layers;
	sf::Vector2u maxSize;
	sf::RectangleShape collisionBox;
	std::vector<std::vector<std::vector<Tile*>>> map;
	TileMap() = default;
	
};
ECS_DEFINE_TYPE(TileMap);