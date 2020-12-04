#include "Logic.h"
#include <SFML/Graphics.hpp>

Logic::Logic(sf::Texture& deckSpriteSheet) :
	deckSpriteSheet(deckSpriteSheet),
	stock(deckSpriteSheet, 10, 700),
	waste(deckSpriteSheet, 1100, 700),
	tableau(deckSpriteSheet, 180, 260),
	foundation(deckSpriteSheet, 260, 60)
{}

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
	foundation.draw(window);
}

// Saves card
void Logic::saveCard(Card card, sf::Vector2i pos) {
	if (card.getRank() > 0 && cardSelected == false) {
		savedPos = pos;
		savedCards.push_back(card);
		cardSelected = true;
		std::cout << "Saved " << card << "\n";
	}
}

// Unsaves card from logic 
void Logic::unsaveCard() {
	savedPos = sf::Vector2i(0, 0);
	cardSelected = false;
	savedCards.clear();
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
			 cardSelected = true;
			 return true;

		} else if (tableau.containsPos(pos) && tableau.getCardAt(pos).getOrientation() == 1) {
			tableau.saveCards(pos, tableau.getCardAt(pos), savedCards);
			savedPos = pos;
			saveCardClass = 2;
			cardSelected = true;
			return true;
		}
	}

	// If a card is selected, check if you are allowed to place it on this new position
	else if (cardSelected && (inStock(pos) || waste.containsPos(pos) || tableau.containsPos(pos)) || foundation.containsPos(pos)) { 

		// Tableau card placement logic
		if (tableau.cascadeIsEmpty(pos) || (tableau.containsPos(pos) && validCardPlacement(tableau.getCardAt(pos)) &&
			tableau.containsTopCard(tableau.getCardAt(pos)))) {

			if (tableau.cascadeIsEmpty(pos) && savedCards[0].getRank() != 13) {
				unsaveCard();
				return false;
			}

			tableau.addCardAt(pos, savedCards);

			if (saveCardClass == 1) waste.removeCardAt(savedPos);
			else if (saveCardClass == 2) tableau.removeCardAt(savedPos);
		}

		// Foundation card placement logic
		if (savedCards.size() == 1 && ((foundation.containsPos(pos)) && foundation.stackIsEmpty(pos) && savedCards[0].getRank() == 1 || (foundation.containsPos(pos) && foundation.validNextCard(savedCards[0], pos)))) {

			foundation.addCardAt(pos, savedCards);

			if (saveCardClass == 1) waste.removeCardAt(savedPos);
			else if (saveCardClass == 2) tableau.removeCardAt(savedPos);
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
	if ((card.getSuit() <= 1 && savedCards[0].getSuit() >= 2 ||
		card.getSuit() >= 2 && savedCards[0].getSuit() <= 1) &&
		card.getRank() - 1 == savedCards[0].getRank()) {
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