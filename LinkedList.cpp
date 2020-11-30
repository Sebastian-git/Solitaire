#include "LinkedList.h"

LinkedList::LinkedList() : length(0), head(nullptr) { }

// Add card and set as new head
void LinkedList::push(Card card) {
	Node * cur = new Node(card);
	if (length == 0) head = cur;
	else {
		cur->nextNode = head;
		head = cur;
	}
	length++;
}

// Remove top card and return it
Card LinkedList::pop() {
	Node * top = head;
	head = top->nextNode;
	Card topData = top->data;
	delete top;
	length -= 1;
	return topData;
}

// Return top card
Card LinkedList::top() {
	return head->data;
}

// Return size of Stack
int LinkedList::size() {
	return length;
}

// Clear Stack
void LinkedList::empty() {
	while (head->nextNode != nullptr) {
		Node * top = head->nextNode;
		delete head;
		head = top;
	}
	head = nullptr;
	length = 0;
}

void LinkedList::forEach(NodeHandler handler, sf::RenderWindow & window, sf::Texture & deckSpriteSheet) {
	Node* cur = head;
	int index = 0;
	while (cur != nullptr) {
		handler(cur->data, index, window, deckSpriteSheet);
		cur = cur->nextNode;
		index++;
	}
}

Card LinkedList::operator[] (int position) {
	Node* cur = head;
	for (int i = 0; i <= position; i++) {
		if (i == position) return cur->data;
		cur = cur->nextNode;
	}
	return cur->data;
}

std::ostream& operator <<(std::ostream& out, const LinkedList& ll) {
	out << ll.length;
	return out;
}