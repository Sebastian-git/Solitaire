# Solitaire

### Introduction
As a final project in my CS003A (Fundamentals of Computer Science II) class, students were asked to choose a game to create with two main rules. The program had to contain SFML to make a graphical interface, and it had to use a linked list (Stack/Queue). 


### Usage


#### Setup

1 - Clone the master repository (```git clone https://github.com/Sebastian-git/Solitaire.git```) <br>
2 - Install SFML [here](https://www.sfml-dev.org/download/sfml/2.5.1/) <br>
3 - Run the program and enjoy! <br>

(** You do not need the folder "readmeImages", it just contains the preview images for Github **)

##### Previews

The graphical display was created using SFML. In order to play the game, simply select a card by left clicking on it, then place it on a valid card. The game ends when you have all cards on the foundation (top four slots). 


<img width="200" height="400" alt="portfolio_view" src="https://github.com/Sebastian-git/Solitaire/blob/master/readmeImages/preview.png"> |


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


This code takes the minimum and maximum constraints given by the front end, then connect the API inside the config object. The program then creates a two dimensional array. There is one array that contains multiple other arrays with entries of data that is then sent to the front end.

Another important group of code lies inside ```config/firebase.js```, which contains multiple functions that take advantage of Firebase's [firestore](https://firebase.google.com/docs/firestore) and [authentication](https://firebase.google.com/docs/auth) API's.
``` js
doCreateUserWithEmailAndPassword = (email, password) => {
  return this.auth.createUserWithEmailAndPassword(email, password)
}
```
These two critical lines of code create a new account using an email and a password through the authentication API.
``` js
doSaveFireball = (fireball, email) => {
  if (email) {
    return this.db
    .collection('fireballs').doc(email)
    .set(
      {fireball: app.firestore.FieldValue.arrayUnion(fireball)},
      {merge: true}
      );
   }
}
```
This function takes a fireball and email as parameters, checks if the email exists and then saves the entries to view in the favorites page.

### <a name="members"></a> Meet the Team

**Titles** | **Sebastian Cevallos** | **Petula Pascall** | **Brandan Herron** |
|-|-|-|-|
|**Role**| Project Manager/Back-end Developer | Front-end Developer | Back-end Developer |
|**Contact**| [Github](https://github.com/Sebastian-git), [LinkedIn](https://www.linkedin.com/in/sebastian-cevallos-2917bb16a/) | [Github](https://github.com/SeePetulaCode), [LinkedIn](https://www.linkedin.com/in/petulapascall/) | [Github](https://github.com/brandan1989), [LinkedIn](https://www.linkedin.com/in/brandan-herron/) |


### Launch
HTML 5, CSS 3, Javascript 3 <br>
Node.js 12.18.3, Nodemon 2.0.4, Express 4.17.1, Express-Session 1.17.1, Axios 0.19.2, Body-Parser 1.19.0 <br>
Firebase 7.18.0, VS Code 1.48, Heroku <br>

### Status: 

Complete 

#### [back to the top](#title)
