#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace std;

int main()
{
	Vector2f screenSize;
	// Get the screen resolution and create an SFML window
	screenSize.x = VideoMode::getDesktopMode().width;
	screenSize.y = VideoMode::getDesktopMode().height;
	Game game(screenSize.x, screenSize.y, "Living Dead Arena");
	game.run();
	return 0;
}