#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Stock.h"
#include "Waste.h"
#include "Tableau.h"

class Logic {

public:
	Logic(sf::Texture & deckSpriteSheet);

	void startGame();
	
	void draw(sf::RenderWindow & window);

private:
	Stock stock;
	Waste waste;
	Tableau tableau;
	sf::Texture & deckSpriteSheet;
};