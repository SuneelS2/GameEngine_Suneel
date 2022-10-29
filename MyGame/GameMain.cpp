#include "../GameEngine_Suneel/Engine.h"



int main(int argc, char* args[]) {
	//Declare and get instance of singleton
	Engine& gameEngine = Engine::GetInstance();
	sf::RenderWindow window(sf::VideoMode(800, 600), "My Game Engine");

	// create the world and attack entities and system to
	gameEngine.world = ECS::World::createWorld();

	ECS::Entity* background = nullptr;
	ECS::Entity* stickFigure = nullptr;
	ECS::Entity* tux = nullptr;

	// add systems to the engine
	gameEngine.addSystem(new RenderingSystem());
	gameEngine.addSystem(new AnimationSystem());
	gameEngine.addSystem(new InputSystem(&window));
	gameEngine.addSystem(new MovementSystem());
	gameEngine.addSystem(new PhysicsSystem());

	//create and assign 250 entities to the world
	//for (int x = 0; x < 25; x++)
	//{
	//	for (int y = 0; y < 10; y++)
	//	{
	//		stickFigure = gameEngine.world->create();
	//		// assign components to entities after creation
	//		stickFigure->assign<Transform>(x * 25, y * 32);
	//		stickFigure->assign<Sprite2D>("../Debug/Pics/hero.png");
	//		std::cout << stickFigure->getEntityId() << " is the entity id." << std::endl;
	//	}
	//}

	//Create and assign entities to the world
	background = gameEngine.world->create();
	stickFigure = gameEngine.world->create();
	tux = gameEngine.world->create();

	//assign components to entities after creation
	background->assign<Transform>(0, 0);
	background->assign<Sprite2D>("../Debug/Pics/bg.jpg");
	stickFigure->assign<Transform>(300, 300);
	stickFigure->assign<Sprite2D>("../Debug/Pics/herosheet.png");
	stickFigure->assign<Animator>(32, 32, 200.0f, 4, 1);
	stickFigure->assign<BoxCollider>();
	tux->assign<Transform>(200, 200, 0.3f, 0.3f);
	tux->assign<Sprite2D>("../Debug/Pics/tux_from_linux.png");
	tux->assign<Animator>(56, 72, 2000.0f, 3, 9);
	tux->assign<InputController>();
	tux->assign<BoxCollider>();
	tux->get<Animator>()->currentRow = 0; //Idle row

	std::cout << background->getEntityId() << " is the entity id." << std::endl;
	std::cout << stickFigure->getEntityId() << " is the entity id." << std::endl;
	std::cout << tux->getEntityId() << " is the entity id." << std::endl;

	// Pass window referance to the engine and start
	gameEngine.Start(&window); // passing in the address of the window


	return 0;
}