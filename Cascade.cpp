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

void Cascade::addCard(std::vector<Card>& cards) {
	for (int i = 0; i < cards.size(); i++) {
		if (cascade.size() > 0) {
			cards[i].setX(x);
			cards[i].setY(cascade.back().getY() + 30);
			cascade.push_back(cards[i]);
		}
		else {
			cards[i].setX(x);
			cards[i].setY(y);
			cascade.push_back(cards[i]);
		}
	}
}

void Cascade::removeCardAt(sf::Vector2i pos) {
	for (int i = cascade.size()-1; i >= 0; i--) {
		if (cascade[i].containsPos(pos)) {
			cascade.erase(cascade.begin() + i, cascade.end());
			break;
		}
	}
	if (cascade.size() > 0) cascade.back().setOrientation(1);
}

void Cascade::saveCards(Card card, std::vector<Card>& savedCards) {
	bool save = false;
	for (int i = 0; i < cascade.size(); i++) {
		if (cascade[i] == card) save = true;
		if (save) savedCards.push_back(cascade[i]);
	}
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