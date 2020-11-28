#pragma once
#include <vector>
#include "LinkedList.h"
#include "Cascade.h"
#include "Stock.h"

class Tableau {

public:
	Tableau(sf::Texture & deckSpriteSheet, int x, int y);
	
	void fillCascades(Stock & stock);
	
	std::vector<Cascade> getCascades();
	std::vector<Card> getTopCards();

	void printCascades();	
	void draw(sf::RenderWindow& window);

private:
	sf::Texture & deckSpriteSheet;
	std::vector<Cascade> cascades;
	int x, y;
};