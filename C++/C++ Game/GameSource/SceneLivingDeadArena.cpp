#include "SceneLivingDeadArena.h"

SceneLivingDeadArena::SceneLivingDeadArena(RenderWindow& rw, int sizeX, int sizeY) :
	Scene(rw, sizeX, sizeY),
	mainView(sf::FloatRect(0, 0, sizeX, sizeY)),
	hudView(sf::FloatRect(0, 0, sizeX, sizeY)),
	resolution(sizeX, sizeY)
{
	loadAssets();
}

SceneLivingDeadArena::~SceneLivingDeadArena()
{
}

void SceneLivingDeadArena::loadAssets()
{
	state = State::GAME_OVER;

	healthPickup = new Pickup(1);
	ammoPickup = new Pickup(2);
	// Load the texture for our background vertex array
	textureBackground = TextureHolder::GetTexture(
		"graphics/background_floor.png");

	// Hide the mouse pointer and replace it with crosshair
	mWindow.setMouseCursorVisible(true);
	textureCrosshair = TextureHolder::GetTexture("graphics/crosshair.png");
	spriteCrosshair.setTexture(textureCrosshair);
	spriteCrosshair.setOrigin(25, 25);

	// For the home/game over screen
	textureGameOver = TextureHolder::GetTexture("graphics/background.jpg");
	spriteGameOver.setTexture(textureGameOver);
	spriteGameOver.setPosition(0, 0);

	// Create a sprite for the ammo icon
	textureAmmoIcon = TextureHolder::GetTexture("graphics/ammo_icon.png");
	spriteAmmoIcon.setTexture(textureAmmoIcon);
	spriteAmmoIcon.setPosition(20, 980);

	// Load the font
	font.loadFromFile("fonts/Enchanted.ttf");

	// Paused
	pausedText.setFont(font);
	pausedText.setCharacterSize(155);
	pausedText.setFillColor(Color::White);
	pausedText.setPosition(400, 400);
	pausedText.setString("Press Enter \nto continue");

	// Game Over
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(125);
	gameOverText.setFillColor(Color::White);
	gameOverText.setPosition(250, 850);
	gameOverText.setString("Press Enter to play");

	// Levelling up
	levelUpText.setFont(font);
	levelUpText.setCharacterSize(80);
	levelUpText.setFillColor(Color::White);
	levelUpText.setPosition(150, 250);
	stringstream levelUpStream;
	levelUpStream <<
		"1- Increased rate of fire" <<
		"\n2- Increased clip size(next reload)" <<
		"\n3- Increased max health" <<
		"\n4- Increased run speed" <<
		"\n5- More and better health pickups" <<
		"\n6- More and better ammo pickups";
	levelUpText.setString(levelUpStream.str());

	// Ammo
	ammoText.setFont(font);
	ammoText.setCharacterSize(55);
	ammoText.setFillColor(Color::White);
	ammoText.setPosition(200, 980);

	// Score
	scoreText.setFont(font);
	scoreText.setCharacterSize(55);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(20, 0);

	// Load the high score from a text file/
	std::ifstream inputFile("gamedata/scores.txt");
	if (inputFile.is_open())
	{
		inputFile >> hiScore;
		inputFile.close();
	}

	// High Score
	hiScoreText.setFont(font);
	hiScoreText.setCharacterSize(80);
	hiScoreText.setFillColor(Color::White);
	hiScoreText.setPosition(1400, 0);
	std::stringstream s;
	s << "High Score:" << hiScore;
	hiScoreText.setString(s.str());

	// Zombies remaining
	zombiesRemainingText.setFont(font);
	zombiesRemainingText.setCharacterSize(55);
	zombiesRemainingText.setFillColor(Color::White);
	zombiesRemainingText.setPosition(1500, 980);
	zombiesRemainingText.setString("Zombies: 100");

	// Wave number
	waveNumberText.setFont(font);
	waveNumberText.setCharacterSize(55);
	waveNumberText.setFillColor(Color::White);
	waveNumberText.setPosition(1250, 980);
	waveNumberText.setString("Wave: 0");

	// Health bar
	healthBar.setFillColor(Color::Red);
	healthBar.setPosition(450, 980);

	// Prepare the hit sound
	hitBuffer.loadFromFile("sound/hit.wav");
	hit.setBuffer(hitBuffer);

	// Prepare the splat sound
	splatBuffer.loadFromFile("sound/splat.wav");
	splat.setBuffer(splatBuffer);

	// Prepare the shoot sound
	shootBuffer.loadFromFile("sound/energySound.wav");
	shoot.setBuffer(shootBuffer);

	// Prepare the reload sound
	reloadBuffer.loadFromFile("sound/reload.wav");
	reload.setBuffer(reloadBuffer);

	// Prepare the failed sound
	reloadFailedBuffer.loadFromFile("sound/reload_failed.wav");
	reloadFailed.setBuffer(reloadFailedBuffer);

	// Prepare the powerup sound
	powerupBuffer.loadFromFile("sound/powerup.wav");
	powerup.setBuffer(powerupBuffer);

	// Prepare the pickup sound
	pickupBuffer.loadFromFile("sound/pickup.wav");
	pickup.setBuffer(pickupBuffer);
}

void SceneLivingDeadArena::processEvents(const Event & event)
{
	if (event.type == Event::KeyPressed)
	{
		// Pause a game while playing
		if (event.key.code == Keyboard::Return &&
			state == State::PLAYING)
		{
			state = State::PAUSED;
		}

		// Restart while paused
		else if (event.key.code == Keyboard::Return &&
			state == State::PAUSED)
		{
			state = State::PLAYING;
			// Reset the clock so there isn't a frame jump
			clock.restart();
		}

		// Start a new game while in GAME_OVER state
		else if (event.key.code == Keyboard::Return &&
			state == State::GAME_OVER)
		{
			state = State::LEVELING_UP;
			wave = 0;
			score = 0;

			// Prepare the gun and ammo for next game
			currentBullet = 0;
			bulletsSpare = 24;
			bulletsInClip = 6;
			clipSize = 6;
			fireRate = 1;

			// Reset the player's stats
			player.resetPlayerStats();
		}
		// Spin and zoom the world

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			mainView.rotate(.5f);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			mainView.rotate(-.5f);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			mainView.zoom(.99f);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			mainView.zoom(1.01f);
		}
		// End spinning and zooming

		if (state == State::PLAYING)
		{
			// Reloading
			if (event.key.code == Keyboard::R)
			{
				if (bulletsSpare >= clipSize)
				{
					// Plenty of bullets. Reload.
					bulletsInClip = clipSize;
					bulletsSpare -= clipSize;
					reload.play();
				}
				else if (bulletsSpare > 0)
				{
					// Only few bullets left
					bulletsInClip = bulletsSpare;
					bulletsSpare = 0;
					reload.play();
				}
				else
				{
					// More here soon?!
					reloadFailed.play();
				}
			}
		}
	}
	
	// Handle the player quitting
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		mWindow.close();
	}

	// Handle controls while playing
	if (state == State::PLAYING)
	{
		// Handle the pressing and releasing of the WASD keys
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			player.moveUp();
		}
		else
		{
			player.stopUp();
		}

		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			player.moveDown();
		}
		else
		{
			player.stopDown();
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			player.moveLeft();
		}
		else
		{
			player.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			player.moveRight();
		}
		else
		{
			player.stopRight();
		}

		// Fire a bullet
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//Cooling down technique
			if (gameTimeTotal.asMilliseconds()
				- lastPressed.asMilliseconds()
					> 1000 / fireRate && bulletsInClip > 0)
			{

				// Pass the centre of the player and the centre of the crosshair
				// to the shoot function
				bullets[currentBullet].shoot(
					player.getCenter().x, player.getCenter().y,
					mouseWorldPosition.x, mouseWorldPosition.y);

				currentBullet++;
				if (currentBullet > 99)
				{
					currentBullet = 0;
				}
				lastPressed = gameTimeTotal;
				shoot.play();
				bulletsInClip--;
			}

		}// End fire a bullet

	}// End WASD while playing

	 // Handle the levelling up state
	if (state == State::LEVELING_UP)
	{
		// Handle the player levelling up
		if (event.key.code == Keyboard::Num1)
		{
			// Increase fire rate
			fireRate++;
			state = State::PLAYING;
		}

		if (event.key.code == Keyboard::Num2)
		{
			// Increase clip size
			clipSize += clipSize;
			state = State::PLAYING;
		}

		if (event.key.code == Keyboard::Num3)
		{
			// Increase health
			player.upgradeHealth();
			state = State::PLAYING;
		}

		if (event.key.code == Keyboard::Num4)
		{
			// Increase speed
			player.upgradeSpeed();
			state = State::PLAYING;
		}

		if (event.key.code == Keyboard::Num5)
		{
			healthPickup->upgrade();
			state = State::PLAYING;
		}

		if (event.key.code == Keyboard::Num6)
		{
			ammoPickup->upgrade();
			state = State::PLAYING;
		}

		if (state == State::PLAYING)
		{
			// Increase the wave number
			wave++;

			// Prepare thelevel
			// We will modify the next two lines later
			arena.width = 500 * wave;
			arena.height = 500 * wave;
			arena.left = 0;
			arena.top = 0;

			// Pass the vertex array by reference 
			// to the createBackground function
			int tileSize = createBackground(background, arena);

			// Spawn the player in the middle of the arena
			player.spawn(arena, resolution, tileSize);

			// Configure the pick-ups
			healthPickup->setArena(arena);
			ammoPickup->setArena(arena);

			// Create a horde of zombies
			numZombies = 5 * wave;

			// Delete the previously allocated memory (if it exists)
			delete[] zombies;
			zombies = createHorde(numZombies, arena);
			numZombiesAlive = numZombies;

			// Play the powerup sound
			powerup.play();

			// Reset the clock so there isn't a frame jump
			clock.restart();
		}
	}// End levelling up
}

void SceneLivingDeadArena::update(Time t)
{
	if (state == State::PLAYING)
	{
		// Update the delta time
		Time dt = clock.restart();
		// Update the total game time
		gameTimeTotal += dt;
		// Make a decimal fraction of 1 from the delta time
		float dtAsSeconds = dt.asSeconds();

		// Where is the mouse pointer
		mouseScreenPosition = Mouse::getPosition();

		// Convert mouse position to world coordinates of mainView
		mouseWorldPosition = mWindow.mapPixelToCoords(
			Mouse::getPosition(), mainView);

		// Set the crosshair to the mouse world location
		spriteCrosshair.setPosition(mouseWorldPosition);

		// Update the player
		player.update(dtAsSeconds, Mouse::getPosition());

		// Make a note of the players new position
		Vector2f playerPosition(player.getCenter());

		// Make the view centre around the player				
		mainView.setCenter(player.getCenter());

		// Loop through each Zombie and update them
		for (int i = 0; i < numZombies; i++)
		{
			if (zombies[i].isAlive())
			{
				zombies[i].update(dt.asSeconds(), playerPosition);
			}
		}

		// Update any bullets that are in-flight
		for (int i = 0; i < 100; i++)
		{
			if (bullets[i].isInFlight())
			{
				bullets[i].update(dtAsSeconds);
			}
		}

		// Update the pickups
		healthPickup->update(dtAsSeconds);
		ammoPickup->update(dtAsSeconds);

		// Collision detection
		// Have any zombies been shot?
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < numZombies; j++)
			{
				if (bullets[i].isInFlight() &&
					zombies[j].isAlive())
				{
					if (bullets[i].getPosition().intersects
					(zombies[j].getPosition()))
					{
						// Stop the bullet
						bullets[i].stop();

						// Register the hit and see if it was a kill
						if (zombies[j].hit()) {
							// Not just a hit but a kill too
							score += 10;
							if (score >= hiScore)
							{
								hiScore = score;
							}

							numZombiesAlive--;

							// When all the zombies are dead (again)
							if (numZombiesAlive == 0) {
								state = State::LEVELING_UP;
							}
						}

						// Make a splat sound
						splat.play();

					}
				}

			}
		}// End zombie being shot

		 // Have any zombies touched the player			
		for (int i = 0; i < numZombies; i++)
		{
			if (player.getPosition().intersects
			(zombies[i].getPosition()) && zombies[i].isAlive())
			{

				if (player.hit(gameTimeTotal))
				{
					// More here later
					hit.play();
				}

				if (player.getHealth() <= 0)
				{
					state = State::GAME_OVER;

					std::ofstream outputFile("gamedata/scores.txt");
					outputFile << hiScore;
					outputFile.close();

				}
			}
		}// End player touched

		 // Has the player touched health pickup
		if (player.getPosition().intersects
		(healthPickup->getPosition()) && healthPickup->isSpawned())
		{
			player.increaseHealthLevel(healthPickup->gotIt());
			// Play a sound
			pickup.play();

		}

		// Has the player touched ammo pickup
		if (player.getPosition().intersects
		(ammoPickup->getPosition()) && ammoPickup->isSpawned())
		{
			bulletsSpare += ammoPickup->gotIt();
			// Play a sound
			reload.play();

		}

		// size up the health bar
		healthBar.setSize(Vector2f(player.getHealth() * 3, 70));

		// Increment the amount of time since the last HUD update
		timeSinceLastUpdate += dt;
		// Increment the number of frames since the last HUD calculation
		framesSinceLastHUDUpdate++;
		// Calculate FPS every fpsMeasurementFrameInterval frames
		if (framesSinceLastHUDUpdate > fpsMeasurementFrameInterval)
		{

			// Update game HUD text
			std::stringstream ssAmmo;
			std::stringstream ssScore;
			std::stringstream ssHiScore;
			std::stringstream ssWave;
			std::stringstream ssZombiesAlive;

			// Update the ammo text
			ssAmmo << bulletsInClip << "/" << bulletsSpare;
			ammoText.setString(ssAmmo.str());

			// Update the score text
			ssScore << "Score:" << score;
			scoreText.setString(ssScore.str());

			// Update the high score text
			ssHiScore << "High Score:" << hiScore;
			hiScoreText.setString(ssHiScore.str());

			// Update the wave
			ssWave << "Wave:" << wave;
			waveNumberText.setString(ssWave.str());

			// Update the high score text
			ssZombiesAlive << "Zombies:" << numZombiesAlive;
			zombiesRemainingText.setString(ssZombiesAlive.str());

			framesSinceLastHUDUpdate = 0;
			timeSinceLastUpdate = Time::Zero;
		}// End HUD update

	}// End updating the scene
}

void SceneLivingDeadArena::render()
{
	// Draw our game scene here
	if (state == State::PLAYING)
	{
		mWindow.clear();

		// set the mainView to be displayed in the window
		// And draw everything related to it
		mWindow.setView(mainView);

		// Draw the background
		mWindow.draw(background, &textureBackground);

		// Draw the zombies
		for (int i = 0; i < numZombies; i++)
		{
			mWindow.draw(zombies[i].getSprite());
		}

		for (int i = 0; i < 100; i++)
		{
			if (bullets[i].isInFlight())
			{
				mWindow.draw(bullets[i].getShape());
			}
		}

		// Draw the player
		mWindow.draw(player.getSprite());

		// Draw the pickups is currently spawned
		if (ammoPickup->isSpawned())
		{
			mWindow.draw(ammoPickup->getSprite());
		}
		if (healthPickup->isSpawned())
		{
			mWindow.draw(healthPickup->getSprite());
		}

		//Draw the crosshair
		mWindow.draw(spriteCrosshair);

		// Switch to the HUD view
		mWindow.setView(hudView);

		// Draw all the HUD elements
		mWindow.draw(spriteAmmoIcon);
		mWindow.draw(ammoText);
		mWindow.draw(scoreText);
		mWindow.draw(hiScoreText);
		mWindow.draw(healthBar);
		mWindow.draw(waveNumberText);
		mWindow.draw(zombiesRemainingText);
	}

	if (state == State::LEVELING_UP)
	{
		mWindow.draw(spriteGameOver);
		mWindow.draw(levelUpText);
	}

	if (state == State::PAUSED)
	{
		mWindow.draw(pausedText);
	}

	if (state == State::GAME_OVER)
	{
		mWindow.draw(spriteGameOver);
		mWindow.draw(gameOverText);
		mWindow.draw(scoreText);
		mWindow.draw(hiScoreText);
	}
}
