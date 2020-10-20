#include "GameObject.h"

GameObject::GameObject(RenderWindow& rw, Scene* s):mWindow(rw),
pTexture(NULL), pSprite(NULL),scene(s),collider(100)
{
}

GameObject::~GameObject()
{
}
