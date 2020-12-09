# Solitaire

### Introduction
As a final project in my CS003A (Fundamentals of Computer Science II) class, students were asked to choose a game to create with two main rules. The program had to contain SFML to make a graphical interface, and it had to use a linked list (Stack/Queue). 


### Usage


#### Setup

1 - Clone the master repository (```git clone https://github.com/Sebastian-git/Solitaire.git```) <br>
2 - Install SFML [here](https://www.sfml-dev.org/download/sfml/2.5.1/) <br>
3 - Run the program and enjoy! <br>

( You do not need the folder "readmeImages", it just contains the preview images for Github )

##### Previews

The graphical display was created using SFML. In order to play the game, simply select a card by left clicking on it, then place it on a valid card. The game ends when you have all cards on the foundation (top four slots). 


<img alt="portfolio_view" src="https://github.com/Sebastian-git/Solitaire/blob/master/readmeImages/preview.png"> |


##### Technical Information 

One of the most important parts of the program is the ```validMousePosition(sf::Vector2i pos)``` function, which returns a boolean and handles nearly all of the logic to determine if there is a card where the user clicks. The function is a little over 50 lines of code, and is split into three main sections. <br>

1 - If there is no card selected

``` cpp
	if (!cardSelected) {

		 if (waste.containsPos(pos) && waste.getCardAt(pos).getOrientation() == 1) {
			 saveCard(waste.getCardAt(pos), pos);
			 saveCardClass = 1;
			 cardSelected = true;
			 return true;

		} else if (tableau.containsPos(pos) && tableau.getCardAt(pos).getOrientation() == 1) {
			tableau.saveCards(pos, tableau.getCardAt(pos), savedCards);
			savedPos = pos;
			saveCardClass = 2;
			cardSelected = true;
			return true;
		}
	}

```

2 - If a card is selected, check if you are allowed to place it on this new position

```cpp
else if (cardSelected && (inStock(pos) || waste.containsPos(pos) || tableau.containsPos(pos)) || foundation.containsPos(pos)) { 

		// Tableau card placement logic
		if (tableau.cascadeIsEmpty(pos) || (tableau.containsPos(pos) && validCardPlacement(tableau.getCardAt(pos)) &&
			tableau.containsTopCard(tableau.getCardAt(pos)))) {

			if (tableau.cascadeIsEmpty(pos) && savedCards[0].getRank() != 13) {
				unsaveCard();
				return false;
			}

			tableau.addCardAt(pos, savedCards);

			if (saveCardClass == 1) waste.removeCardAt(savedPos);
			else if (saveCardClass == 2) tableau.removeCardAt(savedPos);
		}

		// Foundation card placement logic
		if (savedCards.size() == 1 && ((foundation.containsPos(pos)) && foundation.stackIsEmpty(pos) && savedCards[0].getRank() == 1 || (foundation.containsPos(pos) && foundation.validNextCard(savedCards[0], pos)))) {

			foundation.addCardAt(pos, savedCards);

			if (saveCardClass == 1) waste.removeCardAt(savedPos);
			else if (saveCardClass == 2) tableau.removeCardAt(savedPos);
		}
		unsaveCard();
		return true;
	}

```

3 - If you are clicking off screen, unsave card
``` cpp
	else {
		unsaveCard();
	}
```


### Launch
C++ (GCC 9.2.0) <br>
Visual Studio <br>

### Status: 

In progress 

#### [back to the top](#title)
