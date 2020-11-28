#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Logic.h"

Game::Game() { }

void Game::run() {

	// Generate deck with card images sprite
	sf::Texture deckSpriteSheet; 
	if (!deckSpriteSheet.loadFromFile("deckImages.png"))
		std::cout << "Could not load sprite sheet.\n";

	// Handles all game logic
	Logic logic(deckSpriteSheet); 
	logic.startGame();

	// Create window that is passed into each class to .draw() cards
	sf::RenderWindow window(sf::VideoMode(1400, 800), "Solitaire");
	sf::Event event;

	// Game loop
	while (window.isOpen()) {

		// Close if user clicks close window
		while (window.pollEvent(event)) if (event.type == sf::Event::Closed) window.close();

		// Set window background to green
		window.clear(sf::Color::Green);
		
		// Draws cards to screen
		logic.draw(window);

		// Updates window display
		window.display();
	}
}