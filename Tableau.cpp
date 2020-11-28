#include "Tableau.h"

Tableau::Tableau(sf::Texture & deckSpriteSheet, int x, int y) : deckSpriteSheet(deckSpriteSheet), x(x), y(y) {};

void Tableau::fillCascades(Stock& stock) {
	for (int i = 1; i <= 7; i++) {
		cascades.push_back(Cascade(deckSpriteSheet, x+(80 + (i-1) * (4.9*35) ), y+300));
		cascades[i - 1].startCards(stock, i);
	}
}

std::vector<Cascade> Tableau::getCascades() {
	return cascades;
}

std::vector<Card> Tableau::getTopCards() {
	std::vector<Card> topCards;
	for (int i = 0; i < cascades.size(); i++) {
		topCards.push_back(cascades[i].getCascade().top());
	}
	return topCards;
}

void Tableau::printCascades() {
	for (int i = 0; i < cascades.size(); i++) {
		std::cout << cascades[i].getCascade().size() << "\n";
	}
}

void Tableau::draw(sf::RenderWindow& window) {
	for (int i = 0; i < cascades.size(); i++) {
		cascades[i].draw(window);
	}
}