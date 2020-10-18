#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Scene;
			//forward definition
class GameObject
{
protected:
	//Display variables
	RenderWindow &mWindow;
	Scene* scene;
public:
	float collider; //This is the collider sphere
	Texture* pTexture;
	Sprite* pSprite;
	GameObject(RenderWindow& rw, Scene* s);
	virtual ~GameObject();
	virtual void processEvents(const Event &event)=0;
	//game loop
	virtual void update(Time t)=0;
	//render
	virtual void render()=0;
	//Collision handling
	virtual void onCollisionEnter(GameObject* collider) {};
	virtual void onCollisionExit(GameObject* collider) {};
};