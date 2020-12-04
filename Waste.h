#pragma once
#include "LinkedList.h"
#include "Card.h"
#include "Stock.h"

class Waste {

public:
	Waste(sf::Texture & deckSpriteSheet, int x, int y);

	void drawCards(Stock & stock); // Draws 3 cards from Stock

	sf::Vector2i getXBounds();
	sf::Vector2i getYBounds();

	bool containsPos(sf::Vector2i pos);

	Card getCardAt(sf::Vector2i pos);
	void removeCardAt(sf::Vector2i pos);
	void saveCards(Card card, std::vector<Card>& savedCards);
	
	void draw(sf::RenderWindow & window); // Draws waste to window

private:
	std::vector<Card> cards;
	sf::Texture & deckSpriteSheet;
	int x, y;
	int drawCount;
};