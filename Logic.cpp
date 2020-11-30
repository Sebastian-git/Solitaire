#include "Logic.h"
#include <SFML/Graphics.hpp>

Logic::Logic(sf::Texture & deckSpriteSheet) : 
	deckSpriteSheet(deckSpriteSheet), 
	stock(deckSpriteSheet, 10, 630),
	waste(deckSpriteSheet, 620, 630), 
	tableau(deckSpriteSheet, 10, 10) {}

// Calls all functions to start game
void Logic::startGame() {

	stock.fill();
	stock.printCards();
	stock.shuffle();
	stock.printCards();

	waste.drawCards(stock);
	std::cout << "\nWaste has been drawn.\n";
	stock.printCards();

	tableau.fillCascades(stock);
	tableau.printCascades();
	stock.printCards();
}

// Draws each category along with their cards to the screen
void Logic::draw(sf::RenderWindow & window) {
	stock.draw(window);
	tableau.draw(window);
	waste.draw(window);
}

// Saves card to place somewhere else
void Logic::saveCard(Card card) {
	std::cout << "Saved" << card << "\n";
	savedCard = card;
}

// Take mouse position, return true if the x/y bounds are valid in the following ways:
// Must be inside either stock, waste, tableau or foundation
bool Logic::validMousePosition(sf::Vector2i pos) {
	// use waste.getXBounds()
	if (inWaste(pos) || inStock(pos)) {
		// Detect which card is being hovered over

		return true; // add inStock(), inTableau() etc
	}
	return false;
}

// Returns true if card placement logic is correct (detect card's suit & rank)
bool Logic::validCardPlacement(sf::Vector2i pos) {
	// Code goes here
	return true; // fix this later
}

// Returns true if mouse position is inside the waste
bool Logic::inWaste(sf::Vector2i pos) {
	if (pos.x > waste.getXBounds().y && pos.x < waste.getXBounds().x
		&& pos.y > waste.getYBounds().x && pos.y < waste.getYBounds().y) {

		if (pos.x > 620) saveCard(waste.getCards(2));
		else if (pos.x > 570 && pos.x < 620) saveCard(waste.getCards(1));
		else saveCard(waste.getCards(0));

		return true;
	}

	return false;
}

bool Logic::inStock(sf::Vector2i pos) {
	if (pos.x > stock.getXBounds().x && pos.x < stock.getXBounds().y
		&& pos.y > stock.getYBounds().x && pos.y < stock.getYBounds().y) {

		saveCard(stock.getTopCard());

		return true;
	}

	return false;
}