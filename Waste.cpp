#include "Waste.h"

Waste::Waste(sf::Texture & deckSpriteSheet, int x, int y) : cards(), deckSpriteSheet(deckSpriteSheet), x(x), y(y) { }

void Waste::drawCards(Stock & stock) {
	for (int i = 0; i < 3; i++) {
		stock.cards.back().setX(x-(i*50));
		stock.cards.back().setY(y);
		cards.push(stock.cards.back());
		stock.cards.pop_back();
	}
}

const LinkedList & Waste::getCards() const {
	return cards;
}

void Waste::draw(sf::RenderWindow & window) {
	auto drawHandler = [](Card & card, int index, sf::RenderWindow & window, sf::Texture & deckSpriteSheet) {
		card.draw(window, deckSpriteSheet);
	};
	cards.forEach(drawHandler, window, deckSpriteSheet);
}