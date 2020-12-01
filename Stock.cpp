#include "Stock.h"
#include <cstdlib>
#include <iostream>

Stock::Stock(sf::Texture & deckSpriteSheet, int x, int y) : deckSpriteSheet(deckSpriteSheet), x(x), y(y) {}

void Stock::fill() {
	cards.clear();
	for (int i = 0; i < 52; i++) {
		cards.push_back(Card((i % 13) + 1, (Suit)(i % 4), x, y, 0));
	}
}

void Stock::shuffle() {
	for (unsigned int i = 0; i < cards.size(); i++) {
		int randIndex = rand() % cards.size();
		Card temp = cards[i];
		cards[i] = cards[randIndex];
		cards[randIndex] = temp;
	}
}

void Stock::printCards() {
	for (unsigned int i = 0; i < cards.size(); i++) {
		if (i % 13 == 0) std::cout << "\n";
		std::cout << cards[i] << " ";
	}
	std::cout << "\n";
}

Card Stock::getTopCard() {
	return cards[cards.size()-1];
}

sf::Vector2i Stock::getXBounds() {
	sf::Vector2i xBounds(x, x+117);
	return xBounds;
}

sf::Vector2i Stock::getYBounds() {
	sf::Vector2i yBounds(y, y+154);
	return yBounds;
}

void Stock::draw(sf::RenderWindow& window) {
	if (cards.size() > 0) {
		cards.back().setOrientation(1);
		cards.back().draw(window, deckSpriteSheet);
	}
}