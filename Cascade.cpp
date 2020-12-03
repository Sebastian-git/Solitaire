#include "Cascade.h"

Cascade::Cascade(sf::Texture& deckSpriteSheet, int x, int y) : deckSpriteSheet(deckSpriteSheet), x(x), y(y),
width(114), height(155) {}; // fix later width and height

void Cascade::startCards(Stock & stock, int total) {
	for (int i = 1; i <= total; i++) {
		stock.cards.back().setX(x);
		stock.cards.back().setY(y + (30 * (i-1)));
		cascade.push_back(stock.cards.back());
		stock.cards.pop_back();
	}
	cascade.back().setOrientation(1);
}

bool Cascade::containsPos(sf::Vector2i pos) {
	if (pos.x > x && pos.x < x + width &&
		pos.y > y && pos.y < y + (height + (28 * cascade.size()))) {
		return true;
	}
	return false;
}

Card Cascade::getCardAt(sf::Vector2i pos) {
	for (int i = cascade.size() - 1; i >= 0; i--) {
		if (cascade[i].containsPos(pos)) return cascade[i];
	}
	return Card();
}

void Cascade::addCard(Card card) {
	if (cascade.size() > 0) {
		card.setX(x);
		card.setY(cascade.back().getY() + 30);
		cascade.push_back(card);
	}
	else {
		card.setX(x);
		card.setY(y);
		cascade.push_back(card);
	}
}

void Cascade::removeCardAt(sf::Vector2i pos) {
	for (int i = cascade.size()-1; i >= 0; i--) {
		if (cascade[i].containsPos(pos)) {
			cascade.erase(cascade.begin() + i);
			break;
		}
	}
	if (cascade.size() > 0) cascade.back().setOrientation(1);
}

std::vector<Card> Cascade::getCascade() {
	return cascade;
}

void Cascade::draw(sf::RenderWindow& window) {
	for (int i = 0; i < cascade.size(); i++) {
		cascade[i].draw(window, deckSpriteSheet);
	}
}

int Cascade::size() {
	return cascade.size();
}