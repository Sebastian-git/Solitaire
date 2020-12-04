#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Stock.h"
#include "Waste.h"
#include "Tableau.h"
#include "Card.h"
#include "Foundation.h"

class Logic {

public:
	Logic(sf::Texture & deckSpriteSheet);

	void startGame();
	
	void draw(sf::RenderWindow & window);

	void saveCard(Card card, sf::Vector2i pos);
	void unsaveCard();

	bool validCardPlacement(Card card);
	bool validMousePosition(sf::Vector2i pos);

	bool inStock(sf::Vector2i pos);

private:
	Stock stock;
	Waste waste;
	Tableau tableau;
	Foundation foundation;
	
	sf::Texture & deckSpriteSheet;

	std::vector<Card> savedCards;
	sf::Vector2i savedPos;
	int saveCardClass; // 0 = default, 1 = waste, 2 = tableau, 3 = foundation
	bool cardSelected;
};