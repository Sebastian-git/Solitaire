#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Logic.h"

Game::Game() { }

void Game::run() {
	
	bool mousePress = false;

	// Generate deck with card images sprite
	sf::Texture deckSpriteSheet;
	if (!deckSpriteSheet.loadFromFile("betterDeckImages.png"))
		std::cout << "Could not load sprite sheet.\n";
	
	sf::Texture splashTexture;
	if (!splashTexture.loadFromFile("splash.png")) 
		std::cout << "Could not load splash screen.\n";

	sf::Texture buttonTexture;
	if (!buttonTexture.loadFromFile("start.png"))
		std::cout << "Could not load button image.\n";

	// Handles all game logic
	Logic* logic = new Logic(deckSpriteSheet);
	logic->startGame();

	// Create window that is passed into each class to .draw() cards
	sf::RenderWindow window(sf::VideoMode(1500, 900), "Solitaire");
	sf::Event event;

	// Create button
	sf::Sprite spriteButton;
	spriteButton.setTexture(buttonTexture);
	spriteButton.setScale(0.5, 0.5);
	spriteButton.setPosition({ (float)((685)), (float)(650)});
	
	// Splash screen loop
	while (window.isOpen()) {

		// Close if user clicks any key or mouse button
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mousePress) {
			mousePress = true;
			sf::Vector2i pos = sf::Mouse::getPosition(window);
			if (pos.x > 685 && pos.x < 800 && pos.y > 650 && pos.y < 800) goto EndSplash;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) mousePress = false;

		// Creates card image
		sf::Sprite sprite;
		sprite.setTexture(splashTexture);
		sprite.scale(sf::Vector2f(2.34, 1.95));
		window.draw(sprite);

		window.draw(spriteButton);

		// Updates window display
		window.display();
	}

	EndSplash:
	
	// Game loop
	while (window.isOpen()) {

		// Close if user clicks close window
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space) {
					std::cout << "Restarted\n";
					delete logic;
					logic = new Logic(deckSpriteSheet);
					logic->startGame();
				}
			}
		}

		// Set window background to green
		window.clear(sf::Color(50,150,50,255));

		// Take mouse position, print position if it's in the x/y bounds of waste

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mousePress) {
			mousePress = true;
			sf::Vector2i pos = sf::Mouse::getPosition(window);
			if (logic->validMousePosition(pos)) { 
				//std::cout << pos.x << ":" << pos.y << "\n";
			}
		} else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) mousePress = false;

		// Draws cards to screen, calls logic class to handle card logic behind the scenes
		logic->draw(window);

		// Updates window display
		window.display();
	}
}