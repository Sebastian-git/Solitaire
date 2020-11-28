#include "Cascade.h"

Cascade::Cascade(sf::Texture& deckSpriteSheet, int x, int y) : deckSpriteSheet(deckSpriteSheet), x(x), y(y) {};

LinkedList Cascade::getCascade() {
	return cascade;
}

void Cascade::startCards(Stock & stock, int total) {
	for (int i = 1; i <= total; i++) {
		stock.cards.back().setX(x);
		stock.cards.back().setY(y + (30 * (total-i)));
		cascade.push(stock.cards.back());
		stock.cards.pop_back();
	}
}

void Cascade::draw(sf::RenderWindow& window) {
	auto drawHandler = [](Card& card, int index, sf::RenderWindow& window, sf::Texture& deckSpriteSheet) {
		card.draw(window, deckSpriteSheet);
	};
	cascade.forEach(drawHandler, window, deckSpriteSheet);
}