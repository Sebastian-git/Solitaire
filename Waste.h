#pragma once
#include "LinkedList.h"
#include "Card.h"
#include "Stock.h"

class Waste {

public:
	Waste(sf::Texture & deckSpriteSheet, int x, int y);

	void drawCards(Stock & stock); // Draws 3 cards from Stock

	Card getCards(int index);

	sf::Vector2i getXBounds();
	sf::Vector2i getYBounds();
	
	void draw(sf::RenderWindow & window); // Draws waste to window

private:
	LinkedList cards;
	sf::Texture & deckSpriteSheet;
	int x, y;
};