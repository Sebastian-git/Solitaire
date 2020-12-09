#include "Waste.h"

Waste::Waste(sf::Texture & deckSpriteSheet, int x, int y) : deckSpriteSheet(deckSpriteSheet), x(x), y(y) { }

void Waste::drawCards(Stock & stock) {
	if (stock.cards.size() > 0) {
		int originalSize = stock.cards.size();
		std::cout << stock.cards.size() << "\n";
		for (int i = 0; i < 3; i++) {
			if (i >= originalSize) return;
			std::cout << stock.cards.back() << "\n";
			stock.cards.back().setX(x);
			stock.cards.back().setY(y);
			stock.cards.back().setOrientation(1);
			cards.push_back(stock.cards.back());
			stock.cards.pop_back();
		}
	}
	else {
		for (int i = cards.size() - 1; i >= 0; i--) {
			stock.cards.push_back(cards[i]);
			stock.cards.back().setX(100);
			stock.cards.back().setY(700);
			stock.cards.back().setOrientation(0);
		}
		cards.clear();
		std::cout << "Put the all cards back into the stock";
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
	for (int i = cards.size() - 1; i >= 0; i--) {
		if (cards[i].containsPos(pos)) {
			return true;
		}
	}
	return false;
}

Card Waste::getCardAt(sf::Vector2i pos) {
	for (int i = cards.size() - 1; i >= 0; i--) {
		if (cards[i].containsPos(pos)) return cards[i];
	}
	return Card();
}

void Waste::removeCardAt(sf::Vector2i pos) {
	for (int i = cards.size() - 1; i >= 0; i--) {
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
	for (int i = 0; i < cards.size(); i++) {
		cards[i].draw(window, deckSpriteSheet);
	}
}