#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Logic.h"

Game::Game() { }

void Game::run() {
	
	bool mousePress = false;

	// Generate deck with card images sprite
	sf::Texture deckSpriteSheet; 
	if (!deckSpriteSheet.loadFromFile("deckImages.png"))
		std::cout << "Could not load sprite sheet.\n";
	
	sf::Texture splashTexture;
	if (!splashTexture.loadFromFile("splash.png")) 
		std::cout << "Could not load splash screen.\n";

	// Handles all game logic
	Logic logic(deckSpriteSheet); 
	logic.startGame();

	// Create window that is passed into each class to .draw() cards
	sf::RenderWindow window(sf::VideoMode(1500, 900), "Solitaire");
	sf::Event event;

	// Splash screen loop
	while (window.isOpen()) {

		// Close if user clicks any key or mouse button
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
			else if (event.type == sf::Event::MouseButtonPressed) goto EndSplash;
			else if (event.type == sf::Event::KeyReleased) goto EndSplash;
		}

		// Creates card image
		sf::Sprite sprite;
		sprite.setTexture(splashTexture);
		sprite.scale(sf::Vector2f(2.34, 1.95));
		window.draw(sprite);

		// Updates window display
		window.display();
	}

	EndSplash:
	
	// Game loop
	while (window.isOpen()) {

		// Close if user clicks close window
		while (window.pollEvent(event)) if (event.type == sf::Event::Closed) window.close();

		// Set window background to green
		window.clear(sf::Color(50,150,50,255));

		// Take mouse position, print position if it's in the x/y bounds of waste
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mousePress) {
			mousePress = true;
			sf::Vector2i pos = sf::Mouse::getPosition(window);
			if (logic.validMousePosition(pos)) { 
				//std::cout << pos.x << ":" << pos.y << "\n";
			}
		} else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) mousePress = false;

		
		
		// Draws cards to screen, calls logic class to handle card logic behind the scenes
		logic.draw(window);

		// Updates window display
		window.display();
	}
}