#include "Game.h"
#include "Windows.h"

Game::Game(int sizeX, int sizeY, String title)
//Initialisation of object (not pointers) in the game
	:mWindow(VideoMode(sizeX,sizeY),title)	
{
	//Create a MonsterScene and store it in the scenes vector
	scenes.push_back(new SceneLivingDeadArena(
		mWindow, sizeX, sizeY));
	currentScene = 0;
	Game::sizeX = sizeX;
	Game::sizeY = sizeY;
}

int Game::sizeX = 0;
int Game::sizeY = 0;

Game::~Game()//Destructor: call when object about to be destroyed
{
	for (auto s = scenes.begin();
		s != scenes.end();
		++s) {
		delete(*s);//delete all scene pointer
	}
	scenes.clear();
}

void Game::run()
{
	while (mWindow.isOpen())//Main Game Loop
	{
		processEvents();
		update(clock.restart());
		render();

	}
}

void Game::processEvents()
{
	Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();
		if (event.type == Event::KeyPressed) {
			switch(event.key.code)
			{
			case Keyboard::Add:
			case Keyboard::Equal:
				currentScene++;
				currentScene %= scenes.size();//Cyclic rotation
				break;
			case Keyboard::Subtract:
			case Keyboard::Hyphen:
				currentScene--;
				currentScene %= scenes.size();//Cyclic rotation
				break;
			default:
				break;
			}
		}
		if (!scenes.empty()) {
			scenes[currentScene]->processEvents(event);
		}
	}
}

void Game::update(Time t)
{
	if (!scenes.empty()) {
		scenes[currentScene]->update(t);
	}
}

void Game::render()
{
	mWindow.clear(Color::White);
	if (!scenes.empty()) {
		scenes[currentScene]->render();
	}
	mWindow.display();
}
