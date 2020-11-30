#pragma once
#include <SFML\Graphics.hpp>
#include "Suit.h"
#include <iostream>

class Card {
	
public:
	Card();
	Card(int rank, Suit suit, int x, int y);

	int getRank();
	int getSuit();

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);

	bool getOrientation();

	void draw(sf::RenderWindow & window, sf::Texture & deckSpriteSheet);

	friend std::ostream& operator <<(std::ostream& out, const Card& card);
	friend bool operator ==(const Card& card1, const Card& card2);
	friend bool operator >(const Card& card1, const Card& card2);
	friend bool operator <(const Card& card1, const Card& card2); 

private:
	int rank;
	Suit suit;

	int x;
	int y;

	bool orientation;
};