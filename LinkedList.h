#pragma once
#include "Card.h"

class Node {

	friend class LinkedList;

public:
	Node(Card data, Node * nextNode = nullptr) : data(data), nextNode(nextNode) {}

private:
	Card data;
	Node * nextNode;
};

class LinkedList {

public:
	typedef void (*NodeHandler) (Card & card, int index, sf::RenderWindow & window, sf::Texture & deckSpriteSheet);

	LinkedList();

	void push(Card card);
	Card pop();
	Card top();

	int size();
	void empty();

	void forEach(NodeHandler handler, sf::RenderWindow & window, sf::Texture & deckSpriteSheet);

	friend std::ostream& operator <<(std::ostream& out, const LinkedList& ll);

private:
	int length;
	Node * head;
};