#pragma once
#include "LinkedList.h"
#include "Stock.h"

class Cascade {

public:
	Cascade(sf::Texture & deckSpriteSheet, int x, int y);
	void startCards(Stock& stock, int total);

	LinkedList getCascade();
	void draw(sf::RenderWindow & window);

private:
	LinkedList cascade;
	sf::Texture& deckSpriteSheet;
	int x, y;
};