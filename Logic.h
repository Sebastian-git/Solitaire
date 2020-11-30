#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Stock.h"
#include "Waste.h"
#include "Tableau.h"
#include "Card.h"

class Logic {

public:
	Logic(sf::Texture & deckSpriteSheet);

	void startGame();
	
	void draw(sf::RenderWindow & window);

	void saveCard(Card card); // if in valid mouse position, save card value to place

	bool validCardPlacement(sf::Vector2i pos);
	bool validMousePosition(sf::Vector2i pos);

	bool inWaste(sf::Vector2i pos); 
	bool inStock(sf::Vector2i pos);

private:
	Stock stock;
	Waste waste;
	Tableau tableau;
	
	sf::Texture & deckSpriteSheet;

	Card savedCard;
};