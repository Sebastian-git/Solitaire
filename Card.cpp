#include "Card.h"

Card::Card() {};

Card::Card(int rank, Suit suit, int x, int y) : rank(rank), suit(suit), x(x), y(y) {}

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

void Card::setX(int x) {
	this->x = x;
}

void Card::setY(int y) {
	this->y = y;
}

bool Card::getOrientation() {
	return orientation;
}

void Card::draw(sf::RenderWindow & window, sf::Texture & deckSpriteSheet) {
	sf::IntRect loc = sf::IntRect(
		(int)((rank - 1) * 39.4),
		((int)suit) * 53,
		39,
		52
	);

	// Creates card image
	sf::Sprite sprite;
	sprite.setTexture(deckSpriteSheet);
	sprite.scale(sf::Vector2f(3.f, 3.f));
	sprite.setTextureRect(loc);
	sprite.setPosition(sf::Vector2f((float)x, (float)y));
	window.draw(sprite);
}

std::ostream& operator <<(std::ostream& out, const Card & card) {
	out << "(" << card.rank << " " << (int)card.suit << ")";
	return out;
}

bool operator ==(const Card & card1, const Card & card2) {
	return (card1.rank == card2.rank && card1.suit == card2.suit);
}

bool operator >(const Card& card1, const Card& card2) {
	return card1.rank > card2.rank;
}

bool operator <(const Card& card1, const Card& card2) {
	return card1.rank < card2.rank;
}