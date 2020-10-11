#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "SceneLivingDeadArena.h"
using namespace std;//C++ Std Tempplate Library
using namespace sf; //SFML Library

class Game
{
protected:
	//Display Variables
	RenderWindow mWindow;//Graphics object to OPENGL
	
	//Engine Variables
	Clock clock; //This is for time.deltaTime
	vector<Scene*> scenes; //This is to store all scenes
	int currentScene;//refer to the current scene to be shown
public:
	Game(int sizeX, int sizeY, String title);
	virtual ~Game();
	void run();
	static int sizeX, sizeY; //Size of the window
protected:
	//Event Handling
	void processEvents();
	//Game Loop
	void update(Time t);
	//Rendering of graphics
	void render();
};

