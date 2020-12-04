#pragma once
#include <vector>
#include "LinkedList.h"
#include "Stock.h"
#include "Card.h"

class Stack {

public:
	Stack(sf::Texture& deckSpriteSheet, int x, int y);

	bool containsPos(sf::Vector2i pos);
	bool validNextCard(Card card, sf::Vector2i pos);

	Card getCardAt(sf::Vector2i pos);

	void addCard(std::vector<Card> cards);

	LinkedList getStack();

	void draw(sf::RenderWindow& window);

private:
	LinkedList stack;

	sf::Texture& deckSpriteSheet;

	int x, y;
	int width, height;
};

