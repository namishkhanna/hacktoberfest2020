#include "Scene.h"

Scene::Scene(RenderWindow& rw, int sizeX, int sizeY):
	mWindow(rw), sizeX(sizeX),sizeY(sizeY)
{
}


Scene::~Scene()
{
	for (auto o = objects.begin();
		o != objects.end();
		++o) {
		delete(*o);//delete all scene pointer
	}
	objects.clear();//clear the vector. 
}

void Scene::processEvents(const Event & event)
{
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->processEvents(event);
	}
}

void Scene::update(Time t)
{

	for (int i = 0; i < objects.size(); i++) {
		objects[i]->update(t);
	}
	//Collision Detection
	
	for (int i = 0; i < objects.size(); i++) { //Get 1st object
		for (int j = i; j < objects.size(); j++) { //Get 2nd object
			if (i != j) { //Make sure object does not check itself
				//Get radius
				int r1 = objects[i]->collider;
				int r2 = objects[j]->collider;
				//Get position
				Vector2f p1 = objects[i]->pSprite->getPosition();
				Vector2f p2 = objects[j]->pSprite->getPosition();
				Vector2f displacement = p1 - p2;
				float distance = sqrt(pow(displacement.x, 2) +
									  pow(displacement.y, 2));//Pythagorous Theorem
				if (distance <= r1 + r2) { //collision
					if(i < objects.size() && j < objects.size())
						objects[i]->onCollisionEnter(objects[j]);
					if (i < objects.size() && j < objects.size())
						objects[j]->onCollisionEnter(objects[i]);
				}
				else {
					if (i < objects.size() && j < objects.size())
						objects[i]->onCollisionExit(objects[j]);
					if (i < objects.size() && j < objects.size())
						objects[j]->onCollisionExit(objects[i]);
				}
			}

		}
	}
}

void Scene::render()
{
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->render();
	}
 
}

void Scene::addGameObject(GameObject * obj)
{
	objects.push_back(obj);
}

void Scene::removeGameObject(GameObject * obj)
{
	for (int i = 0; i < objects.size(); i++) {
		GameObject * obj1 = objects[i];
		if (obj1 == obj) {
			objects.erase(objects.begin() + i);
			delete obj;
			break;
		}
	}
}
