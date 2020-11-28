#pragma once
#include <SFML\Graphics.hpp>
#include "Card.h"
#include <vector>

class Stock {
	friend class Waste;
	friend class Cascade;

public:
	Stock(sf::Texture & deckSpriteSheet, int x, int y);

	void fill();
	void shuffle();
	void printCards();
	Card getTopCard();
	void draw(sf::RenderWindow& window);

private:
	std::vector<Card> cards;
	sf::Texture & deckSpriteSheet;
	int x, y;
};