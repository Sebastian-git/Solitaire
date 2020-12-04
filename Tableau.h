#pragma once
#include <vector>
#include "LinkedList.h"
#include "Cascade.h"
#include "Stock.h"

class Tableau {

public:
	Tableau(sf::Texture & deckSpriteSheet, int x, int y);
	
	void fillCascades(Stock & stock);
	
	std::vector<Card> getTopCards();

	bool cascadeIsEmpty(sf::Vector2i pos);

	bool containsPos(sf::Vector2i pos);
	bool containsTopCard(Card card);

	Card getCardAt(sf::Vector2i pos);
	void removeCardAt(sf::Vector2i pos);
	void saveCards(sf::Vector2i pos, Card card, std::vector<Card>& savedCards);

	void addCardAt(sf::Vector2i pos, std::vector<Card> & cards);

	void printCascades();	
	void draw(sf::RenderWindow& window);

private:
	sf::Texture & deckSpriteSheet;
	std::vector<Cascade> cascades;

	int x, y;
	int width, height;
};