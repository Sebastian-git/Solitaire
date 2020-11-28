#include "Logic.h"
#include <SFML/Graphics.hpp>

Logic::Logic(sf::Texture & deckSpriteSheet) : deckSpriteSheet(deckSpriteSheet), stock(deckSpriteSheet, 10, 630), waste(deckSpriteSheet, 620, 630), tableau(deckSpriteSheet, 10, 10) {}

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

// The following functions will be used to retrieve the card locations on the sprite deck image
// Suit 0 = Heart, 1 = Spades, 2 = Diamonds, 3 = Clubs
// Left, top, width, height =  left, top, right, bottom

// Draw calls Stock.draw(), Tableau.draw(), Foundation.draw()

void Logic::draw(sf::RenderWindow & window) {
	stock.draw(window);
	tableau.draw(window);
	waste.draw(window);
}