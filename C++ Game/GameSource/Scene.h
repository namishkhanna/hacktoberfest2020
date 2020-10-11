#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace std;
using namespace sf;
class Scene //Abstract class. To use must override pvf
{
protected:
	//Display variables
	RenderWindow &mWindow;//Use reference bcos there is only
					//one graphics object in the entire game
	int sizeX, sizeY;
	
public:
	vector<GameObject*> objects;
	Scene(RenderWindow& rw, int sizeX, int sizeY);
	~Scene();
	virtual void processEvents(const Event &event);
	//game loop
	virtual void update(Time t);
	//render
	virtual void render();
	//Add and remove game objects
	void addGameObject(GameObject* obj);
	void removeGameObject(GameObject* obj);
};