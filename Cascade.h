#pragma once
#include <vector>
#include "LinkedList.h"
#include "Stock.h"
#include "Card.h"

class Cascade {

public:
	Cascade(sf::Texture & deckSpriteSheet, int x, int y);
	void startCards(Stock& stock, int total);

	bool containsPos(sf::Vector2i pos);
	Card getCardAt(sf::Vector2i pos);

	void addCard(std::vector<Card>& cards);
	void removeCardAt(sf::Vector2i pos);
	void saveCards(Card card, std::vector<Card>& savedCards);

	std::vector<Card> getCascade();
	int getLargestCascade();
	void draw(sf::RenderWindow & window);

	int size();

private:
	std::vector<Card> cascade;

	sf::Texture& deckSpriteSheet;

	int x, y;
	int width, height;
};