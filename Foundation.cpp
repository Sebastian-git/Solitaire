#include "Foundation.h"

Foundation::Foundation(sf::Texture& deckSpriteSheet, int x, int y) : deckSpriteSheet(deckSpriteSheet), x(x), y(y),
foundationSize(4), width(900), height(160) {
};

std::vector<Card> Foundation::getTopCards() {
	std::vector<Card> topCards;
	
	for (int i = 0; i < foundationSize; i++) {
		if (foundation[i].getStack().size() > 0) {
			topCards.push_back(foundation[i].getStack().top());
		}
	}
	return topCards;
}

bool Foundation::stackIsEmpty(sf::Vector2i pos) {
	for (int i = 0; i < foundationSize; i++) {
		if (foundation[i].containsPos(pos) && foundation[i].getStack().size() == 0) return true;
	}
	return false;
}

bool Foundation::containsPos(sf::Vector2i pos) {
	if (pos.x > x && pos.x < x + width && pos.y > y && pos.y < y + height) {
		for (int i = 0; i < foundationSize; i++) {
			if (foundation[i].containsPos(pos)) {
				return true;
			}
		}
	}
	return false;
}

bool Foundation::containsTopCard(Card card) {
	std::vector<Card> topCards = getTopCards();
	for (int i = 0; i < topCards.size(); i++) {
		if (topCards[i] == card) return true;
	}
	return false;
}

bool Foundation::validNextCard(Card card, sf::Vector2i pos) {
	for (int i = 0; i < foundationSize; i++) {
		if (foundation[i].containsPos(pos)) {
			return foundation[i].validNextCard(card, pos);
		}
	}
	return false;
}

Card Foundation::getCardAt(sf::Vector2i pos) {
	for (int i = 0; i < foundationSize; i++) {
		if (foundation[i].containsPos(pos) && foundation[i].getStack().size() > 0) {
			return foundation[i].getCardAt(pos);
		}
	}
	return Card();
}

void Foundation::addCardAt(sf::Vector2i pos, Card& card) {
	for (int i = 0; i < foundationSize; i++) {
		if (foundation[i].containsPos(pos)) {
			foundation[i].addCard(card);
		}
	}
}

void Foundation::printStacks() {
	for (int i = 0; i < foundationSize; i++) {
		std::cout << foundation[i].getStack().size() << "\n";
	}
}

void Foundation::draw(sf::RenderWindow& window) {
	for (int i = 0; i < foundationSize; i++) {
		foundation[i].draw(window);
	}
}