#pragma once
#include "Scene.h"
#include "Bullet.h"
#include "Pickup.h"
#include "Player.h"
#include "Pickup.h"
#include "TextureHolder.h"
#include "LivingDead.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <sstream>
#include <fstream>
//Global function
int createBackground(VertexArray& rVA, IntRect arena);
LivingDead* createHorde(int numZombies, IntRect arena);
class SceneLivingDeadArena :
	public Scene
{
private:
	// Here is the instabce of TextureHolder
	TextureHolder holder;

	// The game will always be in one of four states
	enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };
	// Start with the GAME_OVER state
	State state = State::GAME_OVER;
	// Get the screen resolution and create an SFML window
	Vector2f resolution;
	// Create a an SFML View for the main action
	View mainView;
	// Here is our clock for timing everything
	Clock clock;
	// How long has the PLAYING state been active
	Time gameTimeTotal;
	// Where is the mouse in relation to world coordinates
	Vector2f mouseWorldPosition;
	// Where is the mouse in relation to screen coordinates
	Vector2i mouseScreenPosition;
	// Create an instance of the Player class
	Player player;
	// The boundaries of the arena
	IntRect arena;
	// Create the background
	VertexArray background;
	// Load the texture for our background vertex array
	Texture textureBackground;
	// Prepare for a horde of zombies
	int numZombies;
	int numZombiesAlive;
	LivingDead* zombies = NULL;
	// 100 bullets should do
	Bullet bullets[100];
	int currentBullet = 0;
	int bulletsSpare = 24;
	int bulletsInClip = 6;
	int clipSize = 6;
	float fireRate = 1;
	// When was the fire button last pressed?
	Time lastPressed;
	Sprite spriteCrosshair;
	Texture textureCrosshair;
	// Create a couple of pickups
	Pickup* healthPickup;
	Pickup* ammoPickup;
	// About the game
	int score = 0;
	int hiScore = 0;
	// For the home/game over screen
	Sprite spriteGameOver;
	Texture textureGameOver;
	// Create a view for the HUD
	View hudView;
	// Create a sprite for the ammo icon
	Sprite spriteAmmoIcon;
	Texture textureAmmoIcon;
	// Load the font
	Font font;
	// Paused
	Text pausedText;
	// Game Over
	Text gameOverText;
	// Levelling up
	Text levelUpText;
	// Ammo
	Text ammoText;
	// Score
	Text scoreText;
	// Load the high score from a text file/
	std::ifstream inputFile;
	// High Score
	Text hiScoreText;
	// Zombies remaining
	Text zombiesRemainingText;
	// Wave number
	int wave = 0;
	Text waveNumberText;
	// Health bar
	RectangleShape healthBar;
	// When did we last update the HUD?
	int framesSinceLastHUDUpdate = 0;
	// What time was the last update
	Time timeSinceLastUpdate;
	// How often (in frames) should we update the HUD
	int fpsMeasurementFrameInterval = 1000;

	// Prepare the hit sound
	SoundBuffer hitBuffer;
	Sound hit;
	// Prepare the splat sound
	SoundBuffer splatBuffer;
	Sound splat;
	// Prepare the shoot sound
	SoundBuffer shootBuffer;
	Sound shoot;
	// Prepare the reload sound
	SoundBuffer reloadBuffer;
	Sound reload;
	// Prepare the failed sound
	SoundBuffer reloadFailedBuffer;
	Sound reloadFailed;
	// Prepare the powerup sound
	SoundBuffer powerupBuffer;
	Sound powerup;
	// Prepare the pickup sound
	SoundBuffer pickupBuffer;
	Sound pickup;

public:
	SceneLivingDeadArena(RenderWindow& rw, int sizeX, int sizeY);
	~SceneLivingDeadArena();
	void loadAssets();
	virtual void processEvents(const Event &event);
	//game loop
	virtual void update(Time t);
	//render
	virtual void render();
};