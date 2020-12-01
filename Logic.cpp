#include "Logic.h"
#include <SFML/Graphics.hpp>

Logic::Logic(sf::Texture & deckSpriteSheet) : 
	deckSpriteSheet(deckSpriteSheet), 
	stock(deckSpriteSheet, 10, 700),
	waste(deckSpriteSheet, 1100, 700), 
	tableau(deckSpriteSheet, 180, 280) {}

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
void Logic::saveCard(Card card, sf::Vector2i pos) {
	if (card.getRank() > 0 && cardSelected == false) {
		std::cout << "Saved" << card << "\n";
		savedPos = pos;
		savedCard = card;
		cardSelected = true;
	}
}

void Logic::unsaveCard() {
	savedPos = sf::Vector2i(0, 0);
	savedCard = Card();
	cardSelected = false;
	std::cout << "Unsaved card card.\n";
}

// Take mouse position, return true if the x/y bounds are valid in the following ways:
// Must be inside either stock, waste, tableau or foundation
bool Logic::validMousePosition(sf::Vector2i pos) {
	if (inStock(pos)) {
		return true;
	}
	// If there is no card selected
	if (!cardSelected) { 
		 if (waste.containsPos(pos) && waste.getCardAt(pos).getOrientation() == 1) {
			saveCard(waste.getCardAt(pos), pos);
			saveCardClass = 1;
			return true;
		} else if (tableau.containsPos(pos) && tableau.getCardAt(pos).getOrientation() == 1) {
			saveCard(tableau.getCardAt(pos), pos);
			saveCardClass = 2;
			return true;
		}
	}
	// If a card is selected, check if you are allowed to place it on this new position
	else if (cardSelected && (inStock(pos) || waste.containsPos(pos) || tableau.containsPos(pos))) { 
		if (tableau.cascadeIsEmpty(pos) || (tableau.containsPos(pos) && validCardPlacement(tableau.getCardAt(pos)) &&
			tableau.containsTopCard(tableau.getCardAt(pos)))) {

			tableau.addCardAt(pos, savedCard);

			if (saveCardClass == 1) waste.removeCardAt(savedPos);
			else if (saveCardClass == 2) tableau.removeCardAt(savedPos);
			//else if (saveCardClass == 3)  foundation
		}
		unsaveCard();
		return true;
	}
	// If you are clicking off screen, unsave card
	else {
		unsaveCard();
	}

	return false;
}

// Returns true if card placement logic is correct (detect card's suit & rank)
bool Logic::validCardPlacement(Card card) {
	if ((card.getSuit() >= 2 && savedCard.getSuit() < 2 ||
		card.getSuit() <= 2 && savedCard.getSuit() >= 2) &&
		card.getRank() - 1 == savedCard.getRank()) {
			return true;
	}
	return false;
}

// Checks if clicking on stock, if you are it draws 3 more waste cards
bool Logic::inStock(sf::Vector2i pos) {
	if (pos.x > stock.getXBounds().x && pos.x < stock.getXBounds().y
		&& pos.y > stock.getYBounds().x && pos.y < stock.getYBounds().y) {

		waste.drawCards(stock);

		return true;
	}
	return false;
}