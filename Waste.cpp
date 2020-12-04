#include "Waste.h"

Waste::Waste(sf::Texture & deckSpriteSheet, int x, int y) : deckSpriteSheet(deckSpriteSheet), x(x), y(y), drawCount(0) { }

void Waste::drawCards(Stock & stock) {
	if (stock.cards.size() >= 3) {
		for (int i = 0; i < 3; i++) {
			stock.cards.back().setX(x - drawCount * 40);
			stock.cards.back().setY(y);
			stock.cards.back().setOrientation(1);
			cards.push_back(stock.cards.back());
			stock.cards.pop_back();
			drawCount++;
		}
	}
}

sf::Vector2i Waste::getXBounds() {
	sf::Vector2i xBounds(x+116, x - 100);
	return xBounds;
}

sf::Vector2i Waste::getYBounds() {
	sf::Vector2i yBounds(y, y+154);
	return yBounds;
}

bool Waste::containsPos(sf::Vector2i pos) {
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i].containsPos(pos)) return true;
	}
	return false;
}

Card Waste::getCardAt(sf::Vector2i pos) {
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i].containsPos(pos)) return cards[i];
	}
	return Card();
}

void Waste::removeCardAt(sf::Vector2i pos) {
	std::cout << "Called waste\n";
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i].containsPos(pos)) {
			cards.erase(cards.begin()+i);
			return;
		}
	}
}

void Waste::saveCards(Card card, std::vector<Card>& savedCards) {
	bool save = false;
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i] == card) save = true;
		if (save) savedCards.push_back(cards[i]);
	}
	for (int i = 0; i < savedCards.size(); i++) {
		std::cout << "Saved" << savedCards[i] << "\n";
	}
}

void Waste::draw(sf::RenderWindow & window) {
	for (int i = cards.size()-1; i >= 0; i--) {
		cards[i].draw(window, deckSpriteSheet);
	}
}