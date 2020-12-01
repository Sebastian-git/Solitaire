#include "Card.h"

const float Card::width = 39, Card::height = 52, Card::scale = 3.f;

Card::Card() {};

Card::Card(int rank, Suit suit, int x, int y, bool orientation) : rank(rank), suit(suit), x(x), y(y), orientation(orientation) {}

int Card::getRank() {
	return rank;
}

int Card::getSuit() {
	return (int)suit;
}

int Card::getX() {
	return x;
}

int Card::getY() {
	return y;
}

float Card::getWidth() {
	return width*scale;
}

float Card::getHeight() {
	return height*scale;
}

void Card::setX(int x) {
	this->x = x;
}

void Card::setY(int y) {
	this->y = y;
}

bool Card::containsPos(sf::Vector2i pos) {
	if (pos.x < x + 114 && pos.x > x &&
		pos.y < y + 152 && pos.y > y) {
		return true;
	}
	return false;
}

void Card::setOrientation(bool orientation) {
	this->orientation = orientation;
}

bool Card::getOrientation() {
	return orientation;
}

void Card::draw(sf::RenderWindow & window, sf::Texture & deckSpriteSheet) {
	sf::IntRect loc = sf::IntRect(
		(int)((rank - 1) * 39.4),
		((int)suit) * 53,
		width,
		height
	);

	// Creates card image
	sf::Sprite sprite;
	sprite.setTexture(deckSpriteSheet);
	sprite.scale(sf::Vector2f(scale, scale));
	sprite.setTextureRect(loc);
	sprite.setPosition(sf::Vector2f((float)x, (float)y));
	// Cards that are visible
	if (orientation == 1) window.draw(sprite);
	// Cards that are flipped upside down
	else {
		sprite.setColor(sf::Color::Red);
		window.draw(sprite);
	}
}

std::ostream& operator <<(std::ostream& out, const Card & card) {
	out << "(" << card.rank << " " << (int)card.suit << ")";
	return out;
}

bool operator ==(const Card & card1, const Card & card2) {
	return (card1.rank == card2.rank && card1.suit == card2.suit);
}